﻿using System;
using System.Media;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Collections.ObjectModel;
using System.IO;
using System.Windows.Threading;

namespace todolist
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    ///
    public partial class MainWindow : Window
    {
        public DateTime DisplayDate { get; set; }
        List<events> row = new List<events>();
        SoundPlayer player = new SoundPlayer("aaa.WAV");
        DispatcherTimer timer;
        public MainWindow()
        {
            InitializeComponent();
            using(StreamReader sr = new StreamReader("Data.txt"))//Read the Data
            {
                string detail, date, description;
                int num = int.Parse(sr.ReadLine());
                for(int i = 0; i < num; i++)
                {
                    detail = sr.ReadLine();
                    date = sr.ReadLine();
                    description = sr.ReadLine();
                    events tmp = new events(date, detail, description);
                    row.Add(tmp);
                }
                dataGrid1.DataContext = row;
            }
        }

        private void listBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

        }

        private void comboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void dataGrid_SelectionChanged_1(object sender, SelectionChangedEventArgs e)
        {
            //Please move to Check_Box_Click
            //This event is a little bit egg-hurt that it will be triggered only when the item you click is changed
        }

        private void textBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void cBox_All_Click(object sender, RoutedEventArgs e)
        {
            CheckBox cb = sender as CheckBox;
            row.FindAll(p =>
            {
                p.IsChecked = cb.IsChecked.Value;
                return true;
            });
            dataGrid1.SelectedIndex = -1;
            row = row.FindAll(p => { return true; });//Why I must refresh the row like this?
            dataGrid1.DataContext = row;
        }


        private void button_Copy_Click(object sender, RoutedEventArgs e)//new
        {
            events tmp = new events();
            tmp.date = datePicker.Text;
            tmp.detail = textBox.Text;

            tmp.description = textBox1.Text;
            tmp.IsChecked = false;
            row.Add(tmp);
            row = row.FindAll(p=> { return true; });//Why I must refresh the row like this?
            dataGrid1.DataContext = row;

            //timer = new DispatcherTimer();
            //timer.Interval = new TimeSpan(0, 0, 5);  
            //timer.Tick += new EventHandler(timer_Tick);
            //timer.Start();

            textBox.Text = null;
            datePicker.Text = null;
            textBox1.Text = null;
            Flag.isMove = true;
        }

        private void button_Click(object sender, RoutedEventArgs e)//delete
        {
            int cnt = row.Count(p=> { if (p.IsChecked) { return true; } else { return false; } });
            if(cnt > 0)
            {
                Window2 win2 = new Window2();
                win2.Left = this.Left + 110;
                win2.Top = this.Top + 250;
                win2.textBlock.Text = "Are you sure to delete the " + (cnt.ToString()) + " selected event(s)?";
                player.Play();
                win2.ShowDialog();
            }
            if(Flag.flag == true)
            {
                Flag.flag = false;
                Flag.isMove = true;
                row = row.FindAll(p => { if (p.IsChecked) { p.IsChecked = false; return false; } return true; });
                cBox_All.IsChecked = false;
                dataGrid1.DataContext = row;
            }
        }

        private void CheckBox_Click(object sender, RoutedEventArgs e)
        {
            var item = dataGrid1.SelectedItem;
            if ((item as events).IsChecked == true)
                (item as events).IsChecked = false;
            else
                (item as events).IsChecked = true;
            dataGrid1.SelectedIndex = -1;
            row = row.FindAll(p => { return true; });//Why I must refresh the row like this?
            dataGrid1.DataContext = row;
        }

        private void Window_Closing(object sender, EventArgs e)
        {
            if(Flag.isMove == true)//Warnning if modifyied
            {
                Window2 win2 = new Window2();
                win2.Left = this.Left + 110;
                win2.Top = this.Top + 250;
                win2.textBlock.Text = "Do you want to save the modifications?";
                player.Play();
                win2.ShowDialog();
            }
            if(Flag.flag == true)
            {
                Flag.flag = false;
                using (StreamWriter sw = new StreamWriter("Data.txt"))//Save the Data
                {
                    int num = row.Count;
                    sw.WriteLine(num);
                    for(int i = 0; i < num; i++)
                    {
                        sw.WriteLine(row[i].detail);
                        sw.WriteLine(row[i].date);
                        sw.WriteLine(row[i].description);
                    }
                }
            }
            
        }

        private void dataGrid1_MouseDoubleClick(object sender, MouseButtonEventArgs e)//Open the Detail Window
        {
            int p = dataGrid1.SelectedIndex;
            if(p >= 0)
            {
                Window1 win1 = new Window1();
                win1.Left = this.Left + 40;//Set to the center of the Main Window
                win1.Top = this.Top + 100;
                win1.textBox.Text = row[p].detail;
                win1.datePicker.Text = row[p].date;
                win1.textBox1.Text = row[p].description;
                win1.ShowDialog();
                if (Flag.flag == true)
                {
                    Flag.flag = false;
                    row[p].detail = win1.textBox.Text;
                    row[p].date = win1.datePicker.Text;
                    row[p].description = win1.textBox1.Text;
                    row = row.FindAll(p2 => { return true; });
                    dataGrid1.DataContext = row;
                    Flag.isMove = true;//Modified
                }
                dataGrid1.SelectedIndex = -1;
            }
        }
        //Time ticker is just have a try. It hasn't been implemented
        void timer_Tick(object sender, EventArgs e)
        {
            int p = row.Count-1;
            if (p >= 0)
            {
                Window1 win1 = new Window1();
                win1.Left = this.Left + 40;
                win1.Top = this.Top + 100;
                win1.textBox.Text = row[p].detail;
                win1.datePicker.Text = row[p].date;
                win1.textBox1.Text = row[p].description;
                win1.ShowDialog();
                if (Flag.flag == true)
                {
                    Flag.flag = false;
                    row[p].detail = win1.textBox.Text;
                    row[p].date = win1.datePicker.Text;
                    row[p].description = win1.textBox1.Text;
                    row = row.FindAll(p2 => { return true; });
                    dataGrid1.DataContext = row;
                    Flag.isMove = true;
                }
                dataGrid1.SelectedIndex = -1;
                timer.Stop();
            }
        }
    }

    public class events
    {
        public string date { get; set; }
        public string detail { get; set; }
        public string description { get; set; }
        public bool IsChecked { get; set; }

        public events()
        {
            IsChecked = false;
        }

        public events(string select, string str, string des)
        {
            date = select;
            detail = str;
            description = des;
        }

    }

    public class Flag
    {
        public static bool flag = false;
        public static bool isMove = false;
    }

}
