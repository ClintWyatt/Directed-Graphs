#ifndef H_adjacencyList
#define H_adjacencyList
#include "Vertex.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <vector>
using namespace std;



class AdjacencyList
{

public:
	//AdjacencyList();
	
	void setUpList(fstream &file);
	void printGraph();
	void setIndegree();
	void dijkstra(char s);
	int findSmallestDist();
	queue<int> findIndexes();
	void printIndegree();
	void printDijkstra(char s);
	void setIndegreeList();
	void tropicalSort();
	void printTropSort();

private:
	void setGraph(string line);
	int size = 0;
	map<char, int> adjlist;
	
	//map<char, int> indexes;
	vector<Vertex> graph;//actual graph
	vector<int> indegree;
	queue<int> adjacentIndexes;
	queue<int> distance;
	vector<char> indegreeList;
	vector<char> tropSort;
};


#endif // !H_adjacencyList
#pragma once
