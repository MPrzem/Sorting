#include "IntrospectiveSort.h"
#include <math.h>  
# define M_LN2          0.6931471805599453094

void TestIntroSortlosowy(int n, int nt, float presorted) {

	std::fstream introsortlosowy;
	introsortlosowy.open("IntroSortTest" + std::to_string(presorted) + ".txt", std::ios::out | std::ios::app);

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
			IntroSort(tablice[j], 0 , (int)n*presorted,M);

	}

	std::chrono::duration<double> elapsed_seconds;
	std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<double>> start;
	std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<double>> end;

	for (int j = 0; j < nt; j++)
	{
		int M = int(std::log2(presorted));

		start = std::chrono::system_clock::now();
		IntroSort(tablice[j], 0,n, M);
		end = std::chrono::system_clock::now();
		elapsed_seconds = elapsed_seconds + end - start;
	}
	introsortlosowy << "liczba elementow tablicy" << n << "\n";
	introsortlosowy << "czas sortowania jednej tablicy: " << elapsed_seconds.count()/100 << "s\n";


	for (int i = 0; i < nt; i++)
		delete[] tablice[i];

	delete[] tablice;

}


void TestIntroSortlosowyOdwrocony(int n, int nt, float presorted) {

	std::fstream introsortlosowy;
	introsortlosowy.open("IntroSortTestOdwrocony" + std::to_string(presorted) + ".txt", std::ios::out | std::ios::app);

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
		IntroSort(tablice[j], 0, (int)n*presorted, M);
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
		IntroSort(tablice[j], 0, n, M);
		end = std::chrono::system_clock::now();
		elapsed_seconds = elapsed_seconds + end - start;
	}
	introsortlosowy << "liczba elementow tablicy" << n << "\n";
	introsortlosowy << "czas sortowania jednej tablicy: " << elapsed_seconds.count() / 100 << "s\n";


	for (int i = 0; i < nt; i++)
		delete[] tablice[i];

	delete[] tablice;

}







int main(void)
{

	srand(time(NULL));

	
	int nt = 100;
	int dlugosc_tablic[5] = { 10000,50000,100000,500000,1000000 };
	for (int i = 0; i < 5; i++) {
		TestIntroSortlosowy(dlugosc_tablic[i], nt, 0.997);

	}
	for (int i = 0; i < 5; i++) {

		TestIntroSortlosowy(dlugosc_tablic[i], nt, 0.25);
	}
	for (int i = 0; i < 5; i++)
	{

		TestIntroSortlosowy(dlugosc_tablic[i], nt, 0.5);
	}

	for (int i = 0; i < 5; i++) {

	TestIntroSortlosowy(dlugosc_tablic[i], nt, 0.75);
}
for (int i = 0; i < 5; i++) {

	TestIntroSortlosowy(dlugosc_tablic[i], nt, 0.99);
}
for (int i = 0; i < 5; i++) {
	TestIntroSortlosowyOdwrocony(dlugosc_tablic[i], nt, 1);
	TestIntroSortlosowy(dlugosc_tablic[i], nt, 1);
} 
	return 0;
}