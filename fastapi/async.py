from fastapi import FastAPI,Path,Query,HTTPException,Depends
from pydantic import BaseModel,Field
import asyncio
#默认jason格式的响应，导入html响应，文件响应
from fastapi.responses import HTMLResponse,FileResponse

#启动，uvicorn async:app --reload

# 创建 FastAPI 应用实例
app = FastAPI()

async def function(first: int, end: int):
    total = 0
    for i in range(first, end):
        total += i
        await asyncio.sleep(0)  # 模拟异步操作
    return total

# 定义 API 端点
@app.get("/calculate")
async def calculate_sum(first: int = 1, end: int = 10):
    """计算从 first 到 end-1 的和"""
    result = await function(first, end)
    return {
        "first": first,
        "end": end,
        "sum": result,
        "message": f"计算 {first} 到 {end-1} 的和"
    }

# 路由：url地址与处理函数的映射关系
@app.get("/hello")
async def root():
    return {"message": "欢迎使用求和计算 API"}

#路径参数，{}要与函数中的参数一致
@app.get("/book/{id}")
async def bookid(id:int=Path(...,gt=0,lt=101,description="书籍取值范围1-100")):
    return {f"这是第{id}本书。"}

#查询参数，过滤
@app.get("/news/news_list")
async def get_news_list(
    skip:int=Query(0,description="跳过记录数",lt=100),
    limit:int=Query(10,description="返回的记录数")):
    return {"skip":skip,"limit":limit}

#请求体，创建更新资源；Field,web类型注解
class User(BaseModel):
    username:str=Field("张三",min_length=2,max_length=4,description="长度2-4")
    password:str=Field(min_length=3,max_length=20)
@app.post("\register")
async def register(user:User):
    return user


#HTML响应,直接通过路径看效果，文档看类型
@app.get("/html",response_class=HTMLResponse)
async def get_html():
    return "<h1>这是html响应</h1>"

#响应文件类型
@app.get("/file")
async def get_file():
    path="6.jpg"
    return FileResponse(path)

#自定义响应格式,使用response_model
class NewBook(BaseModel):
    id:int
    name:str
    price:int
@app.get("/custom_type/{id}",response_model=NewBook)
async def get_newbook(id:int):
    return {
        "id":id,
        "name":"hello world",
        "price":15
    }

#异常处理
@app.get("/new/{id}")
async def get_news(id:int):
    id_list=[1,2,3,4,5,6]
    if id not in id_list:
        raise HTTPException(status_code=404,detail="查找的id不存在")
    return {"id":id}

#中间件，从底到顶的顺序
@app.middleware("http")
async def middleware(request,call_next):
    print('中间件1开始处理 --- start')
    response = await call_next(request)
    print('中间件1处理完成 --- end')
    return response
@app.middleware("http")
async def middleware2(request,call_next):
    print('中间件2开始处理 --- start')
    response = await call_next(request)
    print('中间件2处理完成 --- end')
    return response

#依赖注入，创建依赖项，导入depends，声明依赖项
async def common_parameters(
    skip:int=Query(0,ge=0),
    limit:int=Query(10,le=60)
):
    return{"skip":skip,"limit":limit}
@app.get("/yilai")
async def get_yilai(commons=Depends(common_parameters)):
    return commons

#sqlalchemy