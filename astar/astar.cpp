#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <map>
#include <utility>
#include <cmath>
#include <queue>
#include <set>

using namespace std;

const int MIN_INC = 10;
const int MAX_INC = 20;
const int MAX_N = 20;

typedef pair<int, int> Coordinate; // first => x, second => y

int n;
int matrix[MAX_N][MAX_N]; // matriz de adyacencia
map<int, Coordinate> vertexes; // llave = indice, par = (x, y)

class Cost {
public:
    double real, heuristics;
    int vertex;

    Cost(double r, double h, int v) : real(r), heuristics(h), vertex(v) {}
};

class Comparison {
public:
    bool operator() (const Cost &left, const Cost &right) const {
        if (left.real == right.real) {
            // se procesa el indice menor
            return left.heuristics > right.heuristics;
        } else {
            return left.real > right.real;
        }
    }
};

double euclideanDistance(int a, int b) {
    double xs = vertexes[a].first - vertexes[b].first;
    double ys = vertexes[a].second - vertexes[b].second;
    return sqrt( (xs * xs) + (ys * ys) );
}

void fillMatrix() {
    int increment;

    srand(1234);
    for (int i = 0; i < n; i++) {
        matrix[i][i] = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            increment = 0;
            matrix[i][j] = 0; 
        }
    }
}

double heuristics(int current, int end) {
   return (euclideanDistance(current, end) * 1.30);
}

double aStart(int start, int end) {
    priority_queue<Cost> q;
    set<int> visited; //se guardan los indices de los vértices
    set<int>::iterator itr;

    q.push(Cost(0, heuristics(start, end), start));
    while (!q.empty()) {
        Cost current = q.top(); q.pop();

        if (current.vertex == end) {
            return current.real;
        }

        itr = visited.find(current.vertex);
        if (itr == visited.end()) {
            visited.insert(current.vertex);
            for (int j = 0; j < n; j++) {
                if (current.vertex == j) {
                    continue;
                }
                q.push(Cost(current.real + matrix[current.vertex][j],
                            heuristics(j, end),
                            j));
            }
        }
    }
}

int main(int argc, char* argv[]) {
    int x, y;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        vertexes.insert(pair<int, Coordinate>(i, Coordinate(x, y)));
    }
}