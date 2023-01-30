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

double distance(const Graph &g, const Vector &v) {
	double acum = 0;
	for (int i = 1; i < v.size(); i++) {
		acum += g[v[i - 1]][v[i]];
	}
	return acum;
} 

Vector next(const Vector& v) {
	Vector neighbor(v);
	
	random_shuffle(neighbor.begin(), neighbor.end());
	return neighbor;
}


void displayCurrent(const Graph &g, const Vector &v) {
	cout << "\tPath = " << v[0];
	for (int i = 1; i < v.size(); i++) {
		cout << " " << v[i];
	}
	cout << "\n\tDistance = " << distance(g, v) << "\n\n";
}

Vector simulatedAnnealing(const Graph &g, double startTemperature, double alpha) {
	Vector current(g.size()), neighbor;
	double currentTemperature, acceptProbability, prob;
	double currentDistance, neighborDistance, dEnergy;
	int iter;
	
	for (int i = 0; i < current.size(); i++) {
		current[i] = i;
	}
	currentDistance = distance(g, current);
	currentTemperature = startTemperature;
	displayCurrent(g, current);
	
	iter = 0;
	while (iter < MAX_ITER) {
		neighbor = next(current);
		neighborDistance = distance(g, neighbor);
		displayCurrent(g, neighbor);
		
		dEnergy = neighborDistance - currentDistance;
		if (dEnergy < 0) {
			current = neighbor;
			currentDistance = neighborDistance;
		} else {
			acceptProbability = exp(-dEnergy) / currentTemperature;
			prob = rand();
			if (prob < acceptProbability) {
				current = neighbor;
				currentDistance = neighborDistance;
			}
		}
		
		currentTemperature = (currentTemperature < EPSILON)? 
								currentTemperature : 
								(currentTemperature * alpha);
		
		iter++;
	}
	return Vector(current);
}

int main(int argc, char* argv[]) {
	int x, y, n;
	Points points;
	Graph g;
	double xs, ys;
	double startTemperature = 1000.0;
	double alpha = 0.98;
	
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
	Vector solution = simulatedAnnealing(g, startTemperature, alpha);
	
	cout << "Path = " << solution[0];
	for (int i = 1; i < solution.size(); i++) {
		cout << " " << solution[i];
	}
	cout << "\nDistance = " << distance(g, solution) << "\n";
	
	return 0;
}
