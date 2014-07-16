class JavaBase
{
	public static void main(String args[]){
		System.out.println("Java Basic Knowledge test:");
		System.out.println("Java operators test:");

		System.out.println("Test of Bit operators:");
		byte a = 3;	//00000011
		byte b = 6;	//00000110
		//System.out.println("a || b = " + (a || b));	--Error
		//System.out.println("a && b = " + (a && b));	--Error
		System.out.println("a | b = " + (a | b));
		System.out.println("a & b = " + (a & b));
		System.out.println("a ^ b = " + (a ^ b));
		System.out.println("~a = " + ~a );
		System.out.println("~b = " + ~b );	//now we can know ~b + b == -1 is always true!!
		System.out.println("~a + a = " + ~a + a );	//-43, you know why?!? -4 + 3 is not -1!! It's "-4""3"!
		System.out.println("~a + a = " + (~a + a) );	//Here is OK!!!!! See file opt.c for more...
		System.out.println("a << 1=" + (a << 1));
		System.out.println("b >> 1=" + (b >> 1));
		System.out.println("b >>> 1=" + (b >>> 1));
		b = -6;
		System.out.println("b >> 1=" + (b >> 1));
		System.out.println("b >>> 1=" + (b >>> 1));		//also shift the sign bit!



		System.out.println("Test of Relationship operators:");
		boolean aa = true, bb = false;
		System.out.println("aa || bb = " + (aa || bb));
		System.out.println("aa && bb = " + (aa && bb));
		System.out.println("aa |  bb = " + (aa |  bb));
		System.out.println("aa &  bb = " + (aa &  bb));

		System.out.println("Test of ?::");
		System.out.println("The Max of 3 and 4 is:" + (3>4?3:4));

		System.out.println("You Know the Instanceof operator:");
		//System.out.println(5 instanceof int);	//compile Error!!	--instanceof must using object and class as operator args
		System.out.println(new Integer(5) instanceof Integer);		//just the object of the class
		System.out.println(new Integer(4) instanceof Object);		//Heyhey... the object of the sub-class is also OK!

		
	}
}
