#ifndef _LINEAR_LIST_H_INCLUDED_
#define _LINEAR_LIST_H_INCLUDED_

template <typename Type>
class LinearList
{
public:
	virtual int length() const =0;                   // Return the length of the list
	//virtual int max_length() const =0;
	virtual bool is_in(const Type& x) const =0;      // Judge whether an element is in the list or not
	virtual int index(const Type& x) const =0;       // Return the index(position) of the element, or -1
	virtual bool insert(const Type& x, int i) =0;    // Insert an element into the list
	virtual bool remove(int i) =0;                   // Remove a element
	virtual bool append(const Type& x) =0;           // Add the element to the end of the lists
	virtual bool update(const Type& x, int i) =0;    // Change the value of an element
	virtual bool is_empty() const =0;                // Judge whether the list is empty
	virtual bool is_full() const =0;                 // Judge whether the list is full
	virtual bool clear() =0;                         // Make the list empty
	virtual const Type& get(int i) const=0;          // Return an element by its index
	virtual const Type& operator[](int i) const=0;   // Return an element
	virtual Type& operator[](int i)=0;               // Return a modifiable reference
};

#endif