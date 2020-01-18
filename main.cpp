#include <iostream>

#include "weighted_graph.hpp"

using namespace std;

int main()
{
	WeightedGraph* wg = new WeightedGraph("a.txt");

	wg->GenerateLenList("s");

	wg->PrintLenList();

	delete wg;

	string a; cin >> a;
}