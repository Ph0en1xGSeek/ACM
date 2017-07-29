using System;
using System.Collections.Generic;
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

// “空白页”项模板在 http://go.microsoft.com/fwlink/?LinkId=234238 上有介绍

namespace todolist_windows_App1
{
    /// <summary>
    /// 可用于自身或导航至 Frame 内部的空白页。
    /// </summary>
    public sealed partial class BlankPage1 : Page
    {
        public BlankPage1()
        {
            this.InitializeComponent();
        }

        private void appBarButton_Click(object sender, RoutedEventArgs e)
        {
            Frame.GoBack();
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            if (passwordBox.Password == "1234")
                Frame.Navigate(typeof(Main), 0);
            else
            {
                passwordBox.Password = "";
                textBlock1.Text = "Password Wrong";
            }
        }

        private void textBlock1_SelectionChanged(object sender, RoutedEventArgs e)
        {

        }

    }
}
