using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Shapes;

namespace SilverlightAppTest
{
	class DD
	{
		public string A;
		public string B;
		public string C;
		public string D;
		public string E;

		public DD(string a, string b, string c, string d, string e)
		{
			this.A = a;
			this.B = b;
			this.C = c;
			this.D = d;
			this.E = e;
		}
	}
	public partial class MainPage : UserControl
	{
		public MainPage()
		{
			InitializeComponent();
		}

		private void Button_Click_1(object sender, RoutedEventArgs e)
		{
			//ChildWindow1 cw = new ChildWindow1(this.LayoutRoot);
			//cw.LayoutRoot = this.LayoutRoot;
			//cw.Show();

			//MediaElement snd = this.snd;
			//snd.Source = new Uri("sounds/snd.mp3", UriKind.Relative);
			//snd.Volume = 20d;
			//snd.Play();
			//MessageBox.Show("ddd-dd");

			//FloatableWindow fw = new FloatableWindow();//创建浮动窗口实例
			//fw.ParentLayoutRoot = LayoutRoot;//指定承载浮动窗口的父窗口的根布局元素[这里为Grid x:Name="LayoutRoot"]
			//fw.Title = "Test Floatable Window";//浮动窗口标题
			//fw.Content = "The time is " + DateTime.Now.ToLongTimeString();//浮动窗体内容
			//fw.Width = 300;//浮动窗口的宽度
			//fw.Height = 200;//浮动窗口的高度
			//fw.ResizeMode = ResizeMode.CanResize;//设置浮动窗口可自定义缩放
			//fw.Show();//以非模式窗口形式打开窗体

			//List<DD> data = new List<DD>();
			//data.Add(new DD("A1", "B", "C", "D", "E"));
			//data.Add(new DD("A2", "B", "C", "D", "E"));
			//data.Add(new DD("A3", "B", "C", "D", "E"));
			//data.Add(new DD("A4", "B", "C", "D", "E"));
			//data.Add(new DD("A5", "B", "C", "D", "E"));

			//DataList.ItemsSource = data; 

			OpenFileDialog dg = new OpenFileDialog();
			bool? isOK = dg.ShowDialog();

			if (isOK == true)
			{
				System.IO.Stream fileStream = dg.File.OpenRead();

				using (System.IO.StreamReader reader = new System.IO.StreamReader(fileStream))
				{
					var ct = reader.ReadToEnd();
					//byte[] cb = new byte[1024];
					//var b = fileStream.Read(cb, 0, 1000);

					var gb = System.Text.Encoding.GetEncoding("gb2312");

					var _ct = ct.Replace("\r\n", "#");
					var lines = _ct.Split(new char[] { '#' });

					MessageBox.Show(lines[0]);
				}
				fileStream.Close();
			}

			DateTime dt = new DateTime();

			//Convert.ToDateTime("20130810", "yyyy-MM-dd");

			//var file = dg.File;

			//MessageBox.Show();

			//dg.

		}

		private void MLBDown(object sender, MouseButtonEventArgs e)
		{
			var cell = sender as DataGridCell;
			MessageBox.Show(cell.ToString());

		}

		private void MLBUp(object sender, MouseButtonEventArgs e)
		{

		}
	}
}
