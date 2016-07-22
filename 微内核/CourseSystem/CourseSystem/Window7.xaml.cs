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
    /// Window7.xaml 的交互逻辑
    /// </summary>
    public partial class Window7 : Window
    {
        public int f;//1是学生信息 2是课程信息 3选课信息

        public static List<Student> tempSlist = new List<Student>();
        public static List<Course> tempClist = new List<Course>();
        public static List<Info> tempIlist = new List<Info>(); 
        public Window7()
        {
            InitializeComponent();
            Flag.flag2 = 1;
        }

        private void button_Click(object sender, RoutedEventArgs e)//添加按钮
        {
            
            if(f == 1)
            {
                AddWindow1 win = new AddWindow1();
                win.f = 1;
                win.textBlock1.Text = "学号";
                win.textBlock2.Text = "姓名";
                win.textBlock3.Text = "性别";
                win.textBlock4.Text = "入学年龄";
                win.textBlock5.Text = "入学年份";
                win.textBlock6.Text = "班级";
                win.textBlock7.Text = "密码";
                win.textBox1.Focus();
                win.ShowDialog();
                dataGrid.ItemsSource = null;
                dataGrid.ItemsSource = MainWindow.slist;
            }
            else if(f == 2)
            {
                AddWindow1 win = new AddWindow1();
                win.f = 2;
                win.textBlock1.Text = "课程编号";
                win.textBlock2.Text = "课程名称";
                win.textBlock3.Text = "教师姓名";
                win.textBlock4.Text = "学分";
                win.textBlock5.Text = "适合年级";
                win.textBlock6.Text = "取消年份";
                win.textBlock7.Text = "";
                win.passwordBox.IsEnabled = false;
                win.textBox1.Focus();
                win.ShowDialog();
                dataGrid.ItemsSource = null;
                dataGrid.ItemsSource = MainWindow.clist;
            }
            else//课程信息用不同的窗口
            {
                AddWindow2 win = new AddWindow2();
                win.textBlock1.Text = "学号";
                win.textBlock2.Text = "课程号";
                win.textBlock3.Text = "选课年份";
                win.textBlock4.Text = "成绩";
                win.textBox1.Focus();
                win.ShowDialog();
                dataGrid.ItemsSource = null;
                dataGrid.ItemsSource = MainWindow.ilist;
            }
            
        }

        private void button_Delete_Click(object sender, RoutedEventArgs e)//删除按钮
        {
            try
            {
                if (MessageBox.Show("是否确认删除？", "提示", MessageBoxButton.OKCancel) == MessageBoxResult.OK)
                {
                    //确定按钮的方法
                    MySqlCommand cmd = MainWindow.conn.CreateCommand();
                    if (f == 1)
                    {
                        if (Flag.flag2 == 1)
                        {
                            for (int i = MainWindow.slist.Count - 1; i >= 0; i--)
                            {
                                if (MainWindow.slist[i].isChecked == true)
                                {
                                    string sid = MainWindow.slist[i].sid;
                                    cmd.CommandText = "delete from student where sid=" + sid;
                                    cmd.ExecuteNonQuery();
                                    MainWindow.slist.RemoveAt(i);
                                }
                            }
                            dataGrid.ItemsSource = null;
                            dataGrid.ItemsSource = MainWindow.slist;
                        }
                        else
                        {
                            for (int i = tempSlist.Count - 1; i >= 0; i--)
                            {
                                if (tempSlist[i].isChecked == true)
                                {
                                    string sid = tempSlist[i].sid;
                                    cmd.CommandText = "delete from student where sid=" + sid;
                                    cmd.ExecuteNonQuery();
                                    tempSlist.RemoveAt(i);
                                }
                            }
                            for (int i = MainWindow.slist.Count - 1; i >= 0; i--)
                            {
                                if (MainWindow.slist[i].isChecked == true)
                                {
                                    string sid = MainWindow.slist[i].sid;
                                    cmd.CommandText = "delete from student where sid=" + sid;
                                    cmd.ExecuteNonQuery();
                                    MainWindow.slist.RemoveAt(i);
                                }
                            }
                            dataGrid.ItemsSource = null;
                            dataGrid.ItemsSource = tempSlist;
                        }

                    }
                    else if (f == 2)
                    {
                        if (Flag.flag2 == 1)
                        {
                            for (int i = MainWindow.clist.Count - 1; i >= 0; i--)
                            {
                                if (MainWindow.clist[i].isChecked == true)
                                {
                                    string cid = MainWindow.clist[i].cid;
                                    cmd.CommandText = "delete from course where cid=" + cid;
                                    cmd.ExecuteNonQuery();
                                    MainWindow.clist.RemoveAt(i);
                                }
                            }
                            dataGrid.ItemsSource = null;
                            dataGrid.ItemsSource = MainWindow.clist;
                        }
                        else
                        {
                            for (int i = tempClist.Count - 1; i >= 0; i--)
                            {
                                if (tempClist[i].isChecked == true)
                                {
                                    string cid = tempClist[i].cid;
                                    cmd.CommandText = "delete from course where cid=" + cid;
                                    cmd.ExecuteNonQuery();
                                    tempClist.RemoveAt(i);
                                }
                            }
                            for (int i = MainWindow.clist.Count - 1; i >= 0; i--)
                            {
                                if (MainWindow.clist[i].isChecked == true)
                                {
                                    string cid = MainWindow.clist[i].cid;
                                    cmd.CommandText = "delete from course where cid=" + cid;
                                    cmd.ExecuteNonQuery();
                                    MainWindow.clist.RemoveAt(i);
                                }
                            }
                            dataGrid.ItemsSource = null;
                            dataGrid.ItemsSource = tempClist;
                        }

                    }
                    else if (f == 3)
                    {
                        if (Flag.flag2 == 1)
                        {
                            for (int i = MainWindow.ilist.Count - 1; i >= 0; i--)
                            {
                                if (MainWindow.ilist[i].isChecked == true)
                                {
                                    string sid = MainWindow.ilist[i].sid;
                                    string cid = MainWindow.ilist[i].cid;
                                    cmd.CommandText = String.Format("delete from info where sid='{0}' and cid = '{1}' ", sid, cid);
                                    cmd.ExecuteNonQuery();
                                    MainWindow.ilist.RemoveAt(i);
                                }
                            }
                            dataGrid.ItemsSource = null;
                            dataGrid.ItemsSource = MainWindow.ilist;
                        }
                        else
                        {
                            for (int i = tempIlist.Count - 1; i >= 0; i--)
                            {
                                if (tempIlist[i].isChecked == true)
                                {
                                    string sid = tempIlist[i].sid;
                                    string cid = tempIlist[i].cid;
                                    cmd.CommandText = String.Format("delete from info where sid='{0}' and cid = '{1}' ", sid, cid);
                                    cmd.ExecuteNonQuery();
                                    tempIlist.RemoveAt(i);
                                }
                            }
                            for (int i = MainWindow.ilist.Count - 1; i >= 0; i--)
                            {
                                if (MainWindow.ilist[i].isChecked == true)
                                {
                                    string sid = MainWindow.ilist[i].sid;
                                    string cid = MainWindow.ilist[i].cid;
                                    cmd.CommandText = String.Format("delete from info where sid='{0}' and cid = '{1}' ", sid, cid);
                                    cmd.ExecuteNonQuery();
                                    MainWindow.ilist.RemoveAt(i);
                                }
                            }
                            dataGrid.ItemsSource = null;
                            dataGrid.ItemsSource = tempIlist;
                        }

                    }
                    cBox_All.IsChecked = false;
                }
                else
                {
                    //取消按钮的方法
                    //什么也不做
                }
                
            }
            catch (MySqlException ex)
            {
                textBlock.Text = ex.Message;
            }
            catch (Exception)
            {
                textBlock.Text = "Wrong";
            }
            
        }

        private void refresh_Click(object sender, RoutedEventArgs e)//刷新按钮
        {
            try
            {
                if(f == 1)
                {
                    MySqlCommand cmd = MainWindow.conn.CreateCommand();
                    cmd.CommandText = "select * from student";
                    MySqlDataAdapter adap = new MySqlDataAdapter(cmd);

                    DataSet ds = new DataSet();
                    adap.Fill(ds);
                    MainWindow.slist.Clear();
                    foreach (DataRow r in ds.Tables[0].Rows)
                    {
                        Student tmp = new Student();
                        tmp.sid = r["sid"].ToString();
                        tmp.name = r["name"].ToString();
                        tmp.sex = r["sex"].ToString();
                        tmp.enrolage = r["enrolage"].ToString();
                        tmp.enrolyear = r["enrolyear"].ToString();
                        tmp.cls = r["class"].ToString();
                        MainWindow.slist.Add(tmp);
                    }

                    dataGrid.ItemsSource = null;
                    dataGrid.ItemsSource = MainWindow.slist;
                }
                else if(f == 2)
                {
                    
                       MySqlCommand cmd = MainWindow.conn.CreateCommand();
                       cmd.CommandText = "select * from course";
                       MySqlDataAdapter adap = new MySqlDataAdapter(cmd);

                       DataSet ds = new DataSet();
                       adap.Fill(ds);
                       MainWindow.clist.Clear();
                       foreach (DataRow r in ds.Tables[0].Rows)
                       {
                           Course tmp = new Course();
                           tmp.cid = r["cid"].ToString();
                           tmp.name = r["cname"].ToString();
                           tmp.teacher = r["teacher"].ToString();
                           tmp.credit = r["credit"].ToString();
                           tmp.minage = r["suitage"].ToString();
                           tmp.cancelyear = r["cancelyear"].ToString();
                           MainWindow.clist.Add(tmp);
                       }
                       dataGrid.ItemsSource = null;
                       dataGrid.ItemsSource = MainWindow.clist;
                }
                else if(f == 3)
                {
                    MySqlCommand cmd = MainWindow.conn.CreateCommand();
                    cmd.CommandText = "select * from info";
                    MySqlDataAdapter adap = new MySqlDataAdapter(cmd);

                    DataSet ds = new DataSet();
                    adap.Fill(ds);
                    MainWindow.ilist.Clear();
                    foreach (DataRow r in ds.Tables[0].Rows)
                    {
                        Info tmp = new Info();
                        tmp.sid = r["sid"].ToString();
                        tmp.cid = r["cid"].ToString();
                        tmp.year = r["selectyear"].ToString();
                        tmp.score = r["score"].ToString();
                        MainWindow.ilist.Add(tmp);
                    }
                    dataGrid.ItemsSource = null;
                    dataGrid.ItemsSource = MainWindow.ilist;
                }
                Flag.flag2 = 1;
            }
            catch (Exception)
            {
                MainWindow.conn.Close();
            }
        }

        private void dataGrid_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

        }

        private void cBox_All_Click(object sender, RoutedEventArgs e)   //全选
        {
            if(f == 1)
            {
                if(Flag.flag2 == 1)
                {
                    if (cBox_All.IsChecked == true)
                        foreach (var p in MainWindow.slist)
                        {
                            p.isChecked = true;
                        }
                    else
                        foreach (var p in MainWindow.slist)
                        {
                            p.isChecked = false;
                        }
                    dataGrid.ItemsSource = null;
                    dataGrid.ItemsSource = MainWindow.slist;
                }
                else
                {
                    if (cBox_All.IsChecked == true)
                        foreach (var p in tempSlist)
                        {
                            p.isChecked = true;
                        }
                    else
                        foreach (var p in tempSlist)
                        {
                            p.isChecked = false;
                        }
                    dataGrid.ItemsSource = null;
                    dataGrid.ItemsSource = tempSlist;
                }
                
            }
            else if(f == 2)
            {
                if(Flag.flag2 == 1)
                {
                    if (cBox_All.IsChecked == true)
                        foreach (var p in MainWindow.clist)
                        {
                            p.isChecked = true;
                        }
                    else
                        foreach (var p in MainWindow.clist)
                        {
                            p.isChecked = false;
                        }
                    dataGrid.ItemsSource = null;
                    dataGrid.ItemsSource = MainWindow.clist;
                }
                else
                {
                    if (cBox_All.IsChecked == true)
                        foreach (var p in tempClist)
                        {
                            p.isChecked = true;
                        }
                    else
                        foreach (var p in tempClist)
                        {
                            p.isChecked = false;
                        }
                    dataGrid.ItemsSource = null;
                    dataGrid.ItemsSource = tempClist;
                }
                
            }
            else
            {
                if(Flag.flag2 == 1)
                {
                    if (cBox_All.IsChecked == true)
                        foreach (var p in MainWindow.ilist)
                        {
                            p.isChecked = true;
                        }
                    else
                        foreach (var p in MainWindow.ilist)
                        {
                            p.isChecked = false;
                        }
                    dataGrid.ItemsSource = null;
                    dataGrid.ItemsSource = MainWindow.ilist;
                }
                else
                {
                    if (cBox_All.IsChecked == true)
                        foreach (var p in tempIlist)
                        {
                            p.isChecked = true;
                        }
                    else
                        foreach (var p in tempIlist)
                        {
                            p.isChecked = false;
                        }
                    dataGrid.ItemsSource = null;
                    dataGrid.ItemsSource = tempIlist;
                
                }
            }
                
        }

        private void button1_Click(object sender, RoutedEventArgs e)//搜索按钮
        {
            if(f == 1)
            {
                if(textBox.Text.Length == 0)
                {
                    dataGrid.ItemsSource = MainWindow.slist;
                    Flag.flag2 = 1;
                }
                else
                {
                    tempSlist = MainWindow.slist.FindAll(p => { if (p.name.Contains(textBox.Text)) return true; else return false; });
                    dataGrid.ItemsSource = tempSlist;
                    Flag.flag2 = 2;
                }
            }
            else if(f == 2)
            {
                if (textBox.Text.Length == 0)
                {
                    dataGrid.ItemsSource = MainWindow.clist;
                    Flag.flag2 = 1;
                }
                else
                {
                    tempClist = MainWindow.clist.FindAll(p => { if (p.name.Contains(textBox.Text)) return true; else return false; });
                    dataGrid.ItemsSource = tempClist;
                    Flag.flag2 = 2;
                }
            }
            else if(f == 3)
            {
                if (textBox.Text.Length == 0)
                {
                    dataGrid.ItemsSource = MainWindow.ilist;
                    Flag.flag2 = 1;
                }else
                {
                    tempIlist = MainWindow.ilist.FindAll(p => { if (p.sid.Contains(textBox.Text)) return true; else return false; });
                    dataGrid.ItemsSource = tempIlist;
                    Flag.flag2 = 2;
                }
            }
        }

        private void dataGrid_MouseDoubleClick(object sender, MouseButtonEventArgs e)//双击进入修改界面
        {
            int p = dataGrid.SelectedIndex;
            if (p < 0) return;
            if (f == 1)
            {
                List<Student> tmp;
                ChangeWindow1 win = new ChangeWindow1();
                win.f = 1;
                win.textBlock1.Text = "学号";
                win.textBlock2.Text = "姓名";
                win.textBlock3.Text = "性别";
                win.textBlock4.Text = "入学年龄";
                win.textBlock5.Text = "入学年份";
                win.textBlock6.Text = "班级";
                win.textBlock7.Text = "修改密码";
                if (Flag.flag2 == 1)
                    tmp = MainWindow.slist;
                else
                    tmp = tempSlist;
                win.textBox1.Text = tmp[p].sid;
                win.textBox2.Text = tmp[p].name;
                win.textBox3.Text = tmp[p].sex;
                win.textBox4.Text = tmp[p].enrolage;
                win.textBox5.Text = tmp[p].enrolyear;
                win.textBox6.Text = tmp[p].cls;

                win.textBox1.IsEnabled = false;
                win.textBox5.IsEnabled = false;
                win.index = p;
                win.ShowDialog();

                dataGrid.ItemsSource = null;
                dataGrid.ItemsSource = tmp;
            }
            else if(f == 2)
            {
                List<Course> tmp;
                ChangeWindow1 win = new ChangeWindow1();
                win.f = 2;
                win.textBlock1.Text = "课程编号";
                win.textBlock2.Text = "课程名称";
                win.textBlock3.Text = "教师姓名";
                win.textBlock4.Text = "学分";
                win.textBlock5.Text = "适合年级";
                win.textBlock6.Text = "取消年份";
                win.textBlock7.Text = "";
                win.passwordBox.IsEnabled = false;
                if (Flag.flag2 == 1)
                    tmp = MainWindow.clist;
                else
                    tmp = tempClist;

                win.textBox1.Text = tmp[p].cid;
                win.textBox2.Text = tmp[p].name;
                win.textBox3.Text = tmp[p].teacher;
                win.textBox4.Text = tmp[p].credit;
                win.textBox5.Text = tmp[p].minage;
                win.textBox6.Text = tmp[p].cancelyear;

                win.textBox1.IsEnabled = false;
                win.index = p;
                win.ShowDialog();
                dataGrid.ItemsSource = null;
                dataGrid.ItemsSource = tmp;
            }
            else if(f == 3)
            {
                List<Info> tmp;
                ChangeWindow2 win = new ChangeWindow2();
                if (Flag.flag2 == 1)
                    tmp = MainWindow.ilist;
                else
                    tmp = tempIlist;
                win.textBox1.Text = tmp[p].sid;
                win.textBox2.Text = tmp[p].cid;
                win.textBox3.Text = tmp[p].year;
                win.textBox4.Text = tmp[p].score;

                win.textBox1.IsEnabled = false;
                win.textBox2.IsEnabled = false;
                win.textBox3.IsEnabled = false;
                win.index = p;
                win.ShowDialog();
                dataGrid.ItemsSource = null;
                dataGrid.ItemsSource = tmp;
            }
            dataGrid.SelectedIndex = -1;
        }
    }
}
