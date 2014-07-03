using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using MySql.Data;
using MySql.Data.MySqlClient;

namespace Peterinor.MF
{
    class MySQLDBTest
    {
        static void Main(string[] args)
        {
            string connector = "server=192.168.1.7;uid=tangyu;pwd=tangyu;database=dbtest;";
            MySql.Data.MySqlClient.MySqlConnection conn;

            try
            {
                conn = new MySqlConnection(connector);
                Console.WriteLine("Trying to Connecting to Mysql...");

                conn.Open();

                string sqlsmt = "select * from base_info";
                MySqlCommand cmd = new MySqlCommand(sqlsmt, conn);

                MySqlDataReader res = cmd.ExecuteReader();
                while (res.Read())
                {
                    Console.WriteLine(res["name"]);
                }

                conn.Close();
            }
            catch (MySqlException ex)
            {
                Console.WriteLine(ex.Message);
            }

        }
    }
}
