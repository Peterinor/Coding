using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Peterinor.MF
{
    /// <summary>
    /// Deck Class, A Suit of cards containing 54 cards
    /// </summary>
    public class Deck
    {
        Peterinor.MF.Card[] cards;
        /// <summary>
        /// Constractor
        /// </summary>
        public Deck()
        {
            cards = new Peterinor.MF.Card[52];
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 13; j++)
                {
                    cards[i*13 + j] = new Card((Suit)(i+ (int)(Suit.Heart)), (Rank)(j+1));
                }
            }
        }

        /// <summary>
        /// Get a Card from a Deck
        /// </summary>
        /// <param name="num">the index of the card you want, form 1st</param>
        /// <returns>The Card you want</returns>
        public Card GetCard(int num)
        {
            int index = num - 1;
            if (index >= 0 && index < 52)
                return cards[index];
            throw (new ArgumentOutOfRangeException("There are only 52 cards"));
        }

        public Card[] GetCards(int start, int num)
        {
            Card[] cds = new Card[num];
            if (!(start >= 0 && start < 52 && num > 0 && num < 52 && start + num < 52))
            {
                throw (new ArgumentOutOfRangeException("There are only 52 cards"));
            }
            for (int i = start; i < num; i++)
            {
                cds[i-start] = this.cards[i];
            }
            return cds;
        }

        public void ShowCardsUnit(int start)
        {
            for (int i = start; i < 13 + start; i++)
            {
                Console.Write(cards[i] + "  ");
            }
            Console.WriteLine();
        }

        public void ShowCards()
        {
            for (int i = 0; i < 4; i++)
            {
                ShowCardsUnit(i * 13);
            }
        }

        public void ReRank()
        {
            Card[] tmp = new Card[52];            
            Random seed = new Random();
            for (int index = 0; index < 52; index++)
            {
                bool isSet = false;                
                while (!isSet)
                {
                    int tmpindex = seed.Next(52);
                    if (tmp[tmpindex] == null)
                    {
                        tmp[tmpindex] = new Card(this.cards[index]);
                        isSet = true;
                    }
                }
            }
            this.cards = tmp;

        }
    }
}
