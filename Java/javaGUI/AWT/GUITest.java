import java.awt.Frame;
class JavaGUI_awt{
	public static void main(String args[]){
		System.out.println("JavaGraphic UI:");
		System.out.println("This is a test program of JavaGraphic UI");
		Frame myFirst = new Frame("This is my first UI program,中文测试");
		myFirst.setVisible(true);
		myFirst.setSize(200,200);
	}
}
		
