#include<iostream>
#include<iomanip>
using namespace std;
float numDrink, numSandwich, totalBill, price;
float soda = 2.25, water = 1.75, tenInches = 3.45, twelveInches = 5.25;
char drinkT; 
int sandwichT;
//print out a store interface
void printIntro()
{
	cout << "-----------------7-11 convenient Store-----------------" << endl;
	cout << "Drinks" << endl;
	cout << " Soda(S).......................................$2.25" << endl;
	cout << " Water(W)......................................$1.75" << endl;
	cout << "Sandwiches" << endl;
	cout << " 10 inches.....................................$3.45" << endl;
	cout << " 12 inches.....................................$5.25" << endl;
	cout << "How many drinks? ";
	cin >> numDrink;
	cout << "	What kind of drink(S=Soda, W=Water)? ";
	cin >> drinkT;
	cout << "How many Sandwiches? ";
	cin >> numSandwich;
	cout << "	What size of sandwich(10/12 inches)? ";
	cin >> sandwichT;
}
//print out bill
void printBill()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Your total bill = " << totalBill << endl;
}
int main()
{
	_asm
	{
		call printIntro;
	//calculate drink cost
		cmp drinkT, 'S';
		je drinkIsS;
		fld numDrink;
		fld water;
		fmul;
		fstp price;
		jmp sandwich;
	drinkIsS:
		fld numDrink;
		fld soda;
		fmul;
		fstp price;
	//calculate sandwich price. First calculate 12 inch sandwiches
	sandwich:
		fld price;
		cmp sandwichT, 10;
		je sandwichTen;
		fld numSandwich;
		fld twelveInches;
		fmul;
		jmp endPro;
	//calculate ten inch sandwiches
	sandwichTen:
		fld numSandwich;
		fld tenInches;
		fmul;
	//pop and print bill
	endPro:
		fadd;
		fstp totalBill;
		call printBill;
	}
	system("pause");
}
