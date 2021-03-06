


#include "pch.h"
#include <iostream>
#include "person.h"
#include "adult.h"
#include "kid.h"
#include "train.h"
#include <fstream>
#include <Windows.h>
#define color SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
using namespace std;


void menu();



int main()
{
	color 2);	//green
	for (int i = 0; i < 5; i++)
	{
		system("cls");
		cout << "Application is starting" << endl;
		Sleep(500);
		system("cls");
	}
	color 7);	//white


	train obj;
	bool flag = true;
	do
	{
		//system("cls");
		menu();	//menu
		char input;
		cin >> input;

		if (input == 'a' || input == 'A')	//add bogie
		{
			system("cls");
			cin >> obj;
		}
		else if (input == 'e' || input == 'E')	//add passenger in train
		{
			system("cls");
			cout << "Enter bogie ID to add passenger in train" << endl;
			int bogie_id;
			cin >> bogie_id;
			if (!obj.searchBogie(bogie_id))
			{
				color 4);	//red
				cout << "Bogie with ID: " << bogie_id << " doesn't exists" << endl;
				color 7);	//white
			}
			else
				obj.addPassengers(bogie_id);
		}
		else if (input == 'r' || input == 'R')		//remove bogie
		{
			system("cls");
			cout << "Enter bogie ID to remove from train" << endl;
			int bogie_id;
			cin >> bogie_id;
			if (!obj.searchBogie(bogie_id))
			{
				color 4);	//red
				cout << "Bogie doesn't exixts" << endl;
				color 7);	//white
			}
			else
				obj.removeBogie(bogie_id);
		}
		else if (input == 'v' || input == 'V')		//print information
		{
			system("cls");
			cout << obj;
		}
		else if (input == 'q' || input == 'Q')		//quit
		{
			color 4);	//red
			system("cls");
			for (int i = 0; i < 5; i++)
			{
				system("cls");
				cout << "Application is terminating" << endl;
				Sleep(500);
				system("cls");
			}//for
			flag = !flag;
		}
		else if (input == 's' || input == 'S')		//save data	
		{
			system("cls");
			obj.saveData();
		}
		else if (input == 'l' || input == 'L')		//load data
		{
			system("cls");
			obj.loadData();
		}
		else if (input == 'k' || input == 'K')		//No. of Bogies in a train (for developer)
		{
			system("cls");
			cout << "Number of bogies in this train are: " << train::getNumberOfBogiesInThisTrain() << endl;
		}
		else										//invalid input
		{
			system("cls");
			color 4);	//red
			cout << "Invalid Input";
			cout << "Please try again" << endl;
			color 7);	//white
		}
	} while (flag);//do-while




}



void menu()
{
	cout << "Press 'A' to add bogie in train" << endl;
	cout << "Press 'E' to add passenger in train" << endl;
	cout << "Press 'R' to remove bogie from train" << endl;
	cout << "Press 'V' to print information about train" << endl;
	cout << "Press 'S' to save data" << endl;
	cout << "Press 'L' to load game" << endl;
	cout << "Press 'Q' to terminate the application" << endl;
}//menu