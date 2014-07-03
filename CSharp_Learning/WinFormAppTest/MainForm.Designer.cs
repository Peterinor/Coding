namespace WinFormAppTest
{
    partial class MainForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.btn = new System.Windows.Forms.Button();
            this.lbl = new System.Windows.Forms.Label();
            this.statusBar = new System.Windows.Forms.StatusStrip();
            this.btn_Exit = new System.Windows.Forms.Button();
            this.btn2 = new System.Windows.Forms.Button();
            this.btn1 = new System.Windows.Forms.Button();
            this.llbl = new System.Windows.Forms.LinkLabel();
            this.sbl = new System.Windows.Forms.ToolStripStatusLabel();
            this.statusBar.SuspendLayout();
            this.SuspendLayout();
            // 
            // btn
            // 
            this.btn.Location = new System.Drawing.Point(189, 91);
            this.btn.Name = "btn";
            this.btn.Size = new System.Drawing.Size(73, 27);
            this.btn.TabIndex = 0;
            this.btn.Text = "Press Me";
            this.btn.UseVisualStyleBackColor = true;
            this.btn.Click += new System.EventHandler(this.btn_Click);
            // 
            // lbl
            // 
            this.lbl.AutoSize = true;
            this.lbl.Location = new System.Drawing.Point(150, 45);
            this.lbl.Name = "lbl";
            this.lbl.Size = new System.Drawing.Size(197, 12);
            this.lbl.TabIndex = 1;
            this.lbl.Text = "This is a test of click on a btn";
            // 
            // statusBar
            // 
            this.statusBar.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.sbl});
            this.statusBar.Location = new System.Drawing.Point(0, 354);
            this.statusBar.Name = "statusBar";
            this.statusBar.Size = new System.Drawing.Size(492, 22);
            this.statusBar.TabIndex = 3;
            this.statusBar.Text = "statusBar";
            // 
            // btn_Exit
            // 
            this.btn_Exit.Image = global::WinFormAppTest.Properties.Resources.Exit;
            this.btn_Exit.Location = new System.Drawing.Point(382, 241);
            this.btn_Exit.Name = "btn_Exit";
            this.btn_Exit.Size = new System.Drawing.Size(110, 110);
            this.btn_Exit.TabIndex = 5;
            this.btn_Exit.UseVisualStyleBackColor = true;
            this.btn_Exit.Click += new System.EventHandler(this.btn_Exit_Click);
            // 
            // btn2
            // 
            this.btn2.Image = global::WinFormAppTest.Properties.Resources.share;
            this.btn2.Location = new System.Drawing.Point(189, 195);
            this.btn2.Name = "btn2";
            this.btn2.Size = new System.Drawing.Size(133, 48);
            this.btn2.TabIndex = 4;
            this.btn2.UseVisualStyleBackColor = true;
            // 
            // btn1
            // 
            this.btn1.Image = ((System.Drawing.Image)(resources.GetObject("btn1.Image")));
            this.btn1.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btn1.Location = new System.Drawing.Point(189, 139);
            this.btn1.Name = "btn1";
            this.btn1.Size = new System.Drawing.Size(90, 33);
            this.btn1.TabIndex = 2;
            this.btn1.Text = "button";
            this.btn1.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btn1.UseVisualStyleBackColor = true;
            this.btn1.Click += new System.EventHandler(this.btn1_Click);
            // 
            // llbl
            // 
            this.llbl.AutoSize = true;
            this.llbl.Image = global::WinFormAppTest.Properties.Resources.Add;
            this.llbl.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.llbl.Location = new System.Drawing.Point(152, 279);
            this.llbl.Name = "llbl";
            this.llbl.Size = new System.Drawing.Size(191, 12);
            this.llbl.TabIndex = 6;
            this.llbl.TabStop = true;
            this.llbl.Tag = "http://ehr.xiamenair.com/";
            this.llbl.Text = "    This is another label Text!";
            this.llbl.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.llbl.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.llbl_LinkClicked);
            // 
            // sbl
            // 
            this.sbl.Name = "sbl";
            this.sbl.Size = new System.Drawing.Size(86, 17);
            this.sbl.Text = "statusBarText";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(492, 376);
            this.Controls.Add(this.llbl);
            this.Controls.Add(this.btn_Exit);
            this.Controls.Add(this.btn2);
            this.Controls.Add(this.statusBar);
            this.Controls.Add(this.btn1);
            this.Controls.Add(this.lbl);
            this.Controls.Add(this.btn);
            this.Name = "MainForm";
            this.Text = "MainForm";
            this.Click += new System.EventHandler(this.Form_Click);
            this.statusBar.ResumeLayout(false);
            this.statusBar.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btn;
        private System.Windows.Forms.Label lbl;
        private System.Windows.Forms.Button btn1;
        private System.Windows.Forms.StatusStrip statusBar;
        private System.Windows.Forms.Button btn2;
        private System.Windows.Forms.Button btn_Exit;
        private System.Windows.Forms.LinkLabel llbl;
        private System.Windows.Forms.ToolStripStatusLabel sbl;
    }
}

