#include <bits/stdc++.h>

using namespace std;

void header()
{
	system ("clear");
	// replace the above line with the one below if you use windows:
	// system ("cls");
	
	cout << "[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[ Sudoku Tomodachi ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]" << endl;
	cout << endl << endl;
}

bool isValid (vector <vector <char> > &board, int rowNumber, int columnNumber, char currentNumber)
{
	for (int i = 0; i < 9; i++)
    {
		if (board[i][columnNumber] == currentNumber)
			return false;

		if (board[rowNumber][i] == currentNumber)
			return false;

		if (board[3*(rowNumber/3) + i/3][3*(columnNumber/3) + i%3] == currentNumber)
			return false;
	}
	return true;
}

bool solve (vector<vector<char> > &board)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j] == '.')
            {
                for (char possibleNumber = '1'; possibleNumber <= '9'; ++possibleNumber)
                {
                    if (isValid (board, i, j, possibleNumber))
                    {
                    	// displaying the board:
                    	system ("cls");
                    	
                    	for (int x = 0; x < 9; ++x)
                    	{
                    		for (int y = 0; y < 9; ++y)
                    		{
                    			cout << board[x][y] << ' ';
							}
							cout << endl;
						}
						
                        board[i][j] = possibleNumber;
                        
                        if (solve (board))
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    
    return true;
}

void solveSudoku (vector<vector<char> > &board)
{
    solve (board);
}

int main()
{
	char choice;
	do 
	{
		header();

		cout << "Welcome to Sudoku Tomodachi - a Sudoku solver" << endl;
		cout << "Press 'y' to begin" << endl;
		
		cin >> choice;
	}
	while (tolower (choice) != 'y');
	
	header();
	
	vector<vector<char> > board (9, vector<char> (9, '.'));
	
	cout << "Enter the Sudoku board that you want Sudoku Tomodachi to solve:" << endl;
	
	// input:
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> board[i][j];
		}
	}
	
	solveSudoku (board);
	
	header();
	
	cout << "Sudoku Tomodachi's result:" << endl << endl;
	
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}
