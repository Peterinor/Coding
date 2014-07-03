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
            this.dataGrid = new System.Windows.Forms.DataGridView();
            this.panelData = new System.Windows.Forms.Panel();
            this.control = new System.Windows.Forms.Panel();
            this.tables = new System.Windows.Forms.ComboBox();
            this.read = new System.Windows.Forms.Button();
            this.update = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGrid)).BeginInit();
            this.panelData.SuspendLayout();
            this.control.SuspendLayout();
            this.SuspendLayout();
            // 
            // dataGrid
            // 
            this.dataGrid.AllowUserToOrderColumns = true;
            this.dataGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGrid.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dataGrid.Location = new System.Drawing.Point(0, 0);
            this.dataGrid.Name = "dataGrid";
            this.dataGrid.RowTemplate.Height = 23;
            this.dataGrid.Size = new System.Drawing.Size(595, 475);
            this.dataGrid.TabIndex = 0;
            // 
            // panelData
            // 
            this.panelData.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panelData.AutoSize = true;
            this.panelData.Controls.Add(this.dataGrid);
            this.panelData.Location = new System.Drawing.Point(0, 0);
            this.panelData.Name = "panelData";
            this.panelData.Size = new System.Drawing.Size(595, 475);
            this.panelData.TabIndex = 1;
            // 
            // control
            // 
            this.control.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.control.Controls.Add(this.update);
            this.control.Controls.Add(this.read);
            this.control.Controls.Add(this.tables);
            this.control.Location = new System.Drawing.Point(601, 0);
            this.control.Name = "control";
            this.control.Size = new System.Drawing.Size(154, 475);
            this.control.TabIndex = 2;
            // 
            // tables
            // 
            this.tables.FormattingEnabled = true;
            this.tables.Location = new System.Drawing.Point(21, 51);
            this.tables.Name = "tables";
            this.tables.Size = new System.Drawing.Size(121, 20);
            this.tables.TabIndex = 0;
            // 
            // read
            // 
            this.read.Location = new System.Drawing.Point(21, 257);
            this.read.Name = "read";
            this.read.Size = new System.Drawing.Size(121, 36);
            this.read.TabIndex = 1;
            this.read.Text = "读取数据";
            this.read.UseVisualStyleBackColor = true;
            this.read.Click += new System.EventHandler(this.read_Click);
            // 
            // update
            // 
            this.update.Location = new System.Drawing.Point(21, 344);
            this.update.Name = "update";
            this.update.Size = new System.Drawing.Size(121, 39);
            this.update.TabIndex = 2;
            this.update.Text = "更新数据";
            this.update.UseVisualStyleBackColor = true;
            // 
            // DataForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(755, 476);
            this.Controls.Add(this.control);
            this.Controls.Add(this.panelData);
            this.Name = "DataForm";
            this.Text = "DataForm";
            this.Load += new System.EventHandler(this.Loaded);
            ((System.ComponentModel.ISupportInitialize)(this.dataGrid)).EndInit();
            this.panelData.ResumeLayout(false);
            this.control.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGrid;
        private System.Windows.Forms.Panel panelData;
        private System.Windows.Forms.Panel control;
        private System.Windows.Forms.ComboBox tables;
        private System.Windows.Forms.Button update;
        private System.Windows.Forms.Button read;
    }
}

