#include<iostream>
#include "directedGraph.h"

using namespace std;

int main()
{
	directedGraph G;
	int n;
	cout << "nr noduri: ";
	cin >> n;
	cout << '\n';
	for (int i = 1; i <= n; i++)
	{
		G.addNode(i);
		for (int j = 1; j <= n; j++)
			if ((j % i == 0 || i % j == 0) && i != j)
			{
				G.addEdge(i, j);
				cout << "muchia: " << i << '-' << j << "  \n";
			}
	}

	G.marcare_vizitare();
	cout << "\nBFS: ";
	G.BFS(1);

	G.marcare_vizitare();
	cout << "\nDFS: ";
	G.DFS(1);

	cout << "\nTwo cycles: " << G.twoCycles()<<'\n';

	return 0;
}
