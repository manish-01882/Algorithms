#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
        map<int, list<int>> adj;
        void addEdge(int v, int w);
        map<int, bool> visited;

        void bfs(int v);
};

void graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void graph::bfs(int v) {
    queue<int> q;  

    visited[v] = true;
    q.push(v);

    while(!q.empty()) {

        int current = q.front();
        cout << current << " ";
        q.pop();

        for(auto i : adj[current]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main(){
    graph g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(2,4);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.bfs(0);
}

