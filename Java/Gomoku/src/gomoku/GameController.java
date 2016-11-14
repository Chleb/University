/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gomoku;

import java.util.ArrayList;
import java.util.Random;

public class GameController {

	GameFrame frame;
	public int[][] board = new int[19][19];
	boolean players_turn, win = false;
	int players_tile,AI_tile;
	public Pair win1,win2;
	static final int EMPTY_TILE = 0;
	static final int BLACK_TILE = 1;
	static final int WHITE_TILE = 2;
	
	class Pair
	{
		int x;
		int y;
		
		Pair(int x,int y)
		{
			this.x = x;
			this.y = y;
		}
	}
	public GameController(boolean player_start,GameFrame x)
	{
		frame = x;
		players_turn = player_start;
		for(int i = 0; i < 19; i++)
			for(int j = 0; j < 19; j++)
				board[i][j] = 0;
		if(player_start)
		{
			players_tile = BLACK_TILE;
			AI_tile = WHITE_TILE;
		}
		else
		{
			players_tile = WHITE_TILE;
			AI_tile = BLACK_TILE;
			AITurn();
                        players_turn = true;
		}
	}
	
	public void tileSelected(int x, int y)
	{
		if(players_turn)
		{
			if(board[x][y] == 0)
			{
				board[x][y] = players_tile;
				frame.message("Postawiles pionka na polu (" + (x+1) + ", " + GamePlane.letters[y] + ")");
				players_turn = false;
				if(checkWin(players_tile))
					frame.win(true);
				else
				{
				AITurn();
				if(checkWin(AI_tile))
					frame.win(false);
				else
					players_turn = true;
				}
			}
		}
	}
	boolean checkWin(int tileColor)
	{
		int row;
		for(int i = 0; i < 19;i++)
		{
			row = 0;
			for(int j = 0; j < 19; j++)
			{
				if(board[i][j] == tileColor)
					row++;
				else
					row = 0;
				if(row == 5)
				{
					win1 = new Pair(i,0);
					win2 = new Pair(i,19);
					win = true;
					return true;
				}
			}
		}
		for(int i = 0; i < 19;i++)
		{
			row = 0;
			for(int j = 0; j < 19; j++)
			{
				if(board[j][i] == tileColor)
					row++;
				else
					row = 0;
				if(row == 5)
				{
					win1 = new Pair(0,i);
					win2 = new Pair(19,i);
					win = true;
					return true;
				}
			}
		}
		for(int i = 4; i < 19;i++)
		{
			row = 0;
			for(int j = 0; j <= i; j++)
			{
				if(board[i-j][j] == tileColor)
					row++;
				else
					row = 0;
				if(row == 5)
				{
					win1 = new Pair(i,0);
					win2 = new Pair(0,i);
					win = true;
					return true;
				}
			}
		}	
		for(int i = 4; i < 19;i++)
		{
			row = 0;
			for(int j = 0; j <= i; j++)
			{
				if(board[18-(i-j)][18-j] == tileColor)
					row++;
				else
					row = 0;
				if(row == 5)
				{
					win1 = new Pair(19,17-i);
					win2 = new Pair(17-i,19);
					win = true;
					return true;
				}
			}
		}	
		for(int i = 4; i < 19;i++)
		{
			row = 0;
			for(int j = 0; j <= i; j++)
			{
				if(board[i-j][18-j] == tileColor)
					row++;
				else
					row = 0;
				if(row == 5)
				{
					win1 = new Pair(0,17-i);
					win2 = new Pair(i+2,19);
					win = true;
					return true;
				}
			}
		}	
		for(int i = 4; i < 19;i++)
		{
			row = 0;
			for(int j = 0; j <= i; j++)
			{
				if(board[18-(i-j)][j] == tileColor)
					row++;
				else
					row = 0;
				if(row == 5)
				{
					win1 = new Pair(7,7);
					win2 = new Pair(8,8);
					win = true;
					return true;
				}
			}
		}	
		return false;
	}
	void AITurn()
	{
		int highestValue = 0;
		int currentValue = 0,currentLineCreateValue = 0,currentLineBreakValue = 0;
		ArrayList<Pair> valueList = new ArrayList<Pair>();
		for(int i = 0; i < 19; i++)
			for(int j = 0;j < 19; j++)
			{
				if(board[i][j] == EMPTY_TILE)
				{
					for(int l = -1; l <= 1; l++)
						for(int m = -1; m <= 1;m++)
						{
							for(int k = 1; k < 5;k++)
							{
								if(i + (k*l) >= 0 && i + (k*l) <= 18 && j + (k*m) >= 0 && j + (k*m) <= 18 && !(l==0 && m ==0))
								{
									if(board[i + (k*l)][j + (k*m)] == players_tile)
									{
									    currentLineBreakValue += (5-Math.abs(k))*5;
									    currentLineBreakValue *= 10;
									}
									if(board[i + (k*l)][j + (k*m)] == AI_tile)
									{
                                                                            currentLineCreateValue += (5-Math.abs(k))*10;
                                                                            currentLineCreateValue *= 10;
									}
								}
							}
							currentValue += currentLineBreakValue + currentLineCreateValue;
							currentLineCreateValue = 0;
							currentLineBreakValue = 0;
				        }
					if(currentValue > highestValue)
					{
						valueList = new ArrayList<Pair>();
						highestValue = currentValue;
						valueList.add(new Pair(i,j));
					}
					if(currentValue == highestValue)
						valueList.add(new Pair(i,j));
				}
				currentValue = 0;
			}
		Pair chosen = valueList.get(new Random().nextInt(valueList.size()));
		board[chosen.x][chosen.y] = AI_tile;
		frame.message("Komputer postawil pionka: (" + (chosen.y+1) + ", " + GamePlane.letters[chosen.x] + ")");
	}
	
}