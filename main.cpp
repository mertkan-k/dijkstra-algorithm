#include <iostream>

#include "weighted_graph.hpp"

using namespace std;

int main()
{
	WeightedGraph* wg = new WeightedGraph("a.txt");

	wg->GenerateLenList("A");

	wg->PrintLenList();

	wg->ClearGraph();

	string a; cin >> a;
}