#include<iostream>
#include<vector>

#define INF __INT_MAX__
using namespace std;

int FGraph(vector<vector<int>> graph, int N){
    int dist[N];
    dist[N-1] = 0;

    for(int i = N-2; i>=0; --i){
        dist[i] = INF;
        for(int j=i; j<N; ++j){
            if(graph[i][j] == INF)
                continue;
            dist[i] = min(dist[i], graph[i][j] + dist[j]);
    }
    }
    return dist[0];
}

int main(){
     vector<vector<int>> graph =
        // {{INF, 9, 7, 3, 2, INF, INF, INF, INF, INF, INF, INF},
        //  {INF, INF, INF, INF, INF, 4, 2, 1, INF, INF, INF, INF},
        //  {INF, INF, INF, INF, INF, 2, 7, INF, INF, INF, INF, INF},
        //  {INF, INF, INF, INF, INF, INF, INF, 11, INF, INF, INF, INF},
        //  {INF, INF, INF, INF, INF, INF, 11, 8, INF, INF, INF, INF},
        //  {INF, INF, INF, INF, INF, INF, INF, INF, 6, 5, INF, INF},
        //  {INF, INF, INF, INF, INF, INF, INF, INF, 4, 3, INF, INF},
        //  {INF, INF, INF, INF, INF, INF, INF, INF, INF, 5, 6, INF},
        //  {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 4},
        //  {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 2},
        //  {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 5},
        //  {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0}};

             {{INF, 1, 2, 5, INF, INF, INF, INF},
            {INF, INF, INF, INF, 4, 11, INF, INF},
            {INF, INF, INF, INF, 9, 5, 16, INF},
            {INF, INF, INF, INF, INF, INF, 2, INF},
            {INF, INF, INF, INF, INF, INF, INF, 18},
            {INF, INF, INF, INF, INF, INF, INF, 13},
            {INF, INF, INF, INF, INF, INF, INF, 2}};

        int N = graph.size() + 1;

    cout << FGraph(graph,N)<<endl;

}
