#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int shortestPath(int n, string& start, string& finish) {
  unordered_map<string, bool> visited;
  unordered_map<string, int> dist;
  unordered_map<string, string> src;
  queue<string> q;

  visited[start] = visited[finish] = true;
  dist[start] = dist[finish] = 0;
  src[start] = start;
  src[finish] = finish;

  q.push(start);
  q.push(finish);

  while(!q.empty()) {
    string u = q.front(); q.pop();
    for (int i = 1; i < n; i++) {
      string v = u;
      swap(v[i], v[i - 1]);

      if (!visited[v]) {
        visited[v] = true;
        src[v] = src[u];
        dist[v] = dist[u] + 1;
        q.push(v);
      } else if (src[u] != src[v]) {
        return dist[u] + dist[v] + 1;
      }
    }
  }
  return -1;
}

int main(int argc, char* argv[]) {
  string p1 = "1234567890";
  string p2 = "0987123456";

  cout << "Shortest path length = " << shortestPath(p1.length(), p1, p2) << "\n";
  return 0;
}
