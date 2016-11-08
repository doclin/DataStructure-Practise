#ifndef _POLYNOMIAL_H_INCLUDED_
#define _POLYNOMIAL_H_INCLUDED_

#include "linked_list/linked_list.h"

class Polynomial;                                                            // Declare at first


class Term                                                                   // To storage one single element of polynomila
{
private:
	friend class Polynomial;                                                 // To make Polynomial have access to private data
	friend bool operator==(const Term& t1, const Term& t2);                  // Overrite to fit the function in its father class
	friend Term operator*(const Term& t1, const Term& t2);                   // Base method designed for Polynomial's muti method
	int exp;
	double coef;                                                          
public:
	Term(double coef_=0, int exp_=0): exp(exp_), coef(coef_){};
};


class Polynomial: public LinkedList<Term>
{
public:
	Polynomial(int max_size_=10): LinkedList(max_size_){};
	Polynomial(const Polynomial& p): LinkedList(p){};
	virtual Polynomial& operator=(const Polynomial& p);                   
	virtual ~Polynomial() {};
	bool add_term(const Term& t);                                            // Add a term in a sequential way
	void input_poly();
	void output_poly();
	friend Polynomial operator+(const Polynomial& p1, const Polynomial& p2);
	friend Polynomial operator*(const Polynomial& p1, const Polynomial& p2);
};


#endif

//友元关系不可传递 
//copy assignment不可继承