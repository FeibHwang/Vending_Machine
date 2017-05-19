#include<string>
#include<vector>
#include<unordered_map>



#pragma once

using namespace std;

class Vending_Mach
{
public:
	Vending_Mach(int _cola, int _chip, int _candy, int _mode = 0);
	//constructor: 3 product number, mode:change/extract change

	~Vending_Mach();


	void insert_coins(string &coin);

	void buy_product(int _id);

	void cancel_act();



private:
	int money; //store how many cents

	int mode; //0:INSERT COIN, 1:EXTRACT CHANGE ONLY

	vector<int> _item;

	vector<int> _price;

	vector<string> _cat_name;

	void print_change(int _change);
};

