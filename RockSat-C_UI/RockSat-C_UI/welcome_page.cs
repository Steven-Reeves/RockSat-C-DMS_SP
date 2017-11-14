using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RockSat_C_UI
{
    public partial class welcome_page : Form
    {
        public welcome_page()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
 
        }

        // Back button
        private void back_btn_Click(object sender, EventArgs e)
        {
            // Go back
        }

        // logout button
        private void button3_Click(object sender, EventArgs e)
        {
            // Go back

            // logout popup
            string logout_message = " You've been logged out!";
            MessageBox.Show(logout_message, "Logout", MessageBoxButtons.OK);
        }

        private void newGraph_btn_Click(object sender, EventArgs e)
        {
            data_form data = new data_form();
            data.Show();
        }
    }
}
