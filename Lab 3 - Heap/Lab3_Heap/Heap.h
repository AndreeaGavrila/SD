#pragma once
class Heap
{
	int* vect_heap;
	int dimensiune;
	int lungime;

public:
	Heap();
	Heap(int dim);
	Heap(Heap& H);
	~Heap();

	int parinte(int i);
	int fiu_stang(int i);
	int fiu_drept(int i);

	int extragere_minim();
	void inserare_valoare(int x);

	void afisare();
};

