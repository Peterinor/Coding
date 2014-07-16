import java.io.*;
import java.net.*;

class JavaNet
{
	public static void main(String args[])
	{
		System.out.println("Java Net URL test:");
		try{
			URL localHost = new URL("http://www.baidu.com");
			DataInputStream dis = new DataInputStream(localHost.openStream());
			String inputline;
			while((inputline = dis.readLine()) != null){
				System.out.println(inputline);
			}
			dis.close();
		}catch(MalformedURLException me){
			System.out.println("MalformedURLException :"+me);
		}catch(IOException ioe){
			System.out.println("IOException :"+ioe);
		}		

	}
}
