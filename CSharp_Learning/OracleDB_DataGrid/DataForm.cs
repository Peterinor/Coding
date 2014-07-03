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
        WithOPDASet data = new WithOPDASet();
        public DataForm()
        {
            InitializeComponent();
        }

        private void Loaded(object sender, EventArgs e)
        {
            try
            {
                DataTable dt = data.GetTables();
                foreach (DataRow row in dt.Rows)
                {
                    this.tables.Items.Add(row["table_name"]);
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
    }
}
