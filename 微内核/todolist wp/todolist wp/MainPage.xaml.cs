using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using System.ComponentModel;
using System.Threading.Tasks;
using System.Runtime.Serialization;
using Windows.Storage;
using System.Xml.Serialization;

// “空白页”项模板在 http://go.microsoft.com/fwlink/?LinkId=391641 上有介绍

namespace todolist_wp
{
    /// <summary>
    /// 可用于自身或导航至 Frame 内部的空白页。
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public ObservableCollection<events> row = new ObservableCollection<events>();
        public MainPage()
        {
            this.InitializeComponent();
            this.NavigationCacheMode = NavigationCacheMode.Required;
        }

        /// <summary>
        /// 在此页将要在 Frame 中显示时进行调用。
        /// </summary>
        /// <param name="e">描述如何访问此页的事件数据。
        /// 此参数通常用于配置页。</param>
        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            // TODO: 准备此处显示的页面。

            // TODO: 如果您的应用程序包含多个页面，请确保
            // 通过注册以下事件来处理硬件“后退”按钮:
            // Windows.Phone.UI.Input.HardwareButtons.BackPressed 事件。
            // 如果使用由某些模板提供的 NavigationHelper，
            // 则系统会为您处理该事件。
            listView.ItemsSource = null;
            listView.ItemsSource = row;
        }
        

        private void button_Click(object sender, RoutedEventArgs e)
        {
            //Navigate to the page to add new event with this page
            Frame.Navigate(typeof(AddPage), this);
        }

        private void button_Copy_Click(object sender, RoutedEventArgs e)
        {
            //Delete if is selected
            checkBox.IsChecked = false;
            for(int i = row.Count-1; i >= 0; i--)
            {
                if(row[i].IsChecked == true)
                    row.RemoveAt(i);
            }
        }

        private void listView_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            
        }

        private void checkBox_Checked(object sender, RoutedEventArgs e)
        {
            //Select all, It is the click event
            if (checkBox.IsChecked == true)
            {
                foreach(var ele in row)
                {
                    ele.IsChecked = true;
                }
            }
            else
            {
                foreach (var ele in row)
                {
                    ele.IsChecked = false;
                }
            }
            listView.ItemsSource = null;
            listView.ItemsSource = row;
        }

        private void listView_ItemClick(object sender, ItemClickEventArgs e)
        {
            //Detail
            Frame.Navigate(typeof(BasicPage1), e.ClickedItem);
        }

        private async Task readXMLAsync()
        {
            //Haven't implemented
            var serializer = new DataContractSerializer(typeof(ObservableCollection<events>));
            var myStream = await ApplicationData.Current.LocalCacheFolder.OpenStreamForReadAsync("Data.xml");
            row = (ObservableCollection<events>)serializer.ReadObject(myStream);
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            
        }

        private void Page_Loaded_1(object sender, RoutedEventArgs e)
        {
            //await readXMLAsync();
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

    }
}
