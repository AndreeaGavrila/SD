#include <iostream>
#include <string.h>

using namespace std;

struct arborebinar
{
	char info[100];
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


arborebinar* inserare(arborebinar* radacina, char x[100])
{
	if (radacina == NULL)
	{
		arborebinar* aux = new arborebinar;

		strcpy_s(aux->info, x);

		aux->nod_stang = aux->nod_drept = NULL;

		return aux;
		radacina = aux;
	}
	else
	{
		arborebinar* aux = radacina;

		if (strcmp(x, aux->info) <= 0)
			aux->nod_stang = inserare(aux->nod_stang, x);

		else if (strcmp(x, aux->info) > 0)
			aux->nod_drept = inserare(aux->nod_drept, x);
	}
	return radacina;
}




int main()
{
	char c[100];
	int n;

	cout << "nr noduri: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "c[" << i << "]: "; cin >> c;
		if (i == 0)
		{
			radacina = inserare(radacina, c);
		}
		else
		{
			inserare(radacina, c);
		}
	}


	cout << "\nSRD: ";
	SRD(radacina);

	cout << "\nRSD: ";
	RSD(radacina);  cout << "\n\n";



}
