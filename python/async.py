from fastapi import FastAPI
import asyncio

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

# 可选：根路径端点
@app.get("/")
async def root():
    return {"message": "欢迎使用求和计算 API"}