using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using MySql.Data;
using MySql.Data.MySqlClient;
using System.Data;
using System.Diagnostics;

namespace CourseSystem
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        private String myConnectionString = "Server=localhost;Database=school;Uid=phoenix;Pwd=1114;";
        public static MySqlConnection conn;
        public static List<Student> slist = new List<Student>();
        public static List<Course> clist = new List<Course>();
        public static List<Info> ilist = new List<Info>();
        public MainWindow()
        {
            InitializeComponent();
            studentbutton.IsEnabled = false;
            studentbutton_Copy.IsEnabled = false;
            coursebutton.IsEnabled = false;
            coursebutton_Copy1.IsEnabled = false;
            infobutton.IsEnabled = false;
            scorebutton_Copy.IsEnabled = false;
            scorebutton_Copy2.IsEnabled = true;
            Console_Botton.IsEnabled = false;

            Flag.modeFlag = 1;
            conn = new MySqlConnection(myConnectionString);
            conn.Open();
        }
        
        private void button_Click(object sender, RoutedEventArgs e)//*学生按钮
        {
            try
            {
                MySqlCommand cmd = conn.CreateCommand();
                cmd.CommandText = "select * from student";
                MySqlDataAdapter adap = new MySqlDataAdapter(cmd);

                DataSet ds = new DataSet();
                adap.Fill(ds);
                slist.Clear();
                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    Student tmp = new Student();
                    tmp.sid = r["sid"].ToString();
                    tmp.name = r["name"].ToString();
                    tmp.sex = r["sex"].ToString();
                    tmp.enrolage = r["enrolage"].ToString();
                    tmp.enrolyear = r["enrolyear"].ToString();
                    tmp.cls = r["class"].ToString();
                    slist.Add(tmp);
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

            Window7 win7 = new Window7();
            win7.f = 1;
            win7.dataGrid.Columns.Add(new DataGridTextColumn() { Header = "学号", Binding = new Binding("sid") });
            win7.dataGrid.Columns.Add(new DataGridTextColumn() { Header = "姓名", Binding = new Binding("name") });
            win7.dataGrid.Columns.Add(new DataGridTextColumn() { Header = "性别", Binding = new Binding("sex") });
            win7.dataGrid.Columns.Add(new DataGridTextColumn() { Header = "入学年龄", Binding = new Binding("enrolage") });
            win7.dataGrid.Columns.Add(new DataGridTextColumn() { Header = "入学年份", Binding = new Binding("enrolyear") });
            win7.dataGrid.Columns.Add(new DataGridTextColumn() { Header = "班级", Binding = new Binding("cls") });
            win7.dataGrid.ItemsSource = slist;
            win7.textBlock1.Text = "姓名搜索";
            win7.textBox.Focus();
            win7.ShowDialog();
        }

        private void coursebutton_Click(object sender, RoutedEventArgs e)//*课程按钮
        {
            try
            {
                MySqlCommand cmd = conn.CreateCommand();
                cmd.CommandText = "select * from course";
                MySqlDataAdapter adap = new MySqlDataAdapter(cmd);

                DataSet ds = new DataSet();
                adap.Fill(ds);
                clist.Clear();
                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    Course tmp = new Course();
                    tmp.cid = r["cid"].ToString();
                    tmp.name = r["cname"].ToString();
                    tmp.teacher = r["teacher"].ToString();
                    tmp.credit = r["credit"].ToString();
                    tmp.minage = r["suitage"].ToString();
                    tmp.cancelyear = r["cancelyear"].ToString();
                    clist.Add(tmp);
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

            Window7 win7 = new Window7();
            win7.f = 2;
            win7.dataGrid.Columns.Add(new DataGridTextColumn() { Header = "课程编号", Binding = new Binding("cid") });
            win7.dataGrid.Columns.Add(new DataGridTextColumn() { Header = "课程名称", Binding = new Binding("name") });
            win7.dataGrid.Columns.Add(new DataGridTextColumn() { Header = "教师姓名", Binding = new Binding("teacher") });
            win7.dataGrid.Columns.Add(new DataGridTextColumn() { Header = "学分", Binding = new Binding("credit") });
            win7.dataGrid.Columns.Add(new DataGridTextColumn() { Header = "适合年级", Binding = new Binding("minage") });
            win7.dataGrid.Columns.Add(new DataGridTextColumn() { Header = "取消年份", Binding = new Binding("cancelyear") });
            win7.dataGrid.ItemsSource = clist;
            win7.textBlock1.Text = "课程名搜索";
            win7.textBox.Focus();
            win7.ShowDialog();
        }

        
        private void Window_Closed(object sender, EventArgs e)
        {
            conn.Close();
        }

        private void button1_Click(object sender, RoutedEventArgs e)//*课程信息按钮
        {
            try
            {
                MySqlCommand cmd = conn.CreateCommand();
                cmd.CommandText = "select * from info";
                MySqlDataAdapter adap = new MySqlDataAdapter(cmd);

                DataSet ds = new DataSet();
                adap.Fill(ds);
                ilist.Clear();
                foreach (DataRow r in ds.Tables[0].Rows)
                {
                    Info tmp = new Info();
                    tmp.sid = r["sid"].ToString();
                    tmp.cid = r["cid"].ToString();
                    tmp.year = r["selectyear"].ToString();
                    tmp.score = r["score"].ToString();
                    ilist.Add(tmp);
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

            Window7 win7 = new Window7();
            win7.f = 3;
            win7.dataGrid.Columns.Add(new DataGridTextColumn() { Header = "学号", Binding = new Binding("sid") });
            win7.dataGrid.Columns.Add(new DataGridTextColumn() { Header = "课程编号", Binding = new Binding("cid") });
            win7.dataGrid.Columns.Add(new DataGridTextColumn() { Header = "选课年份", Binding = new Binding("year") });
            win7.dataGrid.Columns.Add(new DataGridTextColumn() { Header = "成绩", Binding = new Binding("score") });
            win7.dataGrid.ItemsSource = ilist;
            win7.textBlock1.Text = "学号搜索";
            win7.textBox.Focus();
            win7.ShowDialog();
        }

        private void student_Click(object sender, RoutedEventArgs e)//学生信息查询
        {
            StudentWindow sw = new StudentWindow();
            sw.textBox.Focus();
            sw.ShowDialog();
        }

        private void course_Click(object sender, RoutedEventArgs e)//课程信息查询
        {
            CourseWindow cw = new CourseWindow();
            cw.textBox.Focus();
            cw.ShowDialog();
        }

        private void score_Click(object sender, RoutedEventArgs e)//学生成绩查询
        {
            ScoreWindow sw = new ScoreWindow();
            sw.textBox.Focus();
            sw.ShowDialog();
        }

        private void class_Click(object sender, RoutedEventArgs e)//班级成绩查询
        {
            ClassWindow cw = new ClassWindow();
            cw.textBox.Focus();
            cw.ShowDialog();
        }

        private void button_Click_1(object sender, RoutedEventArgs e)//权限切换
        {
            if (comboBox.SelectedIndex == 0)
            {
                studentbutton.IsEnabled = false;
                studentbutton_Copy.IsEnabled = false;
                coursebutton.IsEnabled = false;
                coursebutton_Copy1.IsEnabled = false;
                infobutton.IsEnabled = false;
                scorebutton_Copy.IsEnabled = false;
                Console_Botton.IsEnabled = false;
                scorebutton_Copy2.IsEnabled = true;
                Flag.modeFlag = 1;
            }
            else if(comboBox.SelectedIndex == 1)
            {
                if (passwordBox.Password == "1234")
                {
                    studentbutton.IsEnabled = false;
                    studentbutton_Copy.IsEnabled = true;
                    coursebutton.IsEnabled = false;
                    coursebutton_Copy1.IsEnabled = true;
                    infobutton.IsEnabled = false;
                    scorebutton_Copy.IsEnabled = true;
                    scorebutton_Copy2.IsEnabled = true;
                    Console_Botton.IsEnabled = false;

                    Flag.modeFlag = 2;
                }
                else
                    MessageBox.Show("口令错误");
            }
            else if(comboBox.SelectedIndex == 2)
            {
                if (passwordBox.Password == "1111")
                {
                    studentbutton.IsEnabled = true;
                    studentbutton_Copy.IsEnabled = true;
                    coursebutton.IsEnabled = true;
                    coursebutton_Copy1.IsEnabled = true;
                    infobutton.IsEnabled = true;
                    scorebutton_Copy.IsEnabled = true;
                    scorebutton_Copy2.IsEnabled = true;
                    Console_Botton.IsEnabled = true;

                    Flag.modeFlag = 3;
                }
                else
                    MessageBox.Show("口令错误");
            }
            passwordBox.Password = "";
        }

        private void comboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (comboBox.SelectedIndex != 0)
            {
                passwordBox.Focus();
            }
        }

        private void Console_Click(object sender, RoutedEventArgs e)//控制台入口
        {
            MessageBox.Show("高级模式可能会错误更改数据，若非管理员请勿使用");
            Process p = new Process();
            p.StartInfo.FileName = @"C:\ProgramData\Microsoft\Windows\Start Menu\Programs\MySQL\MySQL Server 5.7\MySQL 5.7 Command Line Client";
            try
            { p.Start(); }
            catch (Exception err)
            {
                MessageBox.Show(err.Message);
            }
        }
    }

    public class Student
    {
        public string sid { set; get; }
        public string name { set; get; }
        public string sex { set; get; }
        public string enrolage { set; get; }
        public string enrolyear { set; get; }
        public string cls { set; get; }
        public bool isChecked { set; get; }
    }

    public class Course
    {
        public string cid { set; get; }
        public string name { set; get; }
        public string teacher { set; get; }
        public string credit { set; get; }
        public string minage { set; get; }
        public string cancelyear { set; get; }
        public bool isChecked { set; get; }
    }

    public class Info
    {
        public string sid { set; get; }
        public string cid { set; get; }
        public string year { set; get; }
        public string score { set; get; }
        public bool isChecked { set; get; }
    }

    public class Flag
    {
        public static int modeFlag;//1为学生，2为教师，3为管理员
        public static int flag2;//搜索状态，1为全部列表，2为搜索列表
    }
}
