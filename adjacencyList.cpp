#include "adjacencyList.h"
#include "Vertex.h"
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <limits.h>

void AdjacencyList::setUpList(fstream &file)
{
	string line;//line from the input file to be processed

	while (getline(file, line))
	{
		setGraph(line);//going the the set graph function with the current line form the input file
	}
	indegree.resize(graph.size()); //setting up the indegree array that will help determine the indegree of each vertex
}

void AdjacencyList::setGraph(string line)
{
	Vertex vt;//creating a vertex object
	int x = 0; //the integer for the vertex map
	char c; //character for the vertex map
	vt.setName(line[0]);//setting the name of the verticie to the first character of the line
	for (int i = 1; i < line.size(); i++)
	{
		if (line[i] != ' ')
		{
			x = line[i]-'0'; //translating the integer out of a character by the - '0'
			i += 2; //going the character
			c = line[i]; //reading the character.
			vt.setMap(x, c);//inserting the pair to the vertexe's map
		}
	}
	graph.push_back(vt);//adding the vertex to the graph
}

void AdjacencyList::printGraph()
{
	

	for (int i = 0; i < graph.size(); i++)
	{
		graph[i].printMap();//print the vertexes (if any) that ar adjacent to the vertex
		cout << endl;
	}
}

void AdjacencyList::setIndegree()
{
	setIndegreeList();
	int numIndegrees = 0; //number of indegrees for 
	
	for (int i = 0; i < graph.size(); i++)
	{
		for (int j = 0; j < indegreeList.size(); j++)
		{
			if (graph[i].getName() == indegreeList[j])//if the name of the vertex appears in any of the maps
			{
				numIndegrees++;//increment the indegree
			}
		}
		graph[i].setIndegree(numIndegrees);
		graph[i].setTropDegree(graph[i].getInDegree());
		numIndegrees = 0;
	}
}

void AdjacencyList::dijkstra(char s)
{
	
	int index =-1;//used to check to see whether the input from the user is an actual vertex in the graph
	//find the index of s in the graph
	for (int i = 0; i < graph.size(); i++)
	{
		if (s == graph[i].getName())//if the user input matches a verticie in the graph
		{
			graph[i].setDistance(0);//set the verticie entered by the user to 0
			index = i;	//set the index to i
			graph[i].setKnown(false);//set known to false
		}
		else
		{
			graph[i].setDistance(INT_MAX); //setting the vertex's distance to infinity initially
			graph[i].setKnown(false);//set known to false
		}
	}


	int counter = 0; //used to count the known 
	int smallest = 0;//used for the smallest unknown vertex
	while (counter < graph.size())
	{
		//set index to the graph's index smallest known distance in the map. Needs a function
		smallest = findSmallestDist();//setting smallest to the smallest distance of a unknown verticie.
		graph[smallest].setKnown(true);//setting the smallest verticie to true
		counter++;//incrementing the counter

		//next is for verticies that are adjacent to the current vertice. Uses the verticie's map
		//if the vertice stays at infinity, then it is not reachable
		//set the distance adjacent nodes
		adjlist = graph[smallest].getMap();//getting the verticie's map
		adjacentIndexes = findIndexes();//getting the indexes that the verticies in the map belong to. Uses the adjlist map
		while (adjacentIndexes.size() > 0)//while there are adjacent verticies
		{
			int x = adjacentIndexes.front();//getting the front of the adjacent vertice index.
			if (graph[x].getKnown() == false)
			{
				int dist = distance.front();//getting the distance of the verticie from the smallest known vertex. 
				
				if (graph[smallest].getDistance()+dist < graph[x].getDistance())//if the known vertex + dist(distance) is less than the distance of the adjacent vertex
				{
					graph[x].setDistance(graph[smallest].getDistance() + dist);//setting the adjacent vertex to a smaller index
					graph[x].addToPath(graph[smallest].getName());//adding the vertex name to the path for the smallest vertex 
				}
			}
			adjacentIndexes.pop();//poping the adjacent indexes queue
			distance.pop(); //popping the disteance queue
		}
	}
	adjlist.clear();
}

int AdjacencyList::findSmallestDist()
{
	int small = INT_MAX;//setting small to infinity. Used to compare to the other graph vertexes
	int index = 0;//used to specify the smallest index for the smallest  
	for (int j = 0; j < graph.size(); j++)
	{
		if (small >= graph[j].getDistance() && graph[j].getKnown() == false)//if small is greater than or equal to the verticie's distance and it's not known
		{
			index = j;//index is set equal to the graphs smallest distance vertex
			small = graph[j].getDistance();//setting small to the distance of the smallest distance vertex
		}
	}
 	return index;//returning the smallest 
}

queue<int> AdjacencyList::findIndexes()
{
	queue<char> verticies;//queue for the name of the verticies in the map
	queue<int> indexes;//indexes for the verticies in the map
	map<char, int>::iterator p = adjlist.begin();
	for (p; p != adjlist.end(); ++p)
	{
		verticies.push(p->first);//the name of the verticie is added to the queue
		distance.push(p->second);//the distance of the verticies from the maps vertex is added to this queue
	}
	int index = 0;
	int size = verticies.size();
	while (indexes.size() < size) //now finding the indexes in the adjacency list for the adjacent nodes
	{
		//searching for the verticie in the adjacency list
		if (verticies.front() == graph[index].getName())
		{
			indexes.push(index);
			index = 0;
			verticies.pop();//poping the verticies queue
		}
		else
		{
			index++;
		}
	}
	return indexes;
}

void AdjacencyList::printIndegree()
{

	for (int i = 0; i < graph.size(); i++)
	{
		cout << graph[i].getName() << " : " << graph[i].getInDegree() << endl;
	}
}

void AdjacencyList::printDijkstra(char s)
{
	for (int i = 0; i < graph.size(); i++)
	{
		if (graph[i].getDistance() < 0 || graph[i].getDistance() == INT_MAX)
		{
			cout << "Warning: Not All Vertices May Be Reached." << endl;
		}
		else if(s == graph[i].getName())
		{
			cout << s << " -> " << graph[i].getName() << " : " <<graph[i].getDistance() << endl;
		}
		else
		{
			cout << s << " -> "; 
			graph[i].printPath(s);
			cout << graph[i].getName();
			cout << " : " << graph[i].getDistance() << endl;
		}
	}
}

void AdjacencyList::setIndegreeList()
{
	vector<char> temp;
	for (int i = 0; i < graph.size(); i++)
	{
		temp = graph[i].verticeOccurances();//finding the vertexes map and putting the names of the vertexes into a queue
		for (int j = 0; j < temp.size(); j++)
		{
			indegreeList.push_back(temp[j]);//adding elements of temp to indegreeList
		}
	}
}

void AdjacencyList::tropicalSort()
{
	queue<Vertex> q;//make a queue of vertexes
	
	for (int i = 0; i < graph.size(); i++)
	{
		if (graph[i].getInDegree() == 0)//if the indegree is zero
		{
			q.push(graph[i]);//push the vertex into the vertex queue
		}
	}
	
	while (!q.empty()) //while the queue is not empty
	{
		Vertex v = q.front();//cerating a vertex object to equal the front of the vertex queue
		q.pop();//popping the vertex queue
		tropSort.push_back(v.getName()); //push the name of the vertex (wiht a indegree of 0) into a vector that will print the result of the
			//tropical sort. 
		adjlist = v.getMap();//getting the map of the vertex
		adjacentIndexes = findIndexes(); //finding the indexes (in the graph adjacency list) of the adjacent verticies of the vertex. Uses the adjlist

		while (!adjacentIndexes.empty())//while integer location of the adjacent vertexes to v queue is not empty
		{
			if (graph[adjacentIndexes.front()].decrementTropDegree() == 0)//the indegree is decremented in the if statement
			{
				q.push(graph[adjacentIndexes.front()]);//push the vertex with a indegree of zero to the vertex queue
				adjacentIndexes.pop();//pop the adjacentIndexes queue
			}
			else
			{
				adjacentIndexes.pop();//pop the adjacent indexes queue
			}
		}
	}
	adjlist.clear();
	while (!distance.empty())//popping the distance queue since it is used with Dijkstra’s algorithm
	{
		distance.pop();
	}
}

void AdjacencyList::printTropSort()
{
	for (int i = 0; i < tropSort.size(); i++)
	{
		if (i == 0) //if at first index, only print the vertex name
		{
			cout << tropSort[i];
		}
		else //later indexes
		{
			cout << " -> " << tropSort[i];
		}
	}
	cout << endl;

	while (!distance.empty())//popping the distance queue since it is used with Dijkstra’s algorithm
	{
		distance.pop();
	}
}
