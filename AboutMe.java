/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gomoku;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.Box;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import java.awt.Component;
import javax.swing.UIManager;

public class AboutMe extends JDialog {
  public AboutMe(JFrame parent) {
    super(parent, "About Program", true);

    try {
                    UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
            } catch (Exception e) {}
    setResizable(false);
    Box b = Box.createVerticalBox();
    b.add(new JLabel(" Gra gomoku"));
    b.add(new JLabel(" Karol Bochenski"));
    b.add(new JLabel(" Grudzien - 2015"));
    getContentPane().add(b, "Center");
    
    Component horizontalStrut = Box.createHorizontalStrut(20);
    b.add(horizontalStrut);

    JPanel p2 = new JPanel();
    JButton ok = new JButton("Ok");
    p2.add(ok);
    getContentPane().add(p2, "South");

    ok.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent evt) {
        setVisible(false);
      }
    });

    setSize(219, 137);
  }
}