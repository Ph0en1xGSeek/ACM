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
    /// CourseWindow.xaml 的交互逻辑
    /// </summary>
    public partial class CourseWindow : Window
    {
        public CourseWindow()
        {
            InitializeComponent();
        }

        private void button_Copy1_Click(object sender, RoutedEventArgs e)//图表
        {
            textBlockShow.Text = "";
            if(textBox.Text.Length == 0)
            {
                textBlockShow.Text = "课程编号不能为空！";
                return;
            }
            try
            {
                MySqlCommand cmd = MainWindow.conn.CreateCommand();
                cmd.CommandText = "select score from info where cid = \'" + textBox.Text + "\'";
                MySqlDataAdapter adap = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                adap.Fill(ds);
                double[] a = { 0,0,0,0,0,0};//六种等级的个数
                int total = 0;
                double sum = 0, avg = 0;
                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    try
                    {
                        double score = double.Parse(r["score"].ToString());
                        sum += score;
                        if (score < 60) a[0]++;
                        else if (score < 70) a[1]++;
                        else if (score < 80) a[2]++;
                        else if (score < 90) a[3]++;
                        else if (score < 100) a[4]++;
                        else if (score == 100) a[5]++;
                        total++;
                    }
                    catch
                    {
                        //不做什么，如果分数为空直接跳过
                    }
                    
                }
                ChartWindow cw = new ChartWindow();
                if(total != 0)
                {
                    avg = sum / total;
                    for (int i = 0; i < 6; i++)
                    {
                        cw.chart.Series[0].DataPoints[i].YValue = a[i]/total * 100.0;
                    }
                    cw.textBlock.Text = "选课人数（已完卷）：" + total.ToString();
                    cw.textBlock.Text += "\n平均分：" + avg.ToString();
                }
                else
                    cw.textBlock.Text = "选课人数（已完卷）：" + total.ToString();
                cw.ShowDialog();
            }
            catch (MySqlException ex)
            {
                textBlockShow.Text = ex.Message;
            }
            catch (Exception)
            {
                textBlockShow.Text = "Wrong";
            }
        }

        private void button_Click(object sender, RoutedEventArgs e)//课程信息
        {
            textBlockShow.Text = "";
            if (textBox.Text.Length == 0)
            {
                textBlockShow.Text = "课程编号不能为空！";
                return;
            }
            try
            {
                MySqlCommand cmd = MainWindow.conn.CreateCommand();
                cmd.CommandText = "select * from course where cid = \'" + textBox.Text + "\'";
                MySqlDataAdapter adap = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                adap.Fill(ds);
                int total = ds.Tables[0].Rows.Count;
                if (total != 0)
                {
                    DataRow r = ds.Tables[0].Rows[0];
                    textBlockShow.Text += "课程编号：" + r["cid"];
                    textBlockShow.Text += "\n课程名称：" + r["cname"];
                    textBlockShow.Text += "\n教师姓名：" + r["teacher"];
                    textBlockShow.Text += "\n学分：" + r["credit"];
                    textBlockShow.Text += "\n适合年级：" + r["suitage"];
                    textBlockShow.Text += "\n取消年份：" + r["cancelyear"];
                }
                else
                    textBlockShow.Text = "查询不到此课程！";
            }
            catch (MySqlException ex)
            {
                textBlockShow.Text = ex.Message;
            }
            catch (Exception)
            {
                textBlockShow.Text = "Wrong";
            }
        }

        private void button_Copy_Click(object sender, RoutedEventArgs e)//课程选课信息
        {
            textBlockShow.Text = "";
            if (textBox.Text.Length == 0)
            {
                textBlockShow.Text = "课程编号不能为空！";
                return;
            }
            try
            {
                MySqlCommand cmd = MainWindow.conn.CreateCommand();
                cmd.CommandText = "select sid, score from info where cid = \'" + textBox.Text + "\' order by sid asc";
                MySqlDataAdapter adap = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                adap.Fill(ds);
                int total = ds.Tables[0].Rows.Count;
                textBlockShow.Text += "选课人数：" + total.ToString() + "\n";
                if(total > 0)
                {
                    textBlockShow.Text += String.Format("\n{0,-15}    {1,-10}\t{2}", "学号", "得分", "姓名");
                }
                foreach(DataRow r in ds.Tables[0].Rows)
                {
                    string sid = r["sid"].ToString();
                    string score = r["score"].ToString();
                    cmd.CommandText = "select name from student where sid = \'" + sid + "\'";
                    adap = new MySqlDataAdapter(cmd);
                    DataSet ds1 = new DataSet();
                    adap.Fill(ds1);
                    DataRow r1 = ds1.Tables[0].Rows[0];
                    string name = r1["name"].ToString();
                    textBlockShow.Text += String.Format("\n{0,-15}{1,-5}\t{2}", sid, score, name);

                }
            }
            catch (MySqlException ex)
            {
                textBlockShow.Text = ex.Message;
            }
            catch (Exception)
            {
                textBlockShow.Text = "Wrong";
            }
        }
    }
}
