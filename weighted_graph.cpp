#include "weighted_graph.hpp"

WeightedGraph::WeightedGraph(GraphMap graphMap)
{
	this->graphMap = graphMap;
}

WeightedGraph::WeightedGraph(const char* fileName)
{
	ifstream importFile;
	importFile.open(fileName, ios::in);

	string from, to; size_t len;
	while (importFile >> from >> to >> len)
	{
		cout << "Succesful:: " << from << ": " << to << ": " << len << endl;
		AddNode(from, to, len);
	}
}

void WeightedGraph::AddNode(string from, string to, size_t len)
{
	tNode* fromNode = nullptr, * toNode = nullptr;

	for (auto &&i : graphMap)
	{
		if (i->name.compare(from) == 0)
			fromNode = i;
		else if (i->name.compare(to) == 0)
			toNode = i;
		if (fromNode != nullptr && toNode != nullptr)
			break;
	}
	
	if (fromNode == nullptr)
	{
		fromNode = new tNode(from);
		graphMap.push_back(fromNode);
	}

	if (toNode == nullptr)
	{
		toNode = new tNode(to);
		graphMap.push_back(toNode);
	}

	fromNode->edges.push_back(new tEdge(toNode, len));
	toNode->edges.push_back(new tEdge(fromNode, len));
}

WeightedGraph::~WeightedGraph()
{
}

bool WeightedGraph::GenerateLenList(string nodeName)
{
	// give max value to graph (except target)
	for (auto &&i : graphMap)
		if (i->name.compare(nodeName) == 0)
			i->len = 0;

	RefreshMap();
}

void WeightedGraph::RefreshMap()
{
	while(true)
	{
		// find the min length node
		tNode* minNode = nullptr;
		for (auto &&i : graphMap)
		{
			if (i->is_okey != false)
				continue;

			if (minNode == nullptr)
				minNode = i;
			else
				if (i->len < minNode->len)
					minNode = i;
		}

		// control if target has no edge
		if (minNode == nullptr)
			break;

		// set all edge's len
		for (auto &&i : minNode->edges)
			if (minNode->len + i->len < i->node->len)
				i->node->len = minNode->len + i->len;

		minNode->is_okey = true;
	}
}

void WeightedGraph::PrintLenList()
{
	for (auto &&i : graphMap)
	{
		cout << i->name <<  ": " << i->len << endl;
	}
	
}
