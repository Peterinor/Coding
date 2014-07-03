using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Data;
using MSOracle = System.Data.OracleClient;

using OPDA = Oracle.DataAccess.Client;

namespace Peterinor.MF
{
    class DataBaseInfo
    {
        public static string connector = "Data Source = YKTESTDB;User Id=xhfoc;Password=xhfoc;";
    }
    class OracleDBTest
    {
        static void Main(string[] args)
        {
            try
            {
            //    WithMSClient.ShowData();

                WithOPDA.ShowData();

            //    WithOPDASet.ShowData();

            //    WithOPDABuilder.ShowData();

            //    InsertNewData.AddRecord();

                ExcuntProcedure.Excunt();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            
        }
    }

    /// <summary>
    /// Access Oracle Database using MSClient(Throught DataReader)
    /// </summary>
    class WithMSClient
    {
        public static void ShowData()
        {
            MSOracle.OracleConnection conn = new MSOracle.OracleConnection(DataBaseInfo.connector);

            Console.WriteLine("\nConnecting Oracle Database using MSOracleClient(Throught DataReader)...");
            conn.Open();

            MSOracle.OracleCommand cmd = conn.CreateCommand(); //
            //OracleCommand cmd = new OracleCommand("select * from AAA_DATA");
            cmd.CommandText = "select * from AAA_USR";

            MSOracle.OracleDataReader rd = cmd.ExecuteReader();

            //Console.WriteLine("FLIGHT_NO\tFLIGHT_ORIG\tFLIGHT_DEST\tFLIGHT_DATE");
            Console.WriteLine("USER_ID\t\tUSER_NO\tUSER_PSWD\tUS");

            while (rd.Read())
            {
                //Console.WriteLine("{0}\t{1}\t{2}\t{3}", rd["FLIGHT_NO"], rd["FLIGHT_ORIG"], rd["FLIGHT_DEST"], rd["FLIGHT_DATE"]);
                Console.WriteLine("{0}\t{1}\t{2}\t\t{3}", rd["USER_ID"], rd["USER_NAME"], rd["USER_PSWD"], rd["US"]);
            }
            
            conn.Close();
        }
    }

    /// <summary>
    /// Access Oracle Database using OPDA.NET(Throught DataReader)
    /// </summary>
    class WithOPDA
    {
        public static void ShowData()
        {
            OPDA.OracleConnection conn = new OPDA.OracleConnection(DataBaseInfo.connector);

            Console.WriteLine("\nConnectiong Oracle Database using OPDA.NET(Throught DataReader)...");
            conn.Open();

            //OPDA.OracleCommand cmd = conn.CreateCommand();            
            //cmd.CommandText = "select * from AAA_USR";
            OPDA.OracleCommand cmd = new OPDA.OracleCommand("select * from AAA_USR", conn);

            OPDA.OracleDataReader rd = cmd.ExecuteReader();

            Console.WriteLine("USER_ID\t\tUSER_NO\tUSER_PSWD\tUS");

            while (rd.Read())
            {
                //Console.WriteLine("{0}\t{1}\t{2}\t{3}", rd["FLIGHT_NO"], rd["FLIGHT_ORIG"], rd["FLIGHT_DEST"], rd["FLIGHT_DATE"]);
                Console.WriteLine("{0}\t{1}\t{2}\t\t{3}", rd["USER_ID"], rd["USER_NAME"], rd["USER_PSWD"], rd["US"]);
            }

            conn.Close();
        }
    }

    /// <summary>
    /// Access Oracle Database using OPDA.NET(Throught DataSet)
    /// </summary>
    class WithOPDASet
    {
        public static void ShowData()
        {
            OPDA.OracleConnection conn = new OPDA.OracleConnection(DataBaseInfo.connector);

            Console.WriteLine("\nConnectiong Oracle Database using OPDA.NET(Throught DataSet)...");
            conn.Open();

            OPDA.OracleDataAdapter adapt = new OPDA.OracleDataAdapter("select * from AAA_USR order by USER_ID", conn);
            DataSet usrSet = new DataSet();
            adapt.Fill(usrSet, "Usr_Info");

            Console.WriteLine("USER_ID\t\tUSER_NO\tUSER_PSWD\tUS");
            foreach (DataRow row in usrSet.Tables["Usr_Info"].Rows)
            {
                Console.WriteLine("{0}\t{1}\t{2}\t\t{3}", row["USER_ID"], row["USER_NAME"], row["USER_PSWD"], row["US"]);
            }

            //Update a Record
            usrSet.Tables["Usr_Info"].Rows[1]["USER_NAME"] = "A_New_Name";

            OPDA.OracleCommandBuilder cmdb = new OPDA.OracleCommandBuilder(adapt);
           
            adapt.Update(usrSet,"Usr_Info");
            //adapt.Update(usrSet.Tables["Usr_Info"]);
            
            conn.Close();
        }

    }

    class WithOPDABuilder
    {
        public static void ShowData()
        {
            OPDA.OracleConnectionStringBuilder connector = new OPDA.OracleConnectionStringBuilder();
            connector.DataSource = "YKTESTDB";
            connector.UserID = "xhfoc";
            connector.Password = "xhfoc";

            OPDA.OracleConnection conn = new OPDA.OracleConnection();
            conn.ConnectionString = connector.ConnectionString;

            Console.WriteLine("Connecting to Server Database(With ConnectionStringBuilder...");
            conn.Open();

            OPDA.OracleDataAdapter adapt = new OPDA.OracleDataAdapter("select * from AAA_USR", conn);
            DataSet dat = new DataSet();
            adapt.Fill(dat,"Usr_Info");

            //dat.WriteXml("Console.Out.xml");

            Console.WriteLine("USER_ID\t\tUSER_NO\tUSER_PSWD\tUS");
            foreach (DataRow row in dat.Tables["Usr_Info"].Rows)
            {
                Console.WriteLine("{0}\t{1}\t{2}\t{3}", row["USER_ID"], row["USER_NAME"], row["USER_PSWD"], row["US"]);
            }
            conn.Close();
        }
    }

    class InsertNewData
    {
        public static void AddRecord()
        {
            OPDA.OracleConnection conn = new OPDA.OracleConnection(DataBaseInfo.connector);

            Console.WriteLine("Here we will insert a new record to the database table TestTable...");
            conn.Open();

            string name, id;
            Console.WriteLine("Input Your name...");
            name = Console.ReadLine();
            Console.WriteLine("Input Your ID...");
            id = Console.ReadLine();

            string table = "TestTable";
            string cmdText = "insert into " + table + " values('" + name + "','" + id + "')";
            //Console.WriteLine(cmdText);

            OPDA.OracleCommand cmd = new OPDA.OracleCommand(cmdText, conn);

            cmd.ExecuteNonQuery();

            Console.WriteLine("执行" + cmdText + "成功!");

            conn.Close();
        }
    }

    class ExcuntProcedure
    {
        public static void Excunt()
        {
            OPDA.OracleConnection conn = new OPDA.OracleConnection(DataBaseInfo.connector);

            conn.Open();
            OPDA.OracleCommand cmd = conn.CreateCommand();
            cmd.CommandType = CommandType.StoredProcedure;
            cmd.CommandText = "TestProcedure";
            cmd.ExecuteNonQuery();
            conn.Close();
            Console.WriteLine("OK");
        }
    }


}
