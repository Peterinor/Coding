using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Peterinor.MF
{
    enum Weekday : ushort
    {
        Mon = 1,
        Tus, Wed, Thu, Fri, Sat, Sun
    }

    enum Position
    {
        Teacher = 1,
        Student,
        Manager
    }
    struct Person
    {
        public string name;
        public byte age;
        public Position posi;
    }
    class ComplexType
    {
        static void Main(string[] args)
        {
            //Enum
            Console.WriteLine("-->Test of Enum!");
            ushort today = 256;
            byte wd = (byte)(today % 7);
            Weekday wkd = (Weekday) wd;
            Console.WriteLine(wkd);

            switch (wkd)
            {
                case Weekday.Mon:
                    Console.WriteLine("星期一");
                    break;
                case Weekday.Tus:
                    Console.WriteLine("星期二");
                    break;
                case Weekday.Wed:
                    Console.WriteLine("星期三");
                    break;
                case Weekday.Thu:
                    Console.WriteLine("星期四");
                    break;
                case Weekday.Fri:
                    Console.WriteLine("星期五");
                    break;
            }

            Console.WriteLine(wkd.ToString());
            Console.WriteLine(typeof(Weekday));

            //Struct
            Console.WriteLine("-->Test of Struct!");
            Person lj,ty,hx;
            lj.name = "lj";
            lj.age = 30;
            lj.posi = Position.Manager;
            ty.name = "ty";
            ty.age = 23;
            ty.posi = Position.Student;
            hx.name = "hx";
            hx.age = 28;
            hx.posi = Position.Teacher;

            ShowPerson(lj);
            ShowPerson(hx);
            ShowPerson(ty);

            //Arrays
            Console.WriteLine("-->Test of array!");
            int[] iarray = { 1, 2, 3, 4, 5 };
            int[] iarray2 = new int[5];
            int[] iarray3 = new int[5] { 10, 11, 12, 13, 14 };
            //string people = { "ty", "yf", "zj", ".." };           ---ERROR
            string[] people = new string[4]{ "ty", "yf", "zj", ".." };      //---OK
            ShowArray(iarray, 5);
            ShowArray(iarray2, 5);
            ShowArray(iarray3, 5);

            ShowArray(people, 4);

            //-------------------
            Console.WriteLine("-->Test of Multi array!");
            double[,] darray = {
                                    {1,2,3,4},
                                    {2,3,4,5},
                                    {3,4,5,6},
                                    {4,5,6,7}
                               };
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    Console.Write("{0}\t", darray[i, j]);
                }
                Console.WriteLine();
            }

            int count = 0;
            foreach (double elem in darray)
            {                
                Console.Write("{0}\t",elem);
                count++;
                if (count % 4 == 0)
                {
                    Console.WriteLine();
                }
            }

            //------------------
            Console.WriteLine("-->Test of array of array!");
            int[][] arrayofarray;
            arrayofarray = new int[3][];
            arrayofarray[1] = new int[3] { 3, 3, 4 };
            arrayofarray[2] = new int[5] { 1, 2, 3, 4, 5 };
            arrayofarray[0] = new int[2] { 0, 2 };

            int[][] arrayofarray2 = { new int[2] { 0, 2 }, new int[3] { 3, 3, 4 }, new int[5] { 1, 2, 3, 4, 5 } };

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < arrayofarray[i].Length; j++)
                {
                    Console.Write("{0}\t", arrayofarray[i][j]);
                }
                Console.WriteLine();
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < arrayofarray2[i].Length; j++)
                {
                    Console.Write("{0}\t", arrayofarray2[i][j]);
                }
                Console.WriteLine();
            }
            for (int i = 0; i < 3; i++)
            {
                foreach(int elem in arrayofarray[i])
                {
                    Console.Write("{0}\t", elem);
                }
                Console.WriteLine();
            }



            //----------------------
            Console.WriteLine("-->Test of String!");
            Console.WriteLine("{0}\t{1}", typeof(string), typeof(String));
            Console.WriteLine(typeof(string) == typeof(String));            //string 和 String 是同一回事


            Console.WriteLine(typeof(int[]));
            string[] strArr = new string[100];
            Console.WriteLine(strArr);

            Console.WriteLine(typeof(System.Array));
            System.Array arr = System.Array.CreateInstance(typeof(int),1);
            Console.WriteLine(arr);


        }

        static void ShowPerson(Person ps)
        {
            Console.WriteLine("{0}\t{1}\t{2}", ps.name, ps.age, ps.posi);
        }

        static void ShowArray(int[] arr, int n)
        {
            for (int i = 0; i < n; i++)
            {
                Console.Write("{0}\t", arr[i]);
            }
            Console.WriteLine();
        }
        static void ShowArray(string[] arr, int n)
        {
            //for (int i = 0; i < n; i++)
            //{
            //    Console.Write("{0}\t", arr[i]);
            //}
            //Console.WriteLine();
            foreach (string elem in arr)        //foreach 对数组做只读访问
            {
                Console.Write("{0}\t", elem);
            }
            Console.WriteLine();
        }
    }
}
