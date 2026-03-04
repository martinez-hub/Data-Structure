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
Arrays::Arrays(const Arrays &originalArray)
{
	size = originalArray.size;
	Arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		Arr[i] = originalArray.Arr[i];
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

void Arrays::generateArray()
{
	int i;
	for(i= 0; i< size; i++)
	{
		Arr[i]=rand() % 1000;
	}
	
}

void Arrays::initArray(int i)
{
	delete []Arr;
	Arr=new int[i];
	size = i;
}

//getSize Method: return the size of the Array
int Arrays::getSize()
{
	return size;
}

//Overloading += Operator
void Arrays::operator +=(const Arrays &B)
{
	if (size == B.size)
	{
		int i;
		for(i = 0; i<size; i++)
		{
			Arr[i]+=B.Arr[i];
		}
	}else
	{
		cout<<"Error Different Size, it is imposible to perform the += operation"<<endl;
	}
}


//Overloading *= Operator for Array*int
void Arrays::operator *=(int val)
{
		int i;
		for(i = 0; i<size; i++)
		{
			Arr[i]*=val;
		}

}
//Overloading * operator (dot product or scalar product)
double Arrays::operator *(Arrays &B)
{
	
	int A = size;
	double res=0;
	
	
	
	if(size == B.size)
	{
		int i;
		for(i = 0; i<size; i++)
		{
			res+=Arr[i]*B.Arr[i];
		}
	}else
	{
		cout<<"Error Different Size, it is imposible to perform the * operation"<<endl;
		res=0;
	}
	return res;
}



//Overloading + Operator
Arrays *Arrays::operator +(Arrays &B)
{
	
	int A = size;
	Arrays *res;
	res = new Arrays(size);

		
	if(size == B.size)
	{
		int i;
		for(i = 0; i<size; i++)
		{
			res->Arr[i]=Arr[i]+B.Arr[i];
		}
	}else
	{
		cout<<"Error Different Size, it is imposible to perform the + operation"<<endl;
		res->size=0;
	}

	return res;
	
}



//Overloading * Operator for Array*int
Arrays *Arrays::operator *(int val)
{
	
	int A = size;
	Arrays *res;
	res = new Arrays(size);

		
		int i;
		for(i = 0; i<size; i++)
		{
			res->Arr[i]=Arr[i]*val;
		}
	return res;
}






//Overloading = Operator
void Arrays::operator =(const Arrays &B)
{
	if (this == &B) {
		return;
	}

	if (size != B.size) {
		delete []Arr;
		size = B.size;
		Arr = new int[size];
	}

	for (int i = 0; i < size; i++)
	{
		Arr[i] = B.Arr[i];
	}
}
