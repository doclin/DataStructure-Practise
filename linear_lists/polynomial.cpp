#include <iostream>
#include <iomanip>
#include "polynomial.h"

using namespace std;

bool operator==(const Term& t1, const Term& t2)
{
	if(t1.exp==t2.exp and t1.coef==t2.coef)
		return true;
	return false;
}

Term operator*(const Term& t1, const Term& t2)
{
	double coef = t1.coef * t2.coef;
	int exp = t1.exp + t2.exp;
	Term t(coef, exp);

	return t;
}

Polynomial& Polynomial::operator=(const Polynomial& p)
{
	LinkedList::operator=(p);

	return *this;
}

bool Polynomial::add_term(const Term& t)                                          // Hold in a ascending sort
{
	if(LinkedList::is_full())
		return false;
	if(LinkedList::is_empty())
		LinkedList::append(t);
	else if(LinkedList::get(LinkedList::length()-1).exp < t.exp)
		LinkedList::append(t);
	else
	{
		for(int i=0; i<LinkedList::length(); i++)
		{
			if(LinkedList::get(i).exp < t.exp)
				continue;
			else if(LinkedList::get(i).exp == t.exp)
			{
				if(LinkedList::get(i).coef != -t.coef)
				{
					Term t_update(t.coef+LinkedList::get(i).coef, t.exp);
					LinkedList::update(t_update, i);
			    }
			    else
			    	LinkedList::remove(i);
			    break;
			}
			else
			{
				LinkedList::insert(t, i);
				break;
			}
		}
	}

	return true;
}

void Polynomial::input_poly()
{
	cout << "Please input a polynomial:" << endl;
	while(true)
	{
		double coef;
		int exp;
		cout << "Input the coefficient: (input '0' to end)" << endl;
		cin >> coef;
		if(coef == 0)
			break;
		cout << "Input the exponent: " << endl;
		cin >> exp;
		Term t(coef, exp);
		if(add_term(t))
			cout << "Nice, next one:" << endl;
		else
		{
			cout << "ERROR: NO SPACE LEFT!" << endl;                            
			break;
		}
	}
}

void Polynomial::output_poly()
{
	if(LinkedList::is_empty())
		cout << "It's empty" << endl;
	else
	{
		cout << LinkedList::get(0).coef << "x^(" << LinkedList::get(0).exp << ")";
		cout << setiosflags(ios::showpos);
		for(int i=1; i<LinkedList::length(); i++)
		{
			cout << LinkedList::get(i).coef << "x^(" << LinkedList::get(i).exp << ")";
		}
		cout << endl;
	}
}

Polynomial operator+(const Polynomial& p1, const Polynomial& p2)
{
	Polynomial p(p1);
	for(int i=0; i<p2.length(); i++)
	{
		p.add_term(p2[i]);
	}

	return p;
}


Polynomial operator*(const Polynomial& p1, const Polynomial& p2)
{
	Polynomial p(p1.length()*p2.length());
	for(int i=0; i<p1.length(); i++)
	{
		for(int j=0; j<p2.length(); j++)
		{
			Term t(p1[i]*p2[j]);
			p.add_term(t);
		}
	}

	return p;
}