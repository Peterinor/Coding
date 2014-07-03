using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace UnitTestInit
{
	public static class SetUp
	{
		public static string Conf = "生产环境";

		public static int Version = 100;

		public static void UpdateVersion(int v)
		{
			Version = v;
		}
	}
	[TestClass]
	public class UnitTestSetup
	{
		public int a = 1;
		public UnitTestSetup()
		{
			this.a = 4;
			SetUp.Conf = "测试环境";
			SetUp.UpdateVersion(101);
		}
	}

	[TestClass]
	public class UnitTest : UnitTestSetup
	{
		[TestMethod]
		public void TestMethod()
		{
			Assert.AreEqual(this.a, 4);
			Assert.AreEqual(SetUp.Conf, "测试环境");
			Assert.AreEqual(SetUp.Version, 101);
		}
	}
}
