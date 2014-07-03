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

            Console.WriteLine("请输入团队编号:");
            string team = Console.ReadLine();

            Console.WriteLine("请在待会打开的浏览器页面中查看投票验证码，然后回到此处输入正确的验证码既可开始投票...");

            FirefoxDriver dr = new FirefoxDriver();
           

            //ChromeDriver dr = new ChromeDriver();

            //InternetExplorerDriver dr = new InternetExplorerDriver();

            //Notice navigation is slightly different than the Java version
            //This is because 'get' is a keyword in C#

            //dr.Navigate().GoToUrl("http://js.job.12580.com/www/cydx/index?page=" + page);
            dr.Navigate().GoToUrl("http://js.job.12580.com/www/cydx/index");

			IWebElement code = dr.FindElement(By.Id("vote_code"));


            //Thread.Sleep(10000);
            //code.sendKeys("test");
			
            //String scode = code.GetAttribute("value");
			
            //Console.WriteLine(scode);
            //Console.WriteLine("请输入团队在页面中的序号:");
            //int num = Convert.ToInt32(Console.ReadLine().ToString());
            //Console.WriteLine(num);

            //dr.ExecuteScript("alert('请回到刚才的窗口输入投票的验证码')");

            Console.WriteLine("请输入投票验证码:");
            string scode = Console.ReadLine();

            //IWebElement openDiag = dr.FindElement(By.XPath("/html/body/div/div[3]/div/div[2]/div/div[" + "4" + "]/div[2]/div/a"));
            ///html/body/div/div[3]/div/div[2]/div/div[4]/div[2]/div/a
			
            IWebElement vote = dr.FindElement(By.XPath("/html/body/div[3]/div/div[2]/div[2]/a"));
            while(true){
                //openDiag.Click();
                dr.ExecuteScript("vote(" + team + ");");

                Thread.Sleep(200);
                code.SendKeys(scode);

                //Thread.Sleep(100);
                vote.Click();
                Thread.Sleep(300);	
            }
			

            //Close the browser
            dr.Quit();
        }
    }
}

