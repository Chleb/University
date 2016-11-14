/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gomoku;

import java.awt.Font;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.event.ComponentEvent;
import java.awt.event.ComponentListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JPanel;
import javax.swing.border.BevelBorder;

import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.border.LineBorder;

import java.awt.Color;

public class GamePlane extends JPanel implements ComponentListener,MouseListener{

	/**
	 * Create the panel.
	 */
	int side_length,tile_number,tile_size;
	boolean field_markers,highlight_win;
	Font markerFont;
	GameController controller;
	GameFrame frame;
	static String[] letters = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S"};
	
	public GamePlane(GameFrame x) {
		frame = x;
        side_length = 312;
        controller = new GameController(true,frame);
		addComponentListener(this);
		addMouseListener(this);
		field_markers = false;
		highlight_win = false;
		tile_number = 19;
		tile_size = side_length/tile_number;
		markerFont = new Font("Italic", Font.PLAIN, tile_size - 4);
		
	}

	@Override
	public void paint(Graphics g)
	{
		super.paint(g);
	    markerFont = new Font("Italic", Font.PLAIN, tile_size - 4);
		g.setFont(markerFont);
		drawGrid(g);
		drawTiles(g);
		System.out.println(g.getFont().getSize());
		g.setColor(Color.RED);
		if(controller.win && highlight_win)
		{
			int offset = field_markers ? 1 : 0;
			g.drawLine((tile_size *(controller.win1.x + offset)) + tile_size/2
                                ,tile_size *(controller.win1.y+ offset) + tile_size/2
                                ,tile_size * (controller.win2.x+ offset) + tile_size/2
                                ,tile_size * (controller.win2.y+ offset) + tile_size/2);
		}
	}
	
	public void drawGrid(Graphics g)
	{
		g.setColor(Color.DARK_GRAY);
		g.fillRect(0, 0, tile_size*tile_number, tile_size*tile_number);
		g.setColor(Color.BLACK);
		for(int i = 0; i <= tile_number;i++)
		{
			g.setColor(Color.GRAY);
			g.drawLine(tile_size * i, 0, tile_size * i,tile_size * tile_number);
			g.drawLine(0,tile_size * i, tile_size * tile_number, tile_size * i);
			g.setColor(Color.BLACK);
			g.drawLine(tile_size * i + 1, 0, tile_size * i + 1,tile_size * tile_number);
			g.drawLine(0,tile_size * i + 1, tile_size * tile_number, tile_size * i + 1);
		}
		if(field_markers)
		{
			g.setColor(Color.WHITE);
			for(int i = 1; i < tile_number;i++)
			{
				g.drawString(letters[i-1], (i*tile_size) + tile_size/4, (tile_size*7)/8); 
				if(i < 10)
				    g.drawString(Integer.toString(i),6,(i*tile_size) + (tile_size*7)/8 );
				else
					g.drawString(Integer.toString(i),0,(i*tile_size) + (tile_size*7)/8 );
			}
		}
	}
	public void drawTiles(Graphics g)
	{
		int offset = field_markers ? 1 : 0;
		for(int i = 0;i < 19;i++)
		{
			for(int j = 0 ;j < 19;j++)
			{
				if(controller.board[i][j] == GameController.BLACK_TILE)
				{
					g.setColor(Color.BLACK);
					g.fillOval(tile_size *(i + offset) + 2, tile_size * (j+offset) + 2, tile_size - 3, tile_size - 3);
					g.setColor(Color.GRAY);
					g.fillOval(tile_size *(i + offset) + 2 + tile_size/8, tile_size * (j+offset) + 2 + tile_size/8, (tile_size - 3)/2, (tile_size - 3)/2);
				}
				if(controller.board[i][j] == GameController.WHITE_TILE)
				{
					g.setColor(Color.GRAY);
					g.fillOval(tile_size *(i + offset) + 2, tile_size * (j+offset) + 2, tile_size - 3, tile_size - 3);
					g.setColor(Color.WHITE);
					g.fillOval(tile_size *(i + offset) + 2 + tile_size/8, tile_size * (j+offset) + 2 + tile_size/8, (tile_size - 3)/2, (tile_size - 3)/2);
				}
			}
		}
	}
	public void setMarkers(boolean x)
	{
		field_markers = x;
	    tile_number = field_markers ? 20 : 19;
	    tile_size = side_length/tile_number;

	}
	
	public void setHighlight(boolean x)
	{
		highlight_win = x;
	}
	

	@Override
	public void componentHidden(ComponentEvent e) {}

	@Override
	public void componentMoved(ComponentEvent e) {}


	@Override
	public void componentResized(ComponentEvent arg0) {
	    Rectangle b = arg0.getComponent().getBounds();
	    if(b.width <= b.height){
	        arg0.getComponent().setBounds(b.x, b.y, b.width,b.width);
	        side_length = b.width - 1;
	    }
	    else
	    {
	    	arg0.getComponent().setBounds(b.x, b.y, b.height,b.height);
	    	side_length = b.height - 1;
	    }
	    tile_size = side_length/tile_number;
	}

	@Override
	public void componentShown(ComponentEvent e) {}

	@Override
	public void mouseClicked(MouseEvent e) 
	{
		int x = e.getX()/tile_size;
		int y = e.getY()/tile_size;
		if(field_markers)
		{
			x--;
			y--;
		}
		if(x >= 0 && y >= 0)
		{
			controller.tileSelected(x,y);
			repaint();
		}
	}

	@Override
	public void mouseEntered(MouseEvent e) {}

	@Override
	public void mouseExited(MouseEvent e) {}

	@Override
	public void mousePressed(MouseEvent e) {}

	@Override
	public void mouseReleased(MouseEvent e) {}

}