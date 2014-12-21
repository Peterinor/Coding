using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using libcrc;

namespace crc_gen
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length < 1)
            {
                Console.WriteLine("-----------------------------------");
                Console.WriteLine("FMC crc generate tool by Yu.Tang");
                Console.WriteLine("usage: crc_gen <data>");
                Console.WriteLine("example: crc_gen ADS ");
                Console.WriteLine("the result is: e7bd");
                Console.WriteLine("-----------------------------------");

                return;
            }
            Console.WriteLine("{0:x}", CrcFmc.crc_gen(args[0]));
        }
    }
}
