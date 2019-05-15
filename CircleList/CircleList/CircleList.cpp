#include "CircleList.h"
#include <iostream>


CircleList::CircleList()
{
	Head = new Monom();
}


CircleList::~CircleList()
{
	Monom * cur = Head->getNext();
	while (cur != Head)
	{
		Head->setNext(cur->getNext());
		cur->setNext(nullptr);
		delete cur;
		cur = Head->getNext();
	}
	Head->setNext(nullptr);
	delete Head;
}

CircleList::CircleList(const CircleList & op)
{
	Head = new Monom();
	Monom * last = Head;
	Monom * cur = op.Head->getNext();
	while (cur != op.Head)
	{
		Monom * tmp = new Monom(*cur);
		tmp->setNext(Head);
		last->setNext(tmp);
		cur = cur->getNext();
		last = tmp;
	}
}

CircleList & CircleList::operator=(const CircleList & op)
{
	Monom * cur = Head->getNext();
	while (cur != Head) 
	{
		Head->setNext(cur->getNext());
		cur->setNext(nullptr);
		delete cur; 
		cur = Head->getNext();
	}
	Head->setNext(nullptr);

	Monom * last = Head;
	cur = op.Head->getNext();
	while (cur != op.Head)
	{
		Monom * tmp = new Monom(*cur);
		tmp->setNext(Head);
		last->setNext(tmp);
		cur = cur->getNext();
		last = tmp;
	}
	return *this;
}

void CircleList::AddMonom(int A, int SV)
{
	Monom * m = new Monom(A, SV);
	Monom  * prev = Head;
	Monom  * cur = Head->getNext();

	while (SV < cur->getSV()) 
	{
		prev = cur;
		cur = cur->getNext();
	}

	if (cur->getSV() == SV) 
	{
		int nA = cur->getA() + A; 

		if (nA != 0) 
		{
			cur->setA(nA);
		}
		else
		{
			if (prev != cur)
			{
				prev->setNext(cur->getNext());
				cur->setNext(nullptr);
				delete cur;
			}
		}
	}
	else
	{
		prev->setNext(m);
		m->setNext(cur);
	}
}

void CircleList::AddMonom(std::string str, int maxSt, int n)
{
	Monom * m = new Monom(str, maxSt, n);
	int SV = m->getSV();
	int A = m->getA();
	Monom  * prev = Head;
	Monom  * cur = Head->getNext();

	while (SV < cur->getSV())
	{
		prev = cur;
		cur = cur->getNext();
	}

	if (cur->getSV() == SV) 
	{
		int nA = cur->getA() + A;

		if (nA != 0) 
		{
			cur->setA(nA); 		}
		else 
		{
			if (prev != cur)
			{
				prev->setNext(cur->getNext());
				cur->setNext(nullptr);
				delete cur;
			}
		}
	}
	else
	{
		prev->setNext(m);
		m->setNext(cur);
	}
}

CircleList CircleList::operator+(const CircleList & op)
{
	CircleList res(*this);
	Monom *cur = op.Head->getNext();
	while (cur != op.Head)
	{
		res.AddMonom(cur->getA(), cur->getSV());
		cur = cur->getNext();
	}
	return res;
}

CircleList CircleList::operator-(const CircleList & op)
{
	CircleList res(*this);
	Monom *cur = op.Head->getNext();
	while (cur != op.Head)
	{
		res.AddMonom((-1)*cur->getA(), cur->getSV());
		cur = cur->getNext();
	}
	return res;
}

CircleList CircleList::operator*(int n)
{
	CircleList tmp = *this;
	if (n == 0)
	{
		return CircleList();
	}
	Monom * cur = tmp.Head->getNext();
	while (cur != Head)
	{
		cur->setA((cur->getA())*n);
		cur = cur->getNext();
	}
	return tmp;
}

CircleList CircleList::multiply(CircleList & rhs, int maxSt, int n)
{
	CircleList res;
	Monom * cur = Head->getNext();
	while (cur != Head)
	{
		Monom * m = rhs.Head->getNext();
		while (m != rhs.Head)
		{
			Monom r = cur->multiply(*m, maxSt, n);
			res.AddMonom(r.getA(), r.getSV());
			m = m->getNext();
		}
		cur = cur->getNext();
	}
	return res;
}

std::string CircleList::toString(int maxSt, int n)
{
	Monom * cur = Head->getNext();
	std::string res = "";
	while (cur != Head)
	{
		std::string tmp = cur->MonomToString(maxSt, n);
		if (tmp[0] != '-')
		{
			res += ("+" + tmp);

		}
		else
		{
			res += tmp;
		}
		cur = cur->getNext();
	}


	return res;
}

void CircleList::show(int maxSt, int n)
{
	Monom * cur = Head;
	int i = 0;
	do
	{
		std::cout << "Monom #" << i++ << ":" << std::endl;
		cur->show(maxSt, n);
		cur = cur->getNext();
	} while (cur != Head);
}
