using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


using System.Globalization;
using System.IO;

using System.CodeDom.Compiler;
using Microsoft.CSharp;

using System.Reflection;

namespace CompileAsService
{
	class CompileSample
	{
		[STAThread]
		static void Main(string[] args)
		{
			string assemblyName = "CASTest";
			bool ok = CompileExecutable("./CASTest.cs", assemblyName);
			if (ok)
			{
				Assembly asm = Assembly.Load(assemblyName);
				Type t = asm.GetType("CompileAsServiceTest.CASTest");
				MethodInfo m = t.GetMethod("Add");
				object obj = Activator.CreateInstance(t);
				object r = m.Invoke(obj, new object[] { 1, 2 });
				Console.WriteLine(Convert.ToInt32(r));

				Console.WriteLine("End");
			}
		}

		public static bool CompileExecutable(String sourceName, String assemblyName)
		{
			FileInfo sourceFile = new FileInfo(sourceName);

			FileStream srcFile = new FileStream(sourceName, FileMode.Open, FileAccess.Read);
			StreamReader rd = new StreamReader(srcFile);

			string src = rd.ReadToEnd();


			CodeDomProvider provider = null;
			bool compileOk = false;

			provider = CodeDomProvider.CreateProvider("CSharp");

			if (provider != null)
			{

				String asmName = String.Format(@"{0}\{1}.dll",
					System.Environment.CurrentDirectory,
					assemblyName);

				CompilerParameters cp = new CompilerParameters();

				// Generate an executable instead of 
				// a class library.
				cp.GenerateExecutable = false;

				// Specify the assembly file name to generate.
				cp.OutputAssembly = asmName;

				// Save the assembly as a physical file.
				cp.GenerateInMemory = false;

				// Set whether to treat all warnings as errors.
				cp.TreatWarningsAsErrors = false;

				// Invoke compilation of the source file.
				//CompilerResults cr = provider.CompileAssemblyFromFile(cp,
				//	sourceName);
				CompilerResults cr = provider.CompileAssemblyFromSource(cp, src);

				if (cr.Errors.Count > 0)
				{
					// Display compilation errors.
					Console.WriteLine("Errors building {0} into {1}",
						sourceName, cr.PathToAssembly);
					foreach (CompilerError ce in cr.Errors)
					{
						Console.WriteLine("  {0}", ce.ToString());
						Console.WriteLine();
					}
				}
				else
				{
					// Display a successful compilation message.
					Console.WriteLine("Source {0} built into {1} successfully.",
						sourceName, cr.PathToAssembly);
				}

				// Return the results of the compilation.
				if (cr.Errors.Count > 0)
				{
					compileOk = false;
				}
				else
				{
					compileOk = true;
				}
			}
			return compileOk;
		}
	}
}
