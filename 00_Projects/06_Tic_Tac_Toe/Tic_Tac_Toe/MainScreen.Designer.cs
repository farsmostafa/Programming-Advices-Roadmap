namespace Tic_Tac_Toe
{
    partial class frmGameMainScreen
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmGameMainScreen));
            this.label4 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.btnShowArenaForm = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.rbMultiPlayers = new System.Windows.Forms.RadioButton();
            this.label6 = new System.Windows.Forms.Label();
            this.rbSinglePlayer = new System.Windows.Forms.RadioButton();
            this.label5 = new System.Windows.Forms.Label();
            this.nudNumberOfWins = new System.Windows.Forms.NumericUpDown();
            this.tbPlayer2Name = new System.Windows.Forms.TextBox();
            this.lblMainScreenPlayer2 = new System.Windows.Forms.Label();
            this.tbPlayer1Name = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudNumberOfWins)).BeginInit();
            this.SuspendLayout();
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.Color.Transparent;
            this.label4.Font = new System.Drawing.Font("Segoe UI Black", 38F, System.Drawing.FontStyle.Bold);
            this.label4.ForeColor = System.Drawing.Color.Black;
            this.label4.Location = new System.Drawing.Point(225, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(423, 68);
            this.label4.TabIndex = 3;
            this.label4.Text = "TIC-TAC-CLASH";
            this.label4.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Font = new System.Drawing.Font("Papyrus", 25F);
            this.label1.ForeColor = System.Drawing.Color.Black;
            this.label1.Location = new System.Drawing.Point(14, 92);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(876, 165);
            this.label1.TabIndex = 4;
            this.label1.Text = "Challenge your rival in a classic  strategic showdown  on \r\nvintage  paper. Enter" +
    " player names, set the winning  target,\r\n and discover who will claim the grid f" +
    "irst";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.label1.UseCompatibleTextRendering = true;
            // 
            // btnShowArenaForm
            // 
            this.btnShowArenaForm.AutoSize = true;
            this.btnShowArenaForm.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.btnShowArenaForm.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnShowArenaForm.Enabled = false;
            this.btnShowArenaForm.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.btnShowArenaForm.FlatAppearance.BorderSize = 3;
            this.btnShowArenaForm.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gray;
            this.btnShowArenaForm.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Silver;
            this.btnShowArenaForm.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnShowArenaForm.Font = new System.Drawing.Font("Papyrus", 24F, System.Drawing.FontStyle.Bold);
            this.btnShowArenaForm.Location = new System.Drawing.Point(636, 403);
            this.btnShowArenaForm.Name = "btnShowArenaForm";
            this.btnShowArenaForm.Size = new System.Drawing.Size(224, 121);
            this.btnShowArenaForm.TabIndex = 5;
            this.btnShowArenaForm.Text = "Enter\r\nThe Arena";
            this.btnShowArenaForm.UseCompatibleTextRendering = true;
            this.btnShowArenaForm.UseVisualStyleBackColor = false;
            this.btnShowArenaForm.Click += new System.EventHandler(this.btnShowArenaForm_Click);
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.WhiteSmoke;
            this.panel1.Controls.Add(this.rbMultiPlayers);
            this.panel1.Controls.Add(this.label6);
            this.panel1.Controls.Add(this.rbSinglePlayer);
            this.panel1.Controls.Add(this.label5);
            this.panel1.Controls.Add(this.nudNumberOfWins);
            this.panel1.Controls.Add(this.tbPlayer2Name);
            this.panel1.Controls.Add(this.lblMainScreenPlayer2);
            this.panel1.Controls.Add(this.tbPlayer1Name);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.btnShowArenaForm);
            this.panel1.Controls.Add(this.label4);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Location = new System.Drawing.Point(146, 35);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(906, 610);
            this.panel1.TabIndex = 6;
            // 
            // rbMultiPlayers
            // 
            this.rbMultiPlayers.AutoSize = true;
            this.rbMultiPlayers.Cursor = System.Windows.Forms.Cursors.Hand;
            this.rbMultiPlayers.Font = new System.Drawing.Font("Papyrus", 20F);
            this.rbMultiPlayers.Location = new System.Drawing.Point(551, 280);
            this.rbMultiPlayers.Name = "rbMultiPlayers";
            this.rbMultiPlayers.Size = new System.Drawing.Size(193, 46);
            this.rbMultiPlayers.TabIndex = 14;
            this.rbMultiPlayers.Text = "Multi Players";
            this.rbMultiPlayers.UseVisualStyleBackColor = true;
            this.rbMultiPlayers.CheckedChanged += new System.EventHandler(this.rbMultiPlayers_CheckedChanged);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.BackColor = System.Drawing.Color.Transparent;
            this.label6.Font = new System.Drawing.Font("Papyrus", 20F);
            this.label6.ForeColor = System.Drawing.Color.Black;
            this.label6.Location = new System.Drawing.Point(14, 279);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(162, 49);
            this.label6.TabIndex = 13;
            this.label6.Text = "Game Mode";
            this.label6.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.label6.UseCompatibleTextRendering = true;
            // 
            // rbSinglePlayer
            // 
            this.rbSinglePlayer.AutoSize = true;
            this.rbSinglePlayer.Checked = true;
            this.rbSinglePlayer.Cursor = System.Windows.Forms.Cursors.Hand;
            this.rbSinglePlayer.Font = new System.Drawing.Font("Papyrus", 20F);
            this.rbSinglePlayer.Location = new System.Drawing.Point(293, 280);
            this.rbSinglePlayer.Name = "rbSinglePlayer";
            this.rbSinglePlayer.Size = new System.Drawing.Size(197, 46);
            this.rbSinglePlayer.TabIndex = 12;
            this.rbSinglePlayer.TabStop = true;
            this.rbSinglePlayer.Text = "Single Player";
            this.rbSinglePlayer.UseVisualStyleBackColor = true;
            this.rbSinglePlayer.CheckedChanged += new System.EventHandler(this.rbSinglePlayer_CheckedChanged);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.Color.Transparent;
            this.label5.Font = new System.Drawing.Font("Papyrus", 20F);
            this.label5.ForeColor = System.Drawing.Color.Black;
            this.label5.Location = new System.Drawing.Point(14, 521);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(250, 49);
            this.label5.TabIndex = 11;
            this.label5.Text = "Target Wins (Goal)";
            this.label5.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.label5.UseCompatibleTextRendering = true;
            // 
            // nudNumberOfWins
            // 
            this.nudNumberOfWins.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.nudNumberOfWins.Cursor = System.Windows.Forms.Cursors.Hand;
            this.nudNumberOfWins.Font = new System.Drawing.Font("Papyrus", 25F);
            this.nudNumberOfWins.Location = new System.Drawing.Point(293, 515);
            this.nudNumberOfWins.Maximum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.nudNumberOfWins.Name = "nudNumberOfWins";
            this.nudNumberOfWins.Size = new System.Drawing.Size(304, 60);
            this.nudNumberOfWins.TabIndex = 10;
            this.nudNumberOfWins.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.nudNumberOfWins.ValueChanged += new System.EventHandler(this.nudNumberOfWins_ValueChanged);
            // 
            // tbPlayer2Name
            // 
            this.tbPlayer2Name.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.tbPlayer2Name.Cursor = System.Windows.Forms.Cursors.Hand;
            this.tbPlayer2Name.Font = new System.Drawing.Font("Papyrus", 20F);
            this.tbPlayer2Name.Location = new System.Drawing.Point(293, 441);
            this.tbPlayer2Name.MaxLength = 15;
            this.tbPlayer2Name.Name = "tbPlayer2Name";
            this.tbPlayer2Name.Size = new System.Drawing.Size(304, 49);
            this.tbPlayer2Name.TabIndex = 9;
            this.tbPlayer2Name.Text = "Computer";
            this.tbPlayer2Name.Visible = false;
            this.tbPlayer2Name.TextChanged += new System.EventHandler(this.tbPlayer2Name_TextChanged);
            // 
            // lblMainScreenPlayer2
            // 
            this.lblMainScreenPlayer2.AutoSize = true;
            this.lblMainScreenPlayer2.BackColor = System.Drawing.Color.Transparent;
            this.lblMainScreenPlayer2.Font = new System.Drawing.Font("Papyrus", 20F);
            this.lblMainScreenPlayer2.ForeColor = System.Drawing.Color.Black;
            this.lblMainScreenPlayer2.Location = new System.Drawing.Point(14, 441);
            this.lblMainScreenPlayer2.Name = "lblMainScreenPlayer2";
            this.lblMainScreenPlayer2.Size = new System.Drawing.Size(154, 49);
            this.lblMainScreenPlayer2.TabIndex = 8;
            this.lblMainScreenPlayer2.Text = "Player2 (O)";
            this.lblMainScreenPlayer2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblMainScreenPlayer2.UseCompatibleTextRendering = true;
            this.lblMainScreenPlayer2.Visible = false;
            // 
            // tbPlayer1Name
            // 
            this.tbPlayer1Name.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.tbPlayer1Name.Cursor = System.Windows.Forms.Cursors.Hand;
            this.tbPlayer1Name.Font = new System.Drawing.Font("Papyrus", 20F);
            this.tbPlayer1Name.Location = new System.Drawing.Point(293, 361);
            this.tbPlayer1Name.MaxLength = 15;
            this.tbPlayer1Name.Name = "tbPlayer1Name";
            this.tbPlayer1Name.Size = new System.Drawing.Size(304, 49);
            this.tbPlayer1Name.TabIndex = 7;
            this.tbPlayer1Name.TextChanged += new System.EventHandler(this.tbPlayer1Name_TextChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.Transparent;
            this.label2.Font = new System.Drawing.Font("Papyrus", 20F);
            this.label2.ForeColor = System.Drawing.Color.Black;
            this.label2.Location = new System.Drawing.Point(14, 361);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(145, 49);
            this.label2.TabIndex = 6;
            this.label2.Text = "Player1 (X)";
            this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.label2.UseCompatibleTextRendering = true;
            // 
            // frmGameMainScreen
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::Tic_Tac_Toe.Properties.Resources.TicTacToe_bg;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(1219, 684);
            this.Controls.Add(this.panel1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimumSize = new System.Drawing.Size(800, 600);
            this.Name = "frmGameMainScreen";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "TIC-TAC-CLASH";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudNumberOfWins)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnShowArenaForm;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.TextBox tbPlayer1Name;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.NumericUpDown nudNumberOfWins;
        private System.Windows.Forms.TextBox tbPlayer2Name;
        private System.Windows.Forms.Label lblMainScreenPlayer2;
        private System.Windows.Forms.RadioButton rbSinglePlayer;
        private System.Windows.Forms.RadioButton rbMultiPlayers;
        private System.Windows.Forms.Label label6;
    }
}

