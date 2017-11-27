using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RockSat_C_UI
{

    public partial class data_form : Form
    {
        public data_form()
        {
            InitializeComponent();
            // Currently loads from current directory
            string path = Directory.GetCurrentDirectory();
            PopulateListBox(listBox1, path, "*.csv");
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            // Choose .csv to import
             
        }

        private void enter_btn_Click(object sender, EventArgs e)
        {

        }

        private void back_btn_Click(object sender, EventArgs e)
        {
            // Go Back
            Close();
        }

        private void csv_txtBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void PopulateListBox(ListBox lsb, string Folder, string FileType)
        {
            DirectoryInfo dinfo = new DirectoryInfo(Folder);
            FileInfo[] Files = dinfo.GetFiles(FileType);
            foreach (FileInfo file in Files)
            {
                lsb.Items.Add(file.Name);
            }
        }
    }
}
