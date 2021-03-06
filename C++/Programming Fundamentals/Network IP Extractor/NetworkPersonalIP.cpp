


#include "pch.h"
#include <iostream>
#include <Windows.h>
using namespace std;


//This program takes IP Address and Subnet Address and provides
//1. Network IP
//2. Total Hosts
//3. Usable Hosts

// prototypes
void ipOctectBreaker(int &firstOctect, int &secondOctect, int &thirdOctect, int &fourthOctect, char ip[]);
void subnetmaskOctectBreak(int& subFirstOctect, int& subSecondOctect, int& subThirdOctect, int& subFourthOctect, char subnetmask[]);
int digitCalculator(int digit);
int* binarycalculator(int *&binaryArray, int number);
void printBinary(int binaryArray[], int size);
int *binaryAssignmentOfNetworkIp(int *networkArray, int *ipArray, int *subnetmaskArray);
int NetworkIpInDecimals(int *networkIp);



int main()
{
	//this size is gonna be used in further program where binary arrays which are
	//to be compared for network ip thier size will be always 8
	//as ipv4 is 32-bit system and in 32bit ip octects are always of maximum of 8bits
	//192.168.8.1											255.255.255.0
	//8-bit.8-bit.8-bit.8-bit								8-bit.8-bit.8-bit.8-bit
	int size = 8;

	/************************************************************* Starting Point *******************************************************************/
	cout << "Enter your IP address\n";

	//input of ip
	char ip[16];
	cin.getline(ip, 16, '\n');

	cout << "Enter your Subnet Mask\n";
	char subnetmask[16];
	cin.getline(subnetmask, 16, '\n');

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);	//violet
	cout << "IP" << endl;
	//variables for octects
	int firstOctect = 0, secondOctect = 0, thirdOctect = 0, fourthOctect = 0;

	//calling ipOctectBreaker
	ipOctectBreaker(firstOctect, secondOctect, thirdOctect, fourthOctect, ip);

	//printing octects on screen
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	//white
	cout << "Value of ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);	//red
	cout << "first ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	//white
	cout << "octect is: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);	//violet
	cout << firstOctect << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
	cout << "Value of ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	//red
	cout << "second ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
	cout << "octect is: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);	//violet
	cout << secondOctect << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
	cout << "Value of ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	//red
	cout << "third ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
	cout << "octect is: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);	//violet
	cout << thirdOctect << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
	cout << "Value of ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	//red
	cout << "fourth ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
	cout << "octect is: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);	//violet
	cout << fourthOctect << endl;


	cout << endl << endl << "SUBNEST MASK" << endl;
	//variables for subnet mask
	int subFirstOctect=0, subSecondOctect=0, subThirdOctect = 0 , subFourthOctect = 0;
	//calling subnetmask breaker function
	subnetmaskOctectBreak(subFirstOctect, subSecondOctect, subThirdOctect, subFourthOctect, subnetmask);
	//printing octects on screen
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
	cout << "Value of ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	//red
	cout << "first ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
	cout << "octect is: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);	//violet
	cout << subFirstOctect << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
	cout << "Value of ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	//red
	cout << "second ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
	cout << "octect is: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);	//violet
	cout << subSecondOctect << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
	cout << "Value of ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	//red
	cout << "third ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
	cout << "octect is: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);	//violet
	cout << subThirdOctect << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
	cout << "Value of ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);	//red
	cout << "fourth ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white
	cout << "octect is: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);	//violet
	cout << subFourthOctect << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//white

	//user input
	cout << "Press any key to continue\n";
	cin.get();
	system("cls");


	//calculating digits in octects of ip
	int digitInFirstOctectIp = 0, digitInSecondOctectIp = 0, digitInThirdOctectIp = 0, digitInFourthOctectIp = 0;
	digitInFirstOctectIp = digitCalculator(firstOctect);
	digitInSecondOctectIp = digitCalculator(secondOctect);
	digitInThirdOctectIp = digitCalculator(thirdOctect);
	digitInFourthOctectIp = digitCalculator(fourthOctect);

	//computing ip without '.' (periods) in ipAddress variable
	int ipAddress = 0;
	ipAddress = ipAddress * pow(10, digitInFirstOctectIp) + firstOctect;
	ipAddress = ipAddress * pow(10, digitInSecondOctectIp) + secondOctect;
	ipAddress = ipAddress * pow(10,digitInThirdOctectIp) + thirdOctect;
	ipAddress = ipAddress * pow(10, digitInFourthOctectIp) + fourthOctect;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);	//red
	cout << "Ip Address: is ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);	//violet
	cout << ipAddress << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	//white



	//calculating digits in subnet mask
	int digitInFirstOctectSubnet = 0, digitInSecondOctectSubnet = 0, digitInThirdOctectSubnet = 0, digitInFourthOctectSubnet = 0;
	digitInFirstOctectSubnet=digitCalculator(subFirstOctect);
	digitInSecondOctectSubnet=digitCalculator(subSecondOctect);
	digitInThirdOctectSubnet=digitCalculator(subThirdOctect);
	digitInFourthOctectSubnet=digitCalculator(subFourthOctect);

	//computing subnetmask without '.' (period) in subnetMask variable
	int subnetMask = 0;
	subnetMask = subnetMask * pow(10, digitInFirstOctectSubnet) + subFirstOctect;
	subnetMask = subnetMask * pow(10, digitInSecondOctectSubnet) + subSecondOctect;
	subnetMask = subnetMask * pow(10, digitInThirdOctectSubnet) + subThirdOctect;
	subnetMask = subnetMask * pow(10, digitInFourthOctectSubnet) + subFourthOctect;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);	//red
	cout << "Subnet Mask is: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);	//violet
	cout << subnetMask << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	//white

	//user input
	cout << "Press any key for Netowrk IP\n";
	cin.get();
	system("cls");

	//binary calcultion of ip address in 4 different arrays according to its octects
	//calculating and printing binary of octects of ip address
	cout << "Binary of octects of IP address" << endl;
	int *binaryOfFirstOctectOfIp = new int[size];
	binaryOfFirstOctectOfIp = binarycalculator(binaryOfFirstOctectOfIp, firstOctect);	//first-octect	(ip)
	printBinary(binaryOfFirstOctectOfIp, size);

	
	int *binaryOfSecondOctectOfIp = new int[size];
	binaryOfSecondOctectOfIp=binarycalculator(binaryOfSecondOctectOfIp, secondOctect);	//second-octect	(ip)
	printBinary(binaryOfSecondOctectOfIp, size);

	
	int *binaryOfThirdOctectOfIp = new int[size];
	binaryOfThirdOctectOfIp = binarycalculator(binaryOfThirdOctectOfIp, thirdOctect);	//third-octect	(ip)
	printBinary(binaryOfThirdOctectOfIp, size);

	
	int *binaryOfFourthOctectOfIp = new int[size];
	binaryOfFourthOctectOfIp = binarycalculator(binaryOfFourthOctectOfIp, fourthOctect);	//fourth-octect	(ip)
	printBinary(binaryOfFourthOctectOfIp, size);


	cout << endl;
	//binary calculations of subnet mask in 4 different arrays according to its octects
	//calculating and printing binary of octects of subnet mask
	cout << "Binary of octects of subnetmask" << endl;
	int *binaryOfFirstOctectOfSubnet = new int[size];
	binaryOfFirstOctectOfSubnet = binarycalculator(binaryOfFirstOctectOfSubnet, subFirstOctect);	//first-octect (subnet)
	printBinary(binaryOfFirstOctectOfSubnet, size);

	
	int *binaryOfSecondOctectOfSubnet = new int[size];
	binaryOfSecondOctectOfSubnet = binarycalculator(binaryOfSecondOctectOfSubnet, subSecondOctect);	//second-octect (subnet)
	printBinary(binaryOfSecondOctectOfSubnet, size);

	
	int *binaryOfThirdOctectOfSubnet = new int[size];
	binaryOfThirdOctectOfSubnet = binarycalculator(binaryOfThirdOctectOfSubnet, subThirdOctect);	//third-octect (subnet)
	printBinary(binaryOfThirdOctectOfSubnet, size);

	
	int *binaryOfFourthOctectOfSubnet = new int[size];
	binaryOfFourthOctectOfSubnet = binarycalculator(binaryOfFourthOctectOfSubnet, subFourthOctect);	//fourth-octect (subnet)
	printBinary(binaryOfFourthOctectOfSubnet, size);
	

	cout << '\n';
	//comparing binaries of ip && subnet to calculate network ip Finally
	int *binaryOfFirstOctectOfNetowrk = new int[8];
	binaryOfFirstOctectOfNetowrk = binaryAssignmentOfNetworkIp(binaryOfFirstOctectOfNetowrk, binaryOfFirstOctectOfIp, binaryOfFirstOctectOfSubnet);		//first-octect (network)
	cout << "Network ip of First Octect is: ";
	printBinary(binaryOfFirstOctectOfNetowrk, size);

	int *binaryOfSecondOctectOfNetwork = new int[8];
	binaryOfSecondOctectOfNetwork = binaryAssignmentOfNetworkIp(binaryOfSecondOctectOfNetwork, binaryOfSecondOctectOfIp, binaryOfSecondOctectOfSubnet);		//second-octect (network)
	cout << "Network ip of Second Octect is: ";
	printBinary(binaryOfSecondOctectOfNetwork, size);

	int *binaryOfThirdOctectOfNetwork = new int[8];
	binaryOfThirdOctectOfNetwork = binaryAssignmentOfNetworkIp(binaryOfThirdOctectOfNetwork, binaryOfThirdOctectOfIp, binaryOfThirdOctectOfSubnet);		//third-octect (network)
	cout << "Network ip of Third Octect is: ";
	printBinary(binaryOfThirdOctectOfNetwork, size);

	int *binaryOfFourthOctectOfNetwork = new int[8];
	binaryOfFourthOctectOfNetwork = binaryAssignmentOfNetworkIp(binaryOfFourthOctectOfNetwork, binaryOfFourthOctectOfIp, binaryOfFourthOctectOfSubnet);		//fourth-octect (network)
	cout << "Network ip of Fourth Octect is: ";
	printBinary(binaryOfFourthOctectOfNetwork, size);


	cout << endl;
	cout << "First Octect is" << NetworkIpInDecimals(binaryOfFirstOctectOfNetowrk) << endl;
	cout << "Second Octect is" << NetworkIpInDecimals(binaryOfSecondOctectOfNetwork) << endl;
	cout << "Third Octect is" << NetworkIpInDecimals(binaryOfThirdOctectOfNetwork) << endl;
	cout << "Fourth Octect is" << NetworkIpInDecimals(binaryOfFourthOctectOfNetwork) << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);	//violet
	cout << "Network IP is: " << NetworkIpInDecimals(binaryOfFirstOctectOfNetowrk) << "." << NetworkIpInDecimals(binaryOfSecondOctectOfNetwork) << ".";
	cout << NetworkIpInDecimals(binaryOfThirdOctectOfNetwork) << "." << NetworkIpInDecimals(binaryOfFourthOctectOfNetwork) << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//White
}//main




//definitions
void ipOctectBreaker(int & firstOctect, int & secondOctect, int & thirdOctect, int & fourthOctect, char ip[])
{
	//global variables for whole program
	int totalIndexofIp = 0;


	/***************************************************** GETTING OCTECTS VALUE IN VARIABLES *************************************************************/
	//1. firstOctect
	//2. secondOctect
	//3. thirdOctect
	//4. fourthOCtect

	/****************************************** First Octect ***************************************************/
	//calculating first octect
	//variables for first octect
	//int firstOctect = 0, 
	int	firstOctectPart1 = 0, firstOctectPart2 = 0, firstOctectPart3 = 0;

	//extra variables
	int counterForFirstOctect = 0, index = 0;

	//logic work
	for (int i = 0; i < 16; i++)
	{
		counterForFirstOctect++;
		index++;

		if (ip[i] == '.')
		{
			--counterForFirstOctect;
			firstOctectPart1 = (ip[0] - 48);
			firstOctectPart2 = (ip[1] - 48);
			firstOctectPart3 = (ip[2] - 48);


			//placing values in firstOctect variable according to ip
			if (counterForFirstOctect == 1)
			{
				firstOctect = firstOctect * 10 + firstOctectPart1;
				//cout << "Value of first octect is: " << firstOctect << endl;
				break;
			}
			else if (counterForFirstOctect == 2)
			{
				firstOctect = firstOctect * 10 + firstOctectPart1;
				firstOctect = firstOctect * 10 + firstOctectPart2;
				//cout << "Value of first octect is: " << firstOctect << endl;
				break;
			}
			else if (counterForFirstOctect == 3)
			{
				firstOctect = firstOctect * 10 + firstOctectPart1;
				firstOctect = firstOctect * 10 + firstOctectPart2;
				firstOctect = firstOctect * 10 + firstOctectPart3;
				//cout << "Value of first octect is: " << firstOctect << endl;
				break;
			}
		}//breaking octect if
	}//for
	counterForFirstOctect;



	/****************************************** Second Octect ***************************************************/
	//calculating second octect
	//variables for second octect
	//int secondOctect = 0, 
	int	secondOctectPart1 = 0, secondOctectPart2 = 0, secondOctectPart3 = 0;

	//extra variables
	int counterForSecondOctect = 0;

	//logic work
	for (int i = index; i < 16; i++)
	{
		counterForSecondOctect++;
		index++;

		if (ip[i] == '.')
		{
			--counterForSecondOctect;


			if (counterForFirstOctect == 1)	//if first octect has 1 digit
			{
				if (counterForSecondOctect == 1)
				{
					secondOctectPart1 = (ip[2] - 48);
				}
				else if (counterForSecondOctect == 2)
				{
					secondOctectPart1 = (ip[2] - 48);
					secondOctectPart2 = (ip[3] - 48);
				}
				else if (counterForSecondOctect == 3)
				{
					secondOctectPart1 = (ip[2] - 48);
					secondOctectPart2 = (ip[3] - 48);
					secondOctectPart3 = (ip[4] - 48);
				}
			}
			else if (counterForFirstOctect == 2)	//if first octect has 2 digits
			{
				if (counterForSecondOctect == 1)
				{
					secondOctectPart1 = (ip[3] - 48);
				}
				else if (counterForSecondOctect == 2)
				{
					secondOctectPart1 = (ip[3] - 48);
					secondOctectPart2 = (ip[4] - 48);
				}
				else if (counterForSecondOctect == 3)
				{
					secondOctectPart1 = (ip[3] - 48);
					secondOctectPart2 = (ip[4] - 48);
					secondOctectPart3 = (ip[5] - 48);
				}
			}
			else if (counterForFirstOctect == 3)	//if first octect has 3 digits
			{
				if (counterForSecondOctect == 1)
				{
					secondOctectPart1 = (ip[4] - 48);
				}
				else if (counterForSecondOctect == 2)
				{
					secondOctectPart1 = (ip[4] - 48);
					secondOctectPart2 = (ip[5] - 48);
				}
				else if (counterForSecondOctect == 3)
				{
					secondOctectPart1 = (ip[4] - 48);
					secondOctectPart2 = (ip[5] - 48);
					secondOctectPart3 = (ip[6] - 48);
				}
			}

			// placing values in secondOctect variable according to ip
			if (counterForSecondOctect == 1)
			{
				secondOctect = secondOctect * 10 + secondOctectPart1;
				//cout << "Value of second octect is: " << secondOctect << endl;
				break;
			}
			else if (counterForSecondOctect == 2)
			{
				secondOctect = secondOctect * 10 + secondOctectPart1;
				secondOctect = secondOctect * 10 + secondOctectPart2;
				//cout << "Value of second octect is: " << secondOctect << endl;
				break;
			}
			else if (counterForSecondOctect == 3)
			{
				secondOctect = secondOctect * 10 + secondOctectPart1;
				secondOctect = secondOctect * 10 + secondOctectPart2;
				secondOctect = secondOctect * 10 + secondOctectPart3;
				//cout << "Value of second octect is: " << secondOctect << endl;
				break;
			}
		}//breaking octect if
	}//for



	/****************************************** Third Octect ***************************************************/
	//calculating third octect
	//variables for third octect
	//int thirdOctect = 0, 
	int	thirdOctectPart1 = 0, thirdOctectPart2 = 0, thirdOctectPart3 = 0;

	//extra variables
	int counterForThirdOctect = 0;

	//logic work
	for (int i = index; i < 16; i++)
	{
		counterForThirdOctect++;
		index++;

		if (ip[i] == '.')
		{
			--counterForThirdOctect;

			totalIndexofIp = (++counterForFirstOctect) + (++counterForSecondOctect);
			if (totalIndexofIp == 4)	//if first and second both octect has total of 1:1 digit
			{
				if (counterForThirdOctect == 1)
				{
					thirdOctectPart1 = (ip[4] - 48);
				}
				else if (counterForThirdOctect == 2)
				{
					thirdOctectPart1 = (ip[4] - 48);
					thirdOctectPart2 = (ip[5] - 48);
				}
				else if (counterForThirdOctect == 3)
				{
					thirdOctectPart1 = (ip[4] - 48);
					thirdOctectPart2 = (ip[5] - 48);
					thirdOctectPart3 = (ip[6] - 48);
				}
			}
			else if (totalIndexofIp == 5)	//if first and second both octect has total of 3 digits
			{
				if (counterForThirdOctect == 1)
				{
					thirdOctectPart1 = (ip[5] - 48);
				}
				else if (counterForThirdOctect == 2)
				{
					thirdOctectPart1 = (ip[5] - 48);
					thirdOctectPart2 = (ip[6] - 48);
				}
				else if (counterForThirdOctect == 3)
				{
					thirdOctectPart1 = (ip[5] - 48);
					thirdOctectPart2 = (ip[6] - 48);
					thirdOctectPart3 = (ip[7] - 48);
				}
			}
			else if (totalIndexofIp == 6)	//if first and second both octect has total of 4 digits
			{
				if (counterForThirdOctect == 1)
				{
					thirdOctectPart1 = (ip[6] - 48);
				}
				else if (counterForThirdOctect == 2)
				{
					thirdOctectPart1 = (ip[6] - 48);
					thirdOctectPart2 = (ip[7] - 48);
				}
				else if (counterForThirdOctect == 3)
				{
					thirdOctectPart1 = (ip[6] - 48);
					thirdOctectPart2 = (ip[7] - 48);
					thirdOctectPart3 = (ip[8] - 48);
				}
			}
			else if (totalIndexofIp == 7)	//if first and second both octect has total of 5 digits
			{
				if (counterForThirdOctect == 1)
				{
					thirdOctectPart1 = (ip[7] - 48);
				}
				else if (counterForThirdOctect == 2)
				{
					thirdOctectPart1 = (ip[7] - 48);
					thirdOctectPart2 = (ip[8] - 48);
				}
				else if (counterForThirdOctect == 3)
				{
					thirdOctectPart1 = (ip[7] - 48);
					thirdOctectPart2 = (ip[8] - 48);
					thirdOctectPart3 = (ip[9] - 48);
				}
			}
			else if (totalIndexofIp == 8)	//if first and second both octect has total of 6 digits
			{
				if (counterForThirdOctect == 1)
				{
					thirdOctectPart1 = (ip[8] - 48);
				}
				else if (counterForThirdOctect == 2)
				{
					thirdOctectPart1 = (ip[8] - 48);
					thirdOctectPart2 = (ip[9] - 48);
				}
				else if (counterForThirdOctect == 3)
				{
					thirdOctectPart1 = (ip[8] - 48);
					thirdOctectPart2 = (ip[9] - 48);
					thirdOctectPart3 = (ip[10] - 48);
				}
			}


			// placing values in secondOctect variable according to ip
			if (counterForThirdOctect == 1)
			{
				thirdOctect = thirdOctect * 10 + thirdOctectPart1;
				//cout << "Value of third octect is: " << thirdOctect << endl;
				break;
			}
			else if (counterForThirdOctect == 2)
			{
				thirdOctect = thirdOctect * 10 + thirdOctectPart1;
				thirdOctect = thirdOctect * 10 + thirdOctectPart2;
				//cout << "Value of third octect is: " << thirdOctect << endl;
				break;
			}
			else if (counterForThirdOctect == 3)
			{
				thirdOctect = thirdOctect * 10 + thirdOctectPart1;
				thirdOctect = thirdOctect * 10 + thirdOctectPart2;
				thirdOctect = thirdOctect * 10 + thirdOctectPart3;
				//cout << "Value of third octect is: " << thirdOctect << endl;
				break;
			}
		}//breaking octect if
	}//for


	/****************************************** Fourth Octect ***************************************************/
	//calculating fourth octect
	//variables for fourth octect
	//int fourthOctect = 0, 
	int	fourthOctectPart1 = 0, fourthOctectPart2 = 0, fourthOctectPart3 = 0;

	//extra variables
	int counterForFourthOctect = 0;

	//logic work
	for (int i = index; i < 16; i++)
	{
		counterForFourthOctect++;

		if (ip[i] == '\0')
		{
			--counterForFourthOctect;

			totalIndexofIp = (counterForFirstOctect)+(counterForSecondOctect)+(++counterForThirdOctect);
			if (totalIndexofIp == 6)	//if first, second and third octects has 3 digits i.e 1:1:1
			{
				if (counterForFourthOctect == 1)
				{
					fourthOctectPart1 = (ip[6] - 48);
				}
				else if (counterForFourthOctect == 2)
				{
					fourthOctectPart1 = (ip[6] - 48);
					fourthOctectPart2 = (ip[7] - 48);
				}
				else if (counterForFourthOctect == 3)
				{
					fourthOctectPart1 = (ip[6] - 48);
					fourthOctectPart2 = (ip[7] - 48);
					fourthOctectPart3 = (ip[8] - 48);
				}
			}
			else if (totalIndexofIp == 7)	//if first, second and third octects has total of 4 digits
			{
				if (counterForFourthOctect == 1)
				{
					fourthOctectPart1 = (ip[7] - 48);
				}
				else if (counterForFourthOctect == 2)
				{
					fourthOctectPart1 = (ip[7] - 48);
					fourthOctectPart2 = (ip[8] - 48);
				}
				else if (counterForFourthOctect == 3)
				{
					fourthOctectPart1 = (ip[7] - 48);
					fourthOctectPart2 = (ip[8] - 48);
					fourthOctectPart3 = (ip[9] - 48);
				}
			}
			else if (totalIndexofIp == 8)	//if first, second and third octect has total of 5 digits
			{
				if (counterForFourthOctect == 1)
				{
					fourthOctectPart1 = (ip[8] - 48);
				}
				else if (counterForFourthOctect == 2)
				{
					fourthOctectPart1 = (ip[8] - 48);
					fourthOctectPart2 = (ip[9] - 48);
				}
				else if (counterForFourthOctect == 3)
				{
					fourthOctectPart1 = (ip[8] - 48);
					fourthOctectPart2 = (ip[9] - 48);
					fourthOctectPart3 = (ip[10] - 48);
				}
			}
			else if (totalIndexofIp == 9)	//if first, second and third octect has total of 6 digits
			{
				if (counterForFourthOctect == 1)
				{
					fourthOctectPart1 = (ip[9] - 48);
				}
				else if (counterForFourthOctect == 2)
				{
					fourthOctectPart1 = (ip[9] - 48);
					fourthOctectPart2 = (ip[10] - 48);
				}
				else if (counterForFourthOctect == 3)
				{
					fourthOctectPart1 = (ip[9] - 48);
					fourthOctectPart2 = (ip[10] - 48);
					fourthOctectPart3 = (ip[11] - 48);
				}
			}
			else if (totalIndexofIp == 10)	//if first, second and third octect has total of 7 digits
			{
				if (counterForFourthOctect == 1)
				{
					fourthOctectPart1 = (ip[10] - 48);
				}
				else if (counterForFourthOctect == 2)
				{
					fourthOctectPart1 = (ip[10] - 48);
					fourthOctectPart2 = (ip[11] - 48);
				}
				else if (counterForFourthOctect == 3)
				{
					fourthOctectPart1 = (ip[10] - 48);
					fourthOctectPart2 = (ip[11] - 48);
					fourthOctectPart3 = (ip[12] - 48);
				}
			}
			else if (totalIndexofIp == 11)	//if first, second and third octect has total of 8 digits
			{
				if (counterForFourthOctect == 1)
				{
					fourthOctectPart1 = (ip[11] - 48);
				}
				else if (counterForFourthOctect == 2)
				{
					fourthOctectPart1 = (ip[11] - 48);
					fourthOctectPart2 = (ip[12] - 48);
				}
				else if (counterForFourthOctect == 3)
				{
					fourthOctectPart1 = (ip[11] - 48);
					fourthOctectPart2 = (ip[12] - 48);
					fourthOctectPart3 = (ip[13] - 48);
				}
			}
			else if (totalIndexofIp == 12)	//if first, second and third octect has total of 9 digits i.e 3:3:3
			{
				if (counterForFourthOctect == 1)
				{
					fourthOctectPart1 = (ip[12] - 48);
				}
				else if (counterForFourthOctect == 2)
				{
					fourthOctectPart1 = (ip[12] - 48);
					fourthOctectPart2 = (ip[13] - 48);
				}
				else if (counterForFourthOctect == 3)
				{
					fourthOctectPart1 = (ip[12] - 48);
					fourthOctectPart2 = (ip[13] - 48);
					fourthOctectPart3 = (ip[14] - 48);
				}
			}



			// placing values in secondOctect variable according to ip
			if (counterForFourthOctect == 1)
			{
				fourthOctect = fourthOctect * 10 + fourthOctectPart1;
				//cout << "Value of fourth octect is: " << fourthOctect << endl;
				break;
			}
			else if (counterForFourthOctect == 2)
			{
				fourthOctect = fourthOctect * 10 + fourthOctectPart1;
				fourthOctect = fourthOctect * 10 + fourthOctectPart2;
				//cout << "Value of fourth octect is: " << fourthOctect << endl;
				break;
			}
			else if (counterForFourthOctect == 3)
			{
				fourthOctect = fourthOctect * 10 + fourthOctectPart1;
				fourthOctect = fourthOctect * 10 + fourthOctectPart2;
				fourthOctect = fourthOctect * 10 + fourthOctectPart3;
				//cout << "Value of fourth octect is: " << fourthOctect << endl;
				break;
			}
		}//breaking octect if
	}//for


	/***************************************************** END *************************************************************/
}
void subnetmaskOctectBreak(int & subFirstOctect, int & subSecondOctect, int & subThirdOctect, int & subFourthOctect, char subnetmask[])
{

	//global variables for whole program
	int totalIndexofIp = 0;


	/***************************************************** GETTING OCTECTS VALUE IN VARIABLES *************************************************************/
	//1. firstOctect
	//2. secondOctect
	//3. thirdOctect
	//4. fourthOCtect

	/****************************************** First Octect ***************************************************/
	//calculating first octect
	//variables for first octect
	//int firstOctect = 0, 
	int	firstOctectPart1 = 0, firstOctectPart2 = 0, firstOctectPart3 = 0;

	//extra variables
	int counterForFirstOctect = 0, index = 0;

	//logic work
	for (int i = 0; i < 16; i++)
	{
		counterForFirstOctect++;
		index++;

		if (subnetmask[i] == '.')
		{
			--counterForFirstOctect;
			firstOctectPart1 = (subnetmask[0] - 48);
			firstOctectPart2 = (subnetmask[1] - 48);
			firstOctectPart3 = (subnetmask[2] - 48);


			//placing values in firstOctect variable according to ip
			if (counterForFirstOctect == 1)
			{
				subFirstOctect = subFirstOctect * 10 + firstOctectPart1;
				//cout << "Value of first octect is: " << firstOctect << endl;
				break;
			}
			else if (counterForFirstOctect == 2)
			{
				subFirstOctect = subFirstOctect * 10 + firstOctectPart1;
				subFirstOctect = subFirstOctect * 10 + firstOctectPart2;
				//cout << "Value of first octect is: " << firstOctect << endl;
				break;
			}
			else if (counterForFirstOctect == 3)
			{
				subFirstOctect = subFirstOctect * 10 + firstOctectPart1;
				subFirstOctect = subFirstOctect * 10 + firstOctectPart2;
				subFirstOctect = subFirstOctect * 10 + firstOctectPart3;
				//cout << "Value of first octect is: " << firstOctect << endl;
				break;
			}
		}//breaking octect if
	}//for
	counterForFirstOctect;



	/****************************************** Second Octect ***************************************************/
	//calculating second octect
	//variables for second octect
	//int secondOctect = 0, 
	int	secondOctectPart1 = 0, secondOctectPart2 = 0, secondOctectPart3 = 0;

	//extra variables
	int counterForSecondOctect = 0;

	//logic work
	for (int i = index; i < 16; i++)
	{
		counterForSecondOctect++;
		index++;

		if (subnetmask[i] == '.')
		{
			--counterForSecondOctect;


			if (counterForFirstOctect == 1)	//if first octect has 1 digit
			{
				if (counterForSecondOctect == 1)
				{
					secondOctectPart1 = (subnetmask[2] - 48);
				}
				else if (counterForSecondOctect == 2)
				{
					secondOctectPart1 = (subnetmask[2] - 48);
					secondOctectPart2 = (subnetmask[3] - 48);
				}
				else if (counterForSecondOctect == 3)
				{
					secondOctectPart1 = (subnetmask[2] - 48);
					secondOctectPart2 = (subnetmask[3] - 48);
					secondOctectPart3 = (subnetmask[4] - 48);
				}
			}
			else if (counterForFirstOctect == 2)	//if first octect has 2 digits
			{
				if (counterForSecondOctect == 1)
				{
					secondOctectPart1 = (subnetmask[3] - 48);
				}
				else if (counterForSecondOctect == 2)
				{
					secondOctectPart1 = (subnetmask[3] - 48);
					secondOctectPart2 = (subnetmask[4] - 48);
				}
				else if (counterForSecondOctect == 3)
				{
					secondOctectPart1 = (subnetmask[3] - 48);
					secondOctectPart2 = (subnetmask[4] - 48);
					secondOctectPart3 = (subnetmask[5] - 48);
				}
			}
			else if (counterForFirstOctect == 3)	//if first octect has 3 digits
			{
				if (counterForSecondOctect == 1)
				{
					secondOctectPart1 = (subnetmask[4] - 48);
				}
				else if (counterForSecondOctect == 2)
				{
					secondOctectPart1 = (subnetmask[4] - 48);
					secondOctectPart2 = (subnetmask[5] - 48);
				}
				else if (counterForSecondOctect == 3)
				{
					secondOctectPart1 = (subnetmask[4] - 48);
					secondOctectPart2 = (subnetmask[5] - 48);
					secondOctectPart3 = (subnetmask[6] - 48);
				}
			}

			// placing values in secondOctect variable according to ip
			if (counterForSecondOctect == 1)
			{
				subSecondOctect = subSecondOctect * 10 + secondOctectPart1;
				//cout << "Value of second octect is: " << secondOctect << endl;
				break;
			}
			else if (counterForSecondOctect == 2)
			{
				subSecondOctect = subSecondOctect * 10 + secondOctectPart1;
				subSecondOctect = subSecondOctect * 10 + secondOctectPart2;
				//cout << "Value of second octect is: " << secondOctect << endl;
				break;
			}
			else if (counterForSecondOctect == 3)
			{
				subSecondOctect = subSecondOctect * 10 + secondOctectPart1;
				subSecondOctect = subSecondOctect * 10 + secondOctectPart2;
				subSecondOctect = subSecondOctect * 10 + secondOctectPart3;
				//cout << "Value of second octect is: " << secondOctect << endl;
				break;
			}
		}//breaking octect if
	}//for



	/****************************************** Third Octect ***************************************************/
	//calculating third octect
	//variables for third octect
	//int thirdOctect = 0, 
	int	thirdOctectPart1 = 0, thirdOctectPart2 = 0, thirdOctectPart3 = 0;

	//extra variables
	int counterForThirdOctect = 0;

	//logic work
	for (int i = index; i < 16; i++)
	{
		counterForThirdOctect++;
		index++;

		if (subnetmask[i] == '.')
		{
			--counterForThirdOctect;

			totalIndexofIp = (++counterForFirstOctect) + (++counterForSecondOctect);
			if (totalIndexofIp == 4)	//if first and second both octect has total of 1:1 digit
			{
				if (counterForThirdOctect == 1)
				{
					thirdOctectPart1 = (subnetmask[4] - 48);
				}
				else if (counterForThirdOctect == 2)
				{
					thirdOctectPart1 = (subnetmask[4] - 48);
					thirdOctectPart2 = (subnetmask[5] - 48);
				}
				else if (counterForThirdOctect == 3)
				{
					thirdOctectPart1 = (subnetmask[4] - 48);
					thirdOctectPart2 = (subnetmask[5] - 48);
					thirdOctectPart3 = (subnetmask[6] - 48);
				}
			}
			else if (totalIndexofIp == 5)	//if first and second both octect has total of 3 digits
			{
				if (counterForThirdOctect == 1)
				{
					thirdOctectPart1 = (subnetmask[5] - 48);
				}
				else if (counterForThirdOctect == 2)
				{
					thirdOctectPart1 = (subnetmask[5] - 48);
					thirdOctectPart2 = (subnetmask[6] - 48);
				}
				else if (counterForThirdOctect == 3)
				{
					thirdOctectPart1 = (subnetmask[5] - 48);
					thirdOctectPart2 = (subnetmask[6] - 48);
					thirdOctectPart3 = (subnetmask[7] - 48);
				}
			}
			else if (totalIndexofIp == 6)	//if first and second both octect has total of 4 digits
			{
				if (counterForThirdOctect == 1)
				{
					thirdOctectPart1 = (subnetmask[6] - 48);
				}
				else if (counterForThirdOctect == 2)
				{
					thirdOctectPart1 = (subnetmask[6] - 48);
					thirdOctectPart2 = (subnetmask[7] - 48);
				}
				else if (counterForThirdOctect == 3)
				{
					thirdOctectPart1 = (subnetmask[6] - 48);
					thirdOctectPart2 = (subnetmask[7] - 48);
					thirdOctectPart3 = (subnetmask[8] - 48);
				}
			}
			else if (totalIndexofIp == 7)	//if first and second both octect has total of 5 digits
			{
				if (counterForThirdOctect == 1)
				{
					thirdOctectPart1 = (subnetmask[7] - 48);
				}
				else if (counterForThirdOctect == 2)
				{
					thirdOctectPart1 = (subnetmask[7] - 48);
					thirdOctectPart2 = (subnetmask[8] - 48);
				}
				else if (counterForThirdOctect == 3)
				{
					thirdOctectPart1 = (subnetmask[7] - 48);
					thirdOctectPart2 = (subnetmask[8] - 48);
					thirdOctectPart3 = (subnetmask[9] - 48);
				}
			}
			else if (totalIndexofIp == 8)	//if first and second both octect has total of 6 digits
			{
				if (counterForThirdOctect == 1)
				{
					thirdOctectPart1 = (subnetmask[8] - 48);
				}
				else if (counterForThirdOctect == 2)
				{
					thirdOctectPart1 = (subnetmask[8] - 48);
					thirdOctectPart2 = (subnetmask[9] - 48);
				}
				else if (counterForThirdOctect == 3)
				{
					thirdOctectPart1 = (subnetmask[8] - 48);
					thirdOctectPart2 = (subnetmask[9] - 48);
					thirdOctectPart3 = (subnetmask[10] - 48);
				}
			}


			// placing values in secondOctect variable according to ip
			if (counterForThirdOctect == 1)
			{
				subThirdOctect = subThirdOctect * 10 + thirdOctectPart1;
				//cout << "Value of third octect is: " << thirdOctect << endl;
				break;
			}
			else if (counterForThirdOctect == 2)
			{
				subThirdOctect = subThirdOctect * 10 + thirdOctectPart1;
				subThirdOctect = subThirdOctect * 10 + thirdOctectPart2;
				//cout << "Value of third octect is: " << thirdOctect << endl;
				break;
			}
			else if (counterForThirdOctect == 3)
			{
				subThirdOctect = subThirdOctect * 10 + thirdOctectPart1;
				subThirdOctect = subThirdOctect * 10 + thirdOctectPart2;
				subThirdOctect = subThirdOctect * 10 + thirdOctectPart3;
				//cout << "Value of third octect is: " << thirdOctect << endl;
				break;
			}
		}//breaking octect if
	}//for


	/****************************************** Fourth Octect ***************************************************/
	//calculating fourth octect
	//variables for fourth octect
	//int fourthOctect = 0, 
	int	fourthOctectPart1 = 0, fourthOctectPart2 = 0, fourthOctectPart3 = 0;

	//extra variables
	int counterForFourthOctect = 0;

	//logic work
	for (int i = index; i < 16; i++)
	{
		counterForFourthOctect++;

		if (subnetmask[i] == '\0')
		{
			--counterForFourthOctect;

			totalIndexofIp = (counterForFirstOctect)+(counterForSecondOctect)+(++counterForThirdOctect);
			if (totalIndexofIp == 6)	//if first, second and third octects has 3 digits i.e 1:1:1
			{
				if (counterForFourthOctect == 1)
				{
					fourthOctectPart1 = (subnetmask[6] - 48);
				}
				else if (counterForFourthOctect == 2)
				{
					fourthOctectPart1 = (subnetmask[6] - 48);
					fourthOctectPart2 = (subnetmask[7] - 48);
				}
				else if (counterForFourthOctect == 3)
				{
					fourthOctectPart1 = (subnetmask[6] - 48);
					fourthOctectPart2 = (subnetmask[7] - 48);
					fourthOctectPart3 = (subnetmask[8] - 48);
				}
			}
			else if (totalIndexofIp == 7)	//if first, second and third octects has total of 4 digits
			{
				if (counterForFourthOctect == 1)
				{
					fourthOctectPart1 = (subnetmask[7] - 48);
				}
				else if (counterForFourthOctect == 2)
				{
					fourthOctectPart1 = (subnetmask[7] - 48);
					fourthOctectPart2 = (subnetmask[8] - 48);
				}
				else if (counterForFourthOctect == 3)
				{
					fourthOctectPart1 = (subnetmask[7] - 48);
					fourthOctectPart2 = (subnetmask[8] - 48);
					fourthOctectPart3 = (subnetmask[9] - 48);
				}
			}
			else if (totalIndexofIp == 8)	//if first, second and third octect has total of 5 digits
			{
				if (counterForFourthOctect == 1)
				{
					fourthOctectPart1 = (subnetmask[8] - 48);
				}
				else if (counterForFourthOctect == 2)
				{
					fourthOctectPart1 = (subnetmask[8] - 48);
					fourthOctectPart2 = (subnetmask[9] - 48);
				}
				else if (counterForFourthOctect == 3)
				{
					fourthOctectPart1 = (subnetmask[8] - 48);
					fourthOctectPart2 = (subnetmask[9] - 48);
					fourthOctectPart3 = (subnetmask[10] - 48);
				}
			}
			else if (totalIndexofIp == 9)	//if first, second and third octect has total of 6 digits
			{
				if (counterForFourthOctect == 1)
				{
					fourthOctectPart1 = (subnetmask[9] - 48);
				}
				else if (counterForFourthOctect == 2)
				{
					fourthOctectPart1 = (subnetmask[9] - 48);
					fourthOctectPart2 = (subnetmask[10] - 48);
				}
				else if (counterForFourthOctect == 3)
				{
					fourthOctectPart1 = (subnetmask[9] - 48);
					fourthOctectPart2 = (subnetmask[10] - 48);
					fourthOctectPart3 = (subnetmask[11] - 48);
				}
			}
			else if (totalIndexofIp == 10)	//if first, second and third octect has total of 7 digits
			{
				if (counterForFourthOctect == 1)
				{
					fourthOctectPart1 = (subnetmask[10] - 48);
				}
				else if (counterForFourthOctect == 2)
				{
					fourthOctectPart1 = (subnetmask[10] - 48);
					fourthOctectPart2 = (subnetmask[11] - 48);
				}
				else if (counterForFourthOctect == 3)
				{
					fourthOctectPart1 = (subnetmask[10] - 48);
					fourthOctectPart2 = (subnetmask[11] - 48);
					fourthOctectPart3 = (subnetmask[12] - 48);
				}
			}
			else if (totalIndexofIp == 11)	//if first, second and third octect has total of 8 digits
			{
				if (counterForFourthOctect == 1)
				{
					fourthOctectPart1 = (subnetmask[11] - 48);
				}
				else if (counterForFourthOctect == 2)
				{
					fourthOctectPart1 = (subnetmask[11] - 48);
					fourthOctectPart2 = (subnetmask[12] - 48);
				}
				else if (counterForFourthOctect == 3)
				{
					fourthOctectPart1 = (subnetmask[11] - 48);
					fourthOctectPart2 = (subnetmask[12] - 48);
					fourthOctectPart3 = (subnetmask[13] - 48);
				}
			}
			else if (totalIndexofIp == 12)	//if first, second and third octect has total of 9 digits i.e 3:3:3
			{
				if (counterForFourthOctect == 1)
				{
					fourthOctectPart1 = (subnetmask[12] - 48);
				}
				else if (counterForFourthOctect == 2)
				{
					fourthOctectPart1 = (subnetmask[12] - 48);
					fourthOctectPart2 = (subnetmask[13] - 48);
				}
				else if (counterForFourthOctect == 3)
				{
					fourthOctectPart1 = (subnetmask[12] - 48);
					fourthOctectPart2 = (subnetmask[13] - 48);
					fourthOctectPart3 = (subnetmask[14] - 48);
				}
			}



			// placing values in secondOctect variable according to ip
			if (counterForFourthOctect == 1)
			{
				subFourthOctect = subFourthOctect * 10 + fourthOctectPart1;
				//cout << "Value of fourth octect is: " << fourthOctect << endl;
				break;
			}
			else if (counterForFourthOctect == 2)
			{
				subFourthOctect = subFourthOctect * 10 + fourthOctectPart1;
				subFourthOctect = subFourthOctect * 10 + fourthOctectPart2;
				//cout << "Value of fourth octect is: " << fourthOctect << endl;
				break;
			}
			else if (counterForFourthOctect == 3)
			{
				subFourthOctect = subFourthOctect * 10 + fourthOctectPart1;
				subFourthOctect = subFourthOctect * 10 + fourthOctectPart2;
				subFourthOctect = subFourthOctect * 10 + fourthOctectPart3;
				//cout << "Value of fourth octect is: " << fourthOctect << endl;
				break;
			}
		}//breaking octect if
	}//for


	/***************************************************** END *************************************************************/
}//subnetmaskOctectBreaker
int digitCalculator(int digit)
{	
	if (digit == 0)
	{
		int counter = 1;
		return counter;
	}
	else
	{
		int r = 0, counter = 0;
		while (digit != 0)
		{
			r = digit % 10;
			digit /= 10;
			counter++;
		}//while

		return counter;
	}
}//digitCalculator
int * binarycalculator(int *& binaryArray, int number)
{
	if (number == 0)
	{
		binaryArray[0] = 0;
		for (int i = 0; i < 8; i++)
		{
			if (binaryArray[i] != 1)
			{
				binaryArray[i] = 0;
			}
		}//for
		return binaryArray;
	}
	else if (number == 1)
	{
		binaryArray[0] = 1;
		for (int i = 0; i < 8; i++)
		{
			if (binaryArray[i] != 1)
			{
				binaryArray[i] = 0;
			}
		}//for
		return binaryArray;
	}
	else
	{
		int r = 0;
		int index = 0;
		while (number != 0)
		{
			r = number % 2;
			binaryArray[index++] = r;
			number /= 2;
		}//while

		for (int i = 0; i < 8; i++)
		{
			if (binaryArray[i] != 1)
			{
				binaryArray[i] = 0;
			}
		}//for

		return binaryArray;
	}
}//binaryCalculator
void printBinary(int binaryArray[], int size)
{
	for (int i = 0; i < size; i++)
		cout << binaryArray[i];
	cout << endl;
}//printBinary
int * binaryAssignmentOfNetworkIp(int * networkArray, int * ipArray, int * subnetmaskArray)
{
	for (int i = 0; i < 8; i++)
	{
		if (ipArray[i] == 1 && subnetmaskArray[i] == 1)
			networkArray[i] = 1;
		else
			networkArray[i] = 0;
	}//for

	return networkArray;
}//binaryAssignmentOfNetworkIp
int NetworkIpInDecimals(int * networkIp)
{
	int sum = 0;
	for (int i = 0; i < 8; i++)
	{
		if (networkIp[i] == 1)
		{
			sum = sum + pow(2, i);
		}
	}//for
	return sum;
}//networkIpInDecimals