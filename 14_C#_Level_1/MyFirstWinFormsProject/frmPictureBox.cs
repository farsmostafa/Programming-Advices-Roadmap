using MyFirstWinFormsProject.Properties;
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
    public partial class frmPictureBox : Form
    {
        public frmPictureBox()
        {
            InitializeComponent();
        }

        private void UpdateTitleAndImage()
        {
            if (rbBoy.Checked)
            {
                pbImage.Image = Resources.Boy;
                lblTitle.Text = "Boy";
            }
            else if (rbGirl.Checked)
            {
                pbImage.Image = Resources.Girl;
                lblTitle.Text = "Girl";
            }
            else if (rbBook.Checked)
            {
                pbImage.Image = Resources.Book;
                lblTitle.Text = "Book";
            }
            else
            {
                pbImage.Image = Resources.Pen;
                lblTitle.Text = "Pen";
            }
        }
        private void UpdateTitle2AndImage2()
        {
            switch (comboBox1.SelectedItem.ToString().ToLower())
            {
                case "boy":
                    pictureBox2.Image = Resources.Boy;
                    label1.Text = "Boy";
                    break;
                case "girl":
                    pictureBox2.Image = Resources.Girl;
                    label1.Text = "Girl";
                    break;
                case "book":
                    pictureBox2.Image = Resources.Book;
                    label1.Text = "Book";
                    break;
                case "pen":
                    pictureBox2.Image = Resources.Pen;
                    label1.Text = "Pen";
                    break;
            }
            
        }


        

        private void button1_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Resources.weak;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Resources.Strong;
        }

        private void frmPictureBox_Load(object sender, EventArgs e)
        {
            UpdateTitleAndImage();
        }

        private void rbBoy_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTitleAndImage();
        }

        private void rbGirl_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTitleAndImage();
        }

        private void rbBook_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTitleAndImage();
        }

        private void rbPen_CheckedChanged(object sender, EventArgs e)
        {
            UpdateTitleAndImage();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            UpdateTitle2AndImage2();
        }
    }
}
