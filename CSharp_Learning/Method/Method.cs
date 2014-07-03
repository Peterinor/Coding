using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Peterinor.MF
{
    class Method
    {
        //static void Main()
        static void Main(string[] args)
        //static int Main()
        //static int Main(string[] args)
        {
            Console.WriteLine(SearchChar('t',"tangyutianbulao"));

            int[] iarray = new int[5] { 1, 4, 3, -3, 9 };
            Console.WriteLine(GetMaxValueOfArray(iarray));

            string snt = "This is a test sentence of the function GetAWord";
            Console.WriteLine(GetAWord(snt));
            Console.WriteLine(GetAWord(snt,new int[]{5,6}));

            int x = 10, y = 15;
            Console.WriteLine("{0}\t{1}", x, y);
            Swap(ref x, ref y);
            Console.WriteLine("{0}\t{1}", x, y);

            string word;
            GetAWord(snt, out word);
            Console.WriteLine(word);

            //arguments
            foreach (string arg in args)
            {
                Console.WriteLine(arg);
            }

            //重载、委托
            Console.WriteLine(GetMaxValueOfArray(new double[] { 1.3, 4, 3.4, 9.3, 2.0, 2.1 }));

            Console.WriteLine(BaseOperation(2.0, 3,'+'));
            Console.WriteLine(BaseOperation(2.0, 3, 'x'));
            Console.WriteLine(BaseOperation(2.0, 3, '-'));
            Console.WriteLine(BaseOperation(2.0, 3, '*'));
            Console.WriteLine(BaseOperation(2.0, 3, '/'));
            Console.WriteLine(BaseOperation(2.0, 3, 'f'));

        }

        static bool SearchChar(char ch, string str)
        {
            foreach (char c in str)
            {
                if (ch == c)
                {
                    return true;
                }                
            }
            return false;
        }

        static int GetMaxValueOfArray(int[] iarr)
        {
            int max=iarr[0];
            for (int i = 1; i < iarr.Length; i++)
            {
                if (iarr[i] > max) max = iarr[i];
            }
            return max;
        }

        //可变参数
        static string GetAWord(string snt, params int[] opt)
        {
            string[] words = snt.Split(' ');

            //Console.WriteLine("{0}  {1}",opt[0], opt[1]);
            if (opt.Length == 1) return words[opt[0] - 1];
            if (opt.Length == 2) return words[opt[0] - 1].Substring(0, opt[1]);
            return words[0];            
        }

        //ref out
        static void Swap(ref int x,ref int y)
        {
            int tmp = x;
            x = y;
            y = tmp;
        }
        static void GetAWord(string snt, out string word)
        {
            word = snt.Substring(0,snt.IndexOf(' '));
        }

        //重载、委托

        static double GetMaxValueOfArray(double[] darr)
        {
            double max = darr[0];
            for (int i = 0; i < darr.Length; i++)
            {
                if (darr[i] > max)
                    max = darr[i];
            }
            return max;
        }

        delegate double Operation(double a, double b);
        static double Sum(double a, double b)
        {
            return a + b;
        }
        static double Multi(double a, double b)
        {
            return a * b;
        }
        static double Divid(double a, double b)
        {
            return a / b;
        }
        static double Minuse(double a, double b)
        {
            return a - b;
        }
        static double NoOpt(double a, double b)
        {
            return a;
        }

        static double BaseOperation(double a, double b, char opt)
        {
            Operation fun = null; 
            switch (opt)
            {
                case '+':
                    fun = Sum;
                    break;
                case '*':
                case 'X':
                case 'x':
                    fun = Multi;
                    break;
                case '-':
                    fun = Minuse;
                    break;
                case '/': 
                    fun = Divid;
                    break;
                default:
                    fun = NoOpt;
                    break;
            }
            return fun(a, b);
        }
    }
}
