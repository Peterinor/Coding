using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Peterinor.MF
{
    interface IAnimal
    {
        void Eat();
        void Sleep();
    }
    class Sheep : IAnimal
    {
        public double weight = 0;
        public Sheep(double weight)
        {
            this.weight = weight;
        }
        public void Eat()
        {
            Console.WriteLine("Sheep Eat");
        }
        public void Sleep()
        {
            Console.WriteLine("Sheep Sleep");
        }
    }
    class Dog : IAnimal
    {
        public void Eat()
        {
            Console.WriteLine("Dog Eat");
        }
        public void Sleep()
        {
            Console.WriteLine("Dog Sleep");
        }
    }
    class OOP
    {
        static void Main(string[] args)
        {
            //Sheep sp = new Sheep();       //--WRONG
            Sheep sp2 = new Sheep(200);

            Dog dog = new Dog();

            IAnimal animal = sp2;
            animal.Eat();
            animal.Sleep();

            animal = dog;
            animal.Eat();
            animal.Sleep();

            Console.WriteLine(typeof(CSLib));
            CSLib lib = new CSLib();
            Console.WriteLine(lib);


        }
    }
}
