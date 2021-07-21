// =================================================================
//
// File: coin_change.cpp
// Author: Pedro Perez
// Description: The program implements the BFS algorithm on graphs.
//							The program receives input in number of vertices in
//							the graph (n). The next n lines indicate the connections
//							each vertex. In each line, the number of connections is
//							received m; followed by the vertices to which it
//							connects. Finally, the starting vertex is received.
//							This code uses the greedy technique.
//
// Copyright (c) 2021 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#include <cstdio>
#include <map>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

typedef map<int, list<int> > Graph;

list<int> dfs(const Graph &g, char startVertex) {
	list<int> visited;
	stack<int> xVisit;

	xVisit.push(startVertex);
	while (!xVisit.empty()) {
		int vertex = xVisit.top(); xVisit.pop();

		list<int>::iterator found = find(visited.begin(), visited.end(), vertex);
		if (found == visited.end()) {
			visited.push_back(vertex);
			list<int> conections = g.at(vertex);
			for (list<int>::iterator it = conections.begin(); it != conections.end(); it++) {
				xVisit.push( *it );
			}
		}
	}
	return visited;
}

int main(int argc, char* argv[]) {
	int i, j, k, n, m, start;
	Graph g;
	list<int> reachable;

	scanf("%i", &n);
	for (i = 1; i <= n; i++) {
		scanf("%i", &m);
		g[i] = list<int>();
		for (j = 1; j <= m; j++) {
			scanf("%i", &k);
			g[i].push_back(k);
		}
	}
	scanf("%i", &start);

	reachable = dfs(g, start);
	for (list<int>::iterator it = reachable.begin(); it != reachable.end(); it++) {
		printf("%i ", (*it));
	}
	printf("\n");
	return 0;
}
