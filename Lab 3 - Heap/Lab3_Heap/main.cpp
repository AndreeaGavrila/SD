#include <iostream>
#include "Heap.h"

using namespace std;

void HeapSort(int* v, int n) {
    Heap H(n);
    int i;
    for (i = 0; i < n; i++)
        H.inserare_valoare(v[i]);
    for (i = 0; i < n; i++)
        v[i] = H.extragere_minim();
}

void CountSort(int* v, int n) {

    int i, stg = v[0], dr = v[0];
    int* many, * rez;

    for (i = 1; i < n; i++)
    {
        if (v[i] < stg)
            stg = v[i];

        if (v[i] > dr)
            dr = v[i];
    }
    int interv = dr - stg + 1;
    many = new int[interv];
    rez = new int[n];

    for (i = 0; i < interv; i++)
        many[i] = 0;

    for (i = 0; i < n; i++)
        many[v[i] - stg]++;

    for (i = 1; i < interv; i++)
        many[i] += many[i - 1];

    for (i = 0; i < n; i++)
    {
        rez[many[v[i] - stg] - 1] = v[i];
        many[v[i] - stg]--;
    }

    for (i = 0; i < n; i++)
        v[i] = rez[i];
}



void RadixSort(int* v, int n) {

    int i, p = 1, ok = 0;
    int* many, * rez;
    many = new int[10];
    rez = new int[n];


    do {
        ok = 0;
        for (i = 0; i < n; i++)
            if (v[i] / p)
                ok = 1;
        if (ok)
        {
            for (i = 0; i < 10; i++)
                many[i] = 0;

            for (i = 0; i < n; i++)
                many[v[i] / p % 10]++;

            for (i = 1; i < 10; i++)
                many[i] += many[i - 1];

            for (i = n - 1; i >= 0; i--)
            {
                rez[many[v[i] / p % 10] - 1] = v[i];
                many[v[i] / p % 10]--;
            }

            for (i = 0; i < n; i++)
                v[i] = rez[i];
        }
        p *= 10;

    } while (ok);
}




void RadixSortpeBiti(int* v, int n) {

    int i, p = 1, ok = 0;
    int* many, * rez;
    many = new int[256];
    rez = new int[n];

    do {
        ok = 0;
        for (i = 0; i < n; i++)
            if (v[i] >> p)
                ok = 1;
        if (ok)
        {
            for (i = 0; i < 256; i++)
                many[i] = 0;

            for (i = 0; i < n; i++)
                many[(v[i] >> p) & 255]++;

            for (i = 1; i < 256; i++)
                many[i] += many[i - 1];

            for (i = n - 1; i >= 0; i--)
            {
                rez[many[(v[i] >> p) & 255] - 1] = v[i];
                many[(v[i] >> p) & 255]--;
            }

            for (i = 0; i < n; i++)
                v[i] = rez[i];
        }
        p += 8;

    } while (ok);
}



int main()
{

    // Implementare min-Heap:
    cout << "Problema 1\n\n";

    Heap H(100);

    H.inserare_valoare(9);  H.inserare_valoare(5); // H.afisare();
    H.inserare_valoare(3);  H.inserare_valoare(7); // H.afisare();
    H.inserare_valoare(6);  H.inserare_valoare(2);

    cout << "H-heap: ";     H.afisare();


    cout << "\nMinimul extras: " << H.extragere_minim() << '\n';
    cout << "H-heap: ";     H.afisare();


    // Heap Sort: 

    cout << "\n\nProblema 2\n\n";

    int* v;
    int n = 0, i;

    cout << "n= ";
    cin >> n;

    v = new int[n];
    cout << "v= ";
    for (i = 0; i < n; i++)
        cin >> v[i];

    HeapSort(v, n);
    cout << "\nHeap Sort: ";
    for (i = 0; i < n; i++)
        cout << v[i] << ' ';

    delete[] v;


    //Count Sort:

    cout << "\n\nProblema 3\n\n";

    int* w;
    int l = 0;

    cout << "l= ";
    cin >> l;

    w = new int[l];
    cout << "w= ";
    for (i = 0; i < l; i++)
        cin >> w[i];

    CountSort(w, l);
    cout << "\nCount Sort: ";
    for (i = 0; i < l; i++)
        cout << w[i] << ' ';

    delete[] w;


    // Radix Sort:

    cout << "\n\nProblema 4\n\n";

    int* t;
    int m = 0;

    cout << "m= ";
    cin >> m;

    t = new int[m];
    cout << "t= ";

    for (i = 0; i < m; i++)
        cin >> t[i];

    RadixSort(t, m);
    cout << "\nRadix Sort: ";
    for (i = 0; i < m; i++)
        cout << t[i] << ' ';

    delete[] t;


    int* r;
    int p = 0;

    cout << "\np= ";
    cin >> p;

    r = new int[p];
    cout << "r= ";

    for (i = 0; i < p; i++)
        cin >> r[i];

    RadixSortpeBiti(r, p);
    cout << "\nRadix Sort pe Biti: ";
    for (i = 0; i < p; i++)
        cout << r[i] << ' ';

    delete[] r;


    return 0;
}
