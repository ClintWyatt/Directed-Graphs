#include "Vertex.h"
#include <iostream>
using namespace std;

Vertex::Vertex()
{
	name = ' ';
	indegree = 0;
	//int dist = INT_MAX;//similar to infinity
}



void Vertex::setIndegree(int x)
{
	indegree = x;
}

Vertex & Vertex::operator=(const Vertex obj)
{
	//Vertex v;
	name = obj.name;
	adj = obj.adj;
	adjacentVerticies = obj.adjacentVerticies;
	known = obj.known;
	dist = obj.dist;
	path = obj.path;
	indegree = obj.indegree;
	mapSize = obj.mapSize;
	tropDegree = obj.tropDegree;
	//return v;
	
}

int Vertex::getInDegree()
{
	return indegree;
}

void Vertex::setName(char a)
{
	name = a;
}
char Vertex::getName()
{
	return name;
}

void Vertex::setDistance(int x)
{
	dist = x;
}

int Vertex::getDistance()
{
	return dist;
}

void Vertex::setMap(int x, char c)
{
	adjacentVerticies.push(c);//pushing the adjacent verticie to a queue
	adj.insert(pair<char, int>(c, x));//inserting a verticie into the map
	//mapSize++;//incrementing the size of the map
}

void Vertex::printMap()
{
	cout << getName() << " : ";
	map<char, int>::iterator p = adj.begin(); //setting the iterator to the beginning of the map;

	for (p; p != adj.end(); ++p)
	{
		cout << "-> (" << p->first << ", " << p->second << ")";
	}

}

int Vertex::checkVerticies(char comp)
{
	int x = 0;
	map<char, int>::iterator p = adj.begin();
	for (p; p != adj.end(); ++p)
	{
		if (comp == p->first)//if the verticie is in the map
		{
			x++; //increment x to 1. Represents the number of times 
			return x;
		}
	}
	return x;
}

void Vertex::setKnown(bool val)
{
	known = val;
}

bool Vertex::getKnown()
{
	return known;
}

map<char, int> Vertex::getMap()
{
	return adj;
}

int Vertex::getMapSize()
{
	return adj.size(); //represents the number of adjacent verticies
}

queue<char> Vertex::getQueue()
{
	return adjacentVerticies;
}

void Vertex::setPath(char c)
{
	path = c;
}

char Vertex::getPath()
{
	return path;
}

vector<char> Vertex::verticeOccurances()
{
	vector<char> temp;
	map<char, int>::iterator p = adj.begin();
	for (p; p != adj.end(); ++p)
	{
		temp.push_back(p->first);
	}
	return temp;

}

void Vertex::setTropDegree(int x)
{
	tropDegree = x;
}

int Vertex::decrementTropDegree()
{
	tropDegree--;
	return tropDegree;
}

void Vertex::addToPath(char c)
{
	vertexPath.push_back(c);

}

void Vertex::printPath(char c)
{
	
	for (int i = vertexPath.size() -1; i > -1; i--)
	{
		if (vertexPath[i] != c)
		{
			cout << vertexPath[i] << " -> ";
		}
	}
	vertexPath.clear();
}
