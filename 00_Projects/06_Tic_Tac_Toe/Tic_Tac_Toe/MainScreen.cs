using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tic_Tac_Toe
{
    public partial class frmGameMainScreen : Form
    {
        public frmGameMainScreen()
        {
            InitializeComponent();
        }

        private void CheckEnterArenaBtnEnable()
        {
            btnShowArenaForm.Enabled = !string.IsNullOrWhiteSpace(tbPlayer1Name.Text) &&
                                           !string.IsNullOrWhiteSpace(tbPlayer2Name.Text) &&
                                           nudNumberOfWins.Value > 0;
        }

        private void CheckGameMode()
        {
            if (rbSinglePlayer.Checked)
            {
                lblMainScreenPlayer2.Visible = false;
                tbPlayer2Name.Visible = false;
                tbPlayer2Name.Text = "Computer";
            }
            else
            {
                lblMainScreenPlayer2.Visible = true;
                tbPlayer2Name.Visible = true;
                tbPlayer2Name.Text = string.Empty;
            }
        }

        private void ResetMainScreen()
        {
            rbSinglePlayer.Checked = true;
            CheckGameMode();
            tbPlayer1Name.Text = string.Empty;
            nudNumberOfWins.Value = 0;
        }
        private void tbPlayer1Name_TextChanged(object sender, EventArgs e)
        {
            CheckEnterArenaBtnEnable();
        }

        private void tbPlayer2Name_TextChanged(object sender, EventArgs e)
        {
            CheckEnterArenaBtnEnable();
        }

        private void nudNumberOfWins_ValueChanged(object sender, EventArgs e)
        {
            CheckEnterArenaBtnEnable();
        }

        private void rbSinglePlayer_CheckedChanged(object sender, EventArgs e)
        {
            CheckGameMode();
        }

        private void rbMultiPlayers_CheckedChanged(object sender, EventArgs e)
        {
            CheckGameMode();
        }

        private void btnShowArenaForm_Click(object sender, EventArgs e)
        {
            string p1 = tbPlayer1Name.Text.Trim();
            string p2 = tbPlayer2Name.Text.Trim();
            byte target = (byte)nudNumberOfWins.Value;
            bool isSingle = rbSinglePlayer.Checked;




            Form frmArena = new frm_Arena(p1, p2, target, isSingle);

            frmArena.StartPosition = FormStartPosition.Manual;

            frmArena.Location = this.Location;

            frmArena.FormClosed += (s, args) => { 
                this.Location = frmArena.Location;
                this.Show();
            };
            frmArena.Show();
            this.Hide();
            ResetMainScreen();
        }

        
    }
}
