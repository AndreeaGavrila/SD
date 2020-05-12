#pragma once
#include<iostream>
#include<vector>
using namespace std;

class directedGraph
{
	vector<int> lista_adiacenta[10001];
	bool vizitat[10001];
	static int nr_noduri;

public:

	void addNode(int); 
	void addEdge(int, int); 
	int hasEdge(int, int); 
	void marcare_vizitare();

	void BFS(int);   
	void DFS(int);; 
	
	int twoCycles(); 
}; 