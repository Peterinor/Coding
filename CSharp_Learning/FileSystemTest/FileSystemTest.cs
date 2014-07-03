using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace Peterinor.MF
{
    class FileSystemTest
    {
        static void Main(string[] args)
        {
            //string path = "./";
            //ShowDirectory(path);
            //Directory.CreateDirectory(path + "test");
            //ShowDirectory(path);
            //Directory.Delete(path + "test", true);
            //ShowDirectory(path);

            string sfile = "../../requestData";
            FileInfo fi = new FileInfo(sfile);
            if (fi.Exists)
            {
                try
                {
                    FileStream file = new FileStream(sfile, FileMode.Open, FileAccess.Read);// ; new FileStream(sfile, FileMode.Open, FileAccess.Read);
                    const int size = 1500;
                    byte[] dat = new byte[size];
                    char[] cdat = new char[size];
                    file.Read(dat, 0, size-1);
                    Decoder d = Encoding.GetEncoding("gb2312").GetDecoder();//.UTF8.GetDecoder();
                    d.GetChars(dat, 0, dat.Length, cdat, 0, true);
                    Console.WriteLine(new string(cdat));

                    //StreamReader rd = new StreamReader(file);
                    ////string line;
                    ////do
                    ////{
                    ////    line = rd.ReadLine();
                    ////    Console.WriteLine(line);
                    ////} while (line != null);

                    //string totalfile = rd.ReadToEnd();
                    //Console.WriteLine(totalfile);                        

                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.Message);
                }
            }
        }

        static void ShowDirectory(string path)
        {
            Console.WriteLine(">------------------------<");
            //string[] dirs = Directory.GetDirectories(path);
            //string[] files = Directory.GetFiles(path);            
            //foreach (string d in dirs)
            //{
            //    Console.WriteLine(d);
            //}
            //foreach (string f in files)
            //{
            //    Console.WriteLine(f);
            //} 
            string[] elem = Directory.GetFileSystemEntries(path);
            foreach (string el in elem)
            {
                Console.WriteLine(el);
            }
        }
    }
}
