class JavaBase{
	public static void main( String args[] ){
		System.out.println("Java Basic Knowledge Test:");
		System.out.println("Java Array Test:");

		System.out.println("Pass and return a array in a method Test:");		

		float farray[] = { 89, (float)64.5, 90, 89, 87, 73, 94, 65, 57 };
		System.out.println("The origional data:");
		JavaBase.showArray(farray);

		//Find the max-min values
		System.out.println("The max value of farray is:" + JavaBase.max(farray));
		System.out.println("The min value of farray is:" + JavaBase.min(farray));
		

		//Sort here--1
		JavaBase.sort(farray);
		System.out.println("The sorted data:");
		JavaBase.showArray(farray);


		//Sort here--2
		farray = JavaBase.sort2(farray);
		System.out.println("The sorted data:");
		JavaBase.showArray(farray);	

		String tip = "Here wo know, so called array in java is just a common datatype, no special! Just use it like int or float!";
		System.out.println(tip);
	}


	// pass an array to a method 
	public static void sort( float []farray ){
		for( int i = 0; i < farray.length; i++ ){
			for( int j = i; j < farray.length; j++){
				if( farray[i] > farray[j]){
					float tmp = farray[i];
					farray[i] = farray[j];
					farray[j] = tmp;
				}
			}
		}		
	}

	public static void showArray( float []farray ){
		//show the array passed here
		for( int i = 0; i < farray.length; i++ ){
			System.out.print(farray[i]+"   ");
		}
		System.out.println();	
	}

	public static float max( float []farray ){
		//Find the max values
		float max = 0;
		max = farray[0];
		for( int i = 0; i < farray.length; i++ ){
			if( farray[i] > max ){
				max = farray[i];
				continue;
			}
		}
		return max;
	}

	public static float min( float []farray ){
		//Find the min values
		float min = 0;
		min = farray[0];
		for( int i = 0; i < farray.length; i++ ){
			if( farray[i] < min ){
				min = farray[i];
				continue;
			}
		}
		return min;
	}

	//return an array from a method
	public static float[] sort2( float []farray ){		//pay attention to the protype
		for( int i = 1; i < farray.length; i++ ){
			for( int j = 0; j < i; j++){
				if( farray[i] > farray[j]){
					float tmp = farray[i];
					farray[i] = farray[j];
					farray[j] = tmp;
				}
			}
		}
		return farray;									//and here
	}	//Here wo know, so called array in java is just a common datatype, no special! Just use it like int or float!		
	

}
