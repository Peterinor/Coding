class JavaBase
{
	public static void main(String args[]){
		System.out.println("Java Basic Knowledge test:");
		System.out.println("Java class Basic Knowledge test:");

		System.out.println("The first glance at the java class!");

		Person me = new Person();
		me.name = "tangyu";
		me.age = 22;
		me.showInfo();
	}
}


class Person{
	String name;
	int    age ;
	
	public void showInfo(){
		System.out.println("The infomation of " + name);
		System.out.println("Name  :" + name);
		System.out.println("Age   :" + age );
		
	}
}
