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
using Microsoft.VisualBasic;

namespace RockSat_C_UI
{

    public partial class data_form : Form
    {
        string path = "";
        string filename = "";
        string txtContents;

        public data_form()
        {
            InitializeComponent();
            // Currently loads from current directory
            path = Directory.GetCurrentDirectory();
            PopulateListBox(listBox1, path, "*.csv");
            PopulateListBox(listBox1, path, "*.txt");
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            // Choose file to import
            filename = listBox1.SelectedItem.ToString();

        }

        private void enter_btn_Click(object sender, EventArgs e)
        {
            if (filename == "")
            {
                string filename_message = "No file chosen!";
                MessageBox.Show(filename_message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                // Check which filetype and open window accordingly
                string filetype = filename.Split('.')[1];
                if (filetype == "txt" || filetype == "csv")
                {
                    // Hide old buttons
                    listBox1.Hide();
                    preloaded_label.Hide();
                    enter_btn.Hide();

                    if (filetype == "txt")
                    {

                        // Load new screen
                        textBox1.Show();
                        // Load contents of txt file
                        System.IO.StreamReader myFile = new System.IO.StreamReader(path + "\\" + filename);
                        txtContents = myFile.ReadToEnd();


                        // Diplay contents
                        textBox1.Text = txtContents;

                        myFile.Close();
                    }
                    else
                    {
                        string response = Microsoft.VisualBasic.Interaction.InputBox("Enter number of columns", "Column Number", "3", 5, 5);
                        int colNum;
                        if (Int32.TryParse(response, out colNum))
                        {
                            ImportFile(colNum);
                            // Load new screen
                            dataGridView1.Show();
                        }
                        else
                        {
                            string column_message = "Invalid Column Input";
                            MessageBox.Show(column_message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        } 
                    }
                }
                else
                {
                    string filetype_message = "Filetype unsupported";
                    MessageBox.Show(filetype_message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
 
        }

        private void back_btn_Click(object sender, EventArgs e)
        {
            // Go Back
            Close();
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

        private bool ImportFile(int colNum)
        {
            try
            {
                String[] splitLine;

                // clear the grid view
                dataGridView1.ColumnCount = colNum;
                dataGridView1.Rows.Clear();

                if (System.IO.File.Exists(filename))
                {
                    System.IO.StreamReader objReader = new System.IO.StreamReader(filename);

                    do
                    {
                        string textLine = objReader.ReadLine();
                        if (textLine != "")
                        {
                            splitLine = textLine.Split(',');
                            if (splitLine[0] != "" || splitLine[1] != "")
                            {
                                dataGridView1.Rows.Add(splitLine);
                            }
                        }
                    } while (objReader.Peek() != -1);
                }
                return true;
            }
            catch (Exception ex)
            {
                if (ex.Message.Contains("The process cannot access the file"))
                {
                    MessageBox.Show("The file you are importing is open.", "Import Account", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
                else
                {
                    MessageBox.Show(ex.Message);
                }
                return false;
            }

        }
    }
}
