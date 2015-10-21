#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <deque>

using namespace std;
struct Node {
    public:
    Node() {
            neighbors = new unordered_set<Node*>();
    }

    unordered_set<Node*> *neighbors;
};

class Graph {
    unordered_set<Node*> *nodes;
public:
    Graph() {
        nodes = new unordered_set<Node*>();
    }

    void addEdge(Node* a, Node* b) {
            a->neighbors->insert(b);
            b->neighbors->insert(a);
            nodes->insert(a);
            nodes->insert(b);
    }
  
  //BFS, using queue to mark the nodes with alternative color, 0, 1
  //If a node's neighbor has already been colored with same as currnent node's, return false;
  //else color the neightbor and put it into queue
    bool isBipartite() {
        if(nodes->empty()) return false;
        
        unordered_map<Node*, int> color;
        for(unordered_set<Node*>::iterator it=nodes->begin(); it != nodes->end(); it++)
            color[*it] = -1;
            
        deque<Node*> q;
        Node* src = *(nodes->begin());
        color[src] = 1;
        q.push_back(src);
        
        while(!q.empty()) {
            Node *n = q.front(); q.pop_front();
            int curColor = color[n];
            
            for(unordered_set<Node*>::iterator it=n->neighbors->begin(); 
                it != n->neighbors->end(); it++) {
                    Node *nb = *it;
                if(color[nb] == curColor) return false;
                if(color[nb] == -1) {
                    color[nb] = 1 - curColor;
                    q.push_back(nb);
                }
            }
        }
        
        //return false if it is not a connected graph
         for(unordered_map<Node*,int>::iterator it = color.begin(); 
            it!=color.end(); it++) {
                if(it->second == -1) return false;
            }
        return true;
    }
};

int main() {
        Node* a = new Node();
        Node* b = new Node();
        Node* c = new Node();
        Node* d = new Node();

        Graph* g = new Graph();

        g->addEdge(a, b);
        g->addEdge(b, c);
        g->addEdge(c, d);
        g->addEdge(b, d);

        cout <<"is bipartite: " << g->isBipartite();
}
