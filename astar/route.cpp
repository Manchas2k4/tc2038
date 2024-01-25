#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <utility> 
#include <cmath>

const int MAX = 1000;

using namespace std;

typedef vector<vector<int> > Matrix;

const int options[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int OPTION_SIZE = 4;

class Arc {
public:
	int cost;
	int ren, col;

	Arc() : cost(0), ren(0), col(0) {}

	Arc(int ct, int r, int c) : cost(ct), ren(r), col(c) {}
};

class Compare {
public:
	bool operator() (const Arc& left, const Arc &right) const {
		return left.cost < right.cost;
	}
};

bool compare(const Arc &left, const Arc & right) {
	return left.cost < right.cost;
}

int heuristic(int ren, int col, int end_ren, int end_col) {
	return abs (ren - end_ren) 
		 + abs (col - end_col);
}

int isValid(int ren, int col, const Matrix &m) {
	return (ren >= 0 && ren < m.size() &&
			col >= 0 && col < m[ren].size());
}

int get_minimum_path(const Matrix &m, int start_ren, int start_col, int end_ren, int end_col) {
	priority_queue<Arc, vector<Arc>, Compare> pending;
	Arc current;
	Matrix visited;

	visited.resize(m.size(), vector<int>(m[0].size(), 0));
	
	pending.push(Arc(0, start_ren, start_col));
	while (!pending.empty()) {
		current = pending.top(); pending.pop();

		if (current.ren == end_ren && current.col == end_col) {
			return current.cost;
		}

		if (visited[current.ren][current.col] == 0) {
			visited[current.ren][current.col] = 1;

			for (int i = 0; i < OPTION_SIZE; i++) {
				int new_ren = current.ren + options[i][0];
				int new_col = current.col + options[i][1];
				if (isValid(new_ren, new_col, m) && m[new_ren][new_col] != -1) {
					int cost = current.cost +  m[new_ren][new_col] +
								heuristic(new_ren, new_col, end_ren, end_col);
					pending.push(Arc(cost, new_ren, new_col));
				}
			}
		}
	}
	return -1;
}

int main(int argc, char* argv[]) {
	Matrix m;
	int rows, cols, start_ren, start_col, end_ren, end_col;

	cin >> rows >> cols;
	cin >> start_ren >> start_col >> end_ren >> end_col;

	m.resize(rows, vector<int>(cols, 1));
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m[i].size(); j++) {
			cin >> m[i][j];	
		}
	}

	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m[i].size(); j++) {
			if (m[i][j] == -1) {
				cout << "#";
			} else if (i == start_ren && j == start_col) {
				cout << "S";
			} else if (i == end_ren && j == end_col) {
				cout << "F";
			} else {
				cout << m[i][j];
			}
			cout << " ";
		}
		cout << "\n";
	}

	cout << "Minimum path: " 
		<< get_minimum_path(m, start_ren, start_col, end_ren, end_col) << "\n";
	return 0;
}