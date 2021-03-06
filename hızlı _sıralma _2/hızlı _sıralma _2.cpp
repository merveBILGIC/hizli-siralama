// hızlısıralma _2.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include <iostream>

void hsirala(int M[], int ilk, int son);
int ortadaki(int M[], int ilk, int son);
void swap(int& M, int& K);
void swapNoTemp(int& M, int& K);
void yaz(int dizi[], const int& N);
using namespace std;


int main()
{
	int test[] = { 7,-13,1,3,10,2,4 };
	int N = sizeof(test) / sizeof(int);

	cout << "test dizisinin boyutu :" << N << endl;
	cout << " sıralamadan önce: " << endl;
	yaz(test, N);

	hsirala(test, 0, N - 1);
	cout << endl << endl << "sıralamadan sonra :" << endl;
	yaz(test, N);
	return 0;
}

	void hsirala(int M[], int ilk, int son)
	{

		int ortadaki_element;
		if (ilk < son)
		{
			ortadaki_element = ortadaki(M, ilk, son);
			hsirala(M, ilk, ortadaki_element - 1);
			hsirala(M, ortadaki_element + 1, son);
		}
	}

	int ortadaki(int M[], int ilk, int son)
	{
		int p = ilk;
		int ortadaki_element = M[ilk];

		for (int i = ilk + 1; i <= son; i++)
		{
			if (M[i] <= ortadaki_element)
			{
				p++;
				swap(M[i], M[p]);

			}
		}

		swap(M[p], M[ilk]);
		return p;
	}

	void swap(int& M, int& K)
	{
		int temp = M;
		M = K;
		K = temp;
	}

	void swapNoTemp(int& M, int& K)
	{
		M -= K;
		K += M;
		M = (K - M);
	}

	void yaz(int M[], const  int& N)
	{
		for (int i = 0; i < N; i++)
			cout << "dizi[" << i << "] = " << M[i] << endl;
	}
