﻿#pragma checksum "C:\Users\Ph0en1x\Desktop\todolist windows App1\todolist windows App1\Main.xaml" "{406ea660-64cf-4c82-b6f0-42d48172a799}" "C587588B30E6014B3BFD18424EF12497"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace todolist_windows_App1
{
    partial class Main : 
        global::Windows.UI.Xaml.Controls.Page, 
        global::Windows.UI.Xaml.Markup.IComponentConnector,
        global::Windows.UI.Xaml.Markup.IComponentConnector2
    {
        /// <summary>
        /// Connect()
        /// </summary>
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("Microsoft.Windows.UI.Xaml.Build.Tasks"," 14.0.0.0")]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        public void Connect(int connectionId, object target)
        {
            switch(connectionId)
            {
            case 1:
                {
                    this.button = (global::Windows.UI.Xaml.Controls.Button)(target);
                    #line 14 "..\..\..\Main.xaml"
                    ((global::Windows.UI.Xaml.Controls.Button)this.button).Click += this.button_Click;
                    #line default
                }
                break;
            case 2:
                {
                    this.datePicker = (global::Windows.UI.Xaml.Controls.DatePicker)(target);
                }
                break;
            case 3:
                {
                    this.listView = (global::Windows.UI.Xaml.Controls.ListView)(target);
                    #line 16 "..\..\..\Main.xaml"
                    ((global::Windows.UI.Xaml.Controls.ListView)this.listView).SelectionChanged += this.listView_SelectionChanged_1;
                    #line 16 "..\..\..\Main.xaml"
                    ((global::Windows.UI.Xaml.Controls.ListView)this.listView).ItemClick += this.listView_ItemClick;
                    #line default
                }
                break;
            case 4:
                {
                    this.textBox = (global::Windows.UI.Xaml.Controls.TextBox)(target);
                    #line 44 "..\..\..\Main.xaml"
                    ((global::Windows.UI.Xaml.Controls.TextBox)this.textBox).TextChanged += this.textBox_TextChanged;
                    #line default
                }
                break;
            case 5:
                {
                    this.textBox1 = (global::Windows.UI.Xaml.Controls.TextBox)(target);
                }
                break;
            case 6:
                {
                    this.button_Copy = (global::Windows.UI.Xaml.Controls.Button)(target);
                    #line 46 "..\..\..\Main.xaml"
                    ((global::Windows.UI.Xaml.Controls.Button)this.button_Copy).Click += this.button_Copy_Click;
                    #line default
                }
                break;
            case 7:
                {
                    this.textBlock = (global::Windows.UI.Xaml.Controls.TextBlock)(target);
                    #line 47 "..\..\..\Main.xaml"
                    ((global::Windows.UI.Xaml.Controls.TextBlock)this.textBlock).SelectionChanged += this.textBlock_SelectionChanged;
                    #line default
                }
                break;
            case 8:
                {
                    this.textBlock_Copy = (global::Windows.UI.Xaml.Controls.TextBlock)(target);
                    #line 51 "..\..\..\Main.xaml"
                    ((global::Windows.UI.Xaml.Controls.TextBlock)this.textBlock_Copy).SelectionChanged += this.textBlock_SelectionChanged;
                    #line default
                }
                break;
            case 9:
                {
                    this.textBlock_Copy1 = (global::Windows.UI.Xaml.Controls.TextBlock)(target);
                    #line 55 "..\..\..\Main.xaml"
                    ((global::Windows.UI.Xaml.Controls.TextBlock)this.textBlock_Copy1).SelectionChanged += this.textBlock_SelectionChanged;
                    #line default
                }
                break;
            case 10:
                {
                    this.checkBox = (global::Windows.UI.Xaml.Controls.CheckBox)(target);
                    #line 59 "..\..\..\Main.xaml"
                    ((global::Windows.UI.Xaml.Controls.CheckBox)this.checkBox).Click += this.checkBox_Checked;
                    #line default
                }
                break;
            case 11:
                {
                    this.timePicker = (global::Windows.UI.Xaml.Controls.TimePicker)(target);
                }
                break;
            case 12:
                {
                    this.textBlock_Copy2 = (global::Windows.UI.Xaml.Controls.TextBlock)(target);
                    #line 61 "..\..\..\Main.xaml"
                    ((global::Windows.UI.Xaml.Controls.TextBlock)this.textBlock_Copy2).SelectionChanged += this.textBlock_SelectionChanged;
                    #line default
                }
                break;
            case 13:
                {
                    this.button_Copy1 = (global::Windows.UI.Xaml.Controls.Button)(target);
                    #line 65 "..\..\..\Main.xaml"
                    ((global::Windows.UI.Xaml.Controls.Button)this.button_Copy1).Click += this.save_Click;
                    #line default
                }
                break;
            case 14:
                {
                    this.button_Copy2 = (global::Windows.UI.Xaml.Controls.Button)(target);
                    #line 66 "..\..\..\Main.xaml"
                    ((global::Windows.UI.Xaml.Controls.Button)this.button_Copy2).Click += this.home_Click;
                    #line default
                }
                break;
            default:
                break;
            }
            this._contentLoaded = true;
        }

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("Microsoft.Windows.UI.Xaml.Build.Tasks"," 14.0.0.0")]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        public global::Windows.UI.Xaml.Markup.IComponentConnector GetBindingConnector(int connectionId, object target)
        {
            global::Windows.UI.Xaml.Markup.IComponentConnector returnValue = null;
            return returnValue;
        }
    }
}

