#include <iostream>
#define INF 99999

using namespace std;

struct edge
{
    int src, dest, weight;
};
void bellmanFord(int vertices, int edges, edge graph[], int source)
{
    int dist[vertices];
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INF;
    }

    dist[source] = 0;
    for (int i = 0; i < vertices - 1; i++)
    {
        for (int j = 0; j < edges; j++)
        {
            int u = graph[j].src;
            int v = graph[j].dest;
            int weight = graph[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }
    for (int j = 0; j < edges; j++)
    {
        int u = graph[j].src;
        int v = graph[j].dest;
        int weight = graph[j].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v])
        {
            cout << "Graph contains negative-weight cycle" << endl;
            return;
        }
    }
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < vertices; i++)
    {
        if (dist[i] == INF)
            cout << i << "\t\t" << "INF" << endl;
        else
            cout << i << "\t\t" << dist[i] << endl;
    }

}

int main()
{
    int vertices = 4;
    int edges = 5;
    edge graph[] = {
        {0, 1, 1},
        {0, 2, 4},
        {1, 2, -3},
        {1, 3, 2},
        {2, 3, 3}

    };
    int source = 0;
    bellmanFord(vertices, edges, graph, source);
    cout << "\nJaspreet Singh\nURN: 2203473\n";
    return 0;
}