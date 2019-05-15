#pragma once
#include "Monom.h"
class CircleList
{
	Monom * Head;
public:
	CircleList();
	~CircleList();
	CircleList(const CircleList & op);
	CircleList &operator=(const CircleList & op);
	void AddMonom(int A = 0, int SV = -1);
	void AddMonom(std::string str, int maxSt, int n);
	CircleList operator+(const CircleList &op);
	CircleList operator-(const CircleList &op);
	CircleList operator*(int n);
	CircleList multiply(CircleList & rhs, int maxSt, int n);
	std::string toString(int maxSt, int n);
	void show(int, int);
};

