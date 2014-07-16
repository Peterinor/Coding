class JavaBase
{
	public static void main(String args[]){
		System.out.println("Java Basic Knowledge test:");

		System.out.println("sigle one Instance class Test:");

		//SigleInstance si = new SigleInstance();	-->Error
		SigleInstance si = SigleInstance.getInstance();	//------+
		si.print();										//		+
		SigleInstance s1 = SigleInstance.getInstance();	//------+---- Two reference but just one Instance!!!
		s1.print();

	}
}


//This class can just have sigle one Instance!!
//You know it is because of the private Constructor
class SigleInstance{
	private static SigleInstance si = new SigleInstance();

	private String msg = "Hello, This class just can build sigle one Instance";

	private SigleInstance(){	//private Constructor
	}
	
	public void print(){
		System.out.println(msg);
	}
	public static SigleInstance getInstance(){
		return SigleInstance.si;
	}
}
