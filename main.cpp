#include <iostream>

#include "weighted_graph.hpp"

using namespace std;

int main()
{
	WeightedGraph* wg = new WeightedGraph("a.txt");

	wg->GenerateLenList("C");

	wg->PrintLenList();

	string a; cin >> a;
}