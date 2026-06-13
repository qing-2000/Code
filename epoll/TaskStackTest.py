import socket
import threading
import time

HOST = "127.0.0.1"
PORT = 8888

success_count = 0
fail_count = 0

lock = threading.Lock()


# ======================================
# 长度协议发送
# ======================================
def send_msg(sock, msg):

    data = msg.encode()

    length = len(data).to_bytes(4, 'big')

    sock.sendall(length)
    sock.sendall(data)


# ======================================
# 长度协议接收
# ======================================
def recv_msg(sock):

    length_data = sock.recv(4)

    if not length_data:
        return None

    length = int.from_bytes(length_data, 'big')

    data = b''

    while len(data) < length:

        chunk = sock.recv(length - len(data))

        if not chunk:
            return None

        data += chunk

    return data.decode()


# ======================================
# 每个客户端线程
# ======================================
def worker(index):

    global success_count
    global fail_count

    try:

        s = socket.socket()

        s.connect((HOST, PORT))

        with lock:
            success_count += 1

        while True:

            send_msg(s, f"hello-{index}")

            recv_msg(s)

            time.sleep(1)

    except Exception:

        with lock:
            fail_count += 1
# ======================================
# 创建大量连接
# ======================================
for i in range(5000):

    t = threading.Thread(target=worker,
                         args=(i,),
                         daemon=True)

    t.start()

    time.sleep(0.002)


# ======================================
# 实时打印并发统计
# ======================================
while True:

    print(
        f"success={success_count}, fail={fail_count}"
    )

    time.sleep(2)