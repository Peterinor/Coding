using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Data;

using DAP = MySql.Data.MySqlClient;// MySql.DataAccess.Client;

namespace Peterinor.MF
{
    class DataBaseInfo
    {
        public static string connector ;//= "server=192.168.1.7;uid=tangyu;pwd=tangyu;";
    }

    /// <summary>
    /// Access MySql Database using DAP.NET(Throught DataSet)
    /// </summary>
    class WithDAPSet
    {
        DAP.MySqlConnection conn;
        public void Connect()
        {
            conn = new DAP.MySqlConnection(DataBaseInfo.connector);
            conn.Open();
        }
        ~WithDAPSet()
        {
            conn.Close();
        }

        public DataTable GetDatabases()
        {
            DataTable databases = new DataTable();
            DAP.MySqlDataAdapter adapt = new DAP.MySqlDataAdapter("show databases", conn);
            adapt.Fill(databases);
            return databases;
        } 

        public DataTable GetTables(string database)
        {
            DataTable tables = new DataTable();
            
            DAP.MySqlDataAdapter adapt = new DAP.MySqlDataAdapter("use " + database +";" + "show tables", conn);
            adapt.Fill(tables);
            return tables;
        }

        public DataSet Source(string table)
        {
            DAP.MySqlDataAdapter adapt = new DAP.MySqlDataAdapter("select * from " + table, conn);
            DataSet usrSet = new DataSet();
            adapt.Fill(usrSet, "Usr_Info");

            return usrSet;
        }

    }
}
