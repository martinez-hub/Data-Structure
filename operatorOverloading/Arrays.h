#include <iostream>
#include <stdlib.h>

using namespace std;

class Arrays{
public:
	
	Arrays();				//Default constructor: it creates an Array of 100 positions
	Arrays(int sz);			//Special constructor: it creates an Array of sz positions
	Arrays(const Arrays &B);		//Copy Constructor
	~Arrays();				//Destructor: deallocate memory
	void readArray();		//readArray Method: Reads all positions of the array
	void printArray();		//printArray Method: Prints all positions of the array
	void printArray(int n); //printArray Method: Prints the n first positions of the array
	int getSize();			//getSize Method: return the size of the Array
	void generateArray();   //generateArray Method: Generates the elements for the array
	void operator+=(const Arrays &B); //Overload the Operator += for using with arrays
	Arrays *operator+(Arrays &B); //Overload the Operator + for using with arrays
	void operator=(const Arrays &B);
	void initArray(int i);
	double operator *(Arrays &B); //Overloading * Operator for Array.Array
	Arrays *operator*(int val);//Overloading * Operator for Array*int
	void operator*=(int val);//Overloading *= Operator for Array*int


private:
	int *Arr;
	int size;
};
