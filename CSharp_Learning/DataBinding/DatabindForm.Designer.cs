namespace DataBinding
{
    partial class DatabindForm
    {
        /// <summary>在·
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
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.Label uSER_IDLabel;
            System.Windows.Forms.Label uSER_NAMELabel;
            System.Windows.Forms.Label uSER_PSWDLabel;
            System.Windows.Forms.Label uSLabel;
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(DatabindForm));
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.uSERIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.uSERNAMEDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.uSERPASSDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.sPAREPASSDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dEPTIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.pOSITIONDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.lEVELSDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.aUTHDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.oPERDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.oPTIMEDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.uSERINFOBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.dataSet_Xhfoc = new DataBinding.DataSet_Xhfoc();
            this.uSER_INFOTableAdapter = new DataBinding.DataSet_XhfocTableAdapters.USER_INFOTableAdapter();
            this.findLUToolStrip = new System.Windows.Forms.ToolStrip();
            this.findLUToolStripButton = new System.Windows.Forms.ToolStripButton();
            this.aAA_USRBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.aAA_USRTableAdapter = new DataBinding.DataSet_XhfocTableAdapters.AAA_USRTableAdapter();
            this.tableAdapterManager = new DataBinding.DataSet_XhfocTableAdapters.TableAdapterManager();
            this.uSER_IDTextBox = new System.Windows.Forms.TextBox();
            this.uSER_NAMETextBox = new System.Windows.Forms.TextBox();
            this.uSER_PSWDTextBox = new System.Windows.Forms.TextBox();
            this.uSTextBox = new System.Windows.Forms.TextBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.button2 = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.bindingNavigator1 = new System.Windows.Forms.BindingNavigator(this.components);
            this.bindingNavigatorMoveFirstItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorMovePreviousItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorSeparator = new System.Windows.Forms.ToolStripSeparator();
            this.bindingNavigatorPositionItem = new System.Windows.Forms.ToolStripTextBox();
            this.bindingNavigatorCountItem = new System.Windows.Forms.ToolStripLabel();
            this.bindingNavigatorSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.bindingNavigatorMoveNextItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorMoveLastItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.bindingNavigatorAddNewItem = new System.Windows.Forms.ToolStripButton();
            this.bindingNavigatorDeleteItem = new System.Windows.Forms.ToolStripButton();
            uSER_IDLabel = new System.Windows.Forms.Label();
            uSER_NAMELabel = new System.Windows.Forms.Label();
            uSER_PSWDLabel = new System.Windows.Forms.Label();
            uSLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.uSERINFOBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataSet_Xhfoc)).BeginInit();
            this.findLUToolStrip.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.aAA_USRBindingSource)).BeginInit();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.bindingNavigator1)).BeginInit();
            this.bindingNavigator1.SuspendLayout();
            this.SuspendLayout();
            // 
            // uSER_IDLabel
            // 
            uSER_IDLabel.AutoSize = true;
            uSER_IDLabel.Location = new System.Drawing.Point(66, 93);
            uSER_IDLabel.Name = "uSER_IDLabel";
            uSER_IDLabel.Size = new System.Drawing.Size(53, 12);
            uSER_IDLabel.TabIndex = 2;
            uSER_IDLabel.Text = "USER ID:";
            // 
            // uSER_NAMELabel
            // 
            uSER_NAMELabel.AutoSize = true;
            uSER_NAMELabel.Location = new System.Drawing.Point(54, 150);
            uSER_NAMELabel.Name = "uSER_NAMELabel";
            uSER_NAMELabel.Size = new System.Drawing.Size(65, 12);
            uSER_NAMELabel.TabIndex = 4;
            uSER_NAMELabel.Text = "USER NAME:";
            // 
            // uSER_PSWDLabel
            // 
            uSER_PSWDLabel.AutoSize = true;
            uSER_PSWDLabel.Location = new System.Drawing.Point(54, 213);
            uSER_PSWDLabel.Name = "uSER_PSWDLabel";
            uSER_PSWDLabel.Size = new System.Drawing.Size(65, 12);
            uSER_PSWDLabel.TabIndex = 6;
            uSER_PSWDLabel.Text = "USER PSWD:";
            // 
            // uSLabel
            // 
            uSLabel.AutoSize = true;
            uSLabel.Location = new System.Drawing.Point(96, 269);
            uSLabel.Name = "uSLabel";
            uSLabel.Size = new System.Drawing.Size(23, 12);
            uSLabel.TabIndex = 8;
            uSLabel.Text = "US:";
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToOrderColumns = true;
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.uSERIDDataGridViewTextBoxColumn,
            this.uSERNAMEDataGridViewTextBoxColumn,
            this.uSERPASSDataGridViewTextBoxColumn,
            this.sPAREPASSDataGridViewTextBoxColumn,
            this.dEPTIDDataGridViewTextBoxColumn,
            this.pOSITIONDataGridViewTextBoxColumn,
            this.lEVELSDataGridViewTextBoxColumn,
            this.aUTHDataGridViewTextBoxColumn,
            this.oPERDataGridViewTextBoxColumn,
            this.oPTIMEDataGridViewTextBoxColumn});
            this.dataGridView1.DataSource = this.uSERINFOBindingSource;
            this.dataGridView1.Location = new System.Drawing.Point(0, 28);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 23;
            this.dataGridView1.Size = new System.Drawing.Size(758, 415);
            this.dataGridView1.TabIndex = 0;
            // 
            // uSERIDDataGridViewTextBoxColumn
            // 
            this.uSERIDDataGridViewTextBoxColumn.DataPropertyName = "USERID";
            this.uSERIDDataGridViewTextBoxColumn.HeaderText = "USERID";
            this.uSERIDDataGridViewTextBoxColumn.Name = "uSERIDDataGridViewTextBoxColumn";
            // 
            // uSERNAMEDataGridViewTextBoxColumn
            // 
            this.uSERNAMEDataGridViewTextBoxColumn.DataPropertyName = "USERNAME";
            this.uSERNAMEDataGridViewTextBoxColumn.HeaderText = "USERNAME";
            this.uSERNAMEDataGridViewTextBoxColumn.Name = "uSERNAMEDataGridViewTextBoxColumn";
            // 
            // uSERPASSDataGridViewTextBoxColumn
            // 
            this.uSERPASSDataGridViewTextBoxColumn.DataPropertyName = "USERPASS";
            this.uSERPASSDataGridViewTextBoxColumn.HeaderText = "USERPASS";
            this.uSERPASSDataGridViewTextBoxColumn.Name = "uSERPASSDataGridViewTextBoxColumn";
            // 
            // sPAREPASSDataGridViewTextBoxColumn
            // 
            this.sPAREPASSDataGridViewTextBoxColumn.DataPropertyName = "SPAREPASS";
            this.sPAREPASSDataGridViewTextBoxColumn.HeaderText = "SPAREPASS";
            this.sPAREPASSDataGridViewTextBoxColumn.Name = "sPAREPASSDataGridViewTextBoxColumn";
            // 
            // dEPTIDDataGridViewTextBoxColumn
            // 
            this.dEPTIDDataGridViewTextBoxColumn.DataPropertyName = "DEPTID";
            this.dEPTIDDataGridViewTextBoxColumn.HeaderText = "DEPTID";
            this.dEPTIDDataGridViewTextBoxColumn.Name = "dEPTIDDataGridViewTextBoxColumn";
            // 
            // pOSITIONDataGridViewTextBoxColumn
            // 
            this.pOSITIONDataGridViewTextBoxColumn.DataPropertyName = "POSITION";
            this.pOSITIONDataGridViewTextBoxColumn.HeaderText = "POSITION";
            this.pOSITIONDataGridViewTextBoxColumn.Name = "pOSITIONDataGridViewTextBoxColumn";
            // 
            // lEVELSDataGridViewTextBoxColumn
            // 
            this.lEVELSDataGridViewTextBoxColumn.DataPropertyName = "LEVELS";
            this.lEVELSDataGridViewTextBoxColumn.HeaderText = "LEVELS";
            this.lEVELSDataGridViewTextBoxColumn.Name = "lEVELSDataGridViewTextBoxColumn";
            // 
            // aUTHDataGridViewTextBoxColumn
            // 
            this.aUTHDataGridViewTextBoxColumn.DataPropertyName = "AUTH";
            this.aUTHDataGridViewTextBoxColumn.HeaderText = "AUTH";
            this.aUTHDataGridViewTextBoxColumn.Name = "aUTHDataGridViewTextBoxColumn";
            // 
            // oPERDataGridViewTextBoxColumn
            // 
            this.oPERDataGridViewTextBoxColumn.DataPropertyName = "OPER";
            this.oPERDataGridViewTextBoxColumn.HeaderText = "OPER";
            this.oPERDataGridViewTextBoxColumn.Name = "oPERDataGridViewTextBoxColumn";
            // 
            // oPTIMEDataGridViewTextBoxColumn
            // 
            this.oPTIMEDataGridViewTextBoxColumn.DataPropertyName = "OPTIME";
            this.oPTIMEDataGridViewTextBoxColumn.HeaderText = "OPTIME";
            this.oPTIMEDataGridViewTextBoxColumn.Name = "oPTIMEDataGridViewTextBoxColumn";
            // 
            // uSERINFOBindingSource
            // 
            this.uSERINFOBindingSource.DataMember = "USER_INFO";
            this.uSERINFOBindingSource.DataSource = this.dataSet_Xhfoc;
            // 
            // dataSet_Xhfoc
            // 
            this.dataSet_Xhfoc.DataSetName = "DataSet_Xhfoc";
            this.dataSet_Xhfoc.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // uSER_INFOTableAdapter
            // 
            this.uSER_INFOTableAdapter.ClearBeforeFill = true;
            // 
            // findLUToolStrip
            // 
            this.findLUToolStrip.Dock = System.Windows.Forms.DockStyle.None;
            this.findLUToolStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.findLUToolStripButton});
            this.findLUToolStrip.Location = new System.Drawing.Point(0, 0);
            this.findLUToolStrip.Name = "findLUToolStrip";
            this.findLUToolStrip.Size = new System.Drawing.Size(63, 25);
            this.findLUToolStrip.TabIndex = 1;
            this.findLUToolStrip.Text = "findLUToolStrip";
            // 
            // findLUToolStripButton
            // 
            this.findLUToolStripButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this.findLUToolStripButton.Name = "findLUToolStripButton";
            this.findLUToolStripButton.Size = new System.Drawing.Size(51, 22);
            this.findLUToolStripButton.Text = "FindLU";
            this.findLUToolStripButton.Click += new System.EventHandler(this.findLUToolStripButton_Click);
            // 
            // aAA_USRBindingSource
            // 
            this.aAA_USRBindingSource.DataMember = "AAA_USR";
            this.aAA_USRBindingSource.DataSource = this.dataSet_Xhfoc;
            // 
            // aAA_USRTableAdapter
            // 
            this.aAA_USRTableAdapter.ClearBeforeFill = true;
            // 
            // tableAdapterManager
            // 
            this.tableAdapterManager.AAA_USRTableAdapter = this.aAA_USRTableAdapter;
            this.tableAdapterManager.AABBTableAdapter = null;
            this.tableAdapterManager.BackupDataSetBeforeUpdate = false;
            this.tableAdapterManager.TESTTABLETableAdapter = null;
            this.tableAdapterManager.UpdateOrder = DataBinding.DataSet_XhfocTableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete;
            this.tableAdapterManager.USER_INFOTableAdapter = null;
            // 
            // uSER_IDTextBox
            // 
            this.uSER_IDTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.aAA_USRBindingSource, "USER_ID", true));
            this.uSER_IDTextBox.Location = new System.Drawing.Point(125, 90);
            this.uSER_IDTextBox.Name = "uSER_IDTextBox";
            this.uSER_IDTextBox.Size = new System.Drawing.Size(100, 21);
            this.uSER_IDTextBox.TabIndex = 3;
            // 
            // uSER_NAMETextBox
            // 
            this.uSER_NAMETextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.aAA_USRBindingSource, "USER_NAME", true));
            this.uSER_NAMETextBox.Location = new System.Drawing.Point(125, 147);
            this.uSER_NAMETextBox.Name = "uSER_NAMETextBox";
            this.uSER_NAMETextBox.Size = new System.Drawing.Size(100, 21);
            this.uSER_NAMETextBox.TabIndex = 5;
            // 
            // uSER_PSWDTextBox
            // 
            this.uSER_PSWDTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.aAA_USRBindingSource, "USER_PSWD", true));
            this.uSER_PSWDTextBox.Location = new System.Drawing.Point(125, 210);
            this.uSER_PSWDTextBox.Name = "uSER_PSWDTextBox";
            this.uSER_PSWDTextBox.Size = new System.Drawing.Size(100, 21);
            this.uSER_PSWDTextBox.TabIndex = 7;
            // 
            // uSTextBox
            // 
            this.uSTextBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.aAA_USRBindingSource, "US", true));
            this.uSTextBox.Location = new System.Drawing.Point(125, 266);
            this.uSTextBox.Name = "uSTextBox";
            this.uSTextBox.Size = new System.Drawing.Size(100, 21);
            this.uSTextBox.TabIndex = 9;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.bindingNavigator1);
            this.panel1.Controls.Add(this.button2);
            this.panel1.Controls.Add(this.button1);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(uSER_IDLabel);
            this.panel1.Controls.Add(uSLabel);
            this.panel1.Controls.Add(this.uSER_IDTextBox);
            this.panel1.Controls.Add(this.uSTextBox);
            this.panel1.Controls.Add(this.uSER_NAMETextBox);
            this.panel1.Controls.Add(uSER_PSWDLabel);
            this.panel1.Controls.Add(uSER_NAMELabel);
            this.panel1.Controls.Add(this.uSER_PSWDTextBox);
            this.panel1.Location = new System.Drawing.Point(817, 28);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(294, 392);
            this.panel1.TabIndex = 10;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(68, 333);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 12;
            this.button2.Text = "Prev<<";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(161, 333);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 11;
            this.button1.Text = ">>Next";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this.label1.Font = new System.Drawing.Font("宋体", 24F);
            this.label1.Location = new System.Drawing.Point(92, 27);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(129, 30);
            this.label1.TabIndex = 10;
            this.label1.Text = "USA_AAA";
            // 
            // bindingNavigator1
            // 
            this.bindingNavigator1.AddNewItem = this.bindingNavigatorAddNewItem;
            this.bindingNavigator1.BindingSource = this.aAA_USRBindingSource;
            this.bindingNavigator1.CountItem = this.bindingNavigatorCountItem;
            this.bindingNavigator1.DeleteItem = this.bindingNavigatorDeleteItem;
            this.bindingNavigator1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.bindingNavigatorMoveFirstItem,
            this.bindingNavigatorMovePreviousItem,
            this.bindingNavigatorSeparator,
            this.bindingNavigatorPositionItem,
            this.bindingNavigatorCountItem,
            this.bindingNavigatorSeparator1,
            this.bindingNavigatorMoveNextItem,
            this.bindingNavigatorMoveLastItem,
            this.bindingNavigatorSeparator2,
            this.bindingNavigatorAddNewItem,
            this.bindingNavigatorDeleteItem});
            this.bindingNavigator1.Location = new System.Drawing.Point(0, 0);
            this.bindingNavigator1.MoveFirstItem = this.bindingNavigatorMoveFirstItem;
            this.bindingNavigator1.MoveLastItem = this.bindingNavigatorMoveLastItem;
            this.bindingNavigator1.MoveNextItem = this.bindingNavigatorMoveNextItem;
            this.bindingNavigator1.MovePreviousItem = this.bindingNavigatorMovePreviousItem;
            this.bindingNavigator1.Name = "bindingNavigator1";
            this.bindingNavigator1.PositionItem = this.bindingNavigatorPositionItem;
            this.bindingNavigator1.Size = new System.Drawing.Size(294, 25);
            this.bindingNavigator1.TabIndex = 13;
            this.bindingNavigator1.Text = "bindingNavigator1";
            // 
            // bindingNavigatorMoveFirstItem
            // 
            this.bindingNavigatorMoveFirstItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMoveFirstItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveFirstItem.Image")));
            this.bindingNavigatorMoveFirstItem.Name = "bindingNavigatorMoveFirstItem";
            this.bindingNavigatorMoveFirstItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMoveFirstItem.Size = new System.Drawing.Size(23, 22);
            this.bindingNavigatorMoveFirstItem.Text = "移到第一条记录";
            // 
            // bindingNavigatorMovePreviousItem
            // 
            this.bindingNavigatorMovePreviousItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMovePreviousItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMovePreviousItem.Image")));
            this.bindingNavigatorMovePreviousItem.Name = "bindingNavigatorMovePreviousItem";
            this.bindingNavigatorMovePreviousItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMovePreviousItem.Size = new System.Drawing.Size(23, 22);
            this.bindingNavigatorMovePreviousItem.Text = "移到上一条记录";
            this.bindingNavigatorMovePreviousItem.Click += new System.EventHandler(this.bindingNavigatorMovePreviousItem_Click);
            // 
            // bindingNavigatorSeparator
            // 
            this.bindingNavigatorSeparator.Name = "bindingNavigatorSeparator";
            this.bindingNavigatorSeparator.Size = new System.Drawing.Size(6, 25);
            // 
            // bindingNavigatorPositionItem
            // 
            this.bindingNavigatorPositionItem.AccessibleName = "位置";
            this.bindingNavigatorPositionItem.AutoSize = false;
            this.bindingNavigatorPositionItem.Name = "bindingNavigatorPositionItem";
            this.bindingNavigatorPositionItem.Size = new System.Drawing.Size(50, 23);
            this.bindingNavigatorPositionItem.Text = "0";
            this.bindingNavigatorPositionItem.ToolTipText = "当前位置";
            // 
            // bindingNavigatorCountItem
            // 
            this.bindingNavigatorCountItem.Name = "bindingNavigatorCountItem";
            this.bindingNavigatorCountItem.Size = new System.Drawing.Size(32, 22);
            this.bindingNavigatorCountItem.Text = "/ {0}";
            this.bindingNavigatorCountItem.ToolTipText = "总项数";
            // 
            // bindingNavigatorSeparator1
            // 
            this.bindingNavigatorSeparator1.Name = "bindingNavigatorSeparator";
            this.bindingNavigatorSeparator1.Size = new System.Drawing.Size(6, 25);
            // 
            // bindingNavigatorMoveNextItem
            // 
            this.bindingNavigatorMoveNextItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMoveNextItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveNextItem.Image")));
            this.bindingNavigatorMoveNextItem.Name = "bindingNavigatorMoveNextItem";
            this.bindingNavigatorMoveNextItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMoveNextItem.Size = new System.Drawing.Size(23, 22);
            this.bindingNavigatorMoveNextItem.Text = "移到下一条记录";
            // 
            // bindingNavigatorMoveLastItem
            // 
            this.bindingNavigatorMoveLastItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorMoveLastItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveLastItem.Image")));
            this.bindingNavigatorMoveLastItem.Name = "bindingNavigatorMoveLastItem";
            this.bindingNavigatorMoveLastItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorMoveLastItem.Size = new System.Drawing.Size(23, 22);
            this.bindingNavigatorMoveLastItem.Text = "移到最后一条记录";
            // 
            // bindingNavigatorSeparator2
            // 
            this.bindingNavigatorSeparator2.Name = "bindingNavigatorSeparator";
            this.bindingNavigatorSeparator2.Size = new System.Drawing.Size(6, 25);
            // 
            // bindingNavigatorAddNewItem
            // 
            this.bindingNavigatorAddNewItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorAddNewItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorAddNewItem.Image")));
            this.bindingNavigatorAddNewItem.Name = "bindingNavigatorAddNewItem";
            this.bindingNavigatorAddNewItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorAddNewItem.Size = new System.Drawing.Size(23, 22);
            this.bindingNavigatorAddNewItem.Text = "新添";
            // 
            // bindingNavigatorDeleteItem
            // 
            this.bindingNavigatorDeleteItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.bindingNavigatorDeleteItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorDeleteItem.Image")));
            this.bindingNavigatorDeleteItem.Name = "bindingNavigatorDeleteItem";
            this.bindingNavigatorDeleteItem.RightToLeftAutoMirrorImage = true;
            this.bindingNavigatorDeleteItem.Size = new System.Drawing.Size(23, 22);
            this.bindingNavigatorDeleteItem.Text = "删除";
            // 
            // DatabindForm
            // 
            this.AutoScroll = true;
            this.ClientSize = new System.Drawing.Size(1150, 450);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.findLUToolStrip);
            this.Controls.Add(this.dataGridView1);
            this.Name = "DatabindForm";
            this.Text = "DataBind";
            this.Load += new System.EventHandler(this.DatabindForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.uSERINFOBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataSet_Xhfoc)).EndInit();
            this.findLUToolStrip.ResumeLayout(false);
            this.findLUToolStrip.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.aAA_USRBindingSource)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.bindingNavigator1)).EndInit();
            this.bindingNavigator1.ResumeLayout(false);
            this.bindingNavigator1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private DataSet_Xhfoc dataSet_Xhfoc;
        private System.Windows.Forms.BindingSource uSERINFOBindingSource;
        private DataSet_XhfocTableAdapters.USER_INFOTableAdapter uSER_INFOTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn uSERIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn uSERNAMEDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn uSERPASSDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn sPAREPASSDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn dEPTIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn pOSITIONDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn lEVELSDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn aUTHDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn oPERDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn oPTIMEDataGridViewTextBoxColumn;
        private System.Windows.Forms.ToolStrip findLUToolStrip;
        private System.Windows.Forms.ToolStripButton findLUToolStripButton;
        private System.Windows.Forms.BindingSource aAA_USRBindingSource;
        private DataSet_XhfocTableAdapters.AAA_USRTableAdapter aAA_USRTableAdapter;
        private DataSet_XhfocTableAdapters.TableAdapterManager tableAdapterManager;
        private System.Windows.Forms.TextBox uSER_IDTextBox;
        private System.Windows.Forms.TextBox uSER_NAMETextBox;
        private System.Windows.Forms.TextBox uSER_PSWDTextBox;
        private System.Windows.Forms.TextBox uSTextBox;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.BindingNavigator bindingNavigator1;
        private System.Windows.Forms.ToolStripButton bindingNavigatorAddNewItem;
        private System.Windows.Forms.ToolStripLabel bindingNavigatorCountItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorDeleteItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveFirstItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMovePreviousItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator;
        private System.Windows.Forms.ToolStripTextBox bindingNavigatorPositionItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator1;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveNextItem;
        private System.Windows.Forms.ToolStripButton bindingNavigatorMoveLastItem;
        private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator2;


    }
}

