import java.sql.*;
import java.util.*;
//import com.mysql.jdbc.Driver;
//import org.git.mm.mysql.Driver;

public class JavaDataBase
{
	public static void main(String args[])
	{
		System.out.println("Java DataBase Test here:");
		System.out.println("The first glance at JDBC APIs");

		Connection con = null;
		Statement stmt = null;
		ResultSet result =null;
		
		String DB_Driver = "org.gjt.mm.mysql.Driver";	//mysql JDBC Driver class path
		//String DB_Driver = "com.mysql.jdbc.Driver";	//this will also be OK!
		String DB_URL	 = "jdbc:mysql://localhost:3306/JavaTest";
		String DB_User   = "tangyu";
		String DB_Pwd    = "tangyu";
		
		try{	//exceptions here is required!
			Class.forName(DB_Driver);		//Load Driver class Dymatic
			con = DriverManager.getConnection(DB_URL,DB_User,DB_Pwd);
			String sql = "select * from base_info";
			stmt = con.createStatement();
			result = stmt.executeQuery(sql);

		}catch(Exception e){
			System.out.println(e.toString());
		}

		
		try{	//exceptions here is required!
			System.out.println(con);
			while( result.next() ){
				String num = result.getString("number");
				System.out.println("Number = " + num);
			}

			result.close();
			stmt.close();
			con.close();
		}catch(Exception e){
			System.out.println(e.toString());
		}
			
	}
}
