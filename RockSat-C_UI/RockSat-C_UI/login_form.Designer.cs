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
            this.email_label = new System.Windows.Forms.Label();
            this.pass_label = new System.Windows.Forms.Label();
            this.enter_btn = new System.Windows.Forms.Button();
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
            this.back_btn.Click += new System.EventHandler(this.back_btn_Click);
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
            // email_label
            // 
            this.email_label.AutoSize = true;
            this.email_label.Location = new System.Drawing.Point(132, 130);
            this.email_label.Name = "email_label";
            this.email_label.Size = new System.Drawing.Size(76, 13);
            this.email_label.TabIndex = 4;
            this.email_label.Text = "Email Address:";
            // 
            // pass_label
            // 
            this.pass_label.AutoSize = true;
            this.pass_label.Location = new System.Drawing.Point(132, 260);
            this.pass_label.Name = "pass_label";
            this.pass_label.Size = new System.Drawing.Size(56, 13);
            this.pass_label.TabIndex = 5;
            this.pass_label.Text = "Password:";
            // 
            // enter_btn
            // 
            this.enter_btn.Location = new System.Drawing.Point(395, 370);
            this.enter_btn.Name = "enter_btn";
            this.enter_btn.Size = new System.Drawing.Size(120, 40);
            this.enter_btn.TabIndex = 6;
            this.enter_btn.Text = "Enter";
            this.enter_btn.UseVisualStyleBackColor = true;
            // 
            // login_form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(527, 422);
            this.Controls.Add(this.enter_btn);
            this.Controls.Add(this.pass_label);
            this.Controls.Add(this.email_label);
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
        private System.Windows.Forms.Label email_label;
        private System.Windows.Forms.Label pass_label;
        private System.Windows.Forms.Button enter_btn;
    }
}