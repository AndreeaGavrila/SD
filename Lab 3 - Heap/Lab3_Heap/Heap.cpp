#include<iostream>
#include "Heap.h"

using namespace std;

Heap::Heap() {
	dimensiune = 0;
	lungime = 0;
	vect_heap = nullptr;
}

Heap::Heap(int dimensiune) {
	this->dimensiune = dimensiune;
	lungime = 0;
	vect_heap = new int[dimensiune];
}

Heap::~Heap() {
	dimensiune = lungime = 0;
	delete[] vect_heap;
}

Heap::Heap(Heap& H) {
	dimensiune = H.dimensiune;
	lungime = H.lungime;
	vect_heap = new int[dimensiune];

	for (int i = 0; i < lungime; i++)
		vect_heap[i] = H.vect_heap[i];
}

/* Pentru array - uri care incep de la pozitia 0:
- tatal elementului i se gaseste la pozitia(i - 1) / 2
- fiul stang al elementului i se gaseste la pozitia 2 * i + 1
- fiul drept al elementului i se gaseste la pozitia 2 * i + 2   */


int Heap::parinte(int i) {
	return (i - 1) / 2;
}

int Heap::fiu_stang(int i) {
	return 2 * i + 1;
}

int Heap::fiu_drept(int i) {
	return 2 * i + 2;
}

void Heap::inserare_valoare(int x) {

	if (lungime == dimensiune)
	{
		cout << "\n Dimensiunea este insuficienta!";
		return;
	}
	else
	{
		int i = lungime;
		lungime++;
		vect_heap[i] = x;
		while (i != 0 && vect_heap[parinte(i)] > vect_heap[i])
		{
			swap(vect_heap[parinte(i)], vect_heap[i]);
			i = parinte(i);
		}
	}
}

void Heap::afisare() {
	// cout << "\n Heap = ";
	for (int i = 0; i < lungime; i++)
		cout << vect_heap[i] << " ";
	cout << endl;
}

int Heap::extragere_minim() {

	if (lungime == 0)
	{
		cout << "\n Heap-ul este gol!";
		return 0;
	}
	if (lungime == 1)
	{
		lungime--;
		return vect_heap[0];
	}

	int m = vect_heap[0];
	swap(vect_heap[0], vect_heap[lungime - 1]);
	lungime--;

	int ok = 1;
	int curent = 0;
	int anterior = 0;

	while (ok)
	{
		ok = 0;
		int stang = fiu_stang(curent);
		int drept = fiu_drept(curent);

		if (stang < lungime)
		{
			if (vect_heap[stang] < vect_heap[curent])
				curent = stang;
		}

		if (drept < lungime)
		{
			if (vect_heap[drept] < vect_heap[curent])
				curent = drept;
		}

		if (curent != anterior)
		{
			ok = 1;
			swap(vect_heap[anterior], vect_heap[curent]);
			anterior = curent;
		}
	}
	return m;
}
