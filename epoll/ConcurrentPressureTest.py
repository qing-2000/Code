#并发测试
import socket
import threading

HOST = "127.0.0.1"
PORT = 8888

def worker():

    try:
        s = socket.socket()

        s.connect((HOST, PORT))

        while True:

            s.send(b"hello")

            data = s.recv(1024)

    except:
        pass


threads = []

for _ in range(5000):

    t = threading.Thread(target=worker)

    t.start()

    threads.append(t)

for t in threads:
    t.join()