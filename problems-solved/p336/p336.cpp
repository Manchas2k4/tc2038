#include <iostream>
#include <iomanip>
#include <queue>
#include <utility>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

const int MAX = 32;
const int INFINITY = 100;

//first => costo acumulado
//second => nodo
typedef pair<int, int>  Pair;

class Comparison {
public:
    bool operator() (const Pair &left, const Pair &right) const {
        if (left.first == right.first) {
            return left.second > right.second;
        } else {
            return left.first > right.first;
        }
    }
};

map<int, list<int> > graph;
map<int, list<int> >::iterator it;

int djisktra(int start, int ttl) {
    priority_queue<Pair, vector<Pair>, Comparison> queue;
    list<int>::iterator it2;
    set<int> visited;
    set<int>::iterator it1;
    Pair current;

    queue.push( Pair(0, start) );
    while (!queue.empty()) {
        current = queue.top(); queue.pop();
        
        if (current.first > ttl) {
            break;
        }

        it1 = visited.find(current.second);
        if (it1 == visited.end()) {
            visited.insert(current.second);
            for (it2 = graph[current.second].begin(); it2 != graph[current.second].end(); it2++) {
                queue.push( Pair(current.first + 1, *it2) );
            }
        }
    }
    return visited.size();
}

int main(int argc, char* argv[]) {
    int nc, start, end, cases, ttl, total, result;
    
    cases = 0;
    while(1) {
        cin >> nc;

        if (nc == 0) {
            break;
        }

        graph.clear();
        total = 0;
        for (int i = 0; i < nc; i++) {
            cin >> start >> end;
            
            it = graph.find(start);
            if (it == graph.end()) {
                graph.insert( pair<int, list<int> >(start, list<int>()) );
                total++;
            }
            graph[start].push_back(end);

            it = graph.find(end);
            if (it == graph.end()) {
                graph.insert( pair<int, list<int> >(end, list<int>()) );
                total++;
            }
            graph[end].push_back(start);
        }

        while(1) {
            cin >> start >> ttl;
            if (start == 0 && ttl == 0) {
                break;
            }

            result = 0;
            it = graph.find(start);
            if (it != graph.end()) {
                result = djisktra(start, ttl);
            }
            
            cases++;
            cout << "Case " << cases << ": " << (total - result)
                    << " nodes not reachable from node " << start << " with TTL = "
                    << ttl << ".\n";
        }
    }
    return 0;
}