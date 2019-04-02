#pragma once
#ifndef MergeSort
#define MergeSort



using namespace std;


template <class Item>
void merge(Item tablica[], int start, int srodek, int koniec, Item *tab_pom)
{
	int i = start, j = srodek + 1, k = 0; // zmienne pomocnicze
	for (int k = 0; k < koniec - start + 1; k++)
	{
		if (i <= srodek)
			if (j <= koniec)
				if ((tablica[j] < tablica[i]))
					tab_pom[k] = tablica[j++];
				else
				{
					tab_pom[k] = tablica[i++];
				}
			else
			{
				tab_pom[k] = tablica[i++];
			}
		else if (j <= koniec)
		{
			tab_pom[k] = tablica[j++];
		}
	}

	for (i = 0; i <= koniec - start; i++)
		tablica[start + i] = tab_pom[i];
}
template <class Item>
void merge_sort(Item tablica[], int start, int koniec, Item* tab_pom)
{
	int srodek;

	if (start >= koniec)
		return;

	srodek = (start + koniec) / 2;
	merge_sort(tablica, start, srodek, tab_pom);
	merge_sort(tablica, srodek + 1, koniec, tab_pom);
	merge(tablica, start, srodek, koniec, tab_pom);

}

template <class Item>
void MSort(Item tablica[], int start, int koniec) {
	Item *tab_pom = new int[koniec+1];
	merge_sort(tablica, start, koniec, tab_pom);
	delete[] tab_pom;

}

#endif