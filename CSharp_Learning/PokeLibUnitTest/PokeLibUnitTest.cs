using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

using System.Diagnostics;

namespace Peterinor.MF
{
    [TestClass]
    public class PokeLibUnitTest
    {
        private Deck poke;
        [TestMethod]
        public void Test_GetCard_int()
        {
            this.CaseBegin();
            {
                Card cd = this.poke.GetCard(26);
                //Debug.WriteLine(cd);
                //Assert.AreEqual(1, 2);
                StringAssert.Contains(cd.ToString(), "K");
            }
            this.CaseEnd();
        }
        [TestMethod]
        public void Test_GetCards_int_int()
        {
            this.CaseBegin();
            {
                Card[] cds = this.poke.GetCards(0, 13);
                StringAssert.Contains(cds[12].ToString(), "K");
            }
            this.CaseEnd();
        }
        private void CaseBegin()
        {
            this.poke = new Deck();
        }

        private void CaseEnd()
        {
            GC.Collect();
        }

    }
}
