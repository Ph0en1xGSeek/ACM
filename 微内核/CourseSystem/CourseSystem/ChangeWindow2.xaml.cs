using MySql.Data.MySqlClient;
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

namespace CourseSystem
{
    /// <summary>
    /// ChangeWindow2.xaml 的交互逻辑
    /// </summary>
    public partial class ChangeWindow2 : Window
    {
        public int index;
        public ChangeWindow2()
        {
            InitializeComponent();
        }

        private void button_Click(object sender, RoutedEventArgs e)//添加按钮
        {
            MySqlCommand cmd = MainWindow.conn.CreateCommand();
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
            try
            {
                if (MessageBox.Show("是否确认修改？", "提示", MessageBoxButton.OKCancel) == MessageBoxResult.OK)
                {
                    //确定按钮的方法
                    cmd.CommandText = String.Format("update info set score = '{0}' where sid = '{1}' and cid = '{2}'", textBox4.Text, textBox1.Text, textBox2.Text);

                    cmd.ExecuteNonQuery();
                    List<Info> tmp;
                    if (Flag.flag2 == 1)
                        tmp = MainWindow.ilist;
                    else
                        tmp = Window7.tempIlist;
                    tmp[index].score = textBox4.Text;
                    this.Close();
                }
                else
                {
                    //取消按钮的方法
                    //什么也不做
                }
                
            }
            catch(MySqlException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
