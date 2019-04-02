#include "MergeSort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <ctime>
#include <chrono>
#include <string>
using namespace std;




void TestMSort(int n, int nt, float presorted) {

	std::fstream introsortlosowy;
	introsortlosowy.open("Mergesort" + std::to_string(presorted) + ".txt", std::ios::out | std::ios::app);

	int** tablice;

	tablice = new int*[nt];
	for (int j = 0; j < nt; j++)
		tablice[j] = new int[n];
	for (int j = 0; j < nt; j++)
		for (int i = 0; i < n; i++)
			tablice[j][i] = std::rand();
	//pre sorting part of array

	for (int j = 0; j < nt; j++)
	{

		MSort(tablice[j], 0, (int)n*presorted - 1);

	}

	std::chrono::duration<double> elapsed_seconds;
	std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<double>> start;
	std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<double>> end;

	for (int j = 0; j < nt; j++)
	{

		start = std::chrono::system_clock::now();
		MSort(tablice[j], 0,n - 1);
		end = std::chrono::system_clock::now();
		elapsed_seconds = elapsed_seconds + end - start;
	}
	introsortlosowy << "liczba elementow tablicy" << n << "\n";
	introsortlosowy << "czas sortowania jednej tablicy: " << elapsed_seconds.count() / 100 << "s\n";


	for (int i = 0; i < nt; i++)
		delete[] tablice[i];

	delete[] tablice;

}


void TestMSortOdwrotny(int n, int nt, float presorted) {

	std::fstream introsortlosowy;
	introsortlosowy.open("MSortTestOdwrocony" + std::to_string(presorted) + ".txt", std::ios::out | std::ios::app);

	int** tablice;

	tablice = new int*[nt];
	for (int j = 0; j < nt; j++)
		tablice[j] = new int[n];
	for (int j = 0; j < nt; j++)
		for (int i = 0; i < n; i++)
			tablice[j][i] = std::rand();
	//pre sorting part of array

	for (int j = 0; j < nt; j++)
	{

		int M = int(std::log2(presorted));
		MSort(tablice[j], 0, (int)n*presorted - 1);
		int tmp;
		for (int i = 0; i < n / 2; i++)
		{
			tmp = tablice[j][n - i - 1];
			tablice[j][n - i - 1] = tablice[j][i];
			tablice[j][i] = tmp;
		}
	}

	std::chrono::duration<double> elapsed_seconds;
	std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<double>> start;
	std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<double>> end;

	for (int j = 0; j < nt; j++)
	{
		int M = int(std::log2(presorted));

		start = std::chrono::system_clock::now();
		MSort(tablice[j], 0,n-1);
		end = std::chrono::system_clock::now();
		elapsed_seconds = elapsed_seconds + end - start;
	}
	introsortlosowy << "liczba elementow tablicy" << n << "\n";
	introsortlosowy << "czas sortowania jednej tablicy: " << elapsed_seconds.count() / 100 << "s\n";


	for (int i = 0; i < nt; i++)
		delete[] tablice[i];

	delete[] tablice;

}

/*
void TestMSort(int n, int nt, float presorted) {

	std::fstream introsortlosowy;
	introsortlosowy.open("MSort" + std::to_string(presorted) + ".txt", std::ios::out | std::ios::app);

	int** tablice;

	tablice = new int*[nt];
	for (int j = 0; j < nt; j++)
		tablice[j] = new int[n];
	for (int j = 0; j < nt; j++)
		for (int i = 0; i < n; i++)
			tablice[j][i] = std::rand();
	//pre sorting part of array
	int *tab_pom = new int[n];
	


	for (int j = 0; j < nt; j++)
	{
		MSort(tablice[j],0, (int)n*presorted-1);

	}




	std::chrono::duration<double> elapsed_seconds;
	std::chrono::time_point<std::chrono::system_clock,std::chrono::duration<double>> start;
	std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<double>> end;
	for (int j = 0; j < nt; j++)
	{
		auto start = std::chrono::system_clock::now();
		MSort(tablice[j],0, n-1);
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds =elapsed_seconds+ end - start;
	}
	delete[] tab_pom;
	introsortlosowy << "liczba elementow tablicy" << n << "\n";
	introsortlosowy << "czas: " << elapsed_seconds.count()/nt << "s\n";

	for (int i = 0; i < nt; i++)
		delete[] tablice[i];

	delete[] tablice;

}


void TestMSortOdwrotny(int n, int nt, float presorted) {

	std::fstream introsortlosowy;
	introsortlosowy.open("MSortOdwrocony" + std::to_string(presorted) + ".txt", std::ios::out | std::ios::app);

	int** tablice;

	tablice = new int*[nt];
	for (int j = 0; j < nt; j++)
		tablice[j] = new int[n];
	for (int j = 0; j < nt; j++)
		for (int i = 0; i < n; i++)
			tablice[j][i] = std::rand();
	//pre sorting part of array
	int *tab_pom = new int[n];

	int tmp;


	for (int j = 0; j < nt; j++)
	{
		MSort(tablice[j], 0, (int)n*presorted - 1);
		for (int i = 0; i < n / 2; i++)
		{
			tmp = tablice[j][n - i - 1];
			tablice[j][n - i - 1] = tablice[j][i];
			tablice[j][i] = tmp;
		}
	}

	std::chrono::duration<double> elapsed_seconds;
	std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<double>> start;
	std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<double>> end;
	for (int j = 0; j < nt; j++)
	{
		auto start = std::chrono::system_clock::now();
		MSort(tablice[j], 0, n - 1);
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = elapsed_seconds + end - start;
	}
	delete[] tab_pom;
	introsortlosowy << "liczba elementow tablicy" << n << "\n";
	introsortlosowy << "czas: " << elapsed_seconds.count()/nt << "s\n";


	for (int i = 0; i < nt; i++)
		delete[] tablice[i];

	delete[] tablice;

}
*/
int main(void)
{
	
	

	int nt = 100;
	int dlugosc_tablic[5] = { 10000,50000,100000,500000,1000000 };



	for (int i = 0; i < 5; i++) {
		TestMSort(dlugosc_tablic[i], nt, 0);

	}
	for (int i = 0; i < 5; i++) {

		TestMSort(dlugosc_tablic[i], nt, 0.25);
	}
	for (int i = 0; i < 5; i++)
	{

		TestMSort(dlugosc_tablic[i], nt, 0.5);
	}

	for (int i = 0; i < 5; i++) {

		TestMSort(dlugosc_tablic[i], nt, 0.75);
	}
	for (int i = 0; i < 5; i++) {

		TestMSort(dlugosc_tablic[i], nt, 0.99);
	}
	for (int i = 0; i < 5; i++) {

		TestMSort(dlugosc_tablic[i], nt, 0.997);
	}
	for (int i = 0; i < 5; i++) {

	//	TestMSort(dlugosc_tablic[i], nt, 1);
		TestMSortOdwrotny(dlugosc_tablic[i], nt, 1);

	}
	return 0;
}