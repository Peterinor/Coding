class JavaBase{
	public static void main( String args[] ){
		System.out.println("Java Basic Knowledge Test:");
		System.out.println("Java Array Test:");

		System.out.println("The sort and max-min algrithm Test:");		

		float farray[] = { 89, (float)64.5, 90, 89, 87, 73, 94, 65, 57 };
		System.out.println("The origional data:");
		for( int i = 0; i < farray.length; i++ ){
			System.out.print(farray[i]+"   ");
		}
		System.out.println();

		//Find the max-min values
		float max = 0, min = 0;
		max = min = farray[0];
		for( int i = 0; i < farray.length; i++ ){
			if( min > farray[i] ){
				min = farray[i];
				continue;
			}
			if( farray[i] > max ){
				max = farray[i];
				continue;
			}
		}
		System.out.println("The max value of farray is:" + max);
		System.out.println("The min value of farray is:" + min);
		

		//Sort here--1
		for( int i = 0; i < farray.length; i++ ){
			for( int j = i; j < farray.length; j++){
				if( farray[i] > farray[j]){
					float tmp = farray[i];
					farray[i] = farray[j];
					farray[j] = tmp;
				}
			}
		}
		System.out.println("The sorted data:");
		for( int i = 0; i < farray.length; i++ ){
			System.out.print(farray[i]+"   ");
		}
		System.out.println();	

		//Sort here--2
		for( int i = 1; i < farray.length; i++ ){
			for( int j = 0; j < i; j++){
				if( farray[i] > farray[j]){
					float tmp = farray[i];
					farray[i] = farray[j];
					farray[j] = tmp;
				}
			}
		}
		System.out.println("The sorted data:");
		for( int i = 0; i < farray.length; i++ ){
			System.out.print(farray[i]+"   ");
		}
		System.out.println();		
	
	}
}
