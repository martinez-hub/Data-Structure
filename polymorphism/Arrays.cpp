#include <stdlib.h>
#include "Arrays.h"

//Default constructor: it creates an Array of 100 positions
Arrays::Arrays()
{
	Arr = new int[10];
	size=10;
}

//Special constructor: it creates an Array of sz positions
Arrays::Arrays(int sz)
{
	Arr = new int[sz];
	size = sz;
}

//Copy Constructor
Arrays::Arrays(const Arrays &OR)
{
	size = OR.size;
	Arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		Arr[i] = OR.Arr[i];
	}
}


//Destructor: deallocate memory
Arrays::~Arrays()
{
	delete []Arr;
	Arr=0;
}

//readArray Method: Reads all positions of the array
void Arrays::readArray()
{
	int i;
	for(i= 0; i< size; i++)
	{
		cout<<"Array["<<i<<"]= ";
		cin>>Arr[i];
	}
}

//printArray Method: Prints all positions of the array
void Arrays::printArray()
{
	int i;
	for(i= 0; i< size; i++)
	{
		cout<<Arr[i]<<"  ";
	}
	cout<<endl;
}

//printArray Method: Prints the n first positions of the array
void Arrays::printArray(int n)
{
	int i;
	if (n <= size)
	{
		for(i= 0; i< n; i++)
		{
			cout<<Arr[i]<<"  ";
		}
		cout<<endl;
	}else
	{
		cout<<"Error"<<endl;
	}
}


//printArray Method: Prints from position i to position j
void Arrays::printArray(int i, int j)
{
	int k;
	
	if ((j < size) && (i<=j))
	{
		for(k= i; k<=j ; k++)
		{
			cout<<Arr[k]<<"  ";
		}
		cout<<endl;
	}else
	{
		cout<<"Error"<<endl;
	}
}


void Arrays::generateArray()
{
	int i;
	for(i= 0; i< size; i++)
	{
		Arr[i]=rand();
	}
	
}

//getSize Method: return the size of the Array
int Arrays::getSize()
{
	return size;
}
