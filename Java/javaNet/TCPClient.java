import java.net.*;

public class TCPClient {

    public static void main(String[] args) throws Exception{

        Socket s = new Socket("127.0.0.1", 8000);

        OutputStream os = s.getOutputStream();

        DataOutputStream dos = new DataOutputStream(os);
        dos.writeUTF("Hello Server");
        dos.flush();
        Thread.sleep(3000);
        dos.close();
        os.close();

        // s.
    }
}