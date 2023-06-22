#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Node {
    char id='-';
    set<Node*> subnodes;
};

Node* findNode(char id, vector<Node*> nodes) {
    for (auto *n : nodes)
        if (n->id == id)
            return n;
    return nullptr;
}

int main () {

    ifstream in("dane/keylog.txt");

    string data;
    vector<Node*> nodes;

    for (char i = '0'; i <= '9'; ++i) {
        Node *newNode = new Node;
        newNode->id = i;

        nodes.push_back(newNode);
    }

    while (in >> data) {
        for (int i = 0; i < data.size(); ++i) {
            Node *mainNode = findNode(data[i], nodes);

            for (int j = i + 1; j < data.size(); ++j) {
                Node *subNode = findNode(data[j], nodes);
                mainNode->subnodes.insert(subNode);
            }
        }
    }

    string pass = "";

    for (int i = nodes.size(); i >= 0; --i) {
        for (auto *n : nodes)
            if (n->subnodes.size() == i) {
                pass += n->id;
                break;
            }
    }

    cout << pass;

    in.close();

    return 0;
}