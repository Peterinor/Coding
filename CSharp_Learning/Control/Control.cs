using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Peterinor.MF
{
    class Control
    {
        static void Main(string[] args)
        {
            bool cd1 = true;
            bool cd2 = true;
            bool cd3 = false;
            bool cd4 = false;

            Console.WriteLine(!cd4);

            Console.WriteLine(cd1 ^ cd2);
            Console.WriteLine(cd2 ^ cd3);
            Console.WriteLine(cd3 ^ cd4);

            int tie = 0;
            bool test = (tie != 0) && (200 / tie != 0);     //这里由于&&运算符的短路特性，使得200/tie不会执行

            string result = test ? "test is true":"test is false";
            Console.WriteLine(result);

            //double的比较
            double d1 = 3.0;
            double d2 = 3.0;
            Console.WriteLine(d1 == d2);
            d1 = 3.00000000001;
            d2 = 3.00000000001;
            Console.WriteLine(d1 == d2);


            //Switch while for
            string type = "AB";     //String int bool char...
            switch (type)
            {
                case "AB":
                    Console.WriteLine("AB");
                    break;                      //这里的break是强制性的。。。。
                case "BC":
                    Console.WriteLine("BC");
                    break;
                case "CD":
                case "DE":
                case "EF":
                    Console.WriteLine("Other");
                    break;
                default:
                    Console.WriteLine("Unspecified");
                    break;
            }

            int i = 0;
            do
            {
                Console.Write("{0}  ", i++);
            } while (i < 10);
            Console.WriteLine();

            i = 0;
            while (i < 10)
            {
                Console.Write("{0}  ", i++);
            }
            Console.WriteLine();

            for (i = 0; i < 10; i++)
            {
                Console.Write("{0}  ", i);
            }
            Console.WriteLine();
            
            for (double d = 0; d < 5; d += 0.5)
            {
                Console.Write("{0}  ", d);
            }
            Console.WriteLine();

            //Convert 数据类型转换
            ushort uch = '中';
            Console.WriteLine(uch);

            char ch = (char)uch;
            Console.WriteLine(ch);

            ushort ust = 259;
            byte bt = (byte)ust;
            try
            {
                Console.WriteLine(bt);
                bt = checked((byte)ust);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

            Console.WriteLine(Convert.ToChar(20013));
            Console.WriteLine(Convert.ToDouble(bt));
        }
    }
}
