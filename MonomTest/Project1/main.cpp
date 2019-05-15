#include "Monom.h"
#include <iostream>

using namespace std;

void main()
{
	int l = 1;
	while (l)
	{
		cout << "Input maxSt:";
		int maxSt = 0;
		cin >> maxSt;
		cout << endl << "Input number of X:";
		int num = 0;
		cin >> num;
		cout << endl;

		cout << "Input Monom:\n";
		string monost;
		cin >> monost;
		Monom mono, monocopy, monoresult;

		mono.setA(mono.StringToA(monost));

		cout << endl << "A = " << mono.getA() << endl << endl;

		mono.setSV(mono.StringToSV(monost, maxSt, num));

		cout << "Sv = " << mono.getSV() << endl << endl;

		cout << "String = " << mono.MonomToString(maxSt, num) << endl << endl;

		cout << monoresult.MonomToString(maxSt, num) << endl << monoresult.getSV() << endl << "Do you want to continue? (Y(1)/N(0))\n";
		cin >> l;
		cout << "- - - - - - - - - - - - - " << endl;
	}

}
