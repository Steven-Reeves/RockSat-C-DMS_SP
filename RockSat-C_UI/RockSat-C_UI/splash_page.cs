using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

// TODO: Make a static instance of this for all forms to use.

namespace RockSat_C_UI
{
    public partial class splash_page : Form
    {
        public splash_page()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        // Quick start
        private void button1_Click(object sender, EventArgs e)
        {
            welcome_page welcome = new welcome_page();
            //welcome.Show();
            this.Hide();
            welcome.ShowDialog();
            this.Show();
        }

        // Signup button
        private void button3_Click(object sender, EventArgs e)
        {
            signup_form signup = new signup_form();
            signup.Show();
        }
        
        // Login button
        private void button2_Click(object sender, EventArgs e)
        {
            login_form login = new login_form();
            login.Show();
        }
    }
}
