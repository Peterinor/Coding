import java.net.*;

import java.io.*;

public class TCPServer {

    public static void main(String args[]) throws Exception{

        System.out.println("TCP Server Starting....");

        ServerSocket ss = new ServerSocket(8000);

        while(true){
            Socket s = ss.accept();
            // System.out.println("A cleint connect in..." +  s.getRemoteSocketAddress());
            
            DataInputStream dis = new DataInputStream(s.getInputStream());

            System.out.println(dis.readUTF());

            dis.close();
            s.close();
        }

    }
}