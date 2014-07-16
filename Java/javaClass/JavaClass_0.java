class JavaClass /* extends Object */ {
	public static void main( String args[] ){
		System.out.println("Java Basic knoleage test:");
		System.out.println("Java Class Test");
		
		Shape a = new Shape();
		System.out.println(a);	//toString() is a default Method equiped with all the java class
	
	}
}

class Shape /* extends Object */{
	//to reride the toString() method, the following formate is requied
	public String toString(){
		return "This is the Shape class";
	}
}
