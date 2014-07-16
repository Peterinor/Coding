class JavaClass{
	public static void main( String args[] ){
		System.out.println("Java Basic knoleage test:");
		System.out.println("Java Class Test");
		
		Shape a = new Shape();
		System.out.println(a.toString());	//toString() is a default Method equiped with all the java class
		a.showName();
		
		Triangle b = new Triangle();
		System.out.println(b.toString());
		b.showName();
		Triangle c = new Triangle("tangyu");
		System.out.println(c.toString());
		c.showName();
		Triangle.showAnInformation();
		c.showAnInformation();
		System.out.println("Total num of Triangle is:"+Triangle.num);
		
		Point d = new Point();
		Point e = new Point(50,50);
		System.out.println(d.toString());
		d.showName();
		e.showName();
		Point p[] = new Point[10];	//hasn't call the Constructor Method
		for( int i = 0; i < p.length ; i++ ){
			p[i] = new Point( i, i);	//here the Constructor Method called
		}
		System.out.println("Total num of Point is:"+Point.num);
	}
}

class Shape{
	String name;	//the default access level is Package Level
	/*	public  --- all		:in class , son class , Package and out of Package
		private	---	critical:just in Class
		protected--	family	:in class ,son class and Package family
		default	---	default	:Package
		*/
	//to reride the toString() method, the following formate is requied
	public String toString(){
		return "This is the Shape class";
	}
	public String getName(){
		return this.name;
	}
	public void showName(){
		System.out.println(this.name);
	}
	public Shape(){
		this.name = "Shape";
	}
}

final class Point extends Shape{
	static int num;
	int x, y;
	public String toString(){
		return "This is a Point";
	}
	public Point(int x, int y){
		this.name = "Point("+x+","+y+")";
		this.x = x;
		this.y = y;
		this.num ++;
	}
	public Point(){
		this.name = "Point(0,0)";
		this.x = 0;
		this.y = 0;
		this.num ++;
	}
	public static void showAnInformation(){
		System.out.println("This is a message from Point");
	}
}

final class Triangle extends Shape{
	static int num;		//the basic val in java all has it's own initial value!
	Point A, B, C;
	public String toString(){
		return "This is a Triangle";
	}
	public Triangle(){
		this.name = "Triangle";
		A = new Point();
		B = new Point();
		C = new Point();
		this.num ++;
	}
	public Triangle(String nname){
		this.name = "Triangle:"+nname;
		this.num ++;
	}
	public static void showAnInformation(){
		System.out.println("This is a message from Triangle");
	}
}
