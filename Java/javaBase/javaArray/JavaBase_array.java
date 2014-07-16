class JavaBase
{
	public static void main(String args[]){
		System.out.println("Java Basic Knowledge test:");
		System.out.println("Java Array Test:");
		
		//One Decimal Array
		System.out.println("1D Array");
		int iarray[] = new int[10];
		System.out.println("The ID of iarray is:"+iarray);
		System.out.println("The length of the iarray is:"+iarray.length);
		for( int i = 0 ; i < 10 ; i++ ){
			iarray[i] = i+1;
			System.out.println("The "+(i+1)+"th is:"+i);
		}
		
		//Two Decimal Array------the Array of Array
		System.out.println("2D Array");
		short ssarray[][] = new short[10][];	//--------------|	so here also could be like this,we call the first index main index
												//				|	which must be pointed while the other not.
		for( int i = 0; i < 10 ; i++ ){			//				|
			//ssarray[i] = new short[10];		//				|
			ssarray[i] = new short[11];	/* this run well*///<---|
		}
		for( int i = 0; i < 10; i++ ){
			for( int j = 0; j < ssarray[i].length ; j++ ){
				ssarray[i][j] = (short)(10*i+j);
				System.out.print(ssarray[i][j]+"  ");
			}
			System.out.println("");
		}
		
		//Different length Array--------the Array of Array
		System.out.println("Different length Array");
		byte barray[][]={{1,2,3,4},{5,6,7},{8,9},{0}};
		for( int i = 0; i < barray.length; i++ ){
			System.out.println("The "+(i+1)+"the Array's length is:"+barray[i].length);
		}
		//Display the Array
		for( int i = 0; i< barray.length; i++ ){
			for( int j = 0; j < barray[i].length; j++){
				System.out.print(barray[i][j]+"    ");
			}
			System.out.println("");
		}
	}
}
