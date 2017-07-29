using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Xml.Serialization;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// “空白页”项模板在 http://go.microsoft.com/fwlink/?LinkId=234238 上有介绍

namespace todolist_windows_App1
{
    /// <summary>
    /// 可用于自身或导航至 Frame 内部的空白页。
    /// </summary>
    public sealed partial class Main : Page
    {
        public static ObservableCollection<events> row = new ObservableCollection<events>();
        
        public Main()
        {
            this.InitializeComponent();
            this.NavigationCacheMode = NavigationCacheMode.Enabled;
            //To make sure that the data won't be lost when navigated back to the Page
        }

        private void listView_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

        }

        private void textBlock_SelectionChanged(object sender, RoutedEventArgs e)
        {

        }

        private void textBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            //Navigate to the New Page to add new event
            checkBox.IsChecked = false;
            events tmp = new events();
            tmp.realdate = datePicker.Date;
            tmp.date = datePicker.Date.ToString("yyyy/MM/dd dddd") + ' ' + timePicker.Time.ToString();
            tmp.detail = textBox.Text;
            tmp.description = textBox1.Text;
            tmp.time = timePicker.Time;
            if (comboBox.SelectedIndex == 0)
                tmp.uri = "/Assets/1.jpg";
            else
                tmp.uri = "/Assets/2.jpg";
            row.Add(tmp);
            listView.ItemsSource = row;
            textBox.Text = "";
            datePicker.Date = System.DateTime.Now;
            textBox1.Text = "";
            comboBox.SelectedIndex = 0;
            listView.ScrollIntoView(tmp);
        }

        private void button_Copy_Click(object sender, RoutedEventArgs e)
        {
            //Select All
            checkBox.IsChecked = false;
            int num = row.Count;
            for (int i = num - 1; i >= 0; i--)
            {
                if (row[i].IsChecked == true)
                    row.RemoveAt(i);
            }
        }

        private void listView_SelectionChanged_1(object sender, SelectionChangedEventArgs e)
        {
            //No use any more
            /*if (listView.SelectedItems.Count != row.Count || listView.SelectedItems.Count == 0)
                checkBox.IsChecked = false;
            else
                checkBox.IsChecked = true;

            textBox.Text = listView.SelectedIndex.ToString();*/
        }

        private void listView_ItemClick(object sender, ItemClickEventArgs e)
        {
            this.Frame.Navigate(typeof(ItemDetailPage1), e.ClickedItem);
        }

        private void checkBox_Checked(object sender, RoutedEventArgs e)
        {
            //CheckBox Click Select All

            int num = row.Count;
            if (checkBox.IsChecked == true)
            {
                for (int i = 0; i < num; i++)
                {
                    row[i].IsChecked = true;
                }
            }
            else
            {
                for (int i = 0; i < num; i++)
                {
                    row[i].IsChecked = false;
                }
            }
            listView.ItemsSource = null;
            listView.ItemsSource = row;
        }

        private void checkbox_Click(object sender, RoutedEventArgs e)
        {
        }


        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            //If navigated from home page then Read the Data 
            base.OnNavigatedTo(e);
            listView.ItemsSource = null;
            listView.ItemsSource = row;
            comboBox.SelectedIndex = 0;
            int flag = (int)(e.Parameter);
            if (flag == 0)
            {
                XmlSerializer ser = new XmlSerializer(typeof(ObservableCollection<events>));
                FileStream stream = new FileStream(Flag.fileName, FileMode.Open);
                StreamReader sr = new StreamReader(stream);
                String str = sr.ReadToEnd();
                row = ser.Deserialize(new StringReader(str)) as ObservableCollection<events>;
                listView.ItemsSource = row;
            }
        }

        private void save_Click(object sender, RoutedEventArgs e)
        {
            //Save Data
            XmlSerializer ser = new XmlSerializer(typeof(ObservableCollection<events>));
            FileStream stream = new FileStream(Flag.fileName, FileMode.Create);
            StreamWriter sw = new StreamWriter(stream);
            ser.Serialize(sw, row);
            sw.Flush();
        }

        private void home_Click(object sender, RoutedEventArgs e)
        {
            Frame.Navigate(typeof(MainPage));
        }
        
    }

    public class events
    {
        private string Date;
        private string Detail;
        private string Description;
        private bool isChecked;
        private DateTimeOffset Realdate;
        private TimeSpan Time;
        public string uri { set; get; }
        public event PropertyChangedEventHandler PropertyChanged;

        public string date
        {
            get
            {
                return this.Date;
            }

            set
            {
                if (value != this.Date)
                {
                    this.Date = value;
                    NotifyPropertyChanged();
                }
            }
        }

        public string detail
        {
            get
            {
                return this.Detail;
            }

            set
            {
                if (value != this.Detail)
                {
                    this.Detail = value;
                    NotifyPropertyChanged();
                }
            }
        }

        public string description
        {
            get
            {
                return this.Description;
            }

            set
            {
                if (value != this.Description)
                {
                    this.Description = value;
                    NotifyPropertyChanged();
                }
            }
        }

        public bool IsChecked
        {
            get
            {
                return this.isChecked;
            }

            set
            {
                if (value != this.isChecked)
                {
                    this.isChecked = value;
                    NotifyPropertyChanged();
                }
            }
        }

        public DateTimeOffset realdate
        {
            get
            {
                return this.Realdate;
            }

            set
            {
                if (value != this.Realdate)
                {
                    this.Realdate = value;
                    NotifyPropertyChanged();
                }
            }
        }

        public TimeSpan time
        {
            get
            {
                return this.Time;
            }

            set
            {
                if (value != this.Time)
                {
                    this.Time = value;
                    NotifyPropertyChanged();
                }
            }
        }

        private void NotifyPropertyChanged(String propertyName = "")
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
            }
        }

        public events()
        {
            Date = "";
            Detail = "";
            Description = "";
            isChecked = false;
        }

        public events(String str1, String str2, String str3, String str4, String str5)
        {
            isChecked = false;
            Detail = str1;
            Description = str2;
            Date = str3;
            Realdate = Convert.ToDateTime(str4);
            Time = TimeSpan.Parse(str5);
        }
    }

    public class Flag
    {
        public static int flag;
        public static String fileName;
    }
}
