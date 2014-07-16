import java.awt.*;
import java.awt.event.*;
class JavaGUI_awt{
	public static void main(String args[]){
		System.out.println("JavaGraphic UI:");
		System.out.println("This is a test program of JavaGraphic UI");
		Frame myFirst = new Frame("This is my first UI program");
		//WindowListener
		myFirst.addWindowListener(new WindowAdapter(){
			public void windowClosing( WindowEvent we){
				System.out.println("Windows Closing");
				System.exit(0);
			}
			public void windowClosed( WindowEvent we ){
				System.out.println("Windows Closed");
			}
			public void windowOpened( WindowEvent we ){
				System.out.println("Windows opened");
			}
			public void windowStateChanged( WindowEvent we ){
				System.out.println("Windows State Changed");
			}
		});
		//KeyListener
		myFirst.addKeyListener(new KeyAdapter(){
			public void keyPressed( KeyEvent ke ){
				System.out.println("Key Pressed :"+ke.getKeyChar());
			}
			public void keyReleased( KeyEvent ke ){
				System.out.println("Key Released :"+ke.getKeyChar());
			}
			public void keyTyped( KeyEvent ke ){
				System.out.println("keyTyped :"+ke.getKeyChar());
			}
		});
		//MouseListener
		myFirst.addMouseListener( new MouseAdapter(){
			//
			public void mouseClicked( MouseEvent me ){
				System.out.println("Mouse Clicked:"+me.getPoint());
			}
			public void mousePressed( MouseEvent me ){
				System.out.println("Mouse Pressed:"+me.getPoint());
			}
			public void mouseReleased( MouseEvent me ){
				System.out.println("Mouse Released:"+me.getPoint());
			}
			//
			public void mouseEntered( MouseEvent me ){
				System.out.println("Mouse Entered:"+me.getPoint());
			}
			public void mouseExited( MouseEvent me ){
				System.out.println("Mouse Leaved:"+me.getPoint());
			}
			//
		});
		//MouseMotionListener
		myFirst.addMouseMotionListener( new MouseMotionAdapter(){
			public void mouseDragged( MouseEvent me ){
				System.out.println("Mouse Dragged:"+me.getPoint());
			}
			public void mouseMoved( MouseEvent me ){
				System.out.println("Mouse Moved:"+me.getPoint());
			}
		});
		
		Button abtn = new Button("Press me Please");
		class BtnEven implements ActionListener{
			public void actionPerformed( ActionEvent ae ){
				System.out.println("Btn Pressed");
			}
		}
		abtn.addActionListener(new BtnEven());
		abtn.setSize(100,50);
		//myFirst.add(abtn);
		//myFirst.add(abtn);
		
		myFirst.setLayout(new FlowLayout());
		myFirst.setVisible(true);
		myFirst.setSize(600,400);
	}
}
		
