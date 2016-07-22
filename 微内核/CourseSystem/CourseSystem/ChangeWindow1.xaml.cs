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
    /// ChangeWindow1.xaml 的交互逻辑
    /// </summary>
    public partial class ChangeWindow1 : Window
    {
        public int f;//1学生 2课程
        public int index;//修改的序号
        public ChangeWindow1()
        {
            InitializeComponent();
        }

        private void button_Click(object sender, RoutedEventArgs e)//更改学生、课程信息
        {           //课程更改适合年龄后，若是已经选上可的学生将不会删除他的选课记录
            try
            {
                MySqlCommand cmd = MainWindow.conn.CreateCommand();
                if (f == 1)
                {
                    int a = Convert.ToInt32(textBox4.Text);
                    if (textBox3.Text != "男" && textBox3.Text != "女")
                    {
                        MessageBox.Show("性别只能是男或女");
                    }
                    else if (a < 10 || a > 50)
                    {
                        MessageBox.Show("入学年龄只能为10-50");
                    }
                    else if (textBox2.Text.Length == 0 || textBox6.Text.Length == 0)
                    {
                        MessageBox.Show("姓名、班级不能为空");
                    }
                    else
                    {
                        if (MessageBox.Show("是否确认修改？", "提示", MessageBoxButton.OKCancel) == MessageBoxResult.OK)
                        {
                            //确定按钮的方法
                            cmd.CommandText = String.Format("update student set name = '{0}', sex = '{1}', enrolage = {2}, class = {3}, password = '{4}' where sid = '{5}'", textBox2.Text, textBox3.Text,
                                                                               textBox4.Text, textBox6.Text, passwordBox.Password, textBox1.Text);

                            cmd.ExecuteNonQuery();
                            List<Student> tmp;
                            if (Flag.flag2 == 1)
                                tmp = MainWindow.slist;
                            else
                                tmp = Window7.tempSlist;
                            tmp[index].name = textBox2.Text;
                            tmp[index].sex = textBox3.Text;
                            tmp[index].enrolage = textBox4.Text;
                            tmp[index].cls = textBox6.Text;
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
                    if (textBox2.Text.Length == 0 || textBox3.Text.Length == 0 || textBox4.Text.Length == 0 || textBox5.Text.Length == 0)
                    {
                        MessageBox.Show("只有取消年份才能为空");
                    }
                    else
                    {
                        if(textBox6.Text.Length > 0)
                        {
                            int selectyear, max;
                            try
                            {
                                selectyear = int.Parse(textBox6.Text);
                            }
                            catch
                            {
                                MessageBox.Show("年份需填写整数");
                                return;
                            }
                            cmd.CommandText = "select max(selectyear) s from info where cid = \'" + textBox1.Text + "\'";
                            MySqlDataAdapter adap = new MySqlDataAdapter(cmd);
                            DataSet ds = new DataSet();
                            adap.Fill(ds);
                            DataRow r = ds.Tables[0].Rows[0];
                            try
                            {
                                max = int.Parse(r["s"].ToString());
                            }
                            catch
                            {
                                max = -1;
                            }
                            if (selectyear <= max)
                            {
                                MessageBox.Show("取消年份不能早于任何已选该课的时间");
                                return;
                            }
                        }
                        if (MessageBox.Show("是否确认修改？", "提示", MessageBoxButton.OKCancel) == MessageBoxResult.OK)
                        {
                            //确定按钮的方法
                            string str = textBox6.Text;
                            if (textBox6.Text.Length == 0) str = "Null";
                            cmd.CommandText = String.Format("update course set cname = '{0}', teacher = '{1}', credit = {2}, suitage = {3}, cancelyear = {4} where cid = '{5}'",
                                                                                    textBox2.Text, textBox3.Text, textBox4.Text, textBox5.Text, str, textBox1.Text);
                            List<Course> tmp;
                            if (Flag.flag2 == 1)
                                tmp = MainWindow.clist;
                            else
                                tmp = Window7.tempClist;

                            cmd.ExecuteNonQuery();
                            tmp[index].name = textBox2.Text;
                            tmp[index].teacher = textBox3.Text;
                            tmp[index].credit = textBox4.Text;
                            tmp[index].minage = textBox5.Text;
                            tmp[index].cancelyear = textBox6.Text;
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
