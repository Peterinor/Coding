using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Peterinor.MF
{
    public class Card
    {
        public readonly Peterinor.MF.Suit suit;
        public readonly Peterinor.MF.Rank rank;

        public Card(Suit st, Rank rk)
        {
            this.suit = st;
            this.rank = rk;
        }
        public Card(Card card)
        {
            this.suit = card.suit;
            this.rank = card.rank;
        }
        private Card()
        {
        }

        public override string ToString()
        {
            short ss = (short)(this.suit);
            string cardsuit = new string((char)(ss), 1);
            char cr = (char)(this.rank + '0');
            switch (this.rank)
            {
                case Rank.Ace:
                    cr = 'A';
                    break;
                case Rank.Ten:
                    cr = 'T';
                    break;
                case Rank.Jack:
                    cr = 'J';
                    break;
                case Rank.Queen:
                    cr = 'Q';
                    break;
                case Rank.King:
                    cr = 'K';
                    break;
            }

            string cardrank = new string(cr, 1);

            return string.Concat(cardsuit, cardrank);
        }
    }
}
