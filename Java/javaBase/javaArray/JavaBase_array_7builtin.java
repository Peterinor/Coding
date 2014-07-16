class JavaBase{
	public static void main( String args[] ){
		System.out.println("Java Basic Knowledge Test:");
		System.out.println("Java Array Test:");

		System.out.println("Something built in java for array Test:");		

		float farray[] = { 89, (float)64.5, 90, 89, 87, 73, 94, 65, 57 };
		System.out.println("The origional data:");
		JavaBase.showArray(farray);

		//Java built in sort!!
		System.out.println("Java built in Sort method:");
		java.util.Arrays.sort(farray);		//a sort method from java VM
		System.out.println("The sorted data:");
		JavaBase.showArray(farray);

		//so called foreach, another using of for loop
		System.out.println("So called foreach:");
		for( float x : farray ){
			System.out.print(" -" + x + "- ");
		}
		System.out.println();

		//valuable argments
		System.out.println("valuable argments test:");
		JavaBase.vargs1();
		JavaBase.vargs1(2);
		JavaBase.vargs1(3,5,4);
		JavaBase.vargs2();
		JavaBase.vargs2(2);
		JavaBase.vargs2(3,5,4);
		
	}


	public static void vargs1( int... args ){
		for( int i = 0; i < args.length; i++ ){
			System.out.println("The "+(i+1)+"th args is"+args[i]);
		}
	}	
	public static void vargs2( int... args ){
		int i = 0;
		for( int x : args ){
			System.out.println("The "+(++i)+"th args is"+x+" - "+args[--i]);	//----+
		}																		//	  +----Here we know so called valuable argments is just a  array!!!
	}	


	public static void showArray( float []farray ){
		//show the array passed here
		for( int i = 0; i < farray.length; i++ ){
			System.out.print(farray[i]+"   ");
		}
		System.out.println();	
	}

}
