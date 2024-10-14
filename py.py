# Returns shortest distance from 0 to N-1.
def shortestDist(graph):
    global INF 
    N = len(graph)
    
    # dist[i] is going to store shortest distance from node i to node N-1.
    dist = [0] * N
    dist[N - 1] = 0
    
    # Calculating shortest path for rest of the nodes
    for i in range(N - 2, -1, -1):
        # Initialize distance from i to destination (N-1)
        dist[i] = INF
        
        # Check all nodes of next stages to find shortest distance from i to N-1.
        for j in range(N):
            # Reject if no edge exists
            if graph[i][j] == INF:
                continue
            dist[i] = min(dist[i], graph[i][j] + dist[j])
    
    print("The shortest distance is:")
    return dist[0]

# Driver code
INF = 999999999999
graph = [
    [INF, 3, 6, INF, INF, INF, INF, INF],
    [INF, INF, INF, 2, 5, INF, INF, INF],
    [INF, INF, INF, INF, 2, 4, INF, INF],
    [INF, INF, INF, INF, INF, INF, 1, INF],
    [INF, INF, INF, INF, INF, INF, 2, 3],
    [INF, INF, INF, INF, INF, INF, INF, 1],
    [INF, INF, INF, INF, INF, INF, INF, 2]
]

print(shortestDist(graph))
