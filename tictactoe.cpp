#include <cstdio>
#include <cstdlib>

typedef enum { kHumanWon, kComputerWon, kDraw, kNoResultYet} tResultTypes;

class Board
{
public:

	Board()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cells[i][j] = -1;
			}
		}
	}

	bool SetCell(int x, int y, int val)  // val = 0 or 1
	{
		if (x < 0 || x > 2 || y < 0 || y > 2)
		{
			printf("Invalid location! Please try again.\n");
			return false;
		}

		if (cells[x][y] != -1)
		{
			printf("Cell already filled! Please try again.\n");
			return false;
		}

		if (val != 0 && val != 1)
		{
			printf("Invalid value! Please try again.\n");
			return false;
		}

		cells[x][y] = val;
		return true;
	}

	void GetUnfilledCell(int& x, int& y)
	{
		bool done = false;
		while (!done)
		{
			int r = rand() % 3;
			int c = rand() % 3;
			if (cells[r][c] == -1)
			{
				x = r;
				y = c;
				done = true;
			}
		}
	}

	void PrintPrompt()
	{
		printf("Board\tMovement Key\n");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("%s", cells[i][j]==1? "X" : (cells[i][j]==0? "O" : " "));
				if (j < 2) 
				{
					printf("|");
				}
				else 
				{
					printf("\t%d|%d|%d\n", i*3+1, i*3+2, i*3+3);
				}
			}
		}
	}

	tResultTypes GetBoardResult()
	{
		if (IsRowFilledWith(0, 0) || IsRowFilledWith(1, 0) || IsRowFilledWith(2, 0) ||
			IsColumnFilledWith(0, 0) || IsColumnFilledWith(1, 0) || IsColumnFilledWith(2, 0) ||
			IsDiagonalFilledWith(0, 0) || IsDiagonalFilledWith(1, 0))
		{
			return kComputerWon;
		}
		
		if (IsRowFilledWith(0, 1) || IsRowFilledWith(1, 1) || IsRowFilledWith(2, 1) ||
			IsColumnFilledWith(0, 1) || IsColumnFilledWith(1, 1) || IsColumnFilledWith(2, 1) ||
			IsDiagonalFilledWith(0, 1) || IsDiagonalFilledWith(1, 1))
		{
			return kHumanWon;
		}

		if (AreAllCellsFilled())
		{
			return kDraw;
		}

		return kNoResultYet;
	}

private:
	bool AreAllCellsFilled()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (cells[i][j] == -1)
				{
					// this cell is not filled
					return false;
				}
			}
		}
		return true;
	}

	bool IsRowFilledWith(int row, int val)
	{
		return (cells[row][0] == val && cells[row][1] == val && cells[row][2] == val);
	}

	bool IsColumnFilledWith(int col, int val)
	{
		return (cells[0][col] == val && cells[1][col] == val && cells[2][col] == val);
	}

	bool IsDiagonalFilledWith(int diagIndex, int val)
	{
		// 0 == TL-BR diagonal, 1 = TR-BL diagonal
		if (diagIndex == 0)
		{
			return (cells[0][0] == val && cells[1][1] == val && cells[2][2] == val);
		}
		else
		{
			return (cells[0][2] == val && cells[1][1] == val && cells[2][0] == val);
		}
	}	

	int cells[3][3];   // 0 = O, 1 = x, -1 = unfilled	
};

bool IsGameComplete(tResultTypes t)
{
	return (t == kComputerWon || t == kHumanWon || t == kDraw);
}

const char *GetStringFromCoords(int x, int y)
{
	if (x == 0)
	{
		return (y==0? "upper left" : (y==1? "upper middle" : "upper right"));
	}
	else if (x == 1)
	{
		return (y==0? "center left" : (y==1? "center" : "center right"));
	}
	else
	{
		return (y==0? "lower left" : (y==1? "lower middle" : "lower right"));
	}
}

int main()
{
	Board bd;

	printf("Welcome to Tic-Tac-Toe. Enter 1-9.\n");

	typedef enum { kHumanTurn, kComputerTurn } tTurnType;
	tTurnType turn = kHumanTurn;

	int lastHumanMoveX = -1, lastHumanMoveY = -1;  // we echo the human's last move back to them
	tResultTypes boardResult = bd.GetBoardResult();
	while (!IsGameComplete(boardResult))
	{
		bd.PrintPrompt();

		bool changeTurn = false;
		if (turn == kHumanTurn)
		{
			printf("Where to? ");
			int cellLoc;
			scanf("%d", &cellLoc);
			lastHumanMoveX = (cellLoc-1)/3;
			lastHumanMoveY = (cellLoc-1)%3;
			if (bd.SetCell(lastHumanMoveX, lastHumanMoveY, 1))
			{
				changeTurn = true;
			}
		}
		else
		{
			int x, y;
			bd.GetUnfilledCell(x, y);
			bd.SetCell(x, y, 0);  // computer location

			// print prompt including human's last move and computer's current move
			printf("You have put an X in the %s. I will put an O in the %s.\n", 
				GetStringFromCoords(lastHumanMoveX, lastHumanMoveY),
				GetStringFromCoords(x, y));

			changeTurn = true;
		}
		if (changeTurn)
		{
			turn = (turn == kHumanTurn? kComputerTurn : kHumanTurn);
		}
		boardResult = bd.GetBoardResult();
	}

	// the game is over
	if (boardResult == kHumanWon)
	{
		printf("You have put an X in the %s. You have beaten my poor AI!\n", 
				GetStringFromCoords(lastHumanMoveX, lastHumanMoveY));
	}
	else if (boardResult == kComputerWon)
	{
		printf("Computer won! I'm afraid I can't do that, Dave.\n", 
				GetStringFromCoords(lastHumanMoveX, lastHumanMoveY));
	}
	else if (boardResult == kDraw)
	{
		printf("Game drawn.\n");
	}
	bd.PrintPrompt();

	return 0;
}