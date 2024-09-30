import math
inf=math.inf
src=0 weight=[
[inf, 4, inf, inf, inf, inf, inf, 8, inf],
[4, inf, 8, inf, inf, inf, inf, 11, inf],
[inf, 8, inf, 7, inf, 4, inf, inf, 2],
[inf, inf, 7, inf, 9, 14, inf, inf, inf],
[inf, inf, inf, 9, inf, 10, inf, inf, inf],
[inf, inf, 4, 14, 10, inf, 2, inf, inf],
[inf, inf, inf, inf, inf, 2, inf, 1,6],
[8, 11, inf, inf, inf, inf, 1, inf,7],
[inf, inf, 2, inf, inf, inf, 6, 7, inf]
]
visited=[False for i in range(9)]
distance=[inf for i in range(9)]
nbr=[-1 for i in range(9)]
visited[src]=True
for j in range(9):
    nbr[j]=0
    distance[j]=weight[0][j]
edges=[]
for i in range(1,9):
    min=inf
    for j in range(9):
        if visited[j]==False and distance[j]< min:
            index=j
            min=distance[j]

edges.append([nbr[index],index])
visited[index]=True
for k in range(9):
    if visited[k]==False and distance[k]> weight[index][k]:
        distance[k]=weight[index][k]
        nbr[k]=index

print("Path selected for phone lines [city1 -> city2] \t\t Cost")
for i in range(8):
    print(edges[i],end="\t\t\t\t\t\t\t ")
    print(distance[i+1])

print("Minimun cost of connecting all cities through phone line is : ",
(sum(distance[1:])))