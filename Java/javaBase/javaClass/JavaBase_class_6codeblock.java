class JavaBase
{
	static{	//static block is established before all the code!!
			//So we cann't call even static method!
	//	System.out.println("AAAAA");		//----------------------------------------
	//		main();							//-------Attention! No main method!!!!----
	//}										//----------------------------------------
	//static void main(String args[]){
		System.out.println("Java Basic Knowledge test:");

		System.out.println("About so called code block!:");
		{
			System.out.println("Normal Code Block:");
		}
		//System.out.println("In main method");	

		new Person();
		new Person();
		new Person();	
	
		System.exit(0);
	}
}


class Person{
	private String name = "AAA";
	private int    age  = 0;

	{	//Constructor Block
		System.out.println("In Person's Constructor Block");	
	}

	static{
		System.out.println("In Person's Static Block");
	}

	//Constructor function
	public Person(){
		System.out.println("In Person's Constructor function");
		total++;
	}

	//Reride the toString() function
	public String toString(){
		return "The infomation of " + this.name +":\nName  :" + this.name + "\n" + "Age   :" + this.age + "\nTotal num of Person is:" + Person.total; 
	}

	//Static(Class) peroperty and function
	private static int total = 0;

	public static int getTotal(){
		return Person.total;
	}
}

