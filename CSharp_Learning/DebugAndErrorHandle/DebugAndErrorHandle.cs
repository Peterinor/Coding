using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

//using
using System.Diagnostics;

namespace Peterinor.MF
{
    class DebugAndErrorHandle
    {
        static void Main(string[] args)
        {
            Debug.WriteLine("This is a test info", "Main");
            Trace.WriteLine("This is a test info", "Main");

            Console.WriteLine("This is a test info from Main Method");
            int test = 0;
            for (test = 0; test < 100; test++)
            {
                Console.WriteLine(test);
            }
            for (test = 0; test < 100; test++)
            {
                Console.WriteLine(test);
            }

            Debug.Assert(test == 100);
            //Debug.Assert(test < 100);

            try
            {
                double a = 240 / 0.00000000001;
                double b = a / 0.0;
                double c = b / 0;
                byte x = 2;
                byte i = checked((byte)(125 << x));
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

            try
            {
                throw (new Exception("This is a unknow Exception"));
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            finally
            {
                Console.WriteLine("This Must be over");
            }
                
        }
    }
}
