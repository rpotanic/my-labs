#include "Monom.h"
#include <iostream>
#include <cmath>



Monom::Monom(int _A, int _SV) : A(_A), SV(_SV), pNext(this)
{}

Monom::Monom(const Monom & M) : A(M.A), SV(M.SV), pNext(M.pNext)
{}

Monom::~Monom()
{
	pNext = nullptr;
}

Monom & Monom::operator=(const Monom & M)
{
	A = M.A;
	SV = M.SV;
	pNext = M.pNext;
	return *this;
}

void Monom::setA(int _A)
{
	A = _A;
}

void Monom::setSV(int _SV)
{
	SV = _SV;
}

int Monom::getA()
{
	return A;
}

int Monom::getSV()
{
	return SV;
}

void Monom::setNext(Monom * next)
{
	pNext = next;
}

Monom * Monom::getNext()
{
	return pNext;
}	

std::string Monom::MonomToString(int maxSt, int n)
{
	std::string res = "";
	int ost;
	int chast = SV;
	for (int i = n - 1; i >= 0; i--)
	{
		ost = chast % maxSt;
		chast /= maxSt;
		if (ost == 1)
		{
			res = "x" + std::to_string(i) + res;
		}
		if (ost > 1)
		{
			res = "x" + std::to_string(i) + "^" + std::to_string(ost) + res;
		}
	}
	res = std::to_string(A) + res;
	return res;
}

int Monom::StringToA(std::string str)
{
	int l = str.find("x");
	if (l == std::string::npos)
	{
		return stoi(str);
	}
	switch (l)
	{
	case 0:
	{
		return 1;
		break;

	}
	case 1:
	{
		if (str[0] == '-')
			return -1;
		else
			return str[0] - '0'; 
		break;
	}
	default:
	{
		std::string tmp = str.substr(0, l);
		return stoi(tmp);
		break;
	}
	}
}

int Monom::StringToSV(std::string _str, int maxSt, int k)
{
	int * n = new int[k];
	std::string str = _str;
	std::string t = "";
	int l = 0;
	for (int i = 0; i < k; i++)
	{
		t = "x" + std::to_string(i);
		l = str.find(t);
		if (l == std::string::npos || l > str.length())
		{
			n[i] = 0;
		}
		else
		{

			str.erase(l, t.length()); 
			if (str[l] == '^')
				str.erase(l, 1);
			if (l <= str.length() && str[l] == 'x' || l >= str.length())
			{
				n[i] = 1;
			}
			else
			{
				std::string nst = "";
				while (l <= str.length() && str[l] >= '0' && str[l] <= '9')
				{
					nst += str[l];
					str.erase(l, 1);
				}

				n[i] = stoi(nst);
				if (n[i] >= maxSt)
					return -1;
			}
		}
	}

	int sv = 0;
	for (int i = 0; i <= k - 1; i++) 
	{
		sv += n[i] * pow(maxSt, k - 1 - i);
	}
	delete[] n;
	return sv;
}

Monom Monom::multiply(const Monom & rhs, int maxSt, int n)
{
	Monom res(*this);
	res.setA(A * rhs.A);
	int * deps1 = new int[n];
	int * deps2 = new int[n];
	int c1 = SV;
	int c2 = rhs.SV;
	for (int i = n - 1; i >= 0; i--)
	{
		deps1[i] = c1 % maxSt; 
		c1 = c1 / maxSt;
		deps2[i] = c2 % maxSt;
		c2 /= maxSt;
		deps1[i] = deps1[i] + deps2[i]; 
		if (deps1[i] >= maxSt)
			return Monom();
	}
	int s = 0;
	for (int i = 0; i <= n - 1; i++) 
	{
		s += deps1[i] * pow(maxSt, n - 1 - i);
	}
	res.SV = s;
	return res;
}

void Monom::show(int maxSt, int n)
{
	std::cout << "This monom: " << MonomToString(maxSt, n) << std::endl;
	std::cout << "SV: " << getSV() << std::endl;
	std::cout << "A: " << getA() << std::endl;
}
