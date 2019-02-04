#include"iostream"
#include"vector"
#include"algorithm"
using namespace std;

class Graph;
int degree(const Graph &G, int v);
int MaxDegree(const Graph &G);
double avgDegree(const Graph &G);
int numberOfSelfLoops(const Graph &G);

class Graph {
    friend int degree(const Graph &G, int v);
    friend int MaxDegree(const Graph &G);
    friend double avgDegree(const Graph &G);
    friend int numberOfSelfLoops(const Graph &G);
    private:
    vector<int> **V_set;
    int Vertex;
    int Edge;
    public:
    Graph(int V);
    ~Graph();
    int V();
    int E();
    void addEdge(int v, int w);
    istream& operator>>(istream&);
    //interable adj(int v);
    //string toString();33
};

Graph::Graph(int V) {
    V_set = new vector<int>* [V];
    for(int i =0; i < V; i++) {
        V_set[i] = new vector<int>();
    }
    Vertex = V;
    Edge = 0;
}

Graph::~Graph() {
    for(int i = 0; i < Vertex; i++) {
        delete V_set[i];
    }
    delete V_set;
}

int Graph::V() {
    return Vertex;
}

int Graph::E() {
    return Edge;
}

void Graph::addEdge(int v, int w) {
    V_set[v]->push_back(w);
    V_set[w]->push_back(v);
}

int degree(const Graph &G, int v) {
    return G.V_set[v]->size();
}

int MaxDegree(const Graph &G) {
    int Max = 0;
    for(int i =0; i < G.Vertex; i++) {
        if(G.V_set[i]->size() > Max) {
            Max = G.V_set[i]->size();
        }
    }
    return Max;
}

double avgDegree(const Graph &G) {
    double sum = 0;
    for(int i =0; i < G.Vertex; i++) {
            sum = G.V_set[i]->size();
    }
    return sum/G.Vertex;
}

int numberOfSelfLoops() {
//TODO
}