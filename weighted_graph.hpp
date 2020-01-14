#ifndef _WEIGHTED_GRAPH_H_
#define _WEIGHTED_GRAPH_H_

#include <bits/stdc++.h>
#include <limits.h>
#include <stdbool.h>

using namespace std;

typedef struct sNode
{
	string name;
	vector<struct sEdge*> edges;
	size_t len;
	bool is_okey;

	sNode(string _name):
	name(_name),
	len(UINT32_MAX),
	is_okey(false)
	{}
} tNode;

typedef struct sEdge
{
	tNode* node;
	size_t len;

	sEdge(tNode* _node, size_t _len):
	node(_node),
	len(_len)
	{}
} tEdge;

typedef list<tNode*> GraphMap;

class WeightedGraph
{
protected:
	GraphMap graphMap;
public:
	WeightedGraph(GraphMap graphMap);
	WeightedGraph(const char* fileName);
	~WeightedGraph();
private:
	void AddNode(string from, string to, size_t len);
	void RefreshMap();
public:
	bool GenerateLenList(string nodeName);
	void PrintLenList();
};

#endif