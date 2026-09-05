namespace Tic_Tac_Toe
{
    partial class frm_Arena
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frm_Arena));
            this.tlpXOArenaView = new System.Windows.Forms.TableLayoutPanel();
            this.btnOption9 = new System.Windows.Forms.Button();
            this.btnOption7 = new System.Windows.Forms.Button();
            this.btnOption6 = new System.Windows.Forms.Button();
            this.btnOption5 = new System.Windows.Forms.Button();
            this.btnOption3 = new System.Windows.Forms.Button();
            this.btnOption2 = new System.Windows.Forms.Button();
            this.btnOption1 = new System.Windows.Forms.Button();
            this.btnOption8 = new System.Windows.Forms.Button();
            this.btnOption4 = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.flpPlayer2 = new System.Windows.Forms.FlowLayoutPanel();
            this.lblPlayer2Name = new System.Windows.Forms.Label();
            this.lblPlayer2Wins = new System.Windows.Forms.Label();
            this.flpPlayer1 = new System.Windows.Forms.FlowLayoutPanel();
            this.lblPlayer1Name = new System.Windows.Forms.Label();
            this.lblPlayer1Wins = new System.Windows.Forms.Label();
            this.btnNextRound = new System.Windows.Forms.Button();
            this.lblRounds = new System.Windows.Forms.Label();
            this.lblDraws = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.lblCurrentTurn = new System.Windows.Forms.Label();
            this.lblTargetWins = new System.Windows.Forms.Label();
            this.btnExitMatch = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.tlpXOArenaView.SuspendLayout();
            this.panel1.SuspendLayout();
            this.flpPlayer2.SuspendLayout();
            this.flpPlayer1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tlpXOArenaView
            // 
            this.tlpXOArenaView.BackColor = System.Drawing.Color.WhiteSmoke;
            this.tlpXOArenaView.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.tlpXOArenaView.ColumnCount = 3;
            this.tlpXOArenaView.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tlpXOArenaView.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tlpXOArenaView.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tlpXOArenaView.Controls.Add(this.btnOption9, 2, 2);
            this.tlpXOArenaView.Controls.Add(this.btnOption7, 0, 2);
            this.tlpXOArenaView.Controls.Add(this.btnOption6, 2, 1);
            this.tlpXOArenaView.Controls.Add(this.btnOption5, 1, 1);
            this.tlpXOArenaView.Controls.Add(this.btnOption3, 2, 0);
            this.tlpXOArenaView.Controls.Add(this.btnOption2, 1, 0);
            this.tlpXOArenaView.Controls.Add(this.btnOption1, 0, 0);
            this.tlpXOArenaView.Controls.Add(this.btnOption8, 1, 2);
            this.tlpXOArenaView.Controls.Add(this.btnOption4, 0, 1);
            this.tlpXOArenaView.Location = new System.Drawing.Point(581, 38);
            this.tlpXOArenaView.Name = "tlpXOArenaView";
            this.tlpXOArenaView.RowCount = 3;
            this.tlpXOArenaView.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tlpXOArenaView.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tlpXOArenaView.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tlpXOArenaView.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tlpXOArenaView.Size = new System.Drawing.Size(600, 600);
            this.tlpXOArenaView.TabIndex = 0;
            this.tlpXOArenaView.Paint += new System.Windows.Forms.PaintEventHandler(this.tlpXOArenaView_Paint);
            // 
            // btnOption9
            // 
            this.btnOption9.AutoSize = true;
            this.btnOption9.BackColor = System.Drawing.Color.Transparent;
            this.btnOption9.BackgroundImage = global::Tic_Tac_Toe.Properties.Resources.question_mark;
            this.btnOption9.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnOption9.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnOption9.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.btnOption9.FlatAppearance.BorderSize = 0;
            this.btnOption9.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Transparent;
            this.btnOption9.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent;
            this.btnOption9.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnOption9.Font = new System.Drawing.Font("Papyrus", 18F, System.Drawing.FontStyle.Bold);
            this.btnOption9.Location = new System.Drawing.Point(401, 401);
            this.btnOption9.Name = "btnOption9";
            this.btnOption9.Size = new System.Drawing.Size(196, 196);
            this.btnOption9.TabIndex = 34;
            this.btnOption9.UseCompatibleTextRendering = true;
            this.btnOption9.UseVisualStyleBackColor = false;
            this.btnOption9.Click += new System.EventHandler(this.GameButtonOption_Click);
            this.btnOption9.MouseClick += new System.Windows.Forms.MouseEventHandler(this.GameButtonOption_Click);
            // 
            // btnOption7
            // 
            this.btnOption7.AutoSize = true;
            this.btnOption7.BackColor = System.Drawing.Color.Transparent;
            this.btnOption7.BackgroundImage = global::Tic_Tac_Toe.Properties.Resources.question_mark;
            this.btnOption7.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnOption7.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnOption7.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.btnOption7.FlatAppearance.BorderSize = 0;
            this.btnOption7.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Transparent;
            this.btnOption7.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent;
            this.btnOption7.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnOption7.Font = new System.Drawing.Font("Papyrus", 18F, System.Drawing.FontStyle.Bold);
            this.btnOption7.Location = new System.Drawing.Point(3, 401);
            this.btnOption7.Name = "btnOption7";
            this.btnOption7.Size = new System.Drawing.Size(193, 196);
            this.btnOption7.TabIndex = 32;
            this.btnOption7.UseCompatibleTextRendering = true;
            this.btnOption7.UseVisualStyleBackColor = false;
            this.btnOption7.Click += new System.EventHandler(this.GameButtonOption_Click);
            this.btnOption7.MouseClick += new System.Windows.Forms.MouseEventHandler(this.GameButtonOption_Click);
            // 
            // btnOption6
            // 
            this.btnOption6.AutoSize = true;
            this.btnOption6.BackColor = System.Drawing.Color.Transparent;
            this.btnOption6.BackgroundImage = global::Tic_Tac_Toe.Properties.Resources.question_mark;
            this.btnOption6.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnOption6.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnOption6.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.btnOption6.FlatAppearance.BorderSize = 0;
            this.btnOption6.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Transparent;
            this.btnOption6.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent;
            this.btnOption6.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnOption6.Font = new System.Drawing.Font("Papyrus", 18F, System.Drawing.FontStyle.Bold);
            this.btnOption6.Location = new System.Drawing.Point(401, 202);
            this.btnOption6.Name = "btnOption6";
            this.btnOption6.Size = new System.Drawing.Size(196, 193);
            this.btnOption6.TabIndex = 31;
            this.btnOption6.UseCompatibleTextRendering = true;
            this.btnOption6.UseVisualStyleBackColor = false;
            this.btnOption6.Click += new System.EventHandler(this.GameButtonOption_Click);
            this.btnOption6.MouseClick += new System.Windows.Forms.MouseEventHandler(this.GameButtonOption_Click);
            // 
            // btnOption5
            // 
            this.btnOption5.AutoSize = true;
            this.btnOption5.BackColor = System.Drawing.Color.Transparent;
            this.btnOption5.BackgroundImage = global::Tic_Tac_Toe.Properties.Resources.question_mark;
            this.btnOption5.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnOption5.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnOption5.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.btnOption5.FlatAppearance.BorderSize = 0;
            this.btnOption5.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Transparent;
            this.btnOption5.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent;
            this.btnOption5.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnOption5.Font = new System.Drawing.Font("Papyrus", 18F, System.Drawing.FontStyle.Bold);
            this.btnOption5.Location = new System.Drawing.Point(202, 202);
            this.btnOption5.Name = "btnOption5";
            this.btnOption5.Size = new System.Drawing.Size(193, 193);
            this.btnOption5.TabIndex = 30;
            this.btnOption5.UseCompatibleTextRendering = true;
            this.btnOption5.UseVisualStyleBackColor = false;
            this.btnOption5.Click += new System.EventHandler(this.GameButtonOption_Click);
            this.btnOption5.MouseClick += new System.Windows.Forms.MouseEventHandler(this.GameButtonOption_Click);
            // 
            // btnOption3
            // 
            this.btnOption3.AutoSize = true;
            this.btnOption3.BackColor = System.Drawing.Color.Transparent;
            this.btnOption3.BackgroundImage = global::Tic_Tac_Toe.Properties.Resources.question_mark;
            this.btnOption3.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnOption3.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnOption3.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.btnOption3.FlatAppearance.BorderSize = 0;
            this.btnOption3.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Transparent;
            this.btnOption3.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent;
            this.btnOption3.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnOption3.Font = new System.Drawing.Font("Papyrus", 18F, System.Drawing.FontStyle.Bold);
            this.btnOption3.Location = new System.Drawing.Point(401, 3);
            this.btnOption3.Name = "btnOption3";
            this.btnOption3.Size = new System.Drawing.Size(196, 193);
            this.btnOption3.TabIndex = 28;
            this.btnOption3.UseCompatibleTextRendering = true;
            this.btnOption3.UseVisualStyleBackColor = false;
            this.btnOption3.Click += new System.EventHandler(this.GameButtonOption_Click);
            this.btnOption3.MouseClick += new System.Windows.Forms.MouseEventHandler(this.GameButtonOption_Click);
            // 
            // btnOption2
            // 
            this.btnOption2.AutoSize = true;
            this.btnOption2.BackColor = System.Drawing.Color.Transparent;
            this.btnOption2.BackgroundImage = global::Tic_Tac_Toe.Properties.Resources.question_mark;
            this.btnOption2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnOption2.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnOption2.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.btnOption2.FlatAppearance.BorderSize = 0;
            this.btnOption2.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Transparent;
            this.btnOption2.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent;
            this.btnOption2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnOption2.Font = new System.Drawing.Font("Papyrus", 18F, System.Drawing.FontStyle.Bold);
            this.btnOption2.Location = new System.Drawing.Point(202, 3);
            this.btnOption2.Name = "btnOption2";
            this.btnOption2.Size = new System.Drawing.Size(193, 193);
            this.btnOption2.TabIndex = 27;
            this.btnOption2.UseCompatibleTextRendering = true;
            this.btnOption2.UseVisualStyleBackColor = false;
            this.btnOption2.Click += new System.EventHandler(this.GameButtonOption_Click);
            this.btnOption2.MouseClick += new System.Windows.Forms.MouseEventHandler(this.GameButtonOption_Click);
            // 
            // btnOption1
            // 
            this.btnOption1.AutoSize = true;
            this.btnOption1.BackgroundImage = global::Tic_Tac_Toe.Properties.Resources.question_mark;
            this.btnOption1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnOption1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnOption1.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.btnOption1.FlatAppearance.BorderSize = 0;
            this.btnOption1.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Transparent;
            this.btnOption1.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent;
            this.btnOption1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnOption1.Font = new System.Drawing.Font("Papyrus", 18F, System.Drawing.FontStyle.Bold);
            this.btnOption1.Location = new System.Drawing.Point(3, 3);
            this.btnOption1.Name = "btnOption1";
            this.btnOption1.Size = new System.Drawing.Size(193, 193);
            this.btnOption1.TabIndex = 26;
            this.btnOption1.UseCompatibleTextRendering = true;
            this.btnOption1.UseVisualStyleBackColor = false;
            this.btnOption1.Click += new System.EventHandler(this.GameButtonOption_Click);
            this.btnOption1.MouseClick += new System.Windows.Forms.MouseEventHandler(this.GameButtonOption_Click);
            // 
            // btnOption8
            // 
            this.btnOption8.AutoSize = true;
            this.btnOption8.BackColor = System.Drawing.Color.Transparent;
            this.btnOption8.BackgroundImage = global::Tic_Tac_Toe.Properties.Resources.question_mark;
            this.btnOption8.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnOption8.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnOption8.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.btnOption8.FlatAppearance.BorderSize = 0;
            this.btnOption8.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Transparent;
            this.btnOption8.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent;
            this.btnOption8.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnOption8.Font = new System.Drawing.Font("Papyrus", 18F, System.Drawing.FontStyle.Bold);
            this.btnOption8.Location = new System.Drawing.Point(202, 401);
            this.btnOption8.Name = "btnOption8";
            this.btnOption8.Size = new System.Drawing.Size(193, 196);
            this.btnOption8.TabIndex = 33;
            this.btnOption8.UseCompatibleTextRendering = true;
            this.btnOption8.UseVisualStyleBackColor = false;
            this.btnOption8.Click += new System.EventHandler(this.GameButtonOption_Click);
            this.btnOption8.MouseClick += new System.Windows.Forms.MouseEventHandler(this.GameButtonOption_Click);
            // 
            // btnOption4
            // 
            this.btnOption4.AutoSize = true;
            this.btnOption4.BackColor = System.Drawing.Color.Transparent;
            this.btnOption4.BackgroundImage = global::Tic_Tac_Toe.Properties.Resources.question_mark;
            this.btnOption4.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btnOption4.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnOption4.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.btnOption4.FlatAppearance.BorderSize = 0;
            this.btnOption4.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Transparent;
            this.btnOption4.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent;
            this.btnOption4.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnOption4.Font = new System.Drawing.Font("Papyrus", 18F, System.Drawing.FontStyle.Bold);
            this.btnOption4.Location = new System.Drawing.Point(3, 202);
            this.btnOption4.Name = "btnOption4";
            this.btnOption4.Size = new System.Drawing.Size(193, 193);
            this.btnOption4.TabIndex = 29;
            this.btnOption4.UseCompatibleTextRendering = true;
            this.btnOption4.UseVisualStyleBackColor = false;
            this.btnOption4.Click += new System.EventHandler(this.GameButtonOption_Click);
            this.btnOption4.MouseClick += new System.Windows.Forms.MouseEventHandler(this.GameButtonOption_Click);
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.WhiteSmoke;
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.flpPlayer2);
            this.panel1.Controls.Add(this.flpPlayer1);
            this.panel1.Controls.Add(this.btnNextRound);
            this.panel1.Controls.Add(this.lblRounds);
            this.panel1.Controls.Add(this.lblDraws);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.label7);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Controls.Add(this.lblCurrentTurn);
            this.panel1.Controls.Add(this.lblTargetWins);
            this.panel1.Controls.Add(this.btnExitMatch);
            this.panel1.Controls.Add(this.label4);
            this.panel1.Location = new System.Drawing.Point(33, 119);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(498, 439);
            this.panel1.TabIndex = 7;
            // 
            // flpPlayer2
            // 
            this.flpPlayer2.AutoSize = true;
            this.flpPlayer2.Controls.Add(this.lblPlayer2Name);
            this.flpPlayer2.Controls.Add(this.lblPlayer2Wins);
            this.flpPlayer2.Location = new System.Drawing.Point(9, 245);
            this.flpPlayer2.Name = "flpPlayer2";
            this.flpPlayer2.Size = new System.Drawing.Size(234, 58);
            this.flpPlayer2.TabIndex = 25;
            // 
            // lblPlayer2Name
            // 
            this.lblPlayer2Name.AutoSize = true;
            this.lblPlayer2Name.BackColor = System.Drawing.Color.Transparent;
            this.lblPlayer2Name.Font = new System.Drawing.Font("Papyrus", 22F);
            this.lblPlayer2Name.ForeColor = System.Drawing.Color.Black;
            this.lblPlayer2Name.Location = new System.Drawing.Point(3, 0);
            this.lblPlayer2Name.Name = "lblPlayer2Name";
            this.lblPlayer2Name.Size = new System.Drawing.Size(176, 53);
            this.lblPlayer2Name.TabIndex = 8;
            this.lblPlayer2Name.Text = "Player2 (O):";
            this.lblPlayer2Name.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblPlayer2Name.UseCompatibleTextRendering = true;
            // 
            // lblPlayer2Wins
            // 
            this.lblPlayer2Wins.AutoSize = true;
            this.lblPlayer2Wins.BackColor = System.Drawing.Color.Transparent;
            this.lblPlayer2Wins.Font = new System.Drawing.Font("Papyrus", 20F, System.Drawing.FontStyle.Bold);
            this.lblPlayer2Wins.ForeColor = System.Drawing.Color.Black;
            this.lblPlayer2Wins.Location = new System.Drawing.Point(185, 0);
            this.lblPlayer2Wins.Name = "lblPlayer2Wins";
            this.lblPlayer2Wins.Size = new System.Drawing.Size(26, 49);
            this.lblPlayer2Wins.TabIndex = 18;
            this.lblPlayer2Wins.Text = "6";
            this.lblPlayer2Wins.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblPlayer2Wins.UseCompatibleTextRendering = true;
            // 
            // flpPlayer1
            // 
            this.flpPlayer1.AutoSize = true;
            this.flpPlayer1.Controls.Add(this.lblPlayer1Name);
            this.flpPlayer1.Controls.Add(this.lblPlayer1Wins);
            this.flpPlayer1.Location = new System.Drawing.Point(9, 185);
            this.flpPlayer1.Name = "flpPlayer1";
            this.flpPlayer1.Size = new System.Drawing.Size(228, 58);
            this.flpPlayer1.TabIndex = 24;
            // 
            // lblPlayer1Name
            // 
            this.lblPlayer1Name.AutoSize = true;
            this.lblPlayer1Name.BackColor = System.Drawing.Color.Transparent;
            this.lblPlayer1Name.Font = new System.Drawing.Font("Papyrus", 22F);
            this.lblPlayer1Name.ForeColor = System.Drawing.Color.Black;
            this.lblPlayer1Name.Location = new System.Drawing.Point(3, 0);
            this.lblPlayer1Name.Name = "lblPlayer1Name";
            this.lblPlayer1Name.Size = new System.Drawing.Size(166, 53);
            this.lblPlayer1Name.TabIndex = 15;
            this.lblPlayer1Name.Text = "Player1 (X):";
            this.lblPlayer1Name.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblPlayer1Name.UseCompatibleTextRendering = true;
            // 
            // lblPlayer1Wins
            // 
            this.lblPlayer1Wins.AutoSize = true;
            this.lblPlayer1Wins.BackColor = System.Drawing.Color.Transparent;
            this.lblPlayer1Wins.Font = new System.Drawing.Font("Papyrus", 20F, System.Drawing.FontStyle.Bold);
            this.lblPlayer1Wins.ForeColor = System.Drawing.Color.Black;
            this.lblPlayer1Wins.Location = new System.Drawing.Point(175, 0);
            this.lblPlayer1Wins.Name = "lblPlayer1Wins";
            this.lblPlayer1Wins.Size = new System.Drawing.Size(26, 49);
            this.lblPlayer1Wins.TabIndex = 11;
            this.lblPlayer1Wins.Text = "5";
            this.lblPlayer1Wins.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblPlayer1Wins.UseCompatibleTextRendering = true;
            // 
            // btnNextRound
            // 
            this.btnNextRound.AutoSize = true;
            this.btnNextRound.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.btnNextRound.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnNextRound.Enabled = false;
            this.btnNextRound.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.btnNextRound.FlatAppearance.BorderSize = 3;
            this.btnNextRound.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gray;
            this.btnNextRound.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Silver;
            this.btnNextRound.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnNextRound.Font = new System.Drawing.Font("Papyrus", 16F, System.Drawing.FontStyle.Bold);
            this.btnNextRound.Location = new System.Drawing.Point(336, 168);
            this.btnNextRound.Name = "btnNextRound";
            this.btnNextRound.Size = new System.Drawing.Size(140, 90);
            this.btnNextRound.TabIndex = 23;
            this.btnNextRound.Text = "Next\r\nRound";
            this.btnNextRound.UseCompatibleTextRendering = true;
            this.btnNextRound.UseVisualStyleBackColor = false;
            this.btnNextRound.Click += new System.EventHandler(this.btnNextRound_Click);
            // 
            // lblRounds
            // 
            this.lblRounds.AutoSize = true;
            this.lblRounds.BackColor = System.Drawing.Color.Transparent;
            this.lblRounds.Font = new System.Drawing.Font("Papyrus", 20F, System.Drawing.FontStyle.Bold);
            this.lblRounds.ForeColor = System.Drawing.Color.Black;
            this.lblRounds.Location = new System.Drawing.Point(123, 365);
            this.lblRounds.Name = "lblRounds";
            this.lblRounds.Size = new System.Drawing.Size(42, 49);
            this.lblRounds.TabIndex = 22;
            this.lblRounds.Text = "16";
            this.lblRounds.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblRounds.UseCompatibleTextRendering = true;
            // 
            // lblDraws
            // 
            this.lblDraws.AutoSize = true;
            this.lblDraws.BackColor = System.Drawing.Color.Transparent;
            this.lblDraws.Font = new System.Drawing.Font("Papyrus", 20F, System.Drawing.FontStyle.Bold);
            this.lblDraws.ForeColor = System.Drawing.Color.Black;
            this.lblDraws.Location = new System.Drawing.Point(123, 305);
            this.lblDraws.Name = "lblDraws";
            this.lblDraws.Size = new System.Drawing.Size(26, 49);
            this.lblDraws.TabIndex = 21;
            this.lblDraws.Text = "6";
            this.lblDraws.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblDraws.UseCompatibleTextRendering = true;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.Transparent;
            this.label2.Font = new System.Drawing.Font("Papyrus", 22F);
            this.label2.ForeColor = System.Drawing.Color.Black;
            this.label2.Location = new System.Drawing.Point(9, 125);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(113, 53);
            this.label2.TabIndex = 20;
            this.label2.Text = "Target:";
            this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.label2.UseCompatibleTextRendering = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Font = new System.Drawing.Font("Papyrus", 22F);
            this.label1.ForeColor = System.Drawing.Color.Black;
            this.label1.Location = new System.Drawing.Point(9, 65);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(201, 53);
            this.label1.TabIndex = 19;
            this.label1.Text = "Current Turn:";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.label1.UseCompatibleTextRendering = true;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.BackColor = System.Drawing.Color.Transparent;
            this.label7.Font = new System.Drawing.Font("Papyrus", 22F);
            this.label7.ForeColor = System.Drawing.Color.Black;
            this.label7.Location = new System.Drawing.Point(9, 365);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(106, 53);
            this.label7.TabIndex = 17;
            this.label7.Text = "Round:";
            this.label7.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.label7.UseCompatibleTextRendering = true;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.Color.Transparent;
            this.label3.Font = new System.Drawing.Font("Papyrus", 22F);
            this.label3.ForeColor = System.Drawing.Color.Black;
            this.label3.Location = new System.Drawing.Point(9, 305);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(104, 53);
            this.label3.TabIndex = 16;
            this.label3.Text = "Draws:";
            this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.label3.UseCompatibleTextRendering = true;
            // 
            // lblCurrentTurn
            // 
            this.lblCurrentTurn.AutoSize = true;
            this.lblCurrentTurn.BackColor = System.Drawing.Color.Transparent;
            this.lblCurrentTurn.Font = new System.Drawing.Font("Papyrus", 20F, System.Drawing.FontStyle.Bold);
            this.lblCurrentTurn.ForeColor = System.Drawing.Color.Black;
            this.lblCurrentTurn.Location = new System.Drawing.Point(220, 65);
            this.lblCurrentTurn.Name = "lblCurrentTurn";
            this.lblCurrentTurn.Size = new System.Drawing.Size(236, 49);
            this.lblCurrentTurn.TabIndex = 13;
            this.lblCurrentTurn.Text = "Abdelrahman You";
            this.lblCurrentTurn.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.lblCurrentTurn.UseCompatibleTextRendering = true;
            // 
            // lblTargetWins
            // 
            this.lblTargetWins.AutoSize = true;
            this.lblTargetWins.BackColor = System.Drawing.Color.Transparent;
            this.lblTargetWins.Font = new System.Drawing.Font("Papyrus", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTargetWins.ForeColor = System.Drawing.Color.Black;
            this.lblTargetWins.Location = new System.Drawing.Point(123, 125);
            this.lblTargetWins.Name = "lblTargetWins";
            this.lblTargetWins.Size = new System.Drawing.Size(50, 58);
            this.lblTargetWins.TabIndex = 6;
            this.lblTargetWins.Text = "10";
            this.lblTargetWins.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblTargetWins.UseCompatibleTextRendering = true;
            // 
            // btnExitMatch
            // 
            this.btnExitMatch.AutoSize = true;
            this.btnExitMatch.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.btnExitMatch.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnExitMatch.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.btnExitMatch.FlatAppearance.BorderSize = 3;
            this.btnExitMatch.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gray;
            this.btnExitMatch.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Silver;
            this.btnExitMatch.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnExitMatch.Font = new System.Drawing.Font("Papyrus", 16F, System.Drawing.FontStyle.Bold);
            this.btnExitMatch.Location = new System.Drawing.Point(336, 305);
            this.btnExitMatch.Name = "btnExitMatch";
            this.btnExitMatch.Size = new System.Drawing.Size(140, 90);
            this.btnExitMatch.TabIndex = 5;
            this.btnExitMatch.Text = "Abandon\r\nMatch";
            this.btnExitMatch.UseCompatibleTextRendering = true;
            this.btnExitMatch.UseVisualStyleBackColor = false;
            this.btnExitMatch.Click += new System.EventHandler(this.btnExitMatch_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.Color.Transparent;
            this.label4.Font = new System.Drawing.Font("Segoe UI Black", 36F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.Color.Black;
            this.label4.Location = new System.Drawing.Point(46, -1);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(401, 65);
            this.label4.TabIndex = 3;
            this.label4.Text = "TIC-TAC-CLASH";
            this.label4.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // frm_Arena
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::Tic_Tac_Toe.Properties.Resources.TicTacToe_bg;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(1219, 684);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.tlpXOArenaView);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimumSize = new System.Drawing.Size(800, 600);
            this.Name = "frm_Arena";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "TIC-TAC-CLASH";
            this.tlpXOArenaView.ResumeLayout(false);
            this.tlpXOArenaView.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.flpPlayer2.ResumeLayout(false);
            this.flpPlayer2.PerformLayout();
            this.flpPlayer1.ResumeLayout(false);
            this.flpPlayer1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.TableLayoutPanel tlpXOArenaView;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label lblPlayer1Name;
        private System.Windows.Forms.Label lblCurrentTurn;
        private System.Windows.Forms.Label lblPlayer1Wins;
        private System.Windows.Forms.Label lblPlayer2Name;
        private System.Windows.Forms.Label lblTargetWins;
        private System.Windows.Forms.Button btnExitMatch;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label lblPlayer2Wins;
        private System.Windows.Forms.Label lblRounds;
        private System.Windows.Forms.Label lblDraws;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnNextRound;
        private System.Windows.Forms.FlowLayoutPanel flpPlayer2;
        private System.Windows.Forms.FlowLayoutPanel flpPlayer1;
        private System.Windows.Forms.Button btnOption1;
        private System.Windows.Forms.Button btnOption9;
        private System.Windows.Forms.Button btnOption8;
        private System.Windows.Forms.Button btnOption7;
        private System.Windows.Forms.Button btnOption6;
        private System.Windows.Forms.Button btnOption5;
        private System.Windows.Forms.Button btnOption4;
        private System.Windows.Forms.Button btnOption3;
        private System.Windows.Forms.Button btnOption2;
    }
}