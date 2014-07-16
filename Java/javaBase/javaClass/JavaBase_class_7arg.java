class JavaBase
{
	public static void main(String args[]){
		System.out.println("Java Basic Knowledge test:");

		System.out.println("Object as argument and retrun value:");

		Student st = new Student("00000","tangyu");
		st.setScore(90,94,97);
		print(st);
		fun1(st);	//<<<<<-----------------------+
		print(st);	//							  +----to compare these two function
		fun2(st);	//<<<<<-----------------------+
		print(st);
		//We can conclude that the only form of argument pass is by value
		//And remember reference in java is just a value itself

		System.out.println( st.equals(new Student("2008","you")) );
		System.out.println( st.equals(st) );
		System.out.println( st.equals(new Student("00001","tangyu")) );
	}

	public static void print( Student stu ){
		System.out.println("The infomation of " + stu.getName() + " is :");
		System.out.println("Name    :" + stu.getName());
		System.out.println("StuNo.  :" + stu.getStuno());
		System.out.println("Scores are:" + stu.getMath() + "," + stu.getEnglish() + "  " + stu.getComputer());
		System.out.println("The average score is:" + stu.scoreAvg());
		System.out.println("The sum of Score is :" + stu.scoreSum());	
	}

	public static void fun1( Student stu ){	//Here stu is a copy of the real argument
		stu = new Student("2008","you");	//Here just the value of stu is changed instead of real argument
	}
	
	public static void fun2( Student stu ){
		stu.setName("you");
		stu.setStuno("2008");
	}
		
}


class Student{
	private String stuno;
	private String name;
	private float math = 0;
	private float english = 0;
	private float computer = 0;

	public Student(){
		this.stuno = "0000";
		this.name = "xxxx";
	}
	
	public Student(String stuno,String name){
		//this.stuno = stuno;
		//this.name = name;
		this.setName(name);
		this.setStuno(stuno);
	}
	
	public String toString(){
		return "Name   :" + this.name + "\nNumber :" + this.stuno;
	}

	public boolean equals( Student st ){
		if( this == st ) return true;
		if( this.stuno.equals(st.stuno) && this.name.equals(st.name) ){
			return true;
		}
		return false;
	}

	void setScore( float math, float english, float computer ){
		this.math = math;
		this.english = english;
		this.computer = computer;
	}

	void setStuno( String stuno ){
		this.stuno = stuno;
	}
	void setName( String name ){
		this.name = name;
	}
	String getStuno(){
		return this.stuno;
	}
	String getName(){
		return this.name;
	}

	float getMath(){
		return this.math;
	}
	float getEnglish(){
		return this.english;
	}
	float getComputer(){
		return this.computer;
	}

	float scoreSum(){
		return this.math + this.english + this.computer;
	}
	float scoreAvg(){
		return this.scoreSum()/3;
	}
	
}
