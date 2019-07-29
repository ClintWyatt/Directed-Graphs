#ifndef H_Vertex
#define H_Vertex

#include <map>
#include <queue>
#include <vector>
using namespace std;
class Vertex
{
public:
	Vertex();
	//~Vertex();
	Vertex & operator = (const Vertex obj); //overriding the equal operator
	int getInDegree();
	void setName(char a);
	int getDistance();
	void setDistance(int x);
	void setIndegree(int x);
	void setMap(int x, char a);
	void printMap();
	char getName();
	void setPath(char c);
	char getPath();
	int checkVerticies(char comp);
	void setKnown(bool val);
	bool getKnown();
	vector<char> verticeOccurances();
	map<char, int> getMap();
	int getMapSize();
	queue<char> getQueue();
	void setTropDegree(int x);
	int decrementTropDegree();
	void addToPath(char c);
	void printPath(char c);
private:
	queue<char> adjacentVerticies;
	char name;
	map<char, int> adj; //the adj map contains the verticies that are adjacent to the current vertex
	bool known;
	int dist;
	char path;
	int indegree;
	int mapSize = 0;
	int tropDegree;
	vector<char> vertexPath;
};
#endif // !H_Vertex
#pragma once
