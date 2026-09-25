using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyFirstWinFormsProject
{
    public partial class frmCheckBox : Form
    {
        public frmCheckBox()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show( $"{chkTomato.Text} is {(chkTomato.Checked? "Added" : "NOT Added")}" , $"CheckBox Result : {chkTomato.Checked}");
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {

            button1.Enabled = chkTomato.Checked;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBox.Show($"{rbSmall.Text} is {(rbSmall.Checked ? "Added" : "NOT Added")}\n" +
                $"{rbMedium.Text} is {(rbMedium.Checked ? "Added" : "NOT Added")}\n"+
                $"{rbLarge.Text} is {(rbLarge.Checked ? "Added" : "NOT Added")}\n Tag: {rbLarge.Tag}", "Radio Buttons Result");
        }

        private void rbLarge_CheckedChanged(object sender, EventArgs e)
        {

        }
    }
}
