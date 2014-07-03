using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Data;

using OPDA = Oracle.DataAccess.Client;

namespace Peterinor.MF
{
    class DataBaseInfo
    {
        public static string connector = "Data Source = YKTESTDB;User Id = xhfoc;Password = xhfoc;";
    }

    /// <summary>
    /// Access Oracle Database using OPDA.NET(Throught DataSet)
    /// </summary>
    class WithOPDASet
    {
        OPDA.OracleConnection conn;
        public WithOPDASet()
        {
            conn = new OPDA.OracleConnection(DataBaseInfo.connector);
            conn.Open();
        }
        ~WithOPDASet()
        {
            conn.Close();
        }

        public DataTable GetTables()
        {
            DataTable tables = new DataTable();
            OPDA.OracleDataAdapter adapt = new OPDA.OracleDataAdapter("select table_name from user_tables", conn);
            adapt.Fill(tables);
            return tables;
        }

        public DataSet Source(string table)
        {
            OPDA.OracleDataAdapter adapt = new OPDA.OracleDataAdapter("select * from "+ table, conn);
            DataSet usrSet = new DataSet();
            adapt.Fill(usrSet, "Usr_Info");

            return usrSet;
        }

    }
}
