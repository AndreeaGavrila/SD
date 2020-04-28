#include <iostream>

using namespace std;

struct arborebinar
{
	int info;
	arborebinar* nod_stang, * nod_drept;

} *radacina;


void SRD(arborebinar* rad)
{
	if (rad != NULL)
	{
		SRD(rad->nod_stang);
		cout << rad->info << " ";
		SRD(rad->nod_drept);
	}
}


void RSD(arborebinar* rad)
{
	if (rad != NULL)
	{
		cout << rad->info << " ";
		RSD(rad->nod_stang);
		RSD(rad->nod_drept);
	}
}


int cautare(int x)
{
	arborebinar* aux = radacina;
	while (aux != NULL)
	{
		if (x == aux->info)
		{
			return 1;
		}

		if (x <= aux->info)
		{
			aux = aux->nod_stang;
		}
		else
		{
			aux = aux->nod_drept;
		}
	}
	return 0;
}



void inserare(arborebinar*& radacina, int x)
{
	if (radacina == NULL)
	{
		radacina = new arborebinar;
		radacina->info = x;
		radacina->nod_stang = radacina->nod_drept = NULL;
		return;
	}
	if (x < radacina->info)
		inserare(radacina->nod_stang, x);
	else
		inserare(radacina->nod_drept, x);
}



int main()
{
	

	int v[100], i, n;
	cout << "nr noduri: "; cin >> n;
	for (i = 0; i < n; i++)
	{
		cout<<"v["<<i<<"]: "; cin >> v[i];
	}

	for (i = 0; i < n; i++)
		inserare(radacina, v[i]); 
	

	cout << "\nSRD: ";
	SRD(radacina);

	cout << "\nRSD: ";
	RSD(radacina);  cout << "\n\n";



	int k1, k2;
	cout << "k1= "; cin >> k1;
	cout << "k2= "; cin >> k2;
	if (k2 < k1)
		swap(k1, k2);

	k1++;
	cout << "\nIntervalul (k1, k2): ";
	while (k1 < k2)
	{
		if (cautare(k1))
			cout << k1 << " ";
		k1++;
	}
	cout << "\n";

}
