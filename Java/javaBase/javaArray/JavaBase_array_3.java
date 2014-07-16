class JavaBase{
	public static void main( String args[] ){
		System.out.println("Java Basic Knowledge Test:");
		System.out.println("Java Array Test:");

		System.out.println("Java Array Initialization Test:");
		
		int iarray[] = new int[10];		//Here we know the init value of java array, change the int type, also for other basic type
		System.out.println("Auto Initialization:");		
		for( int i = 0; i < iarray.length; i++ ){
			System.out.print(iarray[i]+"   ");
		}
		System.out.println();

		//Here the Third method to declear an array, go back to the file JavaBase_array_1.java for more!!
		//declear and initialize
		float farray[] = { 89, (float)64.5, 90, 89, 87, 73, 94, 65, 57 };
		System.out.println("Static initialization");
		for( int i = 0; i < farray.length; i++ ){
			System.out.print(farray[i]+"   ");
		}
		System.out.println();
	
	}
}
