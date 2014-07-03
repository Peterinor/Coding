namespace FormAppTest
{
    partial class FormApp
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.sex = new System.Windows.Forms.GroupBox();
            this.rbSex_f = new System.Windows.Forms.RadioButton();
            this.rbSex_m = new System.Windows.Forms.RadioButton();
            this.title = new System.Windows.Forms.Label();
            this.txt_in = new System.Windows.Forms.TextBox();
            this.txt_address = new System.Windows.Forms.TextBox();
            this.lbl_name = new System.Windows.Forms.Label();
            this.lbl_phone = new System.Windows.Forms.Label();
            this.lbl_address = new System.Windows.Forms.Label();
            this.lbl_in = new System.Windows.Forms.Label();
            this.txt_phone = new System.Windows.Forms.TextBox();
            this.txt_name = new System.Windows.Forms.TextBox();
            this.info = new System.Windows.Forms.GroupBox();
            this.btn_sub = new System.Windows.Forms.Button();
            this.btn_prev = new System.Windows.Forms.Button();
            this.btn_photo = new System.Windows.Forms.Button();
            this.txt_path = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.lbl_in_p = new System.Windows.Forms.Label();
            this.lbl_address_p = new System.Windows.Forms.Label();
            this.lbl_phone_p = new System.Windows.Forms.Label();
            this.lbl_sex_p = new System.Windows.Forms.Label();
            this.lbl_name_p = new System.Windows.Forms.Label();
            this.photo = new System.Windows.Forms.PictureBox();
            this.uploadPhoto = new System.Windows.Forms.OpenFileDialog();
            this.sex.SuspendLayout();
            this.info.SuspendLayout();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.photo)).BeginInit();
            this.SuspendLayout();
            // 
            // sex
            // 
            this.sex.Controls.Add(this.rbSex_f);
            this.sex.Controls.Add(this.rbSex_m);
            this.sex.Location = new System.Drawing.Point(9, 83);
            this.sex.Name = "sex";
            this.sex.Size = new System.Drawing.Size(205, 106);
            this.sex.TabIndex = 0;
            this.sex.TabStop = false;
            this.sex.Text = "性别";
            // 
            // rbSex_f
            // 
            this.rbSex_f.AutoSize = true;
            this.rbSex_f.Location = new System.Drawing.Point(24, 63);
            this.rbSex_f.Name = "rbSex_f";
            this.rbSex_f.Size = new System.Drawing.Size(44, 25);
            this.rbSex_f.TabIndex = 1;
            this.rbSex_f.TabStop = true;
            this.rbSex_f.Text = "女";
            this.rbSex_f.UseVisualStyleBackColor = true;
            // 
            // rbSex_m
            // 
            this.rbSex_m.AutoSize = true;
            this.rbSex_m.Location = new System.Drawing.Point(24, 32);
            this.rbSex_m.Name = "rbSex_m";
            this.rbSex_m.Size = new System.Drawing.Size(44, 25);
            this.rbSex_m.TabIndex = 0;
            this.rbSex_m.TabStop = true;
            this.rbSex_m.Text = "男";
            this.rbSex_m.UseVisualStyleBackColor = true;
            // 
            // title
            // 
            this.title.AutoSize = true;
            this.title.Font = new System.Drawing.Font("宋体", 16F);
            this.title.Location = new System.Drawing.Point(338, 20);
            this.title.Name = "title";
            this.title.Size = new System.Drawing.Size(142, 22);
            this.title.TabIndex = 1;
            this.title.Text = "个人信息统计";
            // 
            // txt_in
            // 
            this.txt_in.Location = new System.Drawing.Point(316, 146);
            this.txt_in.Multiline = true;
            this.txt_in.Name = "txt_in";
            this.txt_in.Size = new System.Drawing.Size(179, 106);
            this.txt_in.TabIndex = 4;
            // 
            // txt_address
            // 
            this.txt_address.Location = new System.Drawing.Point(316, 92);
            this.txt_address.Name = "txt_address";
            this.txt_address.Size = new System.Drawing.Size(179, 29);
            this.txt_address.TabIndex = 3;
            this.txt_address.Validating += new System.ComponentModel.CancelEventHandler(this.Empty_Validating);
            // 
            // lbl_name
            // 
            this.lbl_name.AutoSize = true;
            this.lbl_name.Font = new System.Drawing.Font("微软雅黑", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lbl_name.Location = new System.Drawing.Point(6, 42);
            this.lbl_name.Name = "lbl_name";
            this.lbl_name.Size = new System.Drawing.Size(42, 21);
            this.lbl_name.TabIndex = 4;
            this.lbl_name.Text = "姓名";
            // 
            // lbl_phone
            // 
            this.lbl_phone.AutoSize = true;
            this.lbl_phone.Font = new System.Drawing.Font("微软雅黑", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lbl_phone.Location = new System.Drawing.Point(251, 42);
            this.lbl_phone.Name = "lbl_phone";
            this.lbl_phone.Size = new System.Drawing.Size(42, 21);
            this.lbl_phone.TabIndex = 5;
            this.lbl_phone.Text = "电话";
            // 
            // lbl_address
            // 
            this.lbl_address.AutoSize = true;
            this.lbl_address.Font = new System.Drawing.Font("微软雅黑", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lbl_address.Location = new System.Drawing.Point(251, 97);
            this.lbl_address.Name = "lbl_address";
            this.lbl_address.Size = new System.Drawing.Size(42, 21);
            this.lbl_address.TabIndex = 6;
            this.lbl_address.Text = "住址";
            // 
            // lbl_in
            // 
            this.lbl_in.AutoSize = true;
            this.lbl_in.Font = new System.Drawing.Font("微软雅黑", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lbl_in.Location = new System.Drawing.Point(254, 151);
            this.lbl_in.Name = "lbl_in";
            this.lbl_in.Size = new System.Drawing.Size(42, 21);
            this.lbl_in.TabIndex = 7;
            this.lbl_in.Text = "备注";
            // 
            // txt_phone
            // 
            this.txt_phone.Location = new System.Drawing.Point(316, 37);
            this.txt_phone.Name = "txt_phone";
            this.txt_phone.Size = new System.Drawing.Size(179, 29);
            this.txt_phone.TabIndex = 2;
            this.txt_phone.Validating += new System.ComponentModel.CancelEventHandler(this.Number_Validating);
            // 
            // txt_name
            // 
            this.txt_name.Location = new System.Drawing.Point(71, 37);
            this.txt_name.Name = "txt_name";
            this.txt_name.Size = new System.Drawing.Size(143, 29);
            this.txt_name.TabIndex = 1;
            this.txt_name.Validating += new System.ComponentModel.CancelEventHandler(this.Empty_Validating);
            // 
            // info
            // 
            this.info.Controls.Add(this.btn_sub);
            this.info.Controls.Add(this.btn_prev);
            this.info.Controls.Add(this.btn_photo);
            this.info.Controls.Add(this.txt_path);
            this.info.Controls.Add(this.txt_name);
            this.info.Controls.Add(this.lbl_name);
            this.info.Controls.Add(this.lbl_in);
            this.info.Controls.Add(this.txt_phone);
            this.info.Controls.Add(this.txt_in);
            this.info.Controls.Add(this.sex);
            this.info.Controls.Add(this.lbl_phone);
            this.info.Controls.Add(this.lbl_address);
            this.info.Controls.Add(this.txt_address);
            this.info.Font = new System.Drawing.Font("微软雅黑", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.info.Location = new System.Drawing.Point(26, 59);
            this.info.Name = "info";
            this.info.Size = new System.Drawing.Size(523, 312);
            this.info.TabIndex = 10;
            this.info.TabStop = false;
            this.info.Text = "个人信息统计";
            // 
            // btn_sub
            // 
            this.btn_sub.Location = new System.Drawing.Point(290, 271);
            this.btn_sub.Name = "btn_sub";
            this.btn_sub.Size = new System.Drawing.Size(80, 30);
            this.btn_sub.TabIndex = 13;
            this.btn_sub.Text = "提交";
            this.btn_sub.UseVisualStyleBackColor = true;
            // 
            // btn_prev
            // 
            this.btn_prev.Location = new System.Drawing.Point(128, 271);
            this.btn_prev.Name = "btn_prev";
            this.btn_prev.Size = new System.Drawing.Size(86, 30);
            this.btn_prev.TabIndex = 12;
            this.btn_prev.Text = "预览";
            this.btn_prev.UseVisualStyleBackColor = true;
            this.btn_prev.Click += new System.EventHandler(this.btn_prev_Click);
            // 
            // btn_photo
            // 
            this.btn_photo.Location = new System.Drawing.Point(128, 222);
            this.btn_photo.Name = "btn_photo";
            this.btn_photo.Size = new System.Drawing.Size(86, 31);
            this.btn_photo.TabIndex = 5;
            this.btn_photo.Text = "上传照片";
            this.btn_photo.UseVisualStyleBackColor = true;
            this.btn_photo.Click += new System.EventHandler(this.btn_photo_Click);
            // 
            // txt_path
            // 
            this.txt_path.Location = new System.Drawing.Point(9, 224);
            this.txt_path.Name = "txt_path";
            this.txt_path.Size = new System.Drawing.Size(111, 29);
            this.txt_path.TabIndex = 10;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.lbl_in_p);
            this.groupBox1.Controls.Add(this.lbl_address_p);
            this.groupBox1.Controls.Add(this.lbl_phone_p);
            this.groupBox1.Controls.Add(this.lbl_sex_p);
            this.groupBox1.Controls.Add(this.lbl_name_p);
            this.groupBox1.Controls.Add(this.photo);
            this.groupBox1.Font = new System.Drawing.Font("微软雅黑", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.groupBox1.Location = new System.Drawing.Point(569, 59);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(273, 312);
            this.groupBox1.TabIndex = 11;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "预览";
            // 
            // lbl_in_p
            // 
            this.lbl_in_p.AutoSize = true;
            this.lbl_in_p.Location = new System.Drawing.Point(21, 218);
            this.lbl_in_p.Name = "lbl_in_p";
            this.lbl_in_p.Size = new System.Drawing.Size(66, 21);
            this.lbl_in_p.TabIndex = 4;
            this.lbl_in_p.Text = "________";
            // 
            // lbl_address_p
            // 
            this.lbl_address_p.AutoSize = true;
            this.lbl_address_p.Location = new System.Drawing.Point(21, 174);
            this.lbl_address_p.Name = "lbl_address_p";
            this.lbl_address_p.Size = new System.Drawing.Size(66, 21);
            this.lbl_address_p.TabIndex = 4;
            this.lbl_address_p.Text = "________";
            // 
            // lbl_phone_p
            // 
            this.lbl_phone_p.AutoSize = true;
            this.lbl_phone_p.Location = new System.Drawing.Point(21, 130);
            this.lbl_phone_p.Name = "lbl_phone_p";
            this.lbl_phone_p.Size = new System.Drawing.Size(66, 21);
            this.lbl_phone_p.TabIndex = 3;
            this.lbl_phone_p.Text = "________";
            // 
            // lbl_sex_p
            // 
            this.lbl_sex_p.AutoSize = true;
            this.lbl_sex_p.Location = new System.Drawing.Point(21, 86);
            this.lbl_sex_p.Name = "lbl_sex_p";
            this.lbl_sex_p.Size = new System.Drawing.Size(66, 21);
            this.lbl_sex_p.TabIndex = 2;
            this.lbl_sex_p.Text = "________";
            // 
            // lbl_name_p
            // 
            this.lbl_name_p.AutoSize = true;
            this.lbl_name_p.Location = new System.Drawing.Point(21, 42);
            this.lbl_name_p.Name = "lbl_name_p";
            this.lbl_name_p.Size = new System.Drawing.Size(66, 21);
            this.lbl_name_p.TabIndex = 1;
            this.lbl_name_p.Text = "________";
            // 
            // photo
            // 
            this.photo.Location = new System.Drawing.Point(117, 29);
            this.photo.Name = "photo";
            this.photo.Size = new System.Drawing.Size(145, 147);
            this.photo.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.photo.TabIndex = 0;
            this.photo.TabStop = false;
            // 
            // uploadPhoto
            // 
            this.uploadPhoto.DefaultExt = "png,jpg";
            // 
            // FormApp
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(865, 395);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.info);
            this.Controls.Add(this.title);
            this.Name = "FormApp";
            this.Text = "FromElements";
            this.Load += new System.EventHandler(this.Loaded);
            this.sex.ResumeLayout(false);
            this.sex.PerformLayout();
            this.info.ResumeLayout(false);
            this.info.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.photo)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox sex;
        private System.Windows.Forms.RadioButton rbSex_f;
        private System.Windows.Forms.RadioButton rbSex_m;
        private System.Windows.Forms.Label title;
        private System.Windows.Forms.TextBox txt_in;
        private System.Windows.Forms.TextBox txt_address;
        private System.Windows.Forms.Label lbl_name;
        private System.Windows.Forms.Label lbl_phone;
        private System.Windows.Forms.Label lbl_address;
        private System.Windows.Forms.Label lbl_in;
        private System.Windows.Forms.TextBox txt_phone;
        private System.Windows.Forms.TextBox txt_name;
        private System.Windows.Forms.GroupBox info;
        private System.Windows.Forms.Button btn_photo;
        private System.Windows.Forms.TextBox txt_path;
        private System.Windows.Forms.Button btn_sub;
        private System.Windows.Forms.Button btn_prev;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label lbl_in_p;
        private System.Windows.Forms.Label lbl_address_p;
        private System.Windows.Forms.Label lbl_phone_p;
        private System.Windows.Forms.Label lbl_sex_p;
        private System.Windows.Forms.Label lbl_name_p;
        private System.Windows.Forms.PictureBox photo;
        private System.Windows.Forms.OpenFileDialog uploadPhoto;
    }
}

