#orm对象关系映射
from datetime import datetime
from fastapi import FastAPI,Depends,HTTPException
from sqlalchemy import DateTime,func,String,Float,select
from sqlalchemy.ext.asyncio import create_async_engine,async_sessionmaker,AsyncSession
from sqlalchemy.orm import DeclarativeBase,Mapped,mapped_column
from pydantic import BaseModel

app=FastAPI()

#创建异步引擎
ASYNC_DATEBASE_URL = "mysql+aiomysql://root:1234@localhost:3306/fastapi_first?charset=utf8"
async_engine=create_async_engine(
    ASYNC_DATEBASE_URL,
    echo=True,#可选，输出sql日志
    pool_size=10,#设置活跃池连接数
    max_overflow=20#允许额外的连接数
)

#定义模型类：基类+表对应的模型类
class Base(DeclarativeBase):
    create_time:Mapped[datetime] = mapped_column(DateTime,insert_default=func.now(),default=func.now,comment="创建时间")
    update_time:Mapped[datetime] = mapped_column(DateTime,insert_default=func.now(),default=func.now,onupdate=func.now(),comment="修改的时间")

class Book(Base):
    __tablename__="book"

    id:Mapped[int] = mapped_column(primary_key=True,comment="书记id")
    bookname:Mapped[str] = mapped_column(String(255),comment="书名")
    author:Mapped[str] = mapped_column(String(255),comment="作者")
    price:Mapped[float] = mapped_column(Float,comment="价格")

#建表
async def create_tables():
    async with async_engine.begin() as conn:
        await conn.run_sync(Base.metadata.create_all)#使用模型类元数据创建

@app.on_event("startup")
async def startup_event():
    await create_tables()

@app.get("/")
async def root():
    return {"message":"Hello World!"}

#查询功能的结口→创建依赖项获取数据库会话→dependends注入路由器功能
AsyncSessionLocal = async_sessionmaker(
    bind=async_engine,      #绑定数据库引擎
    class_=AsyncSession,       #指定会话类
    expire_on_commit=False  #提交会话后不过期，不会查询数据库
)

#依赖项
async def get_database():
    async with AsyncSessionLocal() as session:
        try:
            yield session #返回数据库会话给路由处理函数
            await session.commit() #提交事务
        except:
            await session.rollback() #有异常回滚
            raise
        finally:
            await session.close() #关闭会话
        
#定义路由----------查询
#查询 await db.execute(select(模型类)),返回一个ORM对象
#获取所有数据  scalars.all()
#获取单条数据  scalars.first();get(模型，主键值)
#查询条件，==，>=,<=,等
#like，任意个：%，一个：_;.like("x_")两个字以x开头，x%以x开头的都行
#&|！，与或非
#in_()，包含
@app.get("/book/books")
async def get_book_list(db:AsyncSession = Depends(get_database)):
    #result存储orm结果
    result=await db.execute(select(Book))
    # ans=result.scalars().all(),获取所有
    # 获取单条 ans=result.scalars().first()
    #get获取 ans = await db.get(Book,2)
    ans=result.scalars().first()
    return ans

@app.get("/book/{book_id}")
async def get_book(book_id:int,db:AsyncSession=Depends(get_database)):
    #where带条件
    result=await db.execute(select(Book).where(Book.id==book_id))
    book=result.scalar_one_or_none()
    return book

#聚合查询
#聚合计算，func.方法名
#cout统计行数量
#avg平均值
#max，min，sum

#分页查询
#select().offset().limit()
#offset：跳过的记录数，其值为[（当前页数-1）*每页记录数]
#limit：返回的记录数，其值为（每页记录数）
 

 #新增   .add
class BookBase(BaseModel):
    id:int
    bookname:str
    author:str
    price:float

@app.post("/book/add_book")
async def addBook(book:BookBase,db:AsyncSession=Depends(get_database)):
    bookOBJ=Book(**book.__dict__)
    db.add(bookOBJ)
    await db.commit()
    return book


 #更新    先查再改
@app.put("/book/updateBook/{book_id}")
async def updateBook(book_id:int,data:BookBase,db:AsyncSession=Depends(get_database)):

    #查找
    book = await db.get(Book,book_id)
    if book is None:
        raise HTTPException(status_code=404,detail="Book not found")
    
    #修改
    book.bookname=data.bookname
    book.author=data.author
    book.price=data.price

    #提交
    await db.commit()
    return book




 #删除    .delete()
@app.delete("/book/deleteBook/{book_id}")
async def deleteBook(book_id:int,db:AsyncSession=Depends(get_database)):

    #查找
    book = await db.get(Book,book_id)
    if book is None:
        raise HTTPException(status_code=404,detail="Book not found")
    
    #删除
    await db.delete(book)

    #提交
    await db.commit()
    return {"message":"删除图书成功"}