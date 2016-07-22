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
    /// StudentWindow.xaml 的交互逻辑
    /// </summary>
    public partial class StudentWindow : Window
    {
        public StudentWindow()
        {
            InitializeComponent();
        }

        private void button_Click(object sender, RoutedEventArgs e)//学生信息
        {
            textBlockShow.Text = "";
            if (textBox.Text.Length == 0)
            {
                textBlockShow.Text = "学号不能为空！";
                return;
            }
            try
            {
                MySqlCommand cmd = MainWindow.conn.CreateCommand();
                cmd.CommandText = "select * from student where sid = \'" + textBox.Text + "\'";
                MySqlDataAdapter adap = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                adap.Fill(ds);
                int total = ds.Tables[0].Rows.Count;
                if (total != 0)
                {
                    DataRow r = ds.Tables[0].Rows[0];
                    textBlockShow.Text += "学号：" + r["sid"];
                    textBlockShow.Text += "\n姓名：" + r["name"];
                    textBlockShow.Text += "\n性别：" + r["sex"];
                    textBlockShow.Text += "\n入学年龄：" + r["enrolage"];
                    textBlockShow.Text += "\n入学年份：" + r["enrolyear"];
                    textBlockShow.Text += "\n班级：" + r["class"];
                }
                else
                    textBlockShow.Text = "查询不到此学生！";
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

        private void button_Copy_Click(object sender, RoutedEventArgs e)//学生选课情况
        {
            textBlockShow.Text = "";
            if (textBox.Text.Length == 0)
            {
                textBlockShow.Text = "学号不能为空！";
                return;
            }
            try
            {
                MySqlCommand cmd = MainWindow.conn.CreateCommand();
                cmd.CommandText = "select cid, score from info where sid = \'" + textBox.Text + "\' order by score";
                MySqlDataAdapter adap = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                adap.Fill(ds);
                int total = ds.Tables[0].Rows.Count;
                textBlockShow.Text += "已选课程数：" + total.ToString() + "\n";
                if (total > 0)
                {
                    textBlockShow.Text += String.Format("\n{0,-12}{1,-10}{2,7}", "课程编号", "得分", "课程名称");
                }
                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    string cid = r["cid"].ToString();
                    string score = r["score"].ToString();
                    if (score.Length == 0) score = "NA"; 
                    cmd.CommandText = "select cname from course where cid = \'" + cid + "\'";
                    adap = new MySqlDataAdapter(cmd);
                    DataSet ds1 = new DataSet();
                    adap.Fill(ds1);
                    DataRow r1 = ds1.Tables[0].Rows[0];
                    string name = r1["cname"].ToString();
                    textBlockShow.Text += String.Format("\n{0,-15}{1,-5}\t{2}", cid, score, name);

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

        private void button_Copy1_Click(object sender, RoutedEventArgs e)//加权平均
        {
            textBlockShow.Text = "";
            if (textBox.Text.Length == 0)
            {
                textBlockShow.Text = "学号不能为空！";
                return;
            }
            try
            {
                MySqlCommand cmd = MainWindow.conn.CreateCommand();
                cmd.CommandText = "select cid, score from info where sid = \'" + textBox.Text + "\'";
                MySqlDataAdapter adap = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                adap.Fill(ds);
                int total = ds.Tables[0].Rows.Count;
                if(total != 0)
                {
                    ChartWindow cw = new ChartWindow();
                    double[] a = { 0, 0, 0, 0, 0, 0 };//六种等级的个数
                    total = 0;
                    double sum = 0;
                    double div = 0;
                    foreach(DataRow r in ds.Tables[0].Rows)
                    {
                        string cid = r["cid"].ToString();
                        try
                        {
                            double score = double.Parse(r["score"].ToString());
                            cmd.CommandText = "select credit from course where cid = \'" + cid + "\'";
                            adap = new MySqlDataAdapter(cmd);
                            DataSet ds1 = new DataSet();
                            adap.Fill(ds1);
                            DataRow r1 = ds1.Tables[0].Rows[0];
                            double credit = double.Parse(r1["credit"].ToString());
                            if (score < 60) a[0]++;
                            else if (score < 70) a[1]++;
                            else if (score < 80) a[2]++;
                            else if (score < 90) a[3]++;
                            else if (score < 100) a[4]++;
                            else if (score == 100) a[5]++;
                            sum += score * credit;
                            div += credit;
                            total++;
                        }
                        catch
                        {
                            //什么也不做,跳过该次循环
                        }
                        
                    }
                    for (int i = 0; i < 6; i++)
                    {
                        cw.chart.Series[0].DataPoints[i].YValue = (a[i] / total) * 100.0;
                    }
                    
                    if(div != 0)
                    {
                        sum /= div;
                        cw.textBlock.Text = "课程数：" + total.ToString() + "\n加权平均：" + sum.ToString();
                    }
                    else
                    {
                        cw.textBlock.Text = "课程数：" + total.ToString()+ "总分：" + sum.ToString() + "\n总学分为0";       //div 0 error
                    }
                    cw.Show();
                }
                else
                {
                    textBlockShow.Text = "无记录";
                }
            }
            catch (MySqlException ex)
            {
                textBlockShow.Text = ex.Message;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
