#include <iostream>
#include <string>
#include <vector>

class NodeTrie {
private:
  char letter;
  bool end;
  NodeTrie* parent;
  std::vector<NodeTrie*> childs;

public:
    NodeTrie(char, NodeTrie*);
    NodeTrie* getChild(char) const;
    bool isEnd() const;
    void addChild(NodeTrie*);
    void setAsEnd();
    void removeChilds();
};

NodeTrie::NodeTrie(char c, NodeTrie* p)
    : letter(c), parent(p), end(false) {
    for (int i = 0; i < childs.size(); i++) {
        childs[i] = NULL;
    }
}

NodeTrie* NodeTrie::getChild(char c) const {
    return childs[ (int) c - 'a' ];
}

bool NodeTrie::isEnd() const {
    return end;
}

void NodeTrie::addChild(NodeTrie* node) {
    childs[ (int) node->letter - 'a' ] = node;
}

void NodeTrie::setAsEnd() {
    end = true;
}

void NodeTrie::removeChilds() {
    for (int i = 0; i < childs.size(); i++) {
        if (childs[i] != NULL) {
            childs[i]->removeChilds();
            delete childs[i];
        }
    }
}

class Trie {
private:
    NodeTrie* root;

public:
    Trie();
    ~Trie();
    void insert(const std::string&);
    bool search(const std::string&);
};

Trie::Trie() {
    root = new NodeTrie('\0', NULL);
}

Trie::~Trie() {
    if (root != NULL) {
        root->removeChilds();
        delete root;
        root = NULL;
    }
}

void Trie::insert(const std::string& word) {
    NodeTrie *current, *child;
    char c;

    current = root;
    for (int i = 0; i < word.size(); i++) {
        c = word[i];
        child = current->getChild(c);
        if (child != NULL) {
            current = child;
        } else {
            current->addChild(new NodeTrie(c, current));
            current = current->getChild(c);
        }
        if (i == word.size() - 1) {
            current->setAsEnd();
        }
    }
}

bool Trie::search(const std::string& word) {
    NodeTrie *current, *child;
    char c;

    current = root;
    for (int i = 0; i < word.size(); i++) {
        c = word[i];
        child = current->getChild(c);
        if (child == NULL) {
            return false;
        }
    }
    return current->isEnd();
}

int main(int argc, char* argv[]) {
    return 0;
}
