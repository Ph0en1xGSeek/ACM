using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace CourseSystem
{
    /// <summary>
    /// ScoreWindow.xaml 的交互逻辑
    /// </summary>
    public partial class ScoreWindow : Window
    {
        public ScoreWindow()
        {
            InitializeComponent();
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            textBlock1.Text = "";
            if (textBox.Text.Length == 0 || textBox_Copy.Text.Length == 0)
            {
                MessageBox.Show(" 学号和课程编号不能为空！");
                return;
            }

            try
            {
                MySqlCommand cmd = MainWindow.conn.CreateCommand();
                cmd.CommandText = "select password from student where sid = \'" + textBox.Text + "\'";
                MySqlDataAdapter adap = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                adap.Fill(ds);
                DataRow r = ds.Tables[0].Rows[0];
                string password = r["password"].ToString();
                if(password != passwordBox.Password)
                {
                   MessageBox.Show("密码错误");
                    return;
                }
            }
            catch (MySqlException ex)
            {
                textBlock1.Text = ex.Message;
            }
            catch (Exception)
            {
                textBlock1.Text = " Wrong";
            }

            try
            {
                MySqlCommand cmd = MainWindow.conn.CreateCommand();
                cmd.CommandText = "select score from info where sid = \'" + textBox.Text + "\' and cid = \'" + textBox_Copy.Text + "\'";
                MySqlDataAdapter adap = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                adap.Fill(ds);
                int total = ds.Tables[0].Rows.Count;
                if (total != 0)
                {
                    DataRow r = ds.Tables[0].Rows[0];
                    try
                    {
                        double score = double.Parse(r["score"].ToString());
                        textBlock1.Text = " 得分：";
                        textBlock1.Text += r["score"].ToString();
                    }
                    catch
                    {
                        textBlock1.Text = "分数暂未公布";
                    }
                }
                else
                    textBlock1.Text = " 无记录";
            }
            catch (MySqlException ex)
            {
                textBlock1.Text = ex.Message;
            }
            catch (Exception)
            {
                textBlock1.Text = " Wrong";
            }
        }
    }
}
