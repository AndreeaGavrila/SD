#include <iostream>

using namespace std;

struct arborebinar
{
	int info;
	arborebinar* nod_stang, * nod_drept;

} *radacina;


void SRD(arborebinar* rad)
{
	if ( rad != NULL )
	{
		SRD( rad->nod_stang );
		cout << rad->info << " ";
		SRD( rad->nod_drept );
	}
}


void RSD(arborebinar* rad)
{
	if ( rad != NULL )
	{
		cout << rad->info << " ";
		RSD( rad->nod_stang );
		RSD( rad->nod_drept );
	}
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


int cautare(int x)
{
	arborebinar* aux = radacina;
	while (aux != NULL)
	{
		if ( x == aux->info )
		{
			return 1;
		}

		if ( x <= aux->info )
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


arborebinar* max(arborebinar*& radacina)
{
	if (radacina->nod_drept != NULL)
		max(radacina->nod_drept);
	else
		return radacina;
}

arborebinar* stergere(arborebinar* radacina, int x)
{
	if (radacina == NULL)
		return radacina;

	if (x < radacina->info)
		radacina->nod_stang = stergere(radacina->nod_stang, x);
	else
		if (x > radacina->info)
		radacina->nod_drept = stergere(radacina->nod_drept, x);
		else
		{

			if (radacina->nod_stang == NULL && radacina->nod_drept == NULL)
			{
				delete radacina;
				radacina = NULL;
			}

			else

				if (radacina->nod_stang == NULL)
				{
					arborebinar* aux = radacina;
					radacina = radacina->nod_drept;
					radacina->nod_drept = stergere(radacina->nod_drept, aux->info);
				}
				else

					if (radacina->nod_drept == NULL)
					{
						arborebinar* aux = radacina;
						radacina = radacina->nod_stang;
						radacina->nod_stang = stergere(radacina->nod_stang, aux->info);
					}

					else
					{
						arborebinar* aux = max(radacina->nod_stang);
						radacina->info = aux->info;
						radacina->nod_stang = stergere(radacina->nod_stang, aux->info);
					}
		}
	return radacina;
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

	int x;
    cout << "Caut " ; cin >> x; cout << "= ";
	cout << "Rezultat: " <<cautare(x) << endl;


    cout << "Caut " ; cin >> x; cout << "= ";
	cout << "Rezultat: " << cautare(x) << endl;


	cout << "\nSterg " ; cin >> x;
	stergere(radacina, x);

	cout << "SRD: ";
	SRD(radacina); cout << endl;

	cout << "RSD: ";
	RSD(radacina); cout << endl;

}
