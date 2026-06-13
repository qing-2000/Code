#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
TCP 回显服务器并发压力测试脚本
用法: python stress_test.py --host 127.0.0.1 --port 8080 --clients 100 --messages 10 --size 64
"""

import socket
import threading
import time
import argparse
from collections import defaultdict

# 全局统计
lock = threading.Lock()
results = {
    "total_connections": 0,
    "successful_connections": 0,
    "failed_connections": 0,
    "total_messages": 0,
    "successful_messages": 0,
    "failed_messages": 0,
    "response_times": [],
}


def client_task(host, port, client_id, num_messages, msg_size):
    """单个客户端任务：连接 -> 发送多条消息 -> 验证回显 -> 关闭"""
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.settimeout(5)  # 连接超时5秒
        sock.connect((host, port))
        sock.settimeout(2)  # 收发超时2秒

        with lock:
            results["successful_connections"] += 1

        # 生成测试消息
        test_msg = f"CLIENT{client_id:05d}:".ljust(msg_size, 'X')[:msg_size]
        test_msg = test_msg.encode()

        for i in range(num_messages):
            try:
                start = time.time()
                sock.sendall(test_msg)
                # 接收回显，期望与发送完全一致
                reply = b""
                while len(reply) < len(test_msg):
                    chunk = sock.recv(len(test_msg) - len(reply))
                    if not chunk:
                        raise ConnectionError("连接关闭")
                    reply += chunk
                end = time.time()

                if reply == test_msg:
                    with lock:
                        results["successful_messages"] += 1
                        results["response_times"].append((end - start) * 1000)  # 毫秒
                else:
                    with lock:
                        results["failed_messages"] += 1

            except Exception as e:
                with lock:
                    results["failed_messages"] += 1
                # 单条消息失败不退出，继续下一条（可根据需求改为 break）

        sock.close()
    except Exception as e:
        with lock:
            results["failed_connections"] += 1
    finally:
        with lock:
            results["total_connections"] += 1


def main():
    parser = argparse.ArgumentParser(description="TCP 回显服务器并发压力测试")
    parser.add_argument("--host", type=str, default="127.0.0.1", help="服务器IP地址")
    parser.add_argument("--port", type=int, default=8080, help="服务器端口")
    parser.add_argument("--clients", type=int, default=100, help="并发客户端数量")
    parser.add_argument("--messages", type=int, default=10, help="每个客户端发送的消息数")
    parser.add_argument("--size", type=int, default=64, help="每条消息的字节数")
    args = parser.parse_args()

    print(f"压力测试参数：")
    print(f"  服务器地址: {args.host}:{args.port}")
    print(f"  并发客户端: {args.clients}")
    print(f"  每客户端消息: {args.messages}")
    print(f"  消息大小: {args.size} 字节")
    print(f"  总请求数: {args.clients * args.messages}")
    print("-" * 50)

    start_time = time.time()

    # 创建并启动所有客户端线程
    threads = []
    for i in range(args.clients):
        t = threading.Thread(
            target=client_task,
            args=(args.host, args.port, i, args.messages, args.size)
        )
        t.daemon = True
        threads.append(t)
        t.start()

    # 等待所有线程完成
    for t in threads:
        t.join()

    total_time = time.time() - start_time

    # 输出统计结果
    with lock:
        print("\n========== 测试结果 ==========")
        print(f"总耗时: {total_time:.2f} 秒")
        print(f"连接成功: {results['successful_connections']}/{results['total_connections']}")
        print(f"连接失败: {results['failed_connections']}")
        print(f"消息成功: {results['successful_messages']}/{args.clients * args.messages}")
        print(f"消息失败: {results['failed_messages']}")

        if results["response_times"]:
            times = results["response_times"]
            avg_ms = sum(times) / len(times)
            max_ms = max(times)
            min_ms = min(times)
            print(f"响应时间(ms) - 平均: {avg_ms:.2f}, 最小: {min_ms:.2f}, 最大: {max_ms:.2f}")
            # 可选：百分位数
            sorted_times = sorted(times)
            p50 = sorted_times[len(sorted_times)//2]
            p95 = sorted_times[int(len(sorted_times)*0.95)]
            p99 = sorted_times[int(len(sorted_times)*0.99)]
            print(f"百分位数 - P50: {p50:.2f}, P95: {p95:.2f}, P99: {p99:.2f}")

        qps = results['successful_messages'] / total_time if total_time > 0 else 0
        print(f"QPS (成功消息/秒): {qps:.2f}")


if __name__ == "__main__":
    main()