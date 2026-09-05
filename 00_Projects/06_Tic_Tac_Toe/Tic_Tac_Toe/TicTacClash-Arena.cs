using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Tic_Tac_Toe.Properties;

namespace Tic_Tac_Toe
{
    public partial class frm_Arena : Form
    {
        private string _Player1Name;
        private string _Player2Name;
        private byte _TargetWins;
        private bool _IsSinglePlayer;
        private byte _Player1Wins = 0;
        private byte _Player2Wins = 0;
        private byte _Draws = 0;
        private byte _Rounds = 1;
        private bool _IsPlayer1Turn = true;
        private byte _MovesCount = 0;
        private string _WinnterName;
        private string _RoundWinnterTag;
        private Button[,] _Board;
        private bool _RoundPlayer1Turn = true;
        private Random _rnd = new Random();
        public frm_Arena(string player1, string player2, byte targetWins, bool isSinglePlayer)
        {
            InitializeComponent();
            _Player1Name = player1;
            _Player2Name = player2;
            _TargetWins = targetWins;
            _IsSinglePlayer = isSinglePlayer;
            lblPlayer1Name.Text = $"{_Player1Name} (X):";
            lblPlayer2Name.Text = $"{_Player2Name} (O):";
            _Board = new Button[3, 3] {
                { btnOption1, btnOption2, btnOption3 },
                { btnOption4, btnOption5, btnOption6 },
                { btnOption7, btnOption8, btnOption9 }
            };
            UpdateScoreBoard();
        }

        private void UpdateScoreBoard()
        {
            lblTargetWins.Text = $"{_TargetWins}";
            lblPlayer1Wins.Text = $"{_Player1Wins}";
            lblPlayer2Wins.Text = $"{_Player2Wins}";
            lblDraws.Text = $"{_Draws}";
            lblRounds.Text = $"{_Rounds}";
            lblCurrentTurn.Text = _IsPlayer1Turn ? $"{_Player1Name}" : $"{_Player2Name}";
        }

        private bool CheckLine(Button b1, Button b2, Button b3)
        {
            if (b1.Tag != null && b1.Tag.ToString() == b2.Tag?.ToString() && b2.Tag?.ToString() == b3.Tag?.ToString())
            {
                _RoundWinnterTag = b1.Tag.ToString();
                b1.BackColor = Color.ForestGreen;
                b2.BackColor = Color.ForestGreen;
                b3.BackColor = Color.ForestGreen;
                return true;
            }
            return false;
        }
        private bool CheckWinner()
        {
            for (int i = 0; i < 3; i++)
            {
                if (CheckLine(_Board[i, 0], _Board[i, 1], _Board[i, 2])) return true;
                if (CheckLine(_Board[0, i], _Board[1, i], _Board[2, i])) return true;
            }
            if (CheckLine(_Board[0, 0], _Board[1, 1], _Board[2, 2])) return true;
            if (CheckLine(_Board[0, 2], _Board[1, 1], _Board[2, 0])) return true;
            return false;
        }

        private void btnExitMatch_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Are you sure you want to exit? All progress will be lost.", "Abandon Match", MessageBoxButtons.YesNo) == DialogResult.Yes)
            {
                this.Close();
            }

        }

        private void tlpXOArenaView_Paint(object sender, PaintEventArgs e)
        {
            Pen myPen = new Pen(Color.Black);
            myPen.Width = 5;
            int thirdWidth = tlpXOArenaView.Width / 3;
            int thirdHeight = tlpXOArenaView.Height / 3;
            e.Graphics.DrawLine(myPen, thirdWidth, 0, thirdWidth, this.Height);
            e.Graphics.DrawLine(myPen, thirdWidth * 2, 0, thirdWidth * 2, this.Height);
            e.Graphics.DrawLine(myPen, 0, thirdHeight, this.Width, thirdHeight);
            e.Graphics.DrawLine(myPen, 0, thirdHeight * 2, this.Width, thirdHeight * 2);
            myPen.Dispose();
        }

        private void ResetBoard()
        {
            for (int row = 0; row < 3; row++)
            {
                for (int col = 0; col < 3; col++)
                {
                    _Board[row, col].Tag = null;
                    _Board[row, col].BackgroundImage = Resources.question_mark;
                    _Board[row, col].BackColor = Color.Transparent;
                }
            }

            _MovesCount = 0;
            _RoundWinnterTag = string.Empty;

            _Rounds++;
            _IsPlayer1Turn = _RoundPlayer1Turn ? false : true;
            _RoundPlayer1Turn = !_RoundPlayer1Turn;

            tlpXOArenaView.Enabled = true;
            btnNextRound.Enabled = false;
            UpdateScoreBoard();

            if (_IsSinglePlayer && !_IsPlayer1Turn)
            {
                ComputerPlay();
            }
        }


        private void ComputerPlay()
        {
            List<Button> emptyButtons = new List<Button>();

            for (int row = 0; row < 3; row++)
            {
                for (int col = 0; col < 3; col++)
                {
                    if (_Board[row, col].Tag == null)
                    {
                        emptyButtons.Add(_Board[row, col]);
                    }
                }
            }

            if (emptyButtons.Count > 0)
            {
                int randomIndex = _rnd.Next(emptyButtons.Count);
                Button selectedButton = emptyButtons[randomIndex];

                GameButtonOption_Click(selectedButton, EventArgs.Empty);
            }
        }


        private void GameButtonOption_Click(object sender, EventArgs e)
        {
            Button btn = (Button)sender;

            if (btn.Tag != null)
            {
                return;
            }
            _MovesCount++;
            if (_IsPlayer1Turn)
            {
                btn.Tag = "X";
                btn.BackgroundImage = Resources.X;
            }
            else
            {
                btn.Tag = "O";
                btn.BackgroundImage = Resources.O;
            }
            if (CheckWinner())
            {
                if (_RoundWinnterTag == "X") _Player1Wins++;
                else _Player2Wins++;

                UpdateScoreBoard();
                if (_Player1Wins == _TargetWins || _Player2Wins == _TargetWins)
                {
                    string champion = (_Player1Wins == _TargetWins) ? _Player1Name : _Player2Name;
                    MessageBox.Show($"🏆 {champion} wins the match!", "Match Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    this.Close();
                    return;
                }

                btnNextRound.Enabled = true;
                tlpXOArenaView.Enabled = false;
                return;
            }
            else if (_MovesCount == 9)
            {
                _Draws++;
                UpdateScoreBoard();
                btnNextRound.Enabled = true;
                tlpXOArenaView.Enabled = false;
                return;
            }
            _IsPlayer1Turn = !_IsPlayer1Turn;
            lblCurrentTurn.Text = _IsPlayer1Turn ? _Player1Name : _Player2Name;
            if (_IsSinglePlayer && !_IsPlayer1Turn)
            {
                ComputerPlay();
            }

        }

        private void btnNextRound_Click(object sender, EventArgs e)
        {
            ResetBoard();
        }
    }
}
