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
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
        }

        //private void btnShowPart1_Click(object sender, EventArgs e)
        //{
        //    Form form1 = new Form1();
        //    form1.Show();
        //}

        //private void button1_Click(object sender, EventArgs e)
        //{
        //    Form form1 = new Form1();
        //    form1.ShowDialog();
        //}

        private void btnShowMassage_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Simple Massage With Ok");
        }

        private void btnShowMassageWithTitle_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Simple Body With Ok", "Title");
        }

        private void btnShowMassageWithTitleAndButtons_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Are You Sure", "Title", MessageBoxButtons.YesNo) == DialogResult.Yes)
            {
                MessageBox.Show("Pressed Yes");
            }
        }

        private void btnShowMassageWithTitleAndButtonsAndImage_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Press Ok To Delete", "Title", MessageBoxButtons.OKCancel, MessageBoxIcon.Question) == DialogResult.OK)
            {
                MessageBox.Show("Pressed Ok");
            }
        }
        private void button1_Click_1(object sender, EventArgs e)
        {
            if(MessageBox.Show("Press Ok To Delete", "Title", MessageBoxButtons.OKCancel, MessageBoxIcon.Question,MessageBoxDefaultButton.Button2) == DialogResult.OK)
            {
                MessageBox.Show("Pressed Ok");
            }

        }

        private void btnShowCheckBoxForm_Click(object sender, EventArgs e)
        {
            Form frm1 = new frmCheckBox();
            frm1.ShowDialog();
        }

        private void btnShowPictureBox_Click(object sender, EventArgs e)
        {
            Form form1 = new frmPictureBox();
            form1.ShowDialog();
        }
    }
}
