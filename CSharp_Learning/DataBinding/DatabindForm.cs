using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DataBinding
{
    public partial class DatabindForm : Form
    {
        public DatabindForm()
        {
            InitializeComponent();
        }

        private void DatabindForm_Load(object sender, EventArgs e)
        {
            // TODO: 这行代码将数据加载到表“dataSet_Xhfoc.AAA_USR”中。您可以根据需要移动或删除它。
            this.aAA_USRTableAdapter.Fill(this.dataSet_Xhfoc.AAA_USR);
            // TODO: 这行代码将数据加载到表“dataSet_Xhfoc.USER_INFO”中。您可以根据需要移动或删除它。
            this.uSER_INFOTableAdapter.Fill(this.dataSet_Xhfoc.USER_INFO);

        }

        private void findLUToolStripButton_Click(object sender, EventArgs e)
        {
            try
            {
                this.uSER_INFOTableAdapter.FindLU(this.dataSet_Xhfoc.USER_INFO);
            }
            catch (System.Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }

        }

        private void bindingNavigatorMovePreviousItem_Click(object sender, EventArgs e)
        {

        }
    }
}
