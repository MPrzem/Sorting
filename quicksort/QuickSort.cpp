#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "QuickSort.h"



int main()
{
	int nt = 100;
	int dlugosc_tablic[5] = { 10000,50000,100000,500000,1000000 };
	for (int i = 0; i < 5; i++) {
		TestQuickSort(dlugosc_tablic[i], nt, 0);
	}
	for (int i = 0; i < 5; i++) {
		TestQuickSort(dlugosc_tablic[i], nt, 0.25);
	}
	for (int i = 0; i < 5; i++)
	{

		TestQuickSort(dlugosc_tablic[i], nt, 0.5);
	}

	for (int i = 0; i < 5; i++) {

		TestQuickSort(dlugosc_tablic[i], nt, 0.75);
	}
	for (int i = 0; i < 5; i++) {

		TestQuickSort(dlugosc_tablic[i], nt, 0.99);
	}
	for (int i = 0; i < 5; i++) {

		TestQuickSort(dlugosc_tablic[i], nt, 0.997);
	}
	for (int i = 0; i < 5; i++) {
		TestQuickSortOdwrocony(dlugosc_tablic[i], nt, 1);
		TestQuickSort(dlugosc_tablic[i], nt, 1);
	}
	getchar();
	return 0;
}

