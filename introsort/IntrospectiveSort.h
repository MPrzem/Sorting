#include <math.h>  
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
#include <string>
#include <cstdlib>
#ifndef intro
#define intro



template <class Item>
void swap(Item *Array, long i, long j)
{
	Item temp;
	temp = Array[i];
	Array[i] = Array[j];
	Array[j] = temp;
}
template <class Item>
void Heapify(Item *Array, long i, long N)
{
	long j;
	while (i <= N / 2)
	{
		j = 2 * i;
		if (j + 1 <= N && Array[j + 1] > Array[j])
			j = j + 1;
		if (Array[i] < Array[j])
			swap(Array, i, j);
		else break;
		i = j;
	}
}


template <class Item>
void Heap_Sort(Item *Array, long N)
{
	long i;
	for (i = N / 2; i > 0; --i)
		Heapify(Array - 1, i, N);
	for (i = N - 1; i > 0; --i)
	{
		swap(Array, 0, i);
		Heapify(Array - 1, 1, i);
	}	
}

template <class Item>
void IntroSort(Item *Array, int start_index, int end_index, int M)
{
	if (start_index >= end_index)
		return;
	if (M <= 0) {
		Heap_Sort(Array + start_index, end_index-start_index);
		return;
	}
	int L_lim = start_index;
	int R_Lim = end_index;

	int pivot = Array[(start_index + end_index) / 2]; //piwot na srodku

	do {
		while (Array[L_lim] < pivot)
			L_lim++;


		while (Array[R_Lim] > pivot)
			R_Lim--;

		if (L_lim <= R_Lim)
		{
			swap(Array,L_lim,R_Lim);

			L_lim++;
			R_Lim--;
		}
	} while (L_lim < R_Lim);

	IntroSort(Array, start_index, R_Lim,M-1);

	IntroSort(Array, L_lim, end_index,M-1);

}





void TestIntroSortlosowy(int n,int nt,int M,float presoted); 
#endif // !a