#ifndef QuickSort
#define QuickSort
#include <fstream>
#include <ctime>
#include <chrono>
#include <string>
template <class Item>
void swap(Item*a, Item*b) {
	int tmp(*a);
	*a = *b;
	*b = tmp;
}
template <class Item>
void Quick_Sort(Item tab[], int start, int end)
{
	if (end <= start)
		return;
	int L_lim = start;
	int R_Lim = end;

	int pivot = tab[(start + end) / 2]; //piwot na srodku
	
	do{
		while (tab[L_lim] < pivot) 
			L_lim++;

		
		while (tab[R_Lim] > pivot)
			R_Lim--;

		if (L_lim <= R_Lim)
		{
			swap(&tab[L_lim], &tab[R_Lim]);

			L_lim++;
			R_Lim--;
		}
	}while (L_lim < R_Lim);

	Quick_Sort(tab, start, R_Lim);

	 Quick_Sort(tab, L_lim, end);

}







void TestQuickSort(int n, int nt, float presorted) {

	std::fstream introsortlosowy;
	introsortlosowy.open("QuickSortTest" + std::to_string(presorted) + ".txt", std::ios::out | std::ios::app | std::ios::ate);

	int** tablice;

	tablice = new int*[nt];
	for (int j = 0; j < nt; j++)
		tablice[j] = new int[n];
	for (int j = 0; j < nt; j++)
		for (int i = 0; i < n; i++)
			tablice[j][i] = std::rand();
	//pre sorting part of array

	for (int j = 0; j < nt; j++)
		Quick_Sort(tablice[j], 0, ((int)n*presorted) - 1);

	std::chrono::duration<double> elapsed_seconds;
	std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<double>> start;
	std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<double>> end;

	for (int j = 0; j < nt; j++)
	{
		start = std::chrono::system_clock::now();
		Quick_Sort(tablice[j], 0, n - 1);
		end = std::chrono::system_clock::now();
		elapsed_seconds =elapsed_seconds+ end - start;
	}

	introsortlosowy << "liczba elementow tablicy" << n << "\n";
	introsortlosowy << "czas: " << elapsed_seconds.count()/nt << "s\n";


	for (int i = 0; i < nt; i++)
		delete[] tablice[i];

	delete[] tablice;

}
void TestQuickSortOdwrocony(int n, int nt, float presorted) {

	std::fstream introsortlosowy;
	introsortlosowy.open("QuickSortTestOdwrocony" + std::to_string(presorted) + ".txt", std::ios::out | std::ios::app | std::ios::ate);

	int** tablice;

	tablice = new int*[nt];
	for (int j = 0; j < nt; j++)
		tablice[j] = new int[n];
	for (int j = 0; j < nt; j++)
		for (int i = 0; i < n; i++)
			tablice[j][i] = std::rand();
	//pre sorting part of array

	for (int j = 0; j < nt; j++)
		Quick_Sort(tablice[j], 0, ((int)n*presorted) - 1);

	std::chrono::duration<double> elapsed_seconds;
	std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<double>> start;
	std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<double>> end;

	for (int j = 0; j < nt; j++)
	{
		int tmp;
		for (int i = 0; i < n / 2; i++)
		{
			tmp = tablice[j][n - i - 1];
			tablice[j][n - i - 1] = tablice[j][i];
			tablice[j][i] = tmp;
		}
	}

	for (int j = 0; j < nt; j++)
	{
		start = std::chrono::system_clock::now();
		Quick_Sort(tablice[j], 0, n - 1);
		end = std::chrono::system_clock::now();
		elapsed_seconds = elapsed_seconds + end - start;
	}

	introsortlosowy << "liczba elementow tablicy" << n << "\n";
	introsortlosowy << "czas: " << elapsed_seconds.count() / nt << "s\n";


	for (int i = 0; i < nt; i++)
		delete[] tablice[i];

	delete[] tablice;

}
#endif // !QuickSort




