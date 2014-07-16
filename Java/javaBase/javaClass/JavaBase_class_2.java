class JavaBase
{
	public static void main(String args[]){
		System.out.println("Java Basic Knowledge test:");
		System.out.println("Java class Basic Knowledge test:");

		System.out.println("More Deeply!");

		Person me = new Person("tangyu",22);
		Person you = new Person("you",23);
		me.showInfo();
		you.showInfo();

		System.out.println("Me :" + me);		//Here output the reference of me
		//Let's do a test!
		Object obj = new Object();
		System.out.println("obj"+obj);
		System.out.println("obj"+obj.toString());	//We can find println to call the objects' toString() method as default print!!
												//That is to say, we can just define our toString() method to change the default print
												//Reference to PrintStream.println(Object x) , String.valueOf(Object x), Object.toString()
		PersonS mes = new PersonS("tangyu",22);
		System.out.println("Mes :" + mes);

	}
}


class Person{
	private String name;
	private int    age;

	public Person(){
		this.name = "A People";
		this.age  = 0;
	}
	public Person(String name, int age){
		this.name = name;
		this.age  = age;
	}
	
	public void showInfo(){
		System.out.println("The infomation of " + this.name);
		System.out.println("Name  :" + this.name);
		System.out.println("Age   :" + this.age );
		
	}
}

class PersonS{
	private String name;
	private int    age;

	public PersonS(){
		this.name = "A People";
		this.age  = 0;
	}
	public PersonS(String name, int age){
		this.name = name;
		this.age  = age;
	}
	
	public void showInfo(){
		System.out.println("The infomation of " + this.name);
		System.out.println("Name  :" + this.name);
		System.out.println("Age   :" + this.age );
		
	}
	public String toString(){
		return "Name   :" + this.name + "\n" + "Age    :" + this.age; 
	}
}
