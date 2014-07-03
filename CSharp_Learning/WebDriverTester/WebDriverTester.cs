using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Threading;

using System.Drawing;

using OpenQA.Selenium;
using OpenQA.Selenium.Firefox;
using OpenQA.Selenium.IE;
using OpenQA.Selenium.Chrome;
using OpenQA.Selenium.Remote;
// Requires reference to WebDriver.Support.dll
using OpenQA.Selenium.Support.UI;


using System.IO;


namespace Peterinor.MF
{
    class WebDriverTester
    {
        static void Main(string[] args)
        {
            //Console.WriteLine("请输入团队所在页面页码:");
            //int page = Convert.ToInt32(Console.ReadLine().ToString());

            FileStream js = new FileStream("./vote.js", FileMode.Open, FileAccess.Read);

            StreamReader rd = new StreamReader(js);
            string votejs = rd.ReadToEnd();

            rd.Close();
            js.Close();

//            Console.WriteLine(votejs);


            //Console.WriteLine("请输入团队编号:");
            //string team = Console.ReadLine();

            Console.WriteLine("请在待会打开的浏览器页面中查看投票验证码，然后回到此处输入正确的验证码既可开始投票...");

            FirefoxDriver dr = new FirefoxDriver();
           
            dr.Navigate().GoToUrl("http://js.job.12580.com/www/cydx/index");

			IWebElement code = dr.FindElement(By.Id("vote_code"));


            Console.WriteLine("请输入投票验证码:");
            string scode = Console.ReadLine();

            dr.ExecuteScript(votejs);
            Thread.Sleep(300);
            //dr.ExecuteScript("alert(window.aa)");
            //dr.ExecuteScript("vote1736('" + scode + "');");
            //dr.ExecuteScript("vote1736(" + scode + ");");
			
            //IWebElement vote = dr.FindElement(By.XPath("/html/body/div[3]/div/div[2]/div[2]/a"));
            int count = 0;
            string voters = "";
            while(true){
                //openDiag.Click();
                //dr.ExecuteScript("vote(" + team + ");");
                //dr.ExecuteScript("vote1736(" + scode + ");");

                dr.ExecuteScript("vote1736('" + scode + "');");

                voters = dr.ExecuteScript("return getCount()").ToString();

                if (count % 50 == 0)
                {
                    Console.WriteLine("共有 : " + voters + "票");
                }

                Thread.Sleep(50);
                count++;
            }
			
        }
    }
}

