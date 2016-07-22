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
    public sealed partial class ItemDetailPage1 : Page
    {
        events e1;

        /// <summary>
        /// 可将其更改为强类型视图模型。
        /// </summary>
        /// <summary>
        /// NavigationHelper 在每页上用于协助导航和
        /// 进程生命期管理
        /// </summary>
        public ItemDetailPage1()
        {
            this.InitializeComponent();
        }

        /// <summary>
        /// 使用在导航过程中传递的内容填充页。  在从以前的会话
        /// 重新创建页时，也会提供任何已保存状态。
        /// </summary>
        /// <param name="sender">
        /// 事件的源；通常 <see cref="Common.NavigationHelper"/>
        /// </param>
        /// <param name="e">事件数据，其中既提供在最初请求此页时传递给
        /// <see cref="Frame.Navigate(Type, Object)"/> 的导航参数，又提供
        /// 此页在以前会话期间保留的状态的
        /// 字典。首次访问页面时，该状态将为 null。</param>

        #region NavigationHelper 注册

        /// 此部分中提供的方法只是用于使
        /// NavigationHelper 可响应页面的导航方法。
        /// 
        /// 应将页面特有的逻辑放入用于
        /// <see cref="Common.NavigationHelper.LoadState"/>
        /// 和 <see cref="Common.NavigationHelper.SaveState"/>。
        /// 除了在会话期间保留的页面状态之外
        /// LoadState 方法中还提供导航参数。

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            e1 = e.Parameter as events;
            textBox.Text = e1.detail;
            textBox_Copy.Text = e1.description;
            datePicker.Date = e1.realdate;
            timePicker.Time = e1.time;
        }

        protected override void OnNavigatedFrom(NavigationEventArgs e)
        {

        }

        #endregion

        private void button_Click(object sender, RoutedEventArgs e)
        {
            e1.detail = textBox.Text;
            e1.description = textBox_Copy.Text;
            e1.date = datePicker.Date.ToString("yyyy/MM/dd dddd") + ' ' + timePicker.Time.ToString();
            e1.realdate = datePicker.Date;
            e1 = null;

            Frame.Navigate(typeof(Main), 1);
        }

        private void backButton_Click(object sender, RoutedEventArgs e)
        {
            Frame.Navigate(typeof(Main), 1);
        }
    }
}