class JavaBase
{
	public static void main(String args[]){
		System.out.println("Java Basic Knowledge test:");
		System.out.println("Java class Basic Knowledge test:");

		System.out.println("A Test about this and static:");

		Person me  = new Person("tangyu",22);
		Person you = new Person("you",23);
		me.showInfo();
		System.out.println(you);
		System.out.println(me.equals(me));
		System.out.println(me.equals(you));
		System.out.println(me.equals(new Person("tangyu",22)));

		me.setState("USA");		//------------------------------------------+
		System.out.println("State  :" + me.getState());				//		+-------two are good!But this second is better!
		Person.setState("UK");	//------------------------------------------+
		System.out.println("State  :" + Person.getState());
			
	}
}


class Person{
	private String name = "";
	private int    age  = 0;

	//Constructor function
	public Person(){
		total++;
	}
	public Person(String name, int age){
		this();		//--------------------+---+------------>>>>>>Pay attention here, this() to call the Person() Constructor function
		this.setAge(age);		//--------+	  +
		this.setName(name);		//------------+
//		this();			---------->>>>>>Error
	}

	//Setter and Getter function
	public void setName( String name ){
		this.name = name;
	}
	public String getName(){
		return this.name;				//-------->>>>>look at this here
	}
	public void setAge( int age ){
		this.age = age;
	}
	public int getAge(){
		return this.age;
	}


	//Compare-----------------------------------+-->>>>>>>>>>>pay attention to this function
	public boolean equals(Person per){	//		+
		if(this == per) return true;	//------+
		if( this.name.equals(per.name) && this.age==per.age ) return true;
		return false;
	}
	
	public void showInfo(){
		System.out.println(this);		//-------->>>>>Here we find 'this' is just a reference to the object itself, 
										//-------->>>>>And this is a good coding compared with JavaBase_class_3.java
		
	}
	//Reride the toString() function
	public String toString(){
		return "The infomation of " + this.name +":\nName  :" + this.name + "\n" + "Age   :" + this.age + "\nTotal num of Person is:" + Person.total; 
	}

	//Static(Class) peroperty and function
	private static int total = 0;

	private static String state = "China";
	
	public static void setState( String state ){
		Person.state = state;
	}
	
	public static String getState(){
		return Person.state;
	}

	public static int getTotal(){
		return Person.total;
	}
}

