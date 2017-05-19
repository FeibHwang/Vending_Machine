// Vending_Machine_HFB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Vending_Mach.h"

using namespace std;


void simulation()
{
	int _cola, _chip, _candy, _mode;
	cout << "Simulation starts: " << endl << endl;
	cout << "First, please set quantity of the 3 product" << endl;
	cout << "please set Cola quantity: ";
	cin >> _cola;
	cout << "please set Chip quantity: ";
	cin >> _chip;
	cout << "please set Candy quantity: ";
	cin >> _candy; cout << endl;
	cout << "Please set vanding machine mode, 0:With Change, 1:Exact Change Only:  ";
	cin >> _mode;

	Vending_Mach *p = new Vending_Mach(_cola, _chip, _candy, _mode);

	cout << endl << "Please input following command: " << endl;
	cout <<  "===================================================: " << endl;
	cout << "insert 1 pennie, type \"pennie\" or \"i01\" " << endl;
	cout << "insert 1 nickel, type \"nickel\" or \"i05\" " << endl;
	cout << "insert 1 dime, type \"dime\" or \"i10\" " << endl;
	cout << "insert 1 quarter, type \"quarter\" or \"i25\" " << endl;
	cout << "purches product, type \"b1\" , \"b2\" or \"b3\" to buy a cola,chip or candy " << endl;
	cout << "cancel purchesing or finish purchesing, type \"finish\"" << endl;
	cout << "to exit simulation, type \"exit\"" << endl;
	cout << "===================================================: " << endl<< endl;

	cout << endl << endl << (_mode == 0 ? "INSERT COIN" : "EXACT CHANGE ONLY") << endl;

	cout << endl << "Please typing:" << endl;

	bool lp = true;

	while (lp)
	{
		string str;
		cout << ">>>";
		cin >> str;
		if ((str.length() >= 3 && str.substr(0, 3) == "i01") || (str.length() >= 6 && str.substr(0, 6) == "pennie"))
			p->insert_coins((string)"pennie");
		else if ((str.length() >= 3 && str.substr(0, 3) == "i05") || (str.length() >= 6 && str.substr(0, 6) == "nickel"))
			p->insert_coins((string)"nickel");
		else if ((str.length() >= 3 && str.substr(0, 3) == "i10") || (str.length() >= 4 && str.substr(0, 4) == "dime"))
			p->insert_coins((string)"dime");
		else if ((str.length() >= 3 && str.substr(0, 3) == "i25") || (str.length() >= 7 && str.substr(0, 7) == "quarter"))
			p->insert_coins((string)"quarter");
		else if (str.length() >= 2 && str[0] == 'b')
		{
			if (str[1] == '1') p->buy_product(0);
			else if (str[1] == '2') p->buy_product(1);
			else if (str[1] == '3') p->buy_product(2);
			else {
				cout << "invalid input" << endl;
				continue;
			}
		}
		else if (str.length() >= 6 && str.substr(0, 6) == "finish") p->cancel_act();
		else if (str.length() >= 4 && str.substr(0, 6) == "exit") lp = false;
		else {
			cout << "invalid input, please try again" << endl;
		}
	}

	cout << "simualtion complete" << endl;
}



int main()
{
	cout << "Vending Machine Simulator created by Feibai Huang" << endl;
	cout << "****  Email: huang.2650@osu.edu  ****" << endl;
	simulation();

	/*Vending_Mach *p = new Vending_Mach(1, 1, 1);


	p->insert_coins((string)"quarter");
	p->insert_coins((string)"quarter");
	p->insert_coins((string)"quarter");

	p->buy_product(2);

	p->cancel_act();*/

	system("pause");
    return 0;
}

