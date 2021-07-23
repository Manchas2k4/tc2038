#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

const int N = 4;

int C[N][N] = { {5, 9, 10, 3},
                {2, 6, 12, 1},
                {7, 4, 4, 8},
                {11, 16, 2, 14}};

typedef struct {
  int level, limit;
  int assignment[N];
  bool assigned[N];
} Node;

int currentBest = INT_MAX;
Node* currentSolution = NULL;

struct Compare {
  bool operator() (const Node *left, const Node *right) const {
    return left->limit > right->limit;
  }
};

int calculateCost(int *assignment) {
  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += C[i][assignment[i]];
  }
  return sum;
}

Node* createNewNode(int level, int *assignment, bool *assigned, int wid) {
  Node *node = new Node;
  node->level = level;
  memcpy(node->assignment, assignment, sizeof(int) * N);
  memcpy(node->assigned, assigned, sizeof(bool) * N);
  if (node->level != 0) {
    node->assigned[wid] = true;
    node->assignment[node->level - 1] = wid;
  }
  node->limit = calculateCost(node->assignment);
  return node;
}

void printNode(Node *node, bool tab = false) {
  std::string text = (tab)? "\t" : "";
  if (node != NULL) {
    std::cout << text << "Limit = " << node->limit << "\n";
    std::cout << text << "Level = " << node->level << "\n";
    for (int i = 0; i < N; i++) {
      if (node->assigned[i]) {
        std::cout << text << "Worker: " << (i + 1)
                  << " Assigned work: " << (node->assignment[i] + 1) << "\n";
      }
    }
  }
}

void printSolution() {
  if (currentSolution != NULL) {
    std::cout << "Minimum cost = " << currentBest << "\n";
    for (int i = 0; i < N; i++) {
      std::cout << "Worker: " << (i + 1) << " Assigned work: "
                << (currentSolution->assignment[i] + 1) << "\n";
    }
  } else {
    std::cout << "There no is solution\n";
  }
}

void assigmentAlgorithm() {
  std::priority_queue<Node*, std::vector<Node*>, Compare> frontier;
  int assignment[N];
  bool assigned[N];
  int minimum, work;
  Node *node, *child;

  for (int i = 0; i < N; i++) {
    assigned[i] = false;
    minimum = C[i][0];
    work = 0;
    for (int j = 1; j < N; j++) {
      if (C[i][j] < minimum) {
        minimum = C[i][j];
        work = j;
      }
    }
    assignment[i] = work;
  }

  node = createNewNode(0, assignment, assigned, -1);
  //printNode(node);
  frontier.push(node);

  while(!frontier.empty()) {
    node = frontier.top(); frontier.pop();
    //printNode(node);
    if (node->limit < currentBest) {
      if (node->level < N) {
        for (int i = 0; i < N; i++) {
          if (!node->assigned[i]) {
            child = createNewNode(node->level + 1, node->assignment,
                                  node->assigned, i);
            //printNode(child, true);
            frontier.push(child);
          }
        }
      } else {
        currentBest = node->limit;
        currentSolution = node;
      }
    }
  }
}

int main(int argc, char* argv[]) {
  assigmentAlgorithm();
  printSolution();
  return 0;
}
