namespace FileSystemTestGUI
{
    partial class FileSystemForm
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
            this.openFile = new System.Windows.Forms.OpenFileDialog();
            this.path = new System.Windows.Forms.TextBox();
            this.btn = new System.Windows.Forms.Button();
            this.content = new System.Windows.Forms.TextBox();
            this.fontDialog = new System.Windows.Forms.FontDialog();
            this.btn2 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // path
            // 
            this.path.Location = new System.Drawing.Point(36, 39);
            this.path.Name = "path";
            this.path.Size = new System.Drawing.Size(761, 21);
            this.path.TabIndex = 0;
            // 
            // btn
            // 
            this.btn.Location = new System.Drawing.Point(822, 37);
            this.btn.Name = "btn";
            this.btn.Size = new System.Drawing.Size(75, 23);
            this.btn.TabIndex = 1;
            this.btn.Text = "Browser";
            this.btn.UseVisualStyleBackColor = true;
            this.btn.Click += new System.EventHandler(this.btn_Click);
            // 
            // content
            // 
            this.content.BackColor = System.Drawing.SystemColors.ControlLight;
            this.content.Location = new System.Drawing.Point(36, 84);
            this.content.Multiline = true;
            this.content.Name = "content";
            this.content.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.content.Size = new System.Drawing.Size(761, 343);
            this.content.TabIndex = 2;
            // 
            // btn2
            // 
            this.btn2.Location = new System.Drawing.Point(822, 126);
            this.btn2.Name = "btn2";
            this.btn2.Size = new System.Drawing.Size(75, 23);
            this.btn2.TabIndex = 3;
            this.btn2.Text = "Font";
            this.btn2.UseVisualStyleBackColor = true;
            this.btn2.Click += new System.EventHandler(this.btn2_Click);
            // 
            // FileSystemForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(962, 439);
            this.Controls.Add(this.btn2);
            this.Controls.Add(this.content);
            this.Controls.Add(this.btn);
            this.Controls.Add(this.path);
            this.Name = "FileSystemForm";
            this.Text = "File";
            this.Load += new System.EventHandler(this.Loaded);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.OpenFileDialog openFile;
        private System.Windows.Forms.TextBox path;
        private System.Windows.Forms.Button btn;
        private System.Windows.Forms.TextBox content;
        private System.Windows.Forms.FontDialog fontDialog;
        private System.Windows.Forms.Button btn2;

    }
}

