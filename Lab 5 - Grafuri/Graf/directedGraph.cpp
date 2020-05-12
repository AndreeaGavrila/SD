#include "directedGraph.h"

int directedGraph::nr_noduri = 0;

void directedGraph::addNode(int a)
{
	vector<int> lista;
	lista_adiacenta[a] = lista;	
	nr_noduri++;	
}

void directedGraph::addEdge(int source, int target)
{
	lista_adiacenta[source].push_back(target);
}

int directedGraph::hasEdge(int source, int target)
{
	for (auto i : lista_adiacenta[source])
		if (i == target)
			return 1;
	return 0;
}

void directedGraph::marcare_vizitare()
{
	for (int i = 0; i < 10001; i++)
		vizitat[i] = false;
}

void directedGraph::BFS(int startNode)
{
	marcare_vizitare();

	vector<int> coada;
	vizitat[startNode] = true;  

	coada.push_back(startNode);

	while (coada.size())
	{
		cout << *coada.begin() << " ";

		for (auto i : lista_adiacenta[*coada.begin()])
		{
			if ( vizitat[i]==0 )
			{
				vizitat[i] = true;
				coada.push_back(i);
			}
		}
		coada.erase(coada.begin());	
	}
}

void directedGraph::DFS(int startNode)
{
	vizitat[startNode] = true;

	cout << startNode << " ";

	for (auto i : lista_adiacenta[startNode])
		if ( vizitat[i]==0 )
			DFS(i);
}

int directedGraph::twoCycles()
{
	int nr_cicluri = 0;	

	vector< vector<int>> muchii(nr_noduri + 1);

	for (int i = 0; i <= nr_noduri; i++)
		for (int j = 0; j <= nr_noduri; j++)
			muchii[i].push_back(0);	

	for (int i = 1; i < nr_noduri + 1; i++)
		for (int j = 1; j < nr_noduri + 1; j++)
		{
			if ( hasEdge(i, j) == 1  &&  hasEdge(j, i) == 1 && muchii[i][j] == 0 )
						nr_cicluri++;

			muchii[i][j] = 1; 
			muchii[j][i] = 1;
		}

	return nr_cicluri;
}