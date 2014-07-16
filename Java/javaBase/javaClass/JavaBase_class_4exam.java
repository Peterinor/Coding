class JavaBase
{
	public static void main(String args[]){
		System.out.println("Java Basic Knowledge test:");
		System.out.println("Java class Basic Knowledge test:");

		System.out.println("A exam about Class:");

		Student me = new Student("2008301470078","tangyu");
		System.out.println(me);
		me.setScore(90,87,95);
		System.out.println("The Sum of Score is:" + me.scoreSum());
		System.out.println("The Average of Score is:" + me.scoreAvg());	

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
