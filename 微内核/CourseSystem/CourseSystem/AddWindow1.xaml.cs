using System;
using System.Collections.Generic;
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
using MySql.Data.MySqlClient;
using System.Data;

namespace CourseSystem
{
    /// <summary>
    /// AddWindow1.xaml 的交互逻辑
    /// </summary>
    public partial class AddWindow1 : Window
    {
        public int f;//1为学生 2为课程
        public AddWindow1()
        {
            InitializeComponent();
        }

        private void button_Click(object sender, RoutedEventArgs e)//添加按钮
        {
            try
            {
                MySqlCommand cmd = MainWindow.conn.CreateCommand();
                if (f == 1)
                {
                    int a = Convert.ToInt32(textBox4.Text);
                    if (textBox1.Text.Length != 10)
                    {
                        MessageBox.Show("学号不为空，长度须为10");
                    }
                    else if (textBox3.Text != "男" && textBox3.Text != "女")
                    {
                        MessageBox.Show("性别只能是男或女");
                    }
                    else if (a < 10 || a > 50)
                    {
                        MessageBox.Show("入学年龄只能为10-50");
                    }
                    else if(textBox2.Text.Length == 0 || textBox5.Text.Length == 0 || textBox6.Text.Length == 0)
                    {
                        MessageBox.Show("姓名、入学年份、班级不能为空");
                    }
                    else
                    {
                        try
                        {
                            int year = int.Parse(textBox5.Text);
                            if (year < 1000 || year > 9999)
                                throw new Exception();
                        }
                        catch
                        {
                            MessageBox.Show("入学年份请填写4位的整数");
                            return;
                        }

                        if (MessageBox.Show("是否确认添加？\n添加后学号和入学年份将无法更改", "提示", MessageBoxButton.OKCancel) == MessageBoxResult.OK)
                        {
                            //确定按钮的方法
                            cmd.CommandText = String.Format("insert into student value('{0}','{1}','{2}',{3},{4},{5},'{6}')", textBox1.Text, textBox2.Text,
                                                                               textBox3.Text, textBox4.Text, textBox5.Text, textBox6.Text, passwordBox.Password);
                            cmd.ExecuteNonQuery();
                            Student tmp = new Student();
                            tmp.sid = textBox1.Text;
                            tmp.name = textBox2.Text;
                            tmp.sex = textBox3.Text;
                            tmp.enrolage = textBox4.Text;
                            tmp.enrolyear = textBox5.Text;
                            tmp.cls = textBox6.Text;
                            MainWindow.slist.Add(tmp);
                            this.Close();
                        }
                        else
                        {
                            //取消按钮的方法
                            //什么也不做
                        }
                        
                    }
                }
                else if (f == 2)
                {
                    if (textBox1.Text.Length != 7)
                    {
                        MessageBox.Show("课程编号不为空，长度须为7");
                    }
                    else if(textBox2.Text.Length == 0 || textBox3.Text.Length == 0 || textBox4.Text.Length == 0 || textBox5.Text.Length == 0)
                    {
                        MessageBox.Show("只有取消年份才能为空");
                    }
                    else
                    {
                        if (MessageBox.Show("是否确认添加？\n添加后课程号将无法更改", "提示", MessageBoxButton.OKCancel) == MessageBoxResult.OK)
                        {
                            //确定按钮的方法
                            if (textBox6.Text.Length == 0) textBox6.Text = "Null";
                            cmd.CommandText = String.Format("insert into course value('{0}','{1}','{2}',{3},{4},{5})", textBox1.Text, textBox2.Text,
                                                                                   textBox3.Text, textBox4.Text, textBox5.Text, textBox6.Text);
                            cmd.ExecuteNonQuery();
                            Course tmp = new Course();
                            tmp.cid = textBox1.Text;
                            tmp.name = textBox2.Text;
                            tmp.teacher = textBox3.Text;
                            tmp.credit = textBox4.Text;
                            tmp.minage = textBox5.Text;
                            tmp.cancelyear = textBox6.Text == "Null" ? null : textBox6.Text;
                            MainWindow.clist.Add(tmp);
                            this.Close();
                        }
                        else
                        {
                            //取消按钮的方法
                            //什么也不做
                        }
                    }
                }
                
            }
            catch (MySqlException ex)
            {
                MessageBox.Show(ex.Message);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
