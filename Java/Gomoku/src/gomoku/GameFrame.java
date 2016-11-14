/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gomoku;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JMenuBar;
import javax.swing.JMenu;

import java.awt.Component;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.logging.Level;
import java.util.logging.Logger;



import javax.swing.Box;
import javax.swing.ButtonGroup;
import javax.swing.JLabel;
import javax.swing.JMenuItem;
import javax.swing.JRadioButtonMenuItem;
import javax.swing.JCheckBoxMenuItem;
import javax.swing.SwingConstants;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

public class GameFrame extends JFrame{

	private JPanel contentPane;
	private JLabel lblNewLabel;
	private boolean player_starts;
        AboutMe dialog1 = new AboutMe(this);
        GameRules dialog2 = new GameRules(this);
	GamePlane panel;

	/**
	 * Launch the application.
	 */
	public void win(boolean x)
	{
		if(x)
			message("Wygrales!");
		else
			message("Porazka!");
	}
	
	public void message(String x)
	{
		lblNewLabel.setText(x);
	}
	public void newGame()
	{
		panel.controller = new GameController(player_starts,this);
		if(player_starts)
			message("Nowa gra, ty zaczynasz!");
		else
			message("Nowa gra, ruch komputera.");
		repaint();
	}
	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					GameFrame frame = new GameFrame();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public GameFrame() {
            try {
                    UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
            } catch (Exception e) {}
		player_starts = true;
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 340, 400);
		setMinimumSize(new Dimension(340, 400));
		
		JMenuBar menuBar = new JMenuBar();
		setJMenuBar(menuBar);
		
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(new BorderLayout(0, 0));
		
		lblNewLabel = new JLabel("Nowa Gra");
		contentPane.add(lblNewLabel, BorderLayout.SOUTH);

		
        panel = new GamePlane(this);
		contentPane.add(panel);
		
		JMenu mnNewMenu = new JMenu("Game");
		menuBar.add(mnNewMenu);
		
		JMenuItem mntmNewGame = new JMenuItem("Nowa gra!");
		mnNewMenu.add(mntmNewGame);
		
		mntmNewGame.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e)
            {
            	newGame();
            }
		});
		
		JMenuItem mntmExit = new JMenuItem("Exit");
		mnNewMenu.add(mntmExit);
		mntmExit.addActionListener(new ActionListener() {
		    public void actionPerformed(ActionEvent e)
		    {
		       dispose();
		    }
		});
		
		JMenu mnNewMenu_1 = new JMenu("Options");
		menuBar.add(mnNewMenu_1);
		
		JCheckBoxMenuItem chckbxmntmRowMarkers = new JCheckBoxMenuItem("Row Markers");
		mnNewMenu_1.add(chckbxmntmRowMarkers);
		chckbxmntmRowMarkers.addActionListener(new ActionListener() {
		    public void actionPerformed(ActionEvent e)
		    {
		       panel.setMarkers(chckbxmntmRowMarkers.getState());
		       panel.repaint();
		    }
		});
		
		
		JCheckBoxMenuItem chckbxmntmHighlightWinner = new JCheckBoxMenuItem("Highlight Winner");
		mnNewMenu_1.add(chckbxmntmHighlightWinner);
		chckbxmntmHighlightWinner.addActionListener(new ActionListener() {
		    public void actionPerformed(ActionEvent e)
		    {
		       panel.setHighlight(chckbxmntmHighlightWinner.getState());
		       panel.repaint();
		    }
		});
		
		JMenu mnStarting = new JMenu("Starting");
		mnNewMenu_1.add(mnStarting);
		
		JRadioButtonMenuItem rdbtnmntmPlayer = new JRadioButtonMenuItem("Player");
		JRadioButtonMenuItem rdbtnmntmComputer = new JRadioButtonMenuItem("Computer");
		ButtonGroup group = new ButtonGroup();
		group.add(rdbtnmntmPlayer);
		group.add(rdbtnmntmComputer);
		
		rdbtnmntmPlayer.setSelected(true);
		mnStarting.add(rdbtnmntmPlayer);
		
		mnStarting.add(rdbtnmntmComputer);
		
		rdbtnmntmPlayer.addActionListener(new ActionListener() {
		    public void actionPerformed(ActionEvent e)
		    {
		       player_starts = true;
		    }
		});
		rdbtnmntmComputer.addActionListener(new ActionListener() {
		    public void actionPerformed(ActionEvent e)
		    {
		       player_starts = false;
		    }
		});
		
		Component horizontalGlue = Box.createHorizontalGlue();
		menuBar.add(horizontalGlue);
		
		JMenu mnNewMenu_2 = new JMenu("Help");
		menuBar.add(mnNewMenu_2);
		
		JMenuItem mntmGomokuabout = new JMenuItem("Gomoku");
		mntmGomokuabout.setHorizontalAlignment(SwingConstants.TRAILING);
		mnNewMenu_2.add(mntmGomokuabout);
		mntmGomokuabout.addActionListener(new ActionListener() {
		    public void actionPerformed(ActionEvent e)
		    {
		       dialog2.setVisible(true);
		    }
		});
                
                
		JMenuItem mntmAuthor = new JMenuItem("Author");
		mnNewMenu_2.add(mntmAuthor);
                mntmAuthor.addActionListener(new ActionListener() {
		    public void actionPerformed(ActionEvent e)
		    {
		       dialog1.setVisible(true);
		    }
		});
            }
}