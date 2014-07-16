class JavaBase{
	public static void main(String args[]){
		System.out.println("Java Basic Knowledge Test:");
		System.out.println("Java Array Test:");

		System.out.println("Java Array Basic Test:");

		//Declear and the Allocate!
		int iarray[] = null;	//declear a array -----A reference!
		iarray = new int[10];	//allocate memory for the array
		System.out.println("The length of the iarray is:" + iarray.length);
		System.out.println("And the default value of the iarray is:");
		for( int i = 0; i < iarray.length; i++ ){
			System.out.print(iarray[i]+"   ");
		}
		System.out.println();

		//Declear and the same time Allocate
		byte barray[] = new byte[5];
		System.out.println("The length of the barray is:" + barray.length);
		for( int i = 0; i < barray.length; i++ ){
			System.out.print(barray[i]+"   ");
		}
		System.out.println();

		//----------Does the Java VM Allocate the memory automatically?!
		//String sarray[10];	compile error
		//String sarray[10] = new String[10];
		//System.out.println("The length of the sarray is:" + sarray.length);
		//----------So, I know the Answer!
	}
}
