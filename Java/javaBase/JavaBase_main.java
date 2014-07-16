class JavaBase
{
	public 	//must be public
	static 	//must remain this
	void 	//int ;must be void!
	main(String args[]){
		System.out.println("Java Basic Knowledge test:");
		System.out.println("Java main method perform test:");
		//return 1;
		anotherMethod();
		//this.anotherMethod();		----Error , for the main method is static while 'this' is not
		//otherMethod();   ---Error , for not static method!
	}
	
	public static void anotherMethod(){
		System.out.println("anotherMethod for the main class test!");
	}
	
	public void otherMethod(){
		System.out.println("the otherMethod for the main class test!");
	}
	
}