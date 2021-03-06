


#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <string>
using namespace std;

//functions


void allocateArray(int **&arr, int size)
{
	arr = new int*[size];
	for (int i = 0; i < size; i++)
		arr[i] = new int[size];
}//allocateArray
void saveGame(int **&arr, char **&dummy, int size)
{
	ofstream fout;
	fout.open("C:/Users/ZED/Desktop/University Work/game/save.txt");


	//printing the grid
	bool flag = true, anflag = false;
	int counter = (size*size), index = 0;	//variables for actual grid
	int ancounter = (size*size), copyIndex = 0;	//variables for dummy grid


	//printing the grid values
	for (int i = size - 1; i >= 0; i--)
	{
		if (flag == true)
		{
			int temp = counter;	//variables for actual grid
			int tempCopy = ancounter;	//variables for dummy grid
			if (size % 2 == 0)		//printing the grid if size is even
			{
				for (int j = ((counter - size) + 1); j <= temp; j++, counter--)		//priting actual grid
				{
					fout << arr[i][index++] << " ";
				}//for
				fout << endl;
			}
			else if (size % 2 != 0)		//printing the grid if size is odd
			{
				int limit = (size*size);
				for (int j = (limit - size); j < limit; j++)
				{
					fout << arr[i][index++] << " ";
				}//for
				fout << endl;
			}

			if (size % 2 == 0)		//printing the dummy grid if size is even
			{
				for (int j = ((ancounter - size) + 1); j <= tempCopy; j++, ancounter--)		//printing dummy grid
				{
					fout << dummy[i][copyIndex++] << " ";
				}//for
				fout << endl;
			}
			else if (size % 2 != 0)		//printing the dummy grid if size is odd
			{
				int limit = (size*size);
				for (int j = (limit - size); j < limit; j++)
				{
					fout << dummy[i][copyIndex++] << " ";
				}//for
				fout << endl;
			}
		}
		else if (flag == false)
		{
			int temp = counter;	//variables for actual grid
			int tempCopy = ancounter;	//variables for dummy grid
			if (size % 2 == 0)		//printing the grid if size is even
			{
				for (int j = counter; j >= ((temp - size) + 1); j--, counter--)		//printing actual grid
				{
					fout << arr[i][--index] << " ";
				}//for
				fout << endl;
			}
			else if (size % 2 != 0)		//printing the grid if size is odd
			{
				int limit = (size*size);
				for (int j = (limit - size); j < limit; j++)
				{
					fout << arr[i][--index] << " ";
				}//for
				fout << endl;
			}

			if (size % 2 == 0)		//printing the dummy grid if size is even
			{
				for (int j = ancounter; j >= ((tempCopy - size) + 1); j--, ancounter--)		//printing dummy grid
				{
					fout << dummy[i][--copyIndex] << " ";
				}//for
				fout << endl;
			}
			else if (size % 2 != 0)		//printing the dummy grid if size is odd
			{
				int limit = (size*size);
				for (int j = (limit - size); j < limit; j++)
				{
					fout << dummy[i][--copyIndex] << " ";
				}//for
				fout << endl;
			}
		}
		swap(flag, anflag);
	}//for
	fout.close();

}//saveGame
void printGrid(int **&arr, char **&dummy, int size)
{
	//it is done in 2 steps
	//1. filling values of array (grid) with 0-to-size integers
	//2. printing it in form of grid

	int limitCopy = (size*size);	//variable for actual grid
	int copyIndex = 0, limitCopyDummy=(size*size);	//variable for dummy grid

	//filling the grid
	int k = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			arr[i][j] = k++;
	}//for

	//variables for printing the grid
	bool flag = true, anflag = false;
	int counter = (size*size), index = 0;


	//filling the char(dummy) array with spaces
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			dummy[i][j] = '*';
	}//for

	//printing the grid values
	for (int i = size - 1; i >= 0; i--)
	{
		if (flag == true)
		{
			if (size % 2 == 0)		//printing the actual grid if size is even
			{
				int temp = counter;
				for (int j = ((counter - size) + 1); j <= temp; j++, counter--)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << arr[i][index++] << "\t" << "|" << "\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}//for
				cout << endl;
			}
			else if (size % 2 != 0)		//printing the actual grid if size is odd
			{
				int limit = (size*size);
				for (int j = (limit - size); j < limit; j++, limitCopy--)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << arr[i][index++] << "\t" << "|" << "\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}//for
				cout << endl;
			}

			if (size % 2 == 0)		//printing the dummy grid if size is even
			{
				for (int j = 0; j < size; j++)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << dummy[i][copyIndex++] << "\t" << "|" << "\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}//for
				cout << endl;
			}
			else if (size % 2 != 0)		//printing the dummy grid if size is odd
			{
				int limit = (size*size);
				for (int j = (limit - size); j < limit; j++, limitCopyDummy--)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << dummy[i][copyIndex++] << "\t" << "|" << "\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}//for
				cout << endl;
			}
		}
		else if (flag == false)
		{
			if (size % 2 == 2)		//printing the actual grid if size is even
			{
				int temp = counter;
				for (int j = counter; j >= ((temp - size) + 1); j--, counter--)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << arr[i][--index] << "\t" << "|" << "\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}//for
				cout << endl;
			}
			else if (size % 2 != 2)		//printing the actual grid if size is odd
			{
				int limit = (size*size);
				for (int j = (limit - size); j < limit; j++, limitCopy--)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << arr[i][--index] << "\t" << "|" << "\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}//for
				cout << endl;
			}

			if (size % 2 == 0)		//printing the dummy grid if size is even
			{
				for (int j = 0; j < size; j++)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << dummy[i][--copyIndex] << "\t" << "|" << "\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}//for
				cout << endl;
			}
			else if (size % 2 != 0)		//printing the dummy grid if size is odd
			{
				int limit = (size*size);
				for (int j = (limit - size); j < limit; j++, limitCopyDummy--)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << dummy[i][--copyIndex] << "\t" << "|" << "\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}//for
				cout << endl;
			}
		}
		swap(flag, anflag);
	}//for

}//printGrid
void printArray1(int **&arr, char **&dummy, int size)
{
	//printing the grid
	bool flag = true, anflag = false;
	int counter = (size*size), index = 0;	//variables for actual grid
	int ancounter = (size*size), copyIndex=0;	//variables for dummy grid


	//printing the grid values
	for (int i = size - 1; i >= 0; i--)
	{
		if (flag == true)
		{
			int temp = counter;	//variables for actual grid
			int tempCopy = ancounter;	//variables for dummy grid
			if (size % 2 == 0)		//printing the grid if size is even
			{
				for (int j = ((counter - size) + 1); j <= temp; j++, counter--)		//priting actual grid
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << arr[i][index++] << "\t" << "|" << "\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}//for
				cout << endl;
			}
			else if (size % 2 != 0)		//printing the grid if size is odd
			{
				int limit = (size*size);
				for (int j = (limit - size); j < limit; j++)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << arr[i][index++] << "\t" << "|" << "\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}//for
				cout << endl;
			}

			if (size % 2 == 0)		//printing the dummy grid if size is even
			{
				for (int j = ((ancounter - size) + 1); j <= tempCopy; j++, ancounter--)		//printing dummy grid
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << dummy[i][copyIndex++] << "\t" << "|" << "\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}//for
				cout << endl;
			}
			else if (size % 2!=0)		//printing the dummy grid if size is odd
			{
				int limit = (size*size);
				for (int j = (limit - size); j < limit; j++)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << dummy[i][copyIndex++] << "\t" << "|" << "\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}//for
				cout << endl;
			}
		}
		else if (flag == false)
		{
			int temp = counter;	//variables for actual grid
			int tempCopy = ancounter;	//variables for dummy grid
			if (size % 2 == 0)		//printing the grid if size is even
			{
				for (int j = counter; j >= ((temp - size) + 1); j--, counter--)		//printing actual grid
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << arr[i][--index] << "\t" << "|" << "\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}//for
				cout << endl;
			}
			else if (size % 2 != 0)		//printing the grid if size is odd
			{
				int limit = (size*size);
				for (int j = (limit - size); j < limit; j++)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << arr[i][--index] << "\t" << "|" << "\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}//for
				cout << endl;
			}

			if (size % 2 == 0)		//printing the dummy grid if size is even
			{
				for (int j = ancounter; j >= ((tempCopy - size) + 1); j--, ancounter--)		//printing dummy grid
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << dummy[i][--copyIndex] << "\t" << "|" << "\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}//for
				cout << endl;
			}
			else if (size % 2 != 0)		//printing the dummy grid if size is odd
			{
				int limit = (size*size);
				for (int j = (limit - size); j < limit; j++)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << dummy[i][--copyIndex] << "\t" << "|" << "\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}//for
				cout << endl;
			}
		}
		swap(flag, anflag);
	}//for
}//printArray1
int** loadGame(int **arr, int size)
{
	ifstream fin;
	fin.open("C:/Users/ZED/Desktop/University Work/game/save.txt");
	char buff[1000];
	
	int i = -1, counter = 0;
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			while (fin.getline(buff, 1000))
			{
				i++;
				for (int j = i; j < i + 1; j++)
				{
					counter++;
					for (int k = 0; k < strlen(buff); k++)
					{
						arr[j][k] = buff[k];
					}//for
					int size = strlen(buff);
					arr[j][size] = '\0';
				}//for
			}//while
		}//while
	}
	else
	{
		cout << "Error Loading game\n";
	}

	return arr;
}//loadGame
void snakePosition(char **&arr, int size)
{
	int snakePosition = 0, limit = (size*size);
	for (int i = 0; i < 5; i++)
	{
		int row = 0, col = 0;
		for (int j = 0; j < 2; j++)
		{
			row = 0, col = 0;
			snakePosition = rand() % limit + 1;
			if (arr[i][j] == 'S')	//if there is an existing snake at the current position
			{
				j--;
			}
			int temp = snakePosition, increment = 0;
			while (temp != 0)
			{
				if (increment == 0)
				{
					int r = temp % 10;
					row = row + r;
					temp /= 10;
					increment++;

				}
				else if (increment == 1)
				{
					int r = temp % 10;
					col = col + r;
					temp /= 10;
					increment++;
				}
				else if (increment == 2)
					break;
			}//while
			int jugaad = 0;
			if (row <= (size - 1))
			{
				jugaad = row;
				arr[col][jugaad] = 'S';
			}
			else if (row >= size)
			{
				jugaad = row - size;
				arr[col][jugaad] = 'S';
			}
		}//for
	}//for

}//snakePosition
void ladderPosition(char **&arr, int size)
{
	int ladderPosition = 0, limit = (size*size);
	for (int i = 0; i < 5; i++)
	{
		int row = 0, col = 0;
		for (int j = 0; j < 2; j++)
		{
			row = 0, col = 0;
			ladderPosition = rand() % limit + 1;
			if (arr[i][j] == '4')		//if there is a ladder at current position
			{
				j--;
			}
			int temp = ladderPosition, increment = 0;
			while (temp != 0)
			{
				if (increment == 0)
				{
					int r = temp % 10;
					row = row + r;
					temp /= 10;
					increment++;

				}
				else if (increment == 1)
				{
					int r = temp % 10;
					col = col + r;
					temp /= 10;
					increment++;
				}
				else if (increment == 2)
					break;
			}//while
			int jugaad = 0;
			if (row <= (size - 1))
			{
				jugaad = row;
				arr[col][jugaad] = 'L';
			}
			else if (row >= size)
			{
				jugaad = row - size;
				arr[col][jugaad] = 'L';
			}
		}//for
	}//for
}//ladderPosition
void deallocateArrayInteger(int **&arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] arr[i];
	}//for
	delete[] arr;
}//dealllocateArrayInteger
void deallocateArrayChar(char **&arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] arr[i];
	}//for
	delete[] arr;
}//deallocateArrayChar


//main function

int main()
{
	int  size = 0 , limit = 0;
	cout << "Enter dimensions of the grid\n";
	cout << "Note: 'Size must be from 5-10' " << endl;
	cin >> size;
	limit = (size*size);

	bool breaker = true;
	do
	{
		if (size >= 5 && size <= 10)	//if valid size
		{
			//game is starting now

			cout << "If you want to load the game press 'l' or 'L' otherwise press 'n' or 'N' to start a new game\n";
			char option;
			cin >> option;
			if (option == 'l' || option == 'L')	//load game
			{
				//allocating array
				int **temp = nullptr;
				temp = new int*[size];
				for (int i = 0; i < size; i++)
					temp[i] = new int[size];
				//input from file

				temp=loadGame(temp, size);

				for (int i = 0; i < size; i++)
					cout << temp[i];
				cout << endl;

			}//loadGame
			else if (option == 'n' || option == 'N')	//new game
			{
				int **grid = nullptr;
				//allocating grid array that is entered by the user
				allocateArray(grid, size);

				//dummy grid for position of snakes and ladders allocation
				char **dummy = new char*[size];
				for (int i = 0; i < size; i++)
					dummy[i] = new char[size + 1];

				//filling the char(dummy) array with spaces
				for (int i = 0; i < size; i++)
				{
					for (int j = 0; j < size; j++)
						dummy[i][j] = '*';
					dummy[i][size] = '\0';
				}//for

				//printing grid as snakes && ladders
				printGrid(grid, dummy, size);

				//printing snakes on grid
				snakePosition(dummy, size);
				
				//printing ladders on grid
				ladderPosition(dummy, size);

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << "Note: (First turn is of Player 1)\n";
				cout << "Press any key to start the game" << endl;
				cout << "Player 1 (p) && Player 2 (z)" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				char turn;
				cin >> turn;
				system("cls");
				int player1Counter = 0, player2Counter = 0, ancounter = 0;
				int rowCopyPlayer1 = 0, colCopyPlayer1 = 0;	//copy player 1
				int rowCopyPlayer2 = 0, colCopyPlayer2 = 0;	//copy player 2

				bool flag = true, anflag = false;
				do	//game loop
				{
					//first turn is of player 1
					cout << "To exit the game, press 'e' or 'E'" << endl;
					cout << "To save the game press 's' or 'S' " << endl;
					cout << "To roll the dice press 'r' or 'R' " << endl;

					if (flag == true)	//turn of player 1
					{
						cout << "Turn of Player 1 " << endl;
						cin >> turn;
						if (turn == 'r' || turn == 'R')	// play game
						{
							system("cls");
							srand(time(0));
							int temp = 0, counter = 0;
							counter = rand() % 6 + 1;
							cout << "Dice value is: " << counter << endl;
							player1Counter = player1Counter + counter;

							temp = player1Counter;
							int row = 0, col = 0, increment = 0;;
							while (temp != 0)
							{
								if (increment == 0)
								{
									int r = 0;
									row = 0;
									r = temp % 10;
									row = row + r;
									temp /= 10;
									increment++;
								}
								else if (increment == 1)
								{
									int r = 0;
									col = 0;
									r = temp % 10;
									col = col + r;
									temp /= 10;
									increment++;
								}
								else if (increment == 2)
									break;
							}//while

							if (dummy[col][row] == 'z')		//if they have same coordinates
							{
								cout << "'p' and 'z' has same coordinates\n";
							}
							//putting player 1 in char(dummy) array 
							int jugaad = 0;
							if (row <= (size - 1))
							{
								jugaad = row;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
								dummy[col][jugaad] = 'p';
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
							}
							else if (row >= size)
							{
								jugaad = row - size;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
								dummy[col][jugaad] = 'p';
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
							}
							if (dummy[colCopyPlayer1][rowCopyPlayer1] == 'z')
								dummy[colCopyPlayer1][rowCopyPlayer1] = 'z';
							else
								dummy[colCopyPlayer1][rowCopyPlayer1] = '*';
							printArray1(grid, dummy, size);
							rowCopyPlayer1 = jugaad;
							colCopyPlayer1 = col;
						}
						else if (turn == 'e' || turn == 'E')	//exit game
						{
							breaker = false;
							break;
						}
						else if (turn == 's' || turn == 'S')	//save game
						{
							system("cls");
							saveGame(grid, dummy, size);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
							cout << "The game has saved successfully\n";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
							printArray1(grid, dummy, size);
							swap(flag, anflag);
						}
						else	// invalid input
						{
							system("cls");
							cout << "Invalid input" << endl;
							swap(flag, anflag);
						}
						swap(flag, anflag);
					}
					else if (flag == false)	//turn of player 2
					{
						cout << "Turn of Player 2 " << endl;
						cin >> turn;
						if (turn == 'r' || turn == 'R')	// play game
						{
							system("cls");
							srand(time(0));
							int temp = 0, counter = 0;
							counter = rand() % 6 + 1;
							cout << "Dice value is: " << counter << endl;
							player2Counter = player2Counter + counter;

							temp = player2Counter;
							int row = 0, col = 0, increment = 0;
							while (temp != 0)
							{
								if (increment == 0)
								{
									int r = 0;
									row = 0;
									r = temp % 10;
									row = row + r;
									temp /= 10;
									increment++;
								}
								else if (increment == 1)
								{
									int r = 0;
									col = 0;
									r = temp % 10;
									col = col + r;
									temp /= 10;
									increment++;
								}
								else if (increment == 2)
									break;
							}//while

							if (dummy[col][row] == 'p')		//if they have same coordinates
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
								cout << "'z' and 'p' has same coordinates\n";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
							}
							//putting player 2 in char(dummy) array
							int jugaad = 0;
							if (row <= (size - 1))
							{
								jugaad = row;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
								dummy[col][jugaad] = 'z';
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
							}
							else if (row >= size)
							{
								jugaad = row - size;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
								dummy[col][jugaad] = 'z';
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
							}
							if(dummy[colCopyPlayer2][rowCopyPlayer2] == 'p')
								dummy[colCopyPlayer2][rowCopyPlayer2] = 'p';
							else
								dummy[colCopyPlayer2][rowCopyPlayer2] = '*';
							printArray1(grid, dummy, size);
							rowCopyPlayer2 = jugaad;
							colCopyPlayer2 = col;
						}
						else if (turn == 'e' || turn == 'E')	//exit game
						{
							breaker = false;
							break;
						}
						else if (turn == 's' || turn == 'S')	//save game
						{
							system("cls");
							saveGame(grid, dummy, size);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
							cout << "The game has saved successfully\n";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
							printArray1(grid, dummy, size);
							swap(flag, anflag);
						}
						else	// invalid input
						{
							system("cls");
							cout << "Invalid input" << endl;
							swap(flag, anflag);
						}
						swap(flag, anflag);
					}
				} while (true);	//do-while
			}//newGame
			else	//invalid input
			{
			system("cls");
			cout << "Please choose from Load game and New game " << endl;
			cout << "Thank you " << endl << endl;
			}
		}
		else	//if invalid size
		{
		system("cls");
		cout << "Invalid size\n";
		cin >> size;
		}
	}while(breaker);	//do-while

	/*
	char del = 0;
	cin >> del;
	if (del == 'd' || del == 'D')
	{
		deallocateArrayInteger(grid, size);
		deallocateArrayInteger(dummy, size);
	}
	else
		cout << "Invalid Input\n";
	*/
}//main