using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WinFormAppTest
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void btn_Click(object sender, EventArgs e)
        {
            this.lbl.Text = "Hello this is a winform application";
            this.sbl.Text = "Press Me";
        }

        private void btn1_Click(object sender, EventArgs e)
        {
            ((Button)sender).Text = "Clicked";
            this.sbl.Text = "Clicked";
        }

        private void Form_Click(object sender, EventArgs e)
        {
            ((Form)sender).BackColor = Color.Gold;
            this.sbl.Text = "Form Click";
        }

        private void btn_Exit_Click(object sender, EventArgs e)
        {
            this.sbl.Text = "Exiting";
            Application.Exit();
        }

        private void llbl_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            string tag = ((LinkLabel)(sender)).Tag as string;
            this.sbl.Text = "Go to " + tag;
            System.Diagnostics.Process.Start(tag);
        }
    }
}
