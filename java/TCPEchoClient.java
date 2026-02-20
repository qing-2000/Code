//TCPEchoClient
//package netWork;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class TCPEchoClient {
    private Socket socket = null;

    public TCPEchoClient(String ip,int port) throws IOException {
        //new操作完成后 开始建立链接 等待服务端accept
        socket = new Socket(ip, port);
    }

    public void start(){
        System.out.println("客户端已启动");
        //接收用户输入的请求
        Scanner input = new Scanner(System.in);
        try(InputStream inputStream = socket.getInputStream();
            OutputStream outputStream = socket.getOutputStream();){
            //不断扫描
            while(true){
                System.out.print("->");
                if(!input.hasNext()){
                    break;
                }
                //获取请求
                String request = input.next();
                PrintWriter writer = new PrintWriter(outputStream);
                writer.println(request);
                writer.flush();
                //接收服务端响应
                Scanner netWork = new Scanner(inputStream);
                String response = netWork.next();
                //向用户展示响应
                System.out.println(response);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) throws IOException {
        TCPEchoClient client = new TCPEchoClient("127.0.0.1",8848);
        client.start();
    }
}
