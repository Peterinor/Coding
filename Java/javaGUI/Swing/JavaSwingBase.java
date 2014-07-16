import java.io.*;

import javax.swing.*;
import javax.swing.event.*;
import java.awt.event.*;
import java.awt.*;

public class JavaSwingBase{

    public static void main(String[] args){
        System.out.println("This is a test from java swing");

        System.setProperty("awt.useSystemAAFontSettings", "on");
        System.setProperty("swing.aatext","true");

        JSwingTest test = new JSwingTest();
	
        test.setVisible(true);	
        test.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	return;
    }
}


class JSwingTest extends JFrame{
    private JLabel label = new JLabel();
    public JSwingTest(){
        super();
        this.label.setBounds(30, 30, 60,20);
        this.label.setText("TestLabel");
        this.add(this.label);
        this.setSize(300, 300);
    }
}
