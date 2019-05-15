#include <iostream>
#include "CircleList.h"


using namespace std;
int main()
{
	int maxSt = 50;
	int n = 5;
	CircleList c1;
	c1.AddMonom();
	c1.AddMonom("x0^2", maxSt, n);
	c1.AddMonom("5x0^2x1^3x^5", maxSt, n);
	c1.AddMonom("-8x1^5x3^9x4", maxSt, n);
	c1.AddMonom(3, 10);
	cout << endl << "Monom c1: " << endl;
	

	cout << endl << "Polinom to string: " << c1.toString(maxSt, n);
	cin.get();

	CircleList c2(c1);
	cout << endl << "Monom c2(c1): " << endl;
	
	cout << endl << "Polinom to string: " << c2.toString(maxSt, n);
	cin.get();

	CircleList c3;
	c3.AddMonom(5, 1050);
	c3.AddMonom(-5, 5);
	c3.AddMonom(-8, 560);
	c3.AddMonom(0, 3456);
	c3.AddMonom(36, 10);
	cout << endl << "Monom c3: " << endl;
	cout << endl << "Polinom to string: " << c3.toString(maxSt, n);
	cin.get();
	c2 = c3;
	cout << endl << "Monom c2 = c3: " << endl;
	cout << endl << "Polinom to string: " << c2.toString(maxSt, n);
	cin.get();

	c2 = c3 + c1;
	cout << endl << "Monom c2 = c3 + c1: " << endl;
	cout << endl << "Polinom to string: " << c2.toString(maxSt, n);
	cin.get();

	c2 = c2 - c1;
	cout << endl << "Monom c2 = c2 - c1: " << endl;
	cout << endl << "Polinom to string: " << c2.toString(maxSt, n);
	cin.get();

	c2 = c3.multiply(c1, maxSt, n);
	cout << endl << "Monom c2 = c3 * c1: " << endl; 
	cout << endl << "Polinom to string: " << c2.toString(maxSt, n);

	n = 2;
	maxSt = 10;
	CircleList c4;
	c4.AddMonom("x0", maxSt, n);
	c4.AddMonom("x1", maxSt, n);
	cout << endl << "c4:" << endl;
	cout << endl << "Polinom to string: " << c4.toString(maxSt, n);
	cin.get();
	CircleList c5;
	c5.AddMonom("x0", maxSt, n);
	c5.AddMonom("-x1", maxSt, n);
	cout << endl << "c5:" << endl;
	cout << endl << "Polinom to string: " << c5.toString(maxSt, n);
	cin.get();
	c5 = c5.multiply(c4, maxSt, n);
	cout << endl << "Monom c5 = c5 * c4: " << endl;
	cout << endl << "Polinom to string: " << c5.toString(maxSt, n);
	cin.get();
	return 0;
}

