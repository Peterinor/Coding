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
    class Animal : IAnimal
    {
        protected string name;
        public Animal()
        {
            this.name = "No Name";
        }
        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
            }
        }
        public void Eat()
        {
            Console.WriteLine(this.Name + " Eating");
        }
        public void Sleep()
        {
            Console.WriteLine(this.Name + " Sleep");
        }
        public override string ToString()
        {
            return this.Name;
        }
    }

    class Dog : Animal
    {
        public Dog()
        {
            this.Name = "Dog X";
        }
        public Dog(string name)
        {
            this.Name = "Dog " + name;
        }
        public void Bite()
        {
            Console.WriteLine(this.Name + " Bite");
        }
    }
    class Checken : Animal
    {
        public Checken()
        {
            this.Name = "Checken X";
        }
        public Checken(string name)
        {
            this.Name = "Checken " + name;
        }
        public void LayEggs()
        {
            Console.WriteLine(this.Name + " LayEggs");
        }
    }
}
