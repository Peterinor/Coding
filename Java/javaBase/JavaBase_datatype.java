class JavaBase
{
	public static void main(String args[]){
		System.out.println("Java Basic Knowledge test:");
		System.out.println("Java DataType test!");
		
		System.out.println("BASIC DataType:");
		System.out.println("\n--------INT-----------");
		byte 	bv = 5;
		short	sv = 5;
		int 	iv = 5;
		long	lv = 5;	
		System.out.println("bv= "+bv);
		System.out.println("sv= "+sv);
		System.out.println("iv= "+iv);
		System.out.println("lv= "+lv);
		
		bv = 127;		//bv = 128;  error!
		bv = -128;
		sv = 32767;		//sv = 32768; error!
		sv = -32768;		
		System.out.println("bv= "+bv);
		System.out.println("sv= "+sv);
		System.out.println("iv= "+iv);
		System.out.println("lv= "+lv);		
		System.out.println("So, wo know the size of byte is 8bit, short is 16bit, int is 32bit and long is 64bit");
		System.out.println("And wo also can get the value include positive numbers as well as negtive ones!");
		
		System.out.println("\n--------REAL------------");
		float 	fv = 4;
		double	dv = 4;
		System.out.println("fv= "+fv);
		System.out.println("dv= "+dv);
		fv = -0.0004f;
		dv = -3.00003;
		System.out.println("fv= "+fv);
		System.out.println("dv= "+dv);		
		System.out.println("the size of float is 32bit,it's called sigal float, the double is 64bit,it's called double float");
		
		System.out.println("\n--------CHAR--------------");
		char ch = 't';
		System.out.println("ch= "+ch);
		ch = 'ÌÆ';
		System.out.println("ch= "+ch);
		ch = 65535;	//ch = 65536;error!
		System.out.println("ch= "+ch);
		System.out.println("Wo know that the size of char is 16bit,we call it Unicode!");
		System.out.println("Because we find ch has a space cantain a integer larger as 65535!");
		
		System.out.println("\n-------BOOLEAN-------------");
		boolean blv = true;
		System.out.println("blv= "+blv);
		blv = false;	//	blv = 0;	error
		System.out.println("blv= "+blv);
		
		System.out.println("\n-------REFERENCE---------------");
		System.out.println("-->Array");
		int []iarr = new int[10];
		for( int i = 0 ; i < iarr.length ; i++ ){
			iarr[i] = i+1;
			System.out.println("iarr["+i+"]="+iarr[i]);
		}
		System.out.println("-->Object-Class");
		String name = "tangyu";
		StringBuffer myname = new StringBuffer("ÌÆÓí");
		System.out.println("name="+name);
		System.out.println("myname"+myname);
		System.out.println("-->Interface, No test");
	}
	
}