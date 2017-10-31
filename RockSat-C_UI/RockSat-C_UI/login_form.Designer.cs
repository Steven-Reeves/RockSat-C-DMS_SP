namespace RockSat_C_UI
{
    partial class login_form
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
            this.back_btn = new System.Windows.Forms.Button();
            this.email_txtBox = new System.Windows.Forms.TextBox();
            this.password_txtBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // back_btn
            // 
            this.back_btn.Location = new System.Drawing.Point(12, 12);
            this.back_btn.Name = "back_btn";
            this.back_btn.Size = new System.Drawing.Size(120, 40);
            this.back_btn.TabIndex = 1;
            this.back_btn.Text = "Back";
            this.back_btn.UseVisualStyleBackColor = true;
            // 
            // email_txtBox
            // 
            this.email_txtBox.Location = new System.Drawing.Point(135, 162);
            this.email_txtBox.Name = "email_txtBox";
            this.email_txtBox.Size = new System.Drawing.Size(278, 20);
            this.email_txtBox.TabIndex = 2;
            // 
            // password_txtBox
            // 
            this.password_txtBox.Location = new System.Drawing.Point(135, 293);
            this.password_txtBox.Name = "password_txtBox";
            this.password_txtBox.PasswordChar = '*';
            this.password_txtBox.Size = new System.Drawing.Size(278, 20);
            this.password_txtBox.TabIndex = 3;
            // 
            // login_form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(527, 422);
            this.Controls.Add(this.password_txtBox);
            this.Controls.Add(this.email_txtBox);
            this.Controls.Add(this.back_btn);
            this.Name = "login_form";
            this.Text = "Login";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button back_btn;
        private System.Windows.Forms.TextBox email_txtBox;
        private System.Windows.Forms.TextBox password_txtBox;
    }
}