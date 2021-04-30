#ifndef GRAPH_H
#define GRAPH_H

#include <string.h>
#include <vector>
#include <iostream>
#include "myException.h"

template<class T>
class Graph {
private:
    int n;
    int e;
    std::vector<std::vector<T>> graph;
    int* fa;
    int* rank;
    int find(int x);
    bool merge(int x, int y);

public:
    explicit Graph(int Vertices);
    bool Exist(int i, int j);
    int Edges() {return e;}
    int Vertices() {return n;}
    void AddEdge(int i, int j, int w);
    void DelEdge(int i, int j);
    int Degree(int i);
    void Prim(int V);
    void Kruskal();
};


template<class T>
Graph<T>::Graph(int Vertices)
{// Constructor.
    n = Vertices;
    e = 0;
    graph = std::vector<std::vector<T>>();
    graph.resize(n + 1);
    for(int i = 0; i < graph.size(); i++)
        graph[i].resize(n + 1);
    for(int i = 0; i < graph.size(); i++)
        for(int j = 0; j < graph[i].size(); j++)
            graph[i][j] = 0;
    fa = new int[n + 1];
    rank = new int[n + 1];
    memset(fa, 0, sizeof(fa));
    memset(rank, 0, sizeof(rank));

}

template<class T>
bool Graph<T>::Exist(int i, int j)
{// Does edge (i, j) exist?
    if (i < 1 || j < 1 || i > n || j > n
        || graph[i][j] == 0) return false;
    return true;
}

template<class T>
void Graph<T>::AddEdge(int i, int j, int w)
{// Add edge (i,j) to graph if not present.
    if (i < 1 || j < 1 || i > n || j > n || i == j || graph[i][j] != 0)
        throw myException("Edge existed");
    graph[i][j] = graph[j][i] = w;
    e++;
}

template<class T>
void Graph<T>::DelEdge(int i, int j)
{// Delete edge (i,j).
    if (i < 1 || j < 1 || i > n || j > n || graph[i][j] == 0)
        throw myException("Invalid parameter");
    graph[i][j] = graph[j][i] = 0;
    e--;
}

template<class T>
int Graph<T>::Degree(int i)
{// Return out degree of vertex i.
    if (i < 1 || i > n) throw myException("Invalid parameter");
    // count out edges from vertex i
    int sum = 0;
    for (int j = 1; j <= n; j++)
        if (graph[i][j] != 0)
            sum++;
    return sum;
}

bool isValidEdge(int u, int v, vector<bool> inMST)
{
    if(u == v)
        return false;
    if(!inMST[u] && !inMST[v])
        return false;
    else if(inMST[u] && inMST[v])
        return false;
    return true;
}

template<class T>
void Graph<T>::Prim(int V) {
    std::cout<< "Starting prim with initial vertex #" << V << endl;
    vector<bool> inMST(n + 1, false);
    inMST[V] = true;

    int edgeCount = 0, minCost = 0;
    while(edgeCount < n - 1)
    {
        int min = 1e9, a = 0, b = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(graph[i][j] > 0 && graph[i][j] < min) {
                    if(isValidEdge(i, j, inMST))
                    {
                        min = graph[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if(a != 0 && b != 0)
        {
            cout << "Added edge from #" << a << " to #" << b << " with the cost of " << min << endl;
            minCost += min;
            inMST[a] = inMST[b] = true;
            edgeCount++;
        }
    }
    cout << "Weight of MST: " << minCost << endl << endl;
}

template<class T>
void Graph<T>::Kruskal()
{
    cout << "Starting kruskal()..." << endl;

    int minCost = 0;
    int edgeCount = 0;

    for(int i = 1; i <= n; i++)
        fa[i] = i, rank[i] = 1;

    while(edgeCount < n - 1)
    {
        int min = 1e9, a = 0, b = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(find(i) != find(j) && graph[i][j] > 0 && graph[i][j] < min)
                    min = graph[i][j], a = i, b = j;

        if(merge(a, b))
        {
            cout << "Added edge from #" << a << " to #" << b << " with the cost of " << min << endl;
            edgeCount++;
            minCost += min;
        }
    }
    cout << "Weight of MST: " << minCost << endl << endl;
}

template<class T>
int Graph<T>::find(int x) {
    if(fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

template<class T>
bool Graph<T>::merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx == fy)
        return false;
    else
    {
        if(rank[fx] <= rank[fy])
            fa[fx] = fy;
        else
            fa[fy] = fx;
        if(rank[fx] == rank[fy])
            rank[fy]++;
        return true;
    }
}




#endif // GRAPH_H
