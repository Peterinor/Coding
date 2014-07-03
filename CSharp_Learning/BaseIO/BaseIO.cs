using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Peterinor.MF
{
    class BaseIO
    {
        static void Main(string[] args)
        {
            System.Console.WriteLine("Hello this is a test program of CSharp!");

            String name;
            int age;
            double heigth, weight;
            Console.WriteLine("input your name:");
            name = Console.ReadLine();
            Console.WriteLine("Input your age");
            age = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Input your height:");
            heigth = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Input your weight:");
            weight = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine("{0}\t{1}\t{2}\t{3}\t", name, age, heigth, weight);

            Console.WriteLine("{0}  {1}\t{0}  {2}\t{0}  {3}\t", name, age, heigth, weight);
        }
    }
}
