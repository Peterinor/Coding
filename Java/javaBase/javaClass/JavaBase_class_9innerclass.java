class JavaBase
{
	public static void main(String args[]){
		System.out.println("Java Basic Knowledge test:");

		System.out.println("Inner class or Nested class Test:");

		Student st = new Student("00000","tangyu");
		st.setScore(90,94,97);
		print(st);

		Student.Score sc = st.new Score(99,93,94);	//pay attention here! st.new
		st.setScore( sc );
		print(st);
		st.setScore( st.new Score(100,100,100) );	//used in same access area
		print(st);

		new InnerClass().print();		//will be error if this JavaBase.InnerClass is not static decleared

		anotherInnerClass();		//So, we know wo can define an inner class in any area if we want

	}

	public static void print( Student stu ){
		System.out.println("The infomation of " + stu.getName() + " is :");
		System.out.println("Name    :" + stu.getName());
		System.out.println("StuNo.  :" + stu.getStuno());
		System.out.println("Scores are:" + stu.getMath() + "," + stu.getEnglish() + "  " + stu.getComputer());
		System.out.println("The average score is:" + stu.scoreAvg());
		System.out.println("The sum of Score is :" + stu.scoreSum());	
	}

	static class InnerClass{	//must be static decleared, or (*) will go error
		public void print(){
			System.out.println("This is a class inner a method of a class!");
		}
	}
	public static void anotherInnerClass(){
		class InnerClass{
			public void print(){
				System.out.println("This is a class inner a method of a class!");
			}
		}
		new InnerClass().print();
	}
		
}


class Student{
	private String stuno;
	private String name;
	//-------------------------------------
	//----------Inner class ---------------
	//-------------------------------------
	class Score{
		public Score(){
		}
		public Score( float math, float english, float computer ){
			this.math = math;
			this.english = english;
			this.computer = computer;
		}
		private float math = 0;
		private float english = 0;
		private float computer = 0;
	}

	private Score score = new Score();

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

	void setScore( Score sc ){
		this.setScore( sc.math, sc.english, sc.computer );
	}

	void setScore( float math, float english, float computer ){
		this.score.math = math;			//-----+
		this.score.english = english;	//-----+-----we could access every area of the inner class, include the private area
		this.score.computer = computer;	//-----+
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
		return this.score.math;
	}
	float getEnglish(){
		return this.score.english;
	}
	float getComputer(){
		return this.score.computer;
	}

	float scoreSum(){
		return this.score.math + this.score.english + this.score.computer;
	}
	float scoreAvg(){
		return this.scoreSum()/3;
	}
	
}
