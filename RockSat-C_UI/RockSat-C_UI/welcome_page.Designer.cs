namespace RockSat_C_UI
{
    partial class welcome_page
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
            this.logout_btn = new System.Windows.Forms.Button();
            this.newGraph_btn = new System.Windows.Forms.Button();
            this.loadGraph_btn = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // back_btn
            // 
            this.back_btn.Location = new System.Drawing.Point(59, 33);
            this.back_btn.Name = "back_btn";
            this.back_btn.Size = new System.Drawing.Size(120, 40);
            this.back_btn.TabIndex = 0;
            this.back_btn.Text = "Back";
            this.back_btn.UseVisualStyleBackColor = true;
            this.back_btn.Click += new System.EventHandler(this.back_btn_Click);
            // 
            // logout_btn
            // 
            this.logout_btn.Location = new System.Drawing.Point(833, 33);
            this.logout_btn.Name = "logout_btn";
            this.logout_btn.Size = new System.Drawing.Size(120, 40);
            this.logout_btn.TabIndex = 2;
            this.logout_btn.Text = "Logout";
            this.logout_btn.UseVisualStyleBackColor = true;
            this.logout_btn.Click += new System.EventHandler(this.button3_Click);
            // 
            // newGraph_btn
            // 
            this.newGraph_btn.Location = new System.Drawing.Point(338, 158);
            this.newGraph_btn.Name = "newGraph_btn";
            this.newGraph_btn.Size = new System.Drawing.Size(291, 67);
            this.newGraph_btn.TabIndex = 3;
            this.newGraph_btn.Text = "New Graph";
            this.newGraph_btn.UseVisualStyleBackColor = true;
            this.newGraph_btn.Click += new System.EventHandler(this.newGraph_btn_Click);
            // 
            // loadGraph_btn
            // 
            this.loadGraph_btn.Location = new System.Drawing.Point(338, 302);
            this.loadGraph_btn.Name = "loadGraph_btn";
            this.loadGraph_btn.Size = new System.Drawing.Size(291, 67);
            this.loadGraph_btn.TabIndex = 4;
            this.loadGraph_btn.Text = "Load Graph";
            this.loadGraph_btn.UseVisualStyleBackColor = true;
            this.loadGraph_btn.Click += new System.EventHandler(this.loadGraph_btn_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackColor = System.Drawing.Color.AliceBlue;
            this.pictureBox1.Location = new System.Drawing.Point(59, 471);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(120, 82);
            this.pictureBox1.TabIndex = 5;
            this.pictureBox1.TabStop = false;
            // 
            // welcome_page
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkBlue;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.ClientSize = new System.Drawing.Size(994, 600);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.loadGraph_btn);
            this.Controls.Add(this.newGraph_btn);
            this.Controls.Add(this.logout_btn);
            this.Controls.Add(this.back_btn);
            this.DoubleBuffered = true;
            this.Name = "welcome_page";
            this.Text = "RockSat-C Data Manager";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button back_btn;
        private System.Windows.Forms.Button logout_btn;
        private System.Windows.Forms.Button newGraph_btn;
        private System.Windows.Forms.Button loadGraph_btn;
        private System.Windows.Forms.PictureBox pictureBox1;
    }
}

