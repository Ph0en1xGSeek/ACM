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
    /// ClassWindow.xaml 的交互逻辑
    /// </summary>
    public partial class ClassWindow : Window
    {
        public ClassWindow()
        {
            InitializeComponent();
        }

        private void button_Click(object sender, RoutedEventArgs e)//班级查询
        {
            textBlockShow.Text = "";
            for (int i = 0; i < 6; i++)
            {
                chart.Series[0].DataPoints[i].YValue = 0;
            }
            if (textBox1.Text.Length == 0 && textBox.Text.Length == 0)
            {
                textBlockShow.Text = "请填写年级或班级！";
                return;
            }
            try
            {
                if(textBox.Text.Length != 0)
                {
                    int year = int.Parse(textBox.Text);
                    if (year < 1000 || year > 9999)
                        throw new Exception();
                }
            }
            catch
            {
                textBlockShow.Text = "年级请填写4位的整数";
                return;
            }
            try
            {
                MySqlCommand cmd = MainWindow.conn.CreateCommand();
                if(textBox.Text.Length != 0 && textBox1.Text.Length != 0)
                    cmd.CommandText = "select sid from student where class = \'" + textBox1.Text + "\' and enrolyear = \'" + textBox.Text + "\'";
                else if(textBox.Text.Length != 0)
                    cmd.CommandText = "select sid from student where enrolyear = \'" + textBox.Text + "\'";
                else
                    cmd.CommandText = "select sid from student where class = \'" + textBox1.Text + "\'";
                MySqlDataAdapter adap = new MySqlDataAdapter(cmd);
                DataSet ds = new DataSet();
                adap.Fill(ds);
                double[] a = { 0, 0, 0, 0, 0, 0 };//六种等级的个数
                double sum = 0, total = 0;    //加权分，总学分
                int cnt = 0;//学生上的课程总数

                if(ds.Tables[0].Rows.Count == 0)    //找班级里的学生
                {
                    textBlockShow.Text = "该年级班级暂无学生";
                    return;
                }
                foreach (DataRow r in ds.Tables[0].Rows)//每个学生找课程和分数
                {
                    DataSet ds1 = new DataSet();
                    string sid = r["sid"].ToString();
                    cmd.CommandText = "select cid, score from info where sid = \'" + sid + "\'";
                    adap = new MySqlDataAdapter(cmd);
                    adap.Fill(ds1);

                    foreach (DataRow r1 in ds1.Tables[0].Rows)//每个课程找学分
                    {
                        DataSet ds2 = new DataSet();
                        try
                        {
                            double score = double.Parse(r1["score"].ToString());//如果没成绩会抛出异常
                            cnt++;
                            string cid = r1["cid"].ToString();
                            if (score < 60) a[0]++;
                            else if (score < 70) a[1]++;
                            else if (score < 80) a[2]++;
                            else if (score < 90) a[3]++;
                            else if (score < 100) a[4]++;
                            else if (score == 100) a[5]++;

                            cmd.CommandText = "select credit from course where cid = \'" + cid + "\'";
                            adap = new MySqlDataAdapter(cmd);
                            adap.Fill(ds2);
                            DataRow r2 = ds2.Tables[0].Rows[0];
                            double credit = double.Parse(r2["credit"].ToString());
                            total += credit;
                            sum += (credit * score);
                        }
                        catch
                        {
                            //不做什么 没成绩直接跳过
                        }
                    }
                }
                if (cnt == 0)
                {
                    textBlockShow.Text = "当前年级班级学生暂未选课";
                    return;
                }
                else
                {
                    sum /= total;
                    textBlockShow.Text = "加权平均：" + sum.ToString();
                }
                for (int i = 0; i < 6; i++)
                {
                    chart.Series[0].DataPoints[i].YValue = (a[i] / cnt) * 100.0;
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
