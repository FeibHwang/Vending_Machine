#include "stdafx.h"
#include "Vending_Mach.h"
#include <iostream>


Vending_Mach::Vending_Mach(int _cola, int _chip, int _candy, int _mode)
{
	mode = _mode;
	money = 0;
	_price = { 100,50,65 };
	_cat_name = { "cola","chip","candy" };
	_item.push_back(_cola);
	_item.push_back(_chip);
	_item.push_back(_candy);

	cout << "product:" << endl;
	cout << "cola   " << 100 << " cents        " << " quantity: " << _cola << endl;
	cout << "chip   " << 50 << "  cents        " << " quantity: " << _chip << endl;
	cout << "candy  " << 65 << "  cents        " << " quantity: " << _candy << endl;
	cout << "Initializing process completed, please input: " << endl;

}


Vending_Mach::~Vending_Mach()
{
}

void Vending_Mach::insert_coins(string &coin)
{
	if (coin == "nickel") { cout << "insert 1 nickel, ";  money += 5; }
	else if (coin == "dime") { cout << "insert 1 dime, "; money += 10; }
	else if (coin == "quarter") { cout << "insert 1 quarter, "; money += 25; }
	else if (coin == "pennie") {
		cout << "invalid coin: pennie, please insert nickel, dime or quarter. Thank you!" << endl;
	}
	else {
		cout << "invalid input, please insert nickel, dime or quarter. Thank you!" << endl << endl;
	}

	cout << "current amount " << money << " cents" << endl;
}

void Vending_Mach::buy_product(int _id)
{
	if (_id < 0 || _id > 2)
	{
		cout << "invalid input" << endl;
		return;
	}
	if (_item[_id] < 1) {
		cout << "sorry, " << _cat_name[_id] << " is currently out of stack" << endl;
		return;
	}
	if (_price[_id] <= money)
	{
		cout << "success!!! you have bought a " << _cat_name[_id] << endl;
		money -= _price[_id];
		cout << "current balance: " << money << endl;
	}
	else {
		cout << "failed, your change is not enough, you can insert extra " << _price[_id] - money << " cents to purch this product or cancel" << endl;
	}
}

void Vending_Mach::cancel_act()
{
	if (mode == 0)
	{
		cout << "thank you for your purchase, have a wonderful day!" << endl;
		if (money > 0) {
			cout << "here is your change: " << endl;;
			Vending_Mach::print_change(money);
			money = 0;
		}
	}
	else {
		cout << "thank you for your purchase, have a wonderful day!" << endl;
		if (money > 0) {
			cout << "extra change is preserved" << endl;
			money = 0;
		}
	}
}

void Vending_Mach::print_change(int _change)
{
	int _quarter = 0;
	int _dime = 0;
	int _nickel = 0;
	int _pennie = 0;

	int cnt = _change;
	while (cnt >= 5)
	{
		if (cnt >= 25) { _quarter++; cnt -= 25; }
		else if (cnt >= 10) { _dime++; cnt -= 10; }
		else if (cnt >= 5) { _nickel++; cnt -= 5; }
	}

	cout << _quarter << " quarter " << _dime << " dime " << _nickel << " nickel " << _pennie << " pennie " << endl;
}


