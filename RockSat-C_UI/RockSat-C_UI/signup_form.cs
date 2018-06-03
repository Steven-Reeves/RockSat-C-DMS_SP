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
    public partial class signup_form : Form
    {
        public signup_form()
        {
            InitializeComponent();
        }

        private void back_btn_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void enter_btn_Click(object sender, EventArgs e)
        {
            string load_message = "Login functionality implemented in v2";
            MessageBox.Show(load_message, "Coming Soon", MessageBoxButtons.OK);
        }
    }
}
