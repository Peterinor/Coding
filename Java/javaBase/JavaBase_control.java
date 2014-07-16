class JavaBase
{
	public static void main(String args[]){
		System.out.println("Java Basic Knowledge test:");
		System.out.println("Java Controler:");

	/*	Error while 	------------------------+
	goto_lab:									+
		goto goto_lab;							+
	*/	//										+	
		//int goto = 7;		//--also Error <<---+
		//Here we know goto is a remain word in java

		/* if else test:*/
		System.out.println("---------IF_ELSE----------");
		float score = 50 ;
		if( score >= 90 ) System.out.println("The Level is A");
		else if( score >= 80 ) System.out.println("The Level is B");
		else if( score >= 70 ) System.out.println("The Level is C");
		else if( score >= 60 ) System.out.println("The Level is D");
		else System.out.println("The Level is E");
		
		/* switch case test:*/
		System.out.println("----------SWITCH------------");
		int level = (int )( score / 10 );
		switch(level)
		{
		case 10:
		case  9:System.out.println("The Level is A");break;
		case  8:System.out.println("The Level is B");break;
		case  7:System.out.println("The Level is C");break;
		case  6:System.out.println("The Level is D");break;
		case  5:
		case  4:
		case  3:
		case  2:
		case  1:
		case  0:System.out.println("The Level is E");break;
		default:System.out.println("Score Erroe");
		}
		
		
		/* for  test :*/
		System.out.println("----------------FOR--------------");
		int sum = 0 ;
		for( int i = 1 ; i <= 100 ; i++){
			sum += i;
		}
		System.out.println(" 9 x 9 table:");
		for( int i = 1; i < 10; i++ ){
			for( int j = 1; j <= i; j++){
				System.out.print(""+i+"x"+j+"="+i*j+"     ");
				//System.out.print(""+j+"x"+i+"="+i*j+"     ");
			}
			System.out.println();
		}
		System.out.println("The total sum of 1...100 is:"+sum);
		
		/*  while test:*/
		System.out.println("----------WHILE--------------");
		sum = 0;
		int i = 1;
		while( i <= 100){
			sum += i ;
			i++;
		}
		System.out.println("The total sum of 1...100 is:"+sum);
		
		/* do while test:*/
		System.out.println("---------DO_WHILE------------");
		sum = 0;
		i = 1;
		do{
			sum += i;
			i++;
		}while( i <= 100 );
		System.out.println("The total sum of 1...100 is:"+sum);
		
		/* continue test */
		System.out.println("-----------CONTINUE--------");
		int data[] = { 1,3,5,6,13,8,10,24,12,28,83,20 };
			
	//continue_label:
	/*we can find it almost invaluable also the break label
		because we know the label must be placed just before the loop	*/
		//System.out.println("Label continue");		//Label continue here
		//System.out.println("Normal continue");	//Normal continue here
		//print all the num bigger than 20
		for( i = 0 ; i < 12 ; i++ ){
			if( data[i] <= 20 ) continue;
			//-->if( data[i] <= 20 ) continue continue_label;
			else System.out.println("The "+i+"th num is:"+data[i]);
		}

		/* break test */		
		System.out.println("------------BREAK-------------");
		int searchNum = 24;
		//search for the number 24
		for( i = 0 ; i < 12 ; i++ ){
			if( data[i] == searchNum ){
				System.out.println("The index of the num is:"+(i+1));
				break;
			}
			System.out.println("The"+(i+1)+"th times running");
		}
	}
}
