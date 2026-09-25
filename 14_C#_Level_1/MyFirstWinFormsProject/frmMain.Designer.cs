namespace MyFirstWinFormsProject
{
    partial class frmMain
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
            this.btnShowPart1 = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.btnShowDialogPart1 = new System.Windows.Forms.Button();
            this.btnShowMassage = new System.Windows.Forms.Button();
            this.btnShowMassageWithTitle = new System.Windows.Forms.Button();
            this.btnShowMassageWithTitleAndButtons = new System.Windows.Forms.Button();
            this.btnShowMassageWithTitleAndButtonsAndImage = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.btnShowCheckBoxForm = new System.Windows.Forms.Button();
            this.btnShowPictureBox = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnShowPart1
            // 
            this.btnShowPart1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnShowPart1.Location = new System.Drawing.Point(179, 156);
            this.btnShowPart1.Name = "btnShowPart1";
            this.btnShowPart1.Size = new System.Drawing.Size(276, 98);
            this.btnShowPart1.TabIndex = 0;
            this.btnShowPart1.Text = "Show Form 1";
            this.btnShowPart1.UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("MV Boli", 48F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(249, 15);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(366, 85);
            this.label3.TabIndex = 14;
            this.label3.Text = "Main Form";
            // 
            // btnShowDialogPart1
            // 
            this.btnShowDialogPart1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnShowDialogPart1.Location = new System.Drawing.Point(504, 156);
            this.btnShowDialogPart1.Name = "btnShowDialogPart1";
            this.btnShowDialogPart1.Size = new System.Drawing.Size(276, 98);
            this.btnShowDialogPart1.TabIndex = 15;
            this.btnShowDialogPart1.Text = "Show Form 1 as Dialog ";
            this.btnShowDialogPart1.UseVisualStyleBackColor = true;
            // 
            // btnShowMassage
            // 
            this.btnShowMassage.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnShowMassage.Location = new System.Drawing.Point(504, 270);
            this.btnShowMassage.Name = "btnShowMassage";
            this.btnShowMassage.Size = new System.Drawing.Size(276, 98);
            this.btnShowMassage.TabIndex = 16;
            this.btnShowMassage.Text = "Show MassageBox";
            this.btnShowMassage.UseVisualStyleBackColor = true;
            this.btnShowMassage.Click += new System.EventHandler(this.btnShowMassage_Click);
            // 
            // btnShowMassageWithTitle
            // 
            this.btnShowMassageWithTitle.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnShowMassageWithTitle.Location = new System.Drawing.Point(179, 380);
            this.btnShowMassageWithTitle.Name = "btnShowMassageWithTitle";
            this.btnShowMassageWithTitle.Size = new System.Drawing.Size(276, 98);
            this.btnShowMassageWithTitle.TabIndex = 17;
            this.btnShowMassageWithTitle.Text = "Show MassageBox and Title";
            this.btnShowMassageWithTitle.UseVisualStyleBackColor = true;
            this.btnShowMassageWithTitle.Click += new System.EventHandler(this.btnShowMassageWithTitle_Click);
            // 
            // btnShowMassageWithTitleAndButtons
            // 
            this.btnShowMassageWithTitleAndButtons.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnShowMassageWithTitleAndButtons.Location = new System.Drawing.Point(504, 380);
            this.btnShowMassageWithTitleAndButtons.Name = "btnShowMassageWithTitleAndButtons";
            this.btnShowMassageWithTitleAndButtons.Size = new System.Drawing.Size(276, 98);
            this.btnShowMassageWithTitleAndButtons.TabIndex = 18;
            this.btnShowMassageWithTitleAndButtons.Text = "Show MassageBox and Title and Buttons";
            this.btnShowMassageWithTitleAndButtons.UseVisualStyleBackColor = true;
            this.btnShowMassageWithTitleAndButtons.Click += new System.EventHandler(this.btnShowMassageWithTitleAndButtons_Click);
            // 
            // btnShowMassageWithTitleAndButtonsAndImage
            // 
            this.btnShowMassageWithTitleAndButtonsAndImage.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnShowMassageWithTitleAndButtonsAndImage.Location = new System.Drawing.Point(179, 495);
            this.btnShowMassageWithTitleAndButtonsAndImage.Name = "btnShowMassageWithTitleAndButtonsAndImage";
            this.btnShowMassageWithTitleAndButtonsAndImage.Size = new System.Drawing.Size(276, 98);
            this.btnShowMassageWithTitleAndButtonsAndImage.TabIndex = 19;
            this.btnShowMassageWithTitleAndButtonsAndImage.Text = "Show MassageBox and Title and Buttons and Images";
            this.btnShowMassageWithTitleAndButtonsAndImage.UseVisualStyleBackColor = true;
            this.btnShowMassageWithTitleAndButtonsAndImage.Click += new System.EventHandler(this.btnShowMassageWithTitleAndButtonsAndImage_Click);
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.Location = new System.Drawing.Point(504, 495);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(276, 98);
            this.button1.TabIndex = 20;
            this.button1.Text = "Show MassageBox and Title and Buttons and Images and Default Button";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // btnShowCheckBoxForm
            // 
            this.btnShowCheckBoxForm.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnShowCheckBoxForm.Location = new System.Drawing.Point(179, 270);
            this.btnShowCheckBoxForm.Name = "btnShowCheckBoxForm";
            this.btnShowCheckBoxForm.Size = new System.Drawing.Size(276, 98);
            this.btnShowCheckBoxForm.TabIndex = 21;
            this.btnShowCheckBoxForm.Text = "Show Check Box Form";
            this.btnShowCheckBoxForm.UseVisualStyleBackColor = true;
            this.btnShowCheckBoxForm.Click += new System.EventHandler(this.btnShowCheckBoxForm_Click);
            // 
            // btnShowPictureBox
            // 
            this.btnShowPictureBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnShowPictureBox.Location = new System.Drawing.Point(826, 156);
            this.btnShowPictureBox.Name = "btnShowPictureBox";
            this.btnShowPictureBox.Size = new System.Drawing.Size(276, 98);
            this.btnShowPictureBox.TabIndex = 22;
            this.btnShowPictureBox.Text = "Show PictureBox Form";
            this.btnShowPictureBox.UseVisualStyleBackColor = true;
            this.btnShowPictureBox.Click += new System.EventHandler(this.btnShowPictureBox_Click);
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1236, 626);
            this.Controls.Add(this.btnShowPictureBox);
            this.Controls.Add(this.btnShowCheckBoxForm);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.btnShowMassageWithTitleAndButtonsAndImage);
            this.Controls.Add(this.btnShowMassageWithTitleAndButtons);
            this.Controls.Add(this.btnShowMassageWithTitle);
            this.Controls.Add(this.btnShowMassage);
            this.Controls.Add(this.btnShowDialogPart1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.btnShowPart1);
            this.Name = "frmMain";
            this.Text = "Main Form";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnShowPart1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button btnShowDialogPart1;
        private System.Windows.Forms.Button btnShowMassage;
        private System.Windows.Forms.Button btnShowMassageWithTitle;
        private System.Windows.Forms.Button btnShowMassageWithTitleAndButtons;
        private System.Windows.Forms.Button btnShowMassageWithTitleAndButtonsAndImage;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button btnShowCheckBoxForm;
        private System.Windows.Forms.Button btnShowPictureBox;
    }
}