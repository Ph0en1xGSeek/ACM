﻿

#pragma checksum "C:\Users\Ph0en1x\Desktop\todolist wp\todolist wp\MainPage.xaml" "{406ea660-64cf-4c82-b6f0-42d48172a799}" "8A2D2F02DE7BF782B79E74A5FC2CDF00"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace todolist_wp
{
    partial class MainPage : global::Windows.UI.Xaml.Controls.Page, global::Windows.UI.Xaml.Markup.IComponentConnector
    {
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("Microsoft.Windows.UI.Xaml.Build.Tasks"," 4.0.0.0")]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
 
        public void Connect(int connectionId, object target)
        {
            switch(connectionId)
            {
            case 1:
                #line 9 "..\..\..\MainPage.xaml"
                ((global::Windows.UI.Xaml.FrameworkElement)(target)).Loaded += this.Page_Loaded_1;
                 #line default
                 #line hidden
                break;
            case 2:
                #line 16 "..\..\..\MainPage.xaml"
                ((global::Windows.UI.Xaml.Controls.Primitives.ButtonBase)(target)).Click += this.button_Click;
                 #line default
                 #line hidden
                break;
            case 3:
                #line 17 "..\..\..\MainPage.xaml"
                ((global::Windows.UI.Xaml.Controls.Primitives.Selector)(target)).SelectionChanged += this.listView_SelectionChanged;
                 #line default
                 #line hidden
                #line 17 "..\..\..\MainPage.xaml"
                ((global::Windows.UI.Xaml.Controls.ListViewBase)(target)).ItemClick += this.listView_ItemClick;
                 #line default
                 #line hidden
                break;
            case 4:
                #line 47 "..\..\..\MainPage.xaml"
                ((global::Windows.UI.Xaml.Controls.Primitives.ButtonBase)(target)).Click += this.button_Copy_Click;
                 #line default
                 #line hidden
                break;
            case 5:
                #line 48 "..\..\..\MainPage.xaml"
                ((global::Windows.UI.Xaml.Controls.Primitives.ButtonBase)(target)).Click += this.checkBox_Checked;
                 #line default
                 #line hidden
                break;
            }
            this._contentLoaded = true;
        }
    }
}


