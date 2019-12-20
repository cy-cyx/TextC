#include<iostream>
#ifndef DOG_H

#define DOG_H

class Dog{
	public:
		Dog();
		Dog(int i,int ii);
		~Dog();
		int getI();
		int getII();
	protected:
		int i;
		int ii;
};

#endif
