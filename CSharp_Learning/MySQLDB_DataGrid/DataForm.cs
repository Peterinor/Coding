using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Peterinor.MF
{
    public partial class DataForm : Form
    {
        WithDAPSet data = new WithDAPSet();
        public DataForm()
        {
            InitializeComponent();
        }

        private void Loaded(object sender, EventArgs e)
        {
            try
            {
                DataBaseInfo.connector = "server="+ this.server.Text + ";uid=" + this.name.Text + ";pwd=" + this.password.Text + ";";

                data.Connect();

                DataTable dt = data.GetDatabases();
                foreach (DataRow row in dt.Rows)
                {
                    this.databases.Items.Add(row[0]);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void Database_Changed(object sender, EventArgs e)
        {
            if (this.databases.SelectedIndex == -1)
            {
                MessageBox.Show("请选择数据库");
                return;
            }

            try
            {
                string database = this.databases.SelectedItem.ToString();

                DataTable dt = data.GetTables(database);
                this.tables.Items.Clear();
                foreach (DataRow row in dt.Rows)
                {
                    this.tables.Items.Add(row[0]);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void read_Click(object sender, EventArgs e)
        {
            if (this.tables.SelectedIndex == -1)
            {
                MessageBox.Show("请选择数据表");
                return;
            }

            try
            {
                string table = this.tables.SelectedItem.ToString();
                DataTable tbl = data.Source(table).Tables["Usr_Info"];
                this.dataGrid.DataSource = tbl;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void exit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
