#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef vector<vector<double> > Graph;
typedef vector<int> Vector;
typedef vector<pair<int, int> > Points;

const unsigned int SEED = 1234;
const double EPSILON = 1e-6;
const int MAX_ITER = 2500;
const int MAX_VALUE = 10000; // 2500;

double distance(const Graph &g, const Vector &v) {
	double acum = 0;
	for (int i = 1; i < v.size(); i++) {
		acum += g[v[i - 1]][v[i]];
	}
	return acum;
} 

Vector next(const Graph &g, const Vector &v) {
	Vector best(v), current(v);
	double bestDistance, dist;
	
	swap(best[0], best[1]);
	bestDistance = distance(g, best);
	
	for (int i = 0; i < v.size(); i++) {
		for (int j = (i + 1); j < v.size(); j++) {
			swap(current[i], current[j]);
			dist = distance(g, current);
			
			if (dist < bestDistance) {
				best = current;
				bestDistance = dist;
			}
			
			swap(current[j], current[i]);
		}
	}
	return best;
}


void displayCurrent(const Graph &g, const Vector &v) {
	cout << "\tPath = " << v[0];
	for (int i = 1; i < v.size(); i++) {
		cout << " " << v[i];
	}
	cout << "\n\tDistance = " << distance(g, v) << "\n\n";
}

Vector hillClimbing(const Graph &g) {
	Vector current(g.size()), neighbor(g.size());
	double currentDistance, neighborDistance, dEnergy;
	int iter;
	bool found;
	
	for (int i = 0; i < current.size(); i++) {
		current[i] = i;
	}
	currentDistance = distance(g, current);
	displayCurrent(g, current);
	
	neighbor = next(g, current);
	neighborDistance = distance(g, neighbor);
	displayCurrent(g, neighbor);
	
	//iter = 0; 
	//found = false;
	//while (iter < MAX_ITER) {
	while (neighborDistance < currentDistance) {
		current = neighbor;
		currentDistance = neighborDistance;
		
		neighbor = next(g, current);
		neighborDistance = distance(g, neighbor);
		displayCurrent(g, neighbor);
		
		//iter++;
	} 
	return Vector(current);
}

int main(int argc, char* argv[]) {
	int x, y, n;
	Points points;
	Graph g;
	double xs, ys;
	
	cin >> n;
	points.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		points[i].first = x;
		points[i].second = y;
	}
	
	g.resize(n);
	for (int i = 0; i < n; i++) {
		g[i].resize(n);
		for (int j = 0; j < n; j++) {
			if (i != j) {
				xs = points[i].first - points[j].first;
				ys = points[i].second - points[j].second;
				g[i][j] = sqrt( (xs * xs) + (ys * ys) );
			} else {
				g[i][j] = 0;
			}
		}
	}
	
	srand(SEED);
	Vector solution = hillClimbing(g);
	
	cout << "Path = " << solution[0];
	for (int i = 1; i < solution.size(); i++) {
		cout << " " << solution[i];
	}
	cout << "\nDistance = " << distance(g, solution) << "\n";
	
	return 0;
}
