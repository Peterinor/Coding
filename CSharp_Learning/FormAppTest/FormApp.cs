using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using System.Text.RegularExpressions;

using System.IO;

namespace FormAppTest
{
    public partial class FormApp : Form
    {
        public FormApp()
        {
            InitializeComponent();
        }

        private void btn_photo_Click(object sender, EventArgs e)
        {
            this.uploadPhoto.ShowDialog();
            this.txt_path.Text = this.uploadPhoto.FileName;
        }

        private bool CheckEmpty(TextBox tb)
        {
            if (tb.Text.Equals(""))
            {
                tb.BackColor = Color.Red;
                tb.Focus();
                return true;
            }
            tb.BackColor = System.Drawing.SystemColors.Window;
            return false;
        }

        private bool CheckPhoneNumber(TextBox tb)
        {
            Regex reg = new Regex(@"^[1]\d{10}$");
            Match mc = reg.Match(tb.Text);
            if (mc.Value.Equals(""))
            {
                tb.BackColor = Color.Red;
                tb.Focus();
                return true;
            }
            else
            {
                tb.BackColor = System.Drawing.SystemColors.Window;
                return false;
            }
        }

        private void btn_prev_Click(object sender, EventArgs e)
        {
            if (CheckEmpty(this.txt_name)) return;
            if (CheckEmpty(this.txt_address)) return;
            if (CheckEmpty(this.txt_in)) return;
            if (CheckPhoneNumber(this.txt_phone)) return;
            this.lbl_name_p.Text = this.txt_name.Text;
            this.lbl_sex_p.Text = (string)(this.rbSex_m.Checked ? "男" : "女");
            this.lbl_address_p.Text = this.txt_address.Text;
            this.lbl_in_p.Text = this.txt_in.Text;
            this.lbl_phone_p.Text = this.txt_phone.Text;

            if (this.txt_path.Text.Equals(""))
            {
                MessageBox.Show("请选择照片");
                this.uploadPhoto.ShowDialog();
                this.txt_path.Text = this.uploadPhoto.FileName;
            }
            else
            {
                try
                {
                    FileStream file = new FileStream(this.txt_path.Text, FileMode.Open, FileAccess.Read);
                    this.photo.Image = Image.FromFile(this.txt_path.Text);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }

        }

        private void Empty_Validating(object sender, CancelEventArgs e)
        {
            TextBox tb = (TextBox)sender;
            if (tb.Text.Equals("")) //Empty
            {
                tb.BackColor = Color.Red;
                tb.Focus();
                tb.Tag = false;
            }
            else
            {
                tb.BackColor = System.Drawing.SystemColors.Window;
                tb.Tag = true;
            }
            isOK();
        }

        private void Number_Validating(object sender, CancelEventArgs e)
        {
            TextBox tb = (TextBox)sender;
            string pattern = @"^[1]\d{10}$";
            pattern = @"\b1\d{10}\b";
            Regex reg = new Regex(pattern);
            Match mc = reg.Match(tb.Text);
            if (mc.Value.Equals(""))
            {
                tb.BackColor = Color.Red;
                tb.Focus();
                tb.Tag = false;
            }
            else
            {
                tb.BackColor = System.Drawing.SystemColors.Window;
                tb.Tag = true;
            }
            isOK();
        }

        private void isOK()
        {
            this.btn_prev.Enabled = (bool)this.txt_address.Tag && (bool)this.txt_name.Tag && (bool)this.txt_phone.Tag;
            this.btn_sub.Enabled = this.btn_prev.Enabled;
            //MessageBox.Show(this.btn_sub.Enabled.ToString());
        }

        private void Loaded(object sender, EventArgs e)
        {
            this.btn_prev.Enabled = false;
            this.btn_sub.Enabled = false;

            this.txt_address.Tag = false;
            this.txt_name.Tag = false;
            this.txt_in.Tag = false;
            this.txt_phone.Tag = false;
        }
    }
}