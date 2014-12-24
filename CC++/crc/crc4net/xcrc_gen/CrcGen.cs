using System;
using System.Windows.Forms;

using libcrc;
namespace xcrc_gen
{
    public partial class CrcGen : Form
    {
        public CrcGen()
        {
            InitializeComponent();
        }

        private void CrcGen_Load(object sender, EventArgs e)
        {

        }

        private void btnGen_Click(object sender, EventArgs e)
        {
            var crc = CrcFmc.cal(this.txtBxInput.Text);

            var crcx = this.txtBxInput.Text + string.Format("{0:x}", crc).ToUpper();

            this.txtBxResult.Text = crcx;
        }

        private void btnCopy_Click(object sender, EventArgs e)
        {
            Clipboard.SetDataObject(this.txtBxResult.Text);
        }
    }
}
