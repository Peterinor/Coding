using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Collections;

namespace Peterinor.MF
{
    class CollectionListAndSoOn
    {
        static void Main(string[] args)
        {
            Animal[] anl = new Animal[2];
            anl[0] = new Dog("zj");
            Checken ck = new Checken("dx");
            anl[1] = ck;
            foreach (Animal al in anl)
            {
                al.Eat();
                al.Sleep();
            }
            ((Dog)anl[0]).Bite();
            ((Checken)anl[1]).LayEggs();

            ArrayList alist = new ArrayList();
            alist.Add(new Dog("zj"));
            alist.Add(ck);
            alist.Add(3);
            foreach (object ob in alist)
            {
                Console.WriteLine(ob);
            }
            
        }
    }
}
