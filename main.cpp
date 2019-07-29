/*
@name: clint Wyatt
@date: 7/2/2019
@description: This project constructs a graph using a adjacency list. Dijkstras algorithm is used for the shortest path between a user selected edge 
and all other vertices. Topological sort is used to order the verticies in order, from the vertexes with the least indegree to the vertices with
the highest indegree. 
*/
#include <iostream>
#include <fstream>
#include <string>
#include "adjacencyList.h"

using namespace std;

int main()
{
	AdjacencyList adj;
	fstream inFile, inFile2;
	string fileName;
	char vertex;//user input for the vertex
	char decision;//user input

	cout << "Enter the name of the input file: ";
	cin >> fileName;
	inFile.open(fileName);

	while (!inFile) {

		cout << "ERROR: invalid file name. To quit, enter 'q'. Enter a valid file name: ";
		cin >> fileName;

		if (fileName == "q") {
			exit(0);
		}
		inFile.open(fileName);

	}
	adj.setUpList(inFile);
	cout << "File " << fileName << " successfully loaded into graph." << endl;
	adj.setIndegree();//setting the indegree of all vertexes
	adj.tropicalSort();//performing the tropical sort algorithm

	do
	{
		cout << "Enter option choice 1 - 5:" << endl;
		cout << "(1) Print Adjacency List" << endl;
		cout << "(2) Print Single-Source Shortest Path" << endl;
		cout << "(3) Print Indegree of Each Vertex" << endl;
		cout << "(4) Print Topological Sort of Graph" << endl;
		cout << "(5) Exit Program" << endl;
		cin >> decision;

		if (decision == '1')
		{
			adj.printGraph();
		}
		else if (decision == '2')
		{
			cout << "Enter Source Vertex (char) for Shortest Path:";
			cin >> vertex;
			adj.dijkstra(vertex);//entering the vertex into the dijkstra algorithmy
			adj.printDijkstra(vertex);
		}
		else if (decision == '3')
		{
			cout << "Indegree of Each Vertex:" << endl;
			adj.printIndegree();
		}
		else if (decision == '4')
		{
			adj.printTropSort();//print the tropical sort of the graph
		}
		else if (decision == '5')
		{
			break;
		}
		else
		{

		}
	}while(decision != 5);//if decision is 5, the loop ends and the program terminates

	return(0);
}
