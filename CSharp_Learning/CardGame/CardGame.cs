using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Data;
using System.Data.OracleClient;

namespace Peterinor.MF
{
    class CardGame
    {
        static void Main(string[] args)
        {
            short st = (short)Suit.Heart;
            Console.WriteLine((char)(st));
            Console.WriteLine((char)(4));

            Console.WriteLine(new Card(Suit.Heart, Rank.Eight));

            Deck deck = new Deck();
            deck.ShowCards();
            Console.WriteLine("ReRank");
            deck.ReRank();
            deck.ShowCards();
          
        }
    }
}
