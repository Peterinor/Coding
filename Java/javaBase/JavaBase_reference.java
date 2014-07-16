class JavaBase
{
	public static void main(String args[]){
		System.out.println("Java Basic Knowledge test:");
		System.out.println("Java Reference type test:");
		/*
			As we know java just offer the value pass for the basic type,
			while Reference pass required by all the nonbasic ones!
			So value name or Reference is not decided by us! but java itself
			*/
		//by value
		int iv = 10;
		float fv = 10;/*float fv = 10.0; ---ERROR*/
		char cv = 'c';
		
		//by Reference
		//Array
		System.out.println("Array Test");
		int [] iarray;
		iarray = new int[10];
		byte barray [] ;
		barray = new byte[10];
		char [] carray = new char[10];
		double darray [] = new double[10];
		short sarray [] = {1,2,3,4,6,7};
		long [] larray = {1,2,3,4,6,8};
		
		for( int i = 0 ; i < sarray.length ; i++ ){
			System.out.println("The "+(i+1)+"th num of larray is:"+larray[i]);
		}
		
		//Object, off cause include the interface
		System.out.println("Object Test");
		String name = "tangyu";
		String ty   = "wangjuan";	
		name = ""+"wangjuan";	//(----------*------------)
		/*name = "wangjuan"; --Error */
		System.out.println( (name == ty) ? "name == ty" : "name != ty" );
		
		StringBuffer nname = new StringBuffer("wangjuan");
		/*	nname = "wangjuan"; -- Error */
		nname = new StringBuffer("wangjuan");	//(----------*------------)
		StringBuffer wj = new StringBuffer("wangjuan");
		System.out.println( (nname == wj) ? "wangjuan == nname" : "wangjuan != nname");
		
		/*	Not only String but also StringBuffer don't support reset it's value , but we can do it like the marked place (----------*------------)*/
		
		
		System.out.println(aTest());
		
	}
	
	
	public static Integer aTest(){
		Integer rg = new Integer(5);
		Integer dg = rg;
		rg = null;
		return dg;		//----return 5
		//return rg;	--return null
	}
}
