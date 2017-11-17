namespace RockSat_C_UI
{
    partial class data_form
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
            this.csv_txtBox = new System.Windows.Forms.TextBox();
            this.csv_label = new System.Windows.Forms.Label();
            this.preloaded_label = new System.Windows.Forms.Label();
            this.enter_btn = new System.Windows.Forms.Button();
            this.listBox1 = new System.Windows.Forms.ListBox();
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
            // csv_txtBox
            // 
            this.csv_txtBox.Location = new System.Drawing.Point(135, 114);
            this.csv_txtBox.Name = "csv_txtBox";
            this.csv_txtBox.Size = new System.Drawing.Size(278, 20);
            this.csv_txtBox.TabIndex = 2;
            // 
            // csv_label
            // 
            this.csv_label.AutoSize = true;
            this.csv_label.Location = new System.Drawing.Point(132, 82);
            this.csv_label.Name = "csv_label";
            this.csv_label.Size = new System.Drawing.Size(117, 13);
            this.csv_label.TabIndex = 4;
            this.csv_label.Text = "Enter .csv file to import:";
            // 
            // preloaded_label
            // 
            this.preloaded_label.AutoSize = true;
            this.preloaded_label.Location = new System.Drawing.Point(132, 188);
            this.preloaded_label.Name = "preloaded_label";
            this.preloaded_label.Size = new System.Drawing.Size(132, 13);
            this.preloaded_label.TabIndex = 5;
            this.preloaded_label.Text = "Or choose from preloaded:";
            // 
            // enter_btn
            // 
            this.enter_btn.Location = new System.Drawing.Point(395, 370);
            this.enter_btn.Name = "enter_btn";
            this.enter_btn.Size = new System.Drawing.Size(120, 40);
            this.enter_btn.TabIndex = 6;
            this.enter_btn.Text = "Enter";
            this.enter_btn.UseVisualStyleBackColor = true;
            this.enter_btn.Click += new System.EventHandler(this.enter_btn_Click);
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Location = new System.Drawing.Point(135, 218);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(278, 134);
            this.listBox1.TabIndex = 7;
            this.listBox1.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            // 
            // data_form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(527, 422);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.enter_btn);
            this.Controls.Add(this.preloaded_label);
            this.Controls.Add(this.csv_label);
            this.Controls.Add(this.csv_txtBox);
            this.Controls.Add(this.back_btn);
            this.Name = "data_form";
            this.Text = "Data entry";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button back_btn;
        private System.Windows.Forms.TextBox csv_txtBox;
        private System.Windows.Forms.Label csv_label;
        private System.Windows.Forms.Label preloaded_label;
        private System.Windows.Forms.Button enter_btn;
        private System.Windows.Forms.ListBox listBox1;
    }
}