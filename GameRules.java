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

public class GameRules extends JDialog {
  public GameRules(JFrame parent) {
    super(parent, "Gomoku Rules", true);
    try {
                    UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
            } catch (Exception e) {}

    setResizable(false);
    Box b = Box.createVerticalBox();
    b.add(new JLabel("Gracze zajmują pola na przemian, dążąc do objęcia pięciu pól w jednej\n" +
" linii"));
    b.add(new JLabel("Do zajęcia pola używa się pionów (jeden z graczy używa pionów czarnych a drugi białych)."));
    b.add(new JLabel("Pole może być zajęte tylko przez jednego gracza i nie zmienia właściciela do końca gry."));
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

    setSize(530, 137);
  }
}