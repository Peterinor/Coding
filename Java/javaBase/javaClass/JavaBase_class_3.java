class JavaBase
{
	public static void main(String args[]){
		System.out.println("Java Basic Knowledge test:");
		System.out.println("Java class Basic Knowledge test:");

		System.out.println("More Deeply!");

		Person me  = new Person("tangyu",22);
		Person you = new Person("you",23);
		me.showInfo();
		you.showInfo();
		System.out.println(me);	

		new Person("Noname",20).showInfo();	//no name object
		{
			new Person("Another",20).showInfo();
		}
		System.out.println(new Person("Third",20));

		//Object Array!!
		Person per[] = new Person[5];		//	(*)	just declear 5 reference
		me.showInfo();		//Here the Total num of Person is still 5
							//That is to say, (*) does not Allocate for the per Array
		//per[0].showInfo();	---running Error, reason has motioned before
		//so, a member of a object Array must be Allocate before used

		Person ps[] = { new Person("tangyu",22), new Person("xxxx",21), new Person("yyyy",32) };
		for( int i = 0; i < ps.length; i++ ){
			ps[i].showInfo();
		}
			
	}
}


class Person{
	//---------Instance peroperty and function
	//Here using private to ...
	private String name = "";
	private int    age  = 0;	//you could do it like this in java while not in c/c++

	//Constructor function
	public Person(){
		total++;
	}
	public Person(String name, int age){
		this();		//------------------------------------->>>>>>Pay attention here, this() to call the Person() Constructor function
		this.name = name;
		this.age  = age;
	}

	//Setter and Getter function
	public void setName( String name ){
		this.name = name;
	}
	public String getName(){
		return this.name;
	}
	public void setAge( int age ){
		this.age = age;
	}
	public int getAge(){
		return this.age;
	}
	
	public void showInfo(){
		System.out.println("The infomation of " + this.name);
		System.out.println("Name  :" + this.name);
		System.out.println("Age   :" + this.age );
		System.out.println("Total num of Person is:" + Person.total);
		
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

