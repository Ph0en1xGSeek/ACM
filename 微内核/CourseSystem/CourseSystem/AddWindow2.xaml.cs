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
    /// AddWindow2.xaml 的交互逻辑
    /// </summary>
    public partial class AddWindow2 : Window
    {
        //仅为选课信息服务
        public AddWindow2()
        {
            InitializeComponent();
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                MySqlCommand cmd = MainWindow.conn.CreateCommand();
                if(textBox1.Text.Length > 0 && textBox2.Text.Length > 0)
                {
                    string sid = textBox1.Text;
                    string cid = textBox2.Text;
                    cmd.CommandText = "select enrolyear from student where sid = " + sid;
                    MySqlDataAdapter adap1 = new MySqlDataAdapter(cmd);
                    DataSet ds1 = new DataSet();            //选择的学生入学年份
                    adap1.Fill(ds1);
                    cmd.CommandText = "select suitage,cancelyear from course where cid = " + cid;
                    MySqlDataAdapter adap2 = new MySqlDataAdapter(cmd);
                    DataSet ds2 = new DataSet();            //选择的课程信息
                    adap2.Fill(ds2);
                    if(ds1.Tables[0].Rows.Count == 0 || ds2.Tables[0].Rows.Count == 0)
                    {
                        //虽然建表时已设外键，但后续代码稳定运行需要外键检验
                        MessageBox.Show("学生或课程不存在");
                        return;
                    }
                    DataRow r = ds1.Tables[0].Rows[0];
                    int enrolyear = Convert.ToInt32(r["enrolyear"]) ;
                    r = ds2.Tables[0].Rows[0];
                    int minage = Convert.ToInt32(r["suitage"]);
                    if(r["cancelyear"].ToString().Length != 0)      //取消年份不为空
                    {
                        int cancelyear = Convert.ToInt32(r["cancelyear"]);
                        if(cancelyear < Convert.ToInt32(textBox3.Text))
                        {
                            MessageBox.Show("此门课程已经取消");
                            return;
                        }
                    }
                    int cGrade = Convert.ToInt32(textBox3.Text) - enrolyear + 1;    //现在年级
                    if(cGrade < minage)
                    {
                        MessageBox.Show("不满足合适年级");
                        return;
                    }

                    try
                    {
                        if(textBox4.Text.Length != 0)
                            double.Parse(textBox4.Text);
                        if (textBox4.Text.Length > 5)
                            throw new Exception();
                    }
                    catch
                    {
                        MessageBox.Show("分数格式不正确, 请填写最多两位的浮点数或整数");
                        return;
                    }
                    //成绩可以暂时没有
                    if (MessageBox.Show("是否确认添加？\n添加后课程编号、学号与选课年份将不能修改", "提示", MessageBoxButton.OKCancel) == MessageBoxResult.OK)
                    {
                        //确定按钮的方法
                        cmd.CommandText = String.Format("insert into info value('{0}','{1}','{2}','{3}')", textBox1.Text, textBox2.Text,
                                                                                                            textBox3.Text, textBox4.Text);
                        cmd.ExecuteNonQuery();
                        Info tmp = new Info();
                        tmp.sid = textBox1.Text;
                        tmp.cid = textBox2.Text;
                        tmp.year = textBox3.Text;
                        tmp.score = textBox4.Text;
                        MainWindow.ilist.Add(tmp);
                        this.Close();
                    }
                    else
                    {
                        //取消按钮的方法
                        //什么也不做
                    }
                    
                }
                else
                {
                    MessageBox.Show("学号与课程编号不能为空");
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
        }//添加新选课信息
    }
}
