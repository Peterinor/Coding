namespace Peterinor.MF
{
    partial class DataForm
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
            this.update = new System.Windows.Forms.Button();
            this.read = new System.Windows.Forms.Button();
            this.control = new System.Windows.Forms.Panel();
            this.tables = new System.Windows.Forms.ComboBox();
            this.dataGrid = new System.Windows.Forms.DataGridView();
            this.panelData = new System.Windows.Forms.Panel();
            this.databases = new System.Windows.Forms.ComboBox();
            this.lbl3 = new System.Windows.Forms.Label();
            this.lbl2 = new System.Windows.Forms.Label();
            this.lbl1 = new System.Windows.Forms.Label();
            this.server = new System.Windows.Forms.TextBox();
            this.name = new System.Windows.Forms.TextBox();
            this.password = new System.Windows.Forms.TextBox();
            this.lbl4 = new System.Windows.Forms.Label();
            this.lbl5 = new System.Windows.Forms.Label();
            this.exit = new System.Windows.Forms.Button();
            this.control.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGrid)).BeginInit();
            this.panelData.SuspendLayout();
            this.SuspendLayout();
            // 
            // update
            // 
            this.update.Location = new System.Drawing.Point(19, 346);
            this.update.Name = "update";
            this.update.Size = new System.Drawing.Size(121, 40);
            this.update.TabIndex = 2;
            this.update.Text = "更新数据";
            this.update.UseVisualStyleBackColor = true;
            // 
            // read
            // 
            this.read.Location = new System.Drawing.Point(19, 287);
            this.read.Name = "read";
            this.read.Size = new System.Drawing.Size(121, 40);
            this.read.TabIndex = 1;
            this.read.Text = "读取数据";
            this.read.UseVisualStyleBackColor = true;
            this.read.Click += new System.EventHandler(this.read_Click);
            // 
            // control
            // 
            this.control.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.control.Controls.Add(this.exit);
            this.control.Controls.Add(this.lbl5);
            this.control.Controls.Add(this.lbl4);
            this.control.Controls.Add(this.password);
            this.control.Controls.Add(this.name);
            this.control.Controls.Add(this.server);
            this.control.Controls.Add(this.lbl1);
            this.control.Controls.Add(this.lbl2);
            this.control.Controls.Add(this.lbl3);
            this.control.Controls.Add(this.update);
            this.control.Controls.Add(this.read);
            this.control.Controls.Add(this.databases);
            this.control.Controls.Add(this.tables);
            this.control.Location = new System.Drawing.Point(764, 1);
            this.control.Name = "control";
            this.control.Size = new System.Drawing.Size(154, 506);
            this.control.TabIndex = 4;
            // 
            // tables
            // 
            this.tables.FormattingEnabled = true;
            this.tables.Location = new System.Drawing.Point(19, 243);
            this.tables.Name = "tables";
            this.tables.Size = new System.Drawing.Size(121, 20);
            this.tables.TabIndex = 0;
            // 
            // dataGrid
            // 
            this.dataGrid.AllowUserToOrderColumns = true;
            this.dataGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGrid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dataGrid.Location = new System.Drawing.Point(0, 0);
            this.dataGrid.Name = "dataGrid";
            this.dataGrid.RowTemplate.Height = 23;
            this.dataGrid.Size = new System.Drawing.Size(758, 506);
            this.dataGrid.TabIndex = 0;
            // 
            // panelData
            // 
            this.panelData.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panelData.AutoSize = true;
            this.panelData.Controls.Add(this.dataGrid);
            this.panelData.Location = new System.Drawing.Point(0, 1);
            this.panelData.Name = "panelData";
            this.panelData.Size = new System.Drawing.Size(758, 506);
            this.panelData.TabIndex = 3;
            // 
            // databases
            // 
            this.databases.FormattingEnabled = true;
            this.databases.Location = new System.Drawing.Point(19, 191);
            this.databases.Name = "databases";
            this.databases.Size = new System.Drawing.Size(121, 20);
            this.databases.TabIndex = 0;
            this.databases.SelectedIndexChanged += new System.EventHandler(this.Database_Changed);
            // 
            // lbl3
            // 
            this.lbl3.AutoSize = true;
            this.lbl3.Location = new System.Drawing.Point(19, 225);
            this.lbl3.Name = "lbl3";
            this.lbl3.Size = new System.Drawing.Size(41, 12);
            this.lbl3.TabIndex = 3;
            this.lbl3.Text = "数据表";
            // 
            // lbl2
            // 
            this.lbl2.AutoSize = true;
            this.lbl2.Location = new System.Drawing.Point(19, 176);
            this.lbl2.Name = "lbl2";
            this.lbl2.Size = new System.Drawing.Size(41, 12);
            this.lbl2.TabIndex = 4;
            this.lbl2.Text = "数据库";
            // 
            // lbl1
            // 
            this.lbl1.AutoSize = true;
            this.lbl1.Location = new System.Drawing.Point(21, 19);
            this.lbl1.Name = "lbl1";
            this.lbl1.Size = new System.Drawing.Size(41, 12);
            this.lbl1.TabIndex = 5;
            this.lbl1.Text = "Server";
            // 
            // server
            // 
            this.server.Location = new System.Drawing.Point(21, 35);
            this.server.Name = "server";
            this.server.Size = new System.Drawing.Size(121, 21);
            this.server.TabIndex = 6;
            this.server.Text = "192.168.1.7";
            // 
            // name
            // 
            this.name.Location = new System.Drawing.Point(21, 86);
            this.name.Name = "name";
            this.name.Size = new System.Drawing.Size(119, 21);
            this.name.TabIndex = 7;
            this.name.Text = "tangyu";
            // 
            // password
            // 
            this.password.Location = new System.Drawing.Point(21, 128);
            this.password.Name = "password";
            this.password.PasswordChar = '*';
            this.password.Size = new System.Drawing.Size(119, 21);
            this.password.TabIndex = 8;
            this.password.Text = "tangyu";
            // 
            // lbl4
            // 
            this.lbl4.AutoSize = true;
            this.lbl4.Location = new System.Drawing.Point(19, 68);
            this.lbl4.Name = "lbl4";
            this.lbl4.Size = new System.Drawing.Size(29, 12);
            this.lbl4.TabIndex = 9;
            this.lbl4.Text = "name";
            // 
            // lbl5
            // 
            this.lbl5.AutoSize = true;
            this.lbl5.Location = new System.Drawing.Point(17, 113);
            this.lbl5.Name = "lbl5";
            this.lbl5.Size = new System.Drawing.Size(53, 12);
            this.lbl5.TabIndex = 9;
            this.lbl5.Text = "password";
            // 
            // exit
            // 
            this.exit.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.exit.Image = global::Peterinor.MF.Properties.Resources.exit;
            this.exit.Location = new System.Drawing.Point(49, 413);
            this.exit.Name = "exit";
            this.exit.Size = new System.Drawing.Size(105, 93);
            this.exit.TabIndex = 10;
            this.exit.UseVisualStyleBackColor = true;
            this.exit.Click += new System.EventHandler(this.exit_Click);
            // 
            // DataForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(918, 507);
            this.Controls.Add(this.control);
            this.Controls.Add(this.panelData);
            this.Name = "DataForm";
            this.Text = "DataWin";
            this.Load += new System.EventHandler(this.Loaded);
            this.control.ResumeLayout(false);
            this.control.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGrid)).EndInit();
            this.panelData.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button update;
        private System.Windows.Forms.Button read;
        private System.Windows.Forms.Panel control;
        private System.Windows.Forms.ComboBox tables;
        private System.Windows.Forms.DataGridView dataGrid;
        private System.Windows.Forms.Panel panelData;
        private System.Windows.Forms.ComboBox databases;
        private System.Windows.Forms.Label lbl2;
        private System.Windows.Forms.Label lbl3;
        private System.Windows.Forms.TextBox server;
        private System.Windows.Forms.Label lbl1;
        private System.Windows.Forms.Label lbl5;
        private System.Windows.Forms.Label lbl4;
        private System.Windows.Forms.TextBox password;
        private System.Windows.Forms.TextBox name;
        private System.Windows.Forms.Button exit;
    }
}

