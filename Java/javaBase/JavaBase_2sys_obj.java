
class JavaBase
{
	public static void main(String args[])
	{
		System.out.println("Java Basic Knowledge test:");
		System.out.println("Something about the System System.in/out or the Object class!");
		//Refer to the API docs
    	//public final static PrintStream out = nullPrintStream();	in the System class
		//So, we know the System.out is a object of the PrintStream class, so goto the PrintStream class in the API docs
		System.out.println("String");

		System.out.println(new Object());	// Here we goto PrintStream.println()
		/*	public void println(Object x) print Object and end the line:
			pirntln first call String.valueOf(x) to get the String object of the object-x, and the just print(String) and println()
			So, goto String.valueOf(Object x)
			public static String valueOf(Object x) return the String format of object-x, 
			return "null" if x==null, else return x.toString();
		----So, so far we know println(Object x) and print(Object x) is just perform as print/println(x.toString());
			so, to reride the toString() method of the classes you define to use the print() or println(), it is very convenient!
		*/
		/*--------------------------------
			And also Refer to the API doc and the src file provided by java-sun, I find also the in and err are just objects of the class or sub-class of Stream!
			Moreover, it really help me to understand the realization of the JDKs!
		-----*/

		//Some other methods can be used with System.out
		System.out.printf("%d %f %s\n",35,45.6,"string");	//houhou,just like the printf() in C and C++
		System.out.format("%d %f %s\n",35,45.6,"string");	//almost same with printf
		//also, several other methods not metioned here which maybe good for use
	}
}
