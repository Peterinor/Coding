using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using System.IO;
namespace FileSystemTestGUI
{
    public partial class FileSystemForm : Form
    {
        public FileSystemForm()
        {
            InitializeComponent();
        }

        private void btn_Click(object sender, EventArgs e)
        {
            this.openFile.ShowDialog();
            string filename = this.openFile.FileName;
            FileStream file = new FileStream(filename, FileMode.Open, FileAccess.Read);

            this.path.Text = filename;

            StreamReader td = new StreamReader(file);

            string content = td.ReadToEnd();

            this.content.Text = content;
        }

        private void Loaded(object sender, EventArgs e)
        {
            this.content.Font = new Font("Courier New", 13);
        }

        private void btn2_Click(object sender, EventArgs e)
        {
            this.fontDialog.ShowDialog();
            this.content.Font = new Font(this.fontDialog.Font.Name, this.fontDialog.Font.Size);
        }
    }
}
