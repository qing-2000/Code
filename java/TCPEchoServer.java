//TCPEchoServer
//package netWork;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class TCPEchoServer {
    ServerSocket serverSocket = null;

    public TCPEchoServer(int port) throws IOException {
        serverSocket = new ServerSocket(port);
    }

    public void start() throws IOException {
        System.out.println("服务器已启动!");
        //使用线程池来管理线程
        ExecutorService pool = Executors.newCachedThreadPool();
        //接受客户端链接
        while (true){
            Socket clientSocket = serverSocket.accept();
            pool.submit(new Runnable() {
                @Override
                public void run() {
                    try {
                        processConnection(clientSocket);
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                }
            });
        }
    }

    public void processConnection(Socket clientSocket) throws IOException {
        System.out.printf("[%s:%d]已上线!\n",clientSocket.getInetAddress(),clientSocket.getPort());
        //获取socket中的输入流和输出流
        try(InputStream inputStream = clientSocket.getInputStream();
            OutputStream outputStream = clientSocket.getOutputStream()){
            //扫描客户端请求
            while (true) {
                //用Scanner包装inputStream输入流 方便获取请求
                Scanner scanner = new Scanner(inputStream);
                if(!scanner.hasNext()){
                    //用户不再输入时 跳出循环 当用户断开后也为不再输入
                    System.out.printf("[%s:%d]已下线!\n",clientSocket.getInetAddress(),clientSocket.getPort());
                    break;
                }
                String request = scanner.next();
                //计算响应
                String response = process(request);
                //直接使用outputStream的write方法无法返回换行符"\n",导致客户端处理较为困难
                //选择使用PrintWriter包装outputStream,使用PrintWriter的println方法
                PrintWriter writer = new PrintWriter(outputStream);
                writer.println(response);
                //PrintWriter中存在缓冲区,需要"攒够一波"数据之后才会真正的发送数据
                //使用flush方法,冲刷缓冲器,让缓冲区的内容直接发送出去
                writer.flush();

                //打印服务器日志
                System.out.printf("[%s:%d] req: %s,resp : %s\n",clientSocket.getInetAddress(),
                        clientSocket.getPort(),request,response);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }finally {
            //执行完毕这一次的链接后 关闭链接
            clientSocket.close();
        }
    }

    public String process(String request) {
        return "响应:"+request;
    }

    public static void main(String[] args) throws IOException {
        TCPEchoServer server = new TCPEchoServer(8848);
        server.start();
    }
}
