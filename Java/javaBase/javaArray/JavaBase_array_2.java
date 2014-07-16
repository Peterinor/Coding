class JavaBase{
	public static void main( String args[] ){
		System.out.println("Java Basic Knowledge Test:");
		System.out.println("Java Array Test:");

		System.out.println("Java Array index check Test:");
		
		int iarray[] = new int[10];
		System.out.println("The length of the iarray is :" + iarray.length );
		System.out.println("Now we will access the iarray[10], what will happen!");
		iarray[10] = 10;
		//------Here we find the index check function! This is a difference between java and c/c++
		//------And the index check is a runtime check!
	
	}
}
