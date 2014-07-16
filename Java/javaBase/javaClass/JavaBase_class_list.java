class JavaBase
{
	public static void main(String args[]){
		System.out.println("Java Basic Knowledge test:");
		System.out.println("Java class Basic Knowledge test:");

		System.out.println("A LinkList realized with Java!!");

		List list = new List();
		list.add( list.new Node("one",1) ,"" );
		list.add( list.new Node("tow",2) ,"" );
		list.add( list.new Node("thr",3) ,"" );
		list.add( list.new Node("fur",4) ,"" );
		list.add( list.new Node("fiv",5) ,"" );
		list.add( list.new Node("six",6) ,"" );
		list.add( list.new Node("sev",7) ,"" );
		list.traverse();

		list.delete( new Person( "one", 1));
		list.traverse();

		list.delete( new Person( "fur",4) );
		list.traverse();


	}
}



class List{
	//------------------------------
	class Node{
		private Person data;		//------Change here the Person for more datatype to use the list
		private Node   next;
		public Node(){
			this.data = new Person();
			this.next = null;
		}
		public Node( Person per ){
			this.data = per;
			this.next = null;
		}
		public Node( String name, int age ){
			this.data = new Person(name,age);
			this.next = null;	
		}
	};
	//-----------------------

	private Node head;
	private Node tail;

	public void add( 	Node node, 
						String pos /* pos = "head" add to head, or add to tail*/){
		if( null == head ){		//the list is empty
			head = node;
			tail = node;
		}
		else{
			tail.next = node;
			tail = node;
		}
	}

	public boolean delete(	Person per ){	//------Change here the Person for more datatype to use the list
											//Tips:the Node.data must reride the equals() function
		if( head.data.equals(per) ){		//head.data is the Person found
			head = head.next;
		}		
		Node tmp = this.head;
		while( null != tmp.next ){
			if( tmp.next.data.equals(per) ){
				tmp.next = tmp.next.next;
				return true;
			}
			tmp = tmp.next;
		}
		return false;
	}


	public void traverse(){	//traverse the list
		System.out.println("--------Travese the List:---------");
		Node tmp = this.head;
		Operate opt = new Operate();
		while( null != tmp ){
			opt.operate(tmp.data);
			tmp = tmp.next;
		}
	}
			
		

}


//Change the Operate class and the operate function for more other datatype
class Operate{
	public	void operate( Person per ){
		per.showInfo();
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

	public boolean equals( Person per ){
		return ( this.name.equals(per.name) ) && ( this.age == per.age );	
	}

	public void showInfo(){
		System.out.println("The infomation of " + this.name);
		System.out.println("Name  :" + this.name);
		System.out.println("Age   :" + this.age );
		
	}
}

