class JavaBase
{
	public static void main(String args[]){
		System.out.println("Java Basic Knowledge test:");
		System.out.println("java main method arguments test:");
		if(args.length == 0){
			System.out.println("Please use this class with arguments!");
		}
		else{
			System.out.println("The arguments you input :");
			for( int i = 0 ; i < args.length ; i++ ){
				System.out.println(i+":"+args[i]);
			}
		}
	}
}
/*
(1).java JavaBase Hello world
(2).java JavaBase "Hello World" "Hello Boy"
*/
