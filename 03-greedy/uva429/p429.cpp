#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <queue>
#include <set>

using namespace std;

bool similar(string &a, string &b) {
	int acum;
	
	if (a.size() != b.size()) {
		return false;
	}
	
	acum = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) {
			acum++;
			if (acum >= 2) {
				return false;
			}
		}
	}
	return true;
}

int bfs(map<string, vector<string> > &graph, string &from, string &to) {
	string current;
	queue<string> pending;
	set<string> visited;
	set<string>::iterator itr;
	map<string, int> counting;
	
	counting[from] = 0;
	pending.push(from);
	while (!pending.empty()) {
		current = pending.front(); pending.pop();
		if (current == to) {
			return counting[current];
		}
		
		if (visited.find(current) == visited.end()) {
			visited.insert(current);
			for (int i = 0; i < graph[current].size(); i++) {
				pending.push(graph[current][i]);
				counting[graph[current][i]] = counting[current] + 1;
			}
		}
	}
	return -1;
}

int main(int argc, char* argv[]) {
	string word, line, from, to;
	vector<string> words;
	map<string, vector<string> > graph;
	
	while (1) {
		cin >> word;
		if (word == "*") {
			break;
		}
		words.push_back(word);
	}
	cin.ignore();
	
	for (int i = 0; i < words.size(); i++) {
		for (int j = i + 1; j < words.size(); j++) {
			if (similar(words[i], words[j])) {
				graph[words[i]].push_back(words[j]);
				graph[words[j]].push_back(words[i]);
			}
		}
	}
	
	while (getline(cin, line)) {
		stringstream ss(line);
		ss >> from >> to;
		if (from == "") continue;
		cout << from << " " << to << " " << bfs(graph, from, to) << "\n";
	}
	
	return 0;
}