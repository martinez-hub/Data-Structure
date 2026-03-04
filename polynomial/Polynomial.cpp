/***********************************************
@authors: Josue Martinez Martinez
          Juan G. Cruz Hernandez
 Polynomial.cpp
 This program uses overloading operators for 
 Work with polynomials. (+, *, +=, =, *=)
************************************************/

#include "Polynomial.h"//se encuentra la clase Polynomial

//default constructor
Polynomial::Polynomial()
{
	degree = 99;
	Coef = new double [100];
}

//special constructor
Polynomial::Polynomial(int dg)
{
	degree = dg;
	Coef = new double [dg + 1];
}

//copy constructor
Polynomial::Polynomial(const Polynomial &Original)
{
	degree = Original.degree;
	Coef = new double[degree + 1];

	for(int i = 0; i <= degree; ++i)
	{
		Coef[i] = Original.Coef[i];
	}
}

//destructor
Polynomial::~Polynomial()
{
	delete[] Coef;
}

//le pide al usuario que entre el coeficiente y lo guarda
void Polynomial::readPolynomial()
{
	double coeficient;
	cout << "Enter the coeficients." <<endl;

	for (int i = degree; i >= 0; i--)
	{
		cout << "Enter coeficient of x^"<< i << ": ";
		cin >> coeficient;

		Coef[i] = coeficient;
	} 
}

//metodo para imprimir polinomio
void Polynomial::printPolynomial()
{
	for (int i = degree; i > 0; i--)
	{
		cout << Coef[i] << "x^" << i << " + ";
	}
	cout << Coef[0] << endl;
}

//metodo para imprimir polinomio de parametro entero
void Polynomial::printPolynomial(int n)
{
	if (n > degree + 1)
	{
		cout << "Error: Invalid coeficient index." << endl;
		return;
	}

	for (int i = degree; i > 0; i--)
		cout << Coef[i] << "x^" << i << " + ";
	cout << Coef[0] << endl;
}

//devuelve el valor de degree
int Polynomial::getDegree()
{
	return degree;
}

//genera numeros aleatorios
void Polynomial::generatePolynomial()
{
	for (int i = 0; i <= degree; ++i)
	{
		Coef[i] = rand() % 100;
	}
}

//overloading operator +=
void Polynomial::operator+= (const Polynomial &B)
{
	int i = 0;

	if (degree < B.degree)
	{
		double *sum;
		sum = new double[B.degree + 1];
		while (i <= degree)
		{
			sum[i] = Coef[i] + B.Coef[i];
			i++;
		}
		while ( i <= B.degree)
		{
			sum[i] = B.Coef[i];
			i++;
		}
		delete[] Coef;
		Coef = sum;
		degree = B.degree;
	}
	else
	{
		while (i <= B.degree)
		{
			Coef[i] += B.Coef[i];
			i++;
		}
	}
}

//Overloading operator +
Polynomial* Polynomial::operator+ (const Polynomial &B)
{
	Polynomial *sum;

	if (degree < B.degree)
	{
		sum = new Polynomial(B);
		for (int i = 0; i <= degree; i++)
			sum->Coef[i] += Coef[i];
	}
	else
	{
		sum = new Polynomial(*this);
		for (int i = 0; i <= B.degree; i++)
			sum->Coef[i] += B.Coef[i];
	}
	return sum;
}

//Overloading operator =
void Polynomial::operator= (const Polynomial &B)
{
	degree = B.degree;
	double *copy = new double[degree + 1];
	for (int i = 0; i <= degree; i++)
		copy[i] = B. Coef[i];
	delete[] Coef;
	Coef = copy;
}

//initialize polynomial
void Polynomial::initPolynomial(int i)
{
	delete[] Coef;
	Coef = new double[i + 1];
	degree = i;
}

//Overloading operador *
/******************************************************************
 metodo comentado es una ruta mas rapida para hacer el overloading,
 no la realice yo, por tanto, no la usare
*******************************************************************/
Polynomial *Polynomial::operator* (const Polynomial &B)
{
	/*
	int i, j;
	Polynomial *mult = new Polynomial(degree + B.degree);

	for (j = 0; j <= degree; j++)
		for (i=0; i<= B.degree; i++)
			mult->Coef[i + j] += Coef[i] * B.Coef[j];
	return mult;
	*/
	int left = 0, right = 0, i, j, newDegree = degree + B.degree;
	double sum;
	Polynomial *mult = new Polynomial(newDegree);

	while (left + right <= newDegree)
	{
		sum = 0;
		j = left;
		i = right;
		while (i <= left && j >= right)
		{
			sum += Coef[i] * B.Coef[j];
			i++; j--;
		}
		mult->Coef[left + right] = sum;
		if (left <= degree)
			left++;
		else
			right++;
	}
	return mult;

}


//metodo para el operador *=
/*****************************************************************
metodo comentado es una ruta mas rapida para hacer el overloading,
 no la realice yo, por tanto, no la usare
******************************************************************/
void Polynomial::operator *= (const Polynomial &B)
{

	/*
	int i,j, newDegree = degree + B.degree;
	double *mult = new double[newDegree + 1];

	for (j = 0; j <= degree; j++)
		for (i=0; i<= B.degree; i++)
			mult[i + j] += Coef[i] * B.Coef[j];
	delete[] Coef;
	Coef = mult;
	degree = newDegree;
	*/
		int left = 0, right = 0, i, j, newDegree = degree + B.degree;
		double sum;
	double *mult = new double[newDegree + 1];

	while (left + right <= newDegree)
	{
		sum = 0;
		j = left;
		i = right;
		while ( i<= left && j >= right)
		{
			sum+= Coef[i] * B.Coef[j];
			i++; j--;
		}
		mult[left + right] = sum;
		if (left <= degree)
			left++;
		else
			right++;
	
	} 
	degree = newDegree;
	delete[] Coef;
	Coef = mult;
}

//metodo para operador * con valor entero
Polynomial *Polynomial::operator* (int val)
{
	Polynomial *scaled = new Polynomial(*this);

	for (int i = 0; i <= degree; i++)
		scaled->Coef[i] *= val;
	return scaled;
}

//metodo para operador *= con valor entero
void Polynomial::operator*= (int val)
{
	for (int i = 0; i <= degree; i++)
		Coef[i] *= val;
}
































