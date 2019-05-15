#pragma once
#include <string>

class Monom
{
private:
	int A; 
	int SV;
	Monom * pNext;
public:
	Monom(int _A = 0, int _SV = -1);
	Monom(const Monom & M);
	Monom(std::string tmp, int maxSt, int n);
	~Monom();
	Monom &operator= (const Monom & M);
	void setA(int _A);
	void setSV(int _SV);
	int getA();
	int getSV();
	void setNext(Monom * next);
	Monom * getNext();
	std::string MonomToString(int maxSt, int n);
	int StringToA(std::string str);
	int StringToSV(std::string _str, int maxSt, int k);
	void show(int maxSt, int n);
	Monom multiply(const Monom & rhs, int maxSt, int n);
};

