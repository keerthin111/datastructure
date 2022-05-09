# datastructure
//tower Hanoi program

#include<iostream>
using namespace std;
void TOH(int d, char t1, char t2, char t3)
{
if(d==1)
{
cout<<"\nShift top disk from tower"<<t1<<" to tower"<<t2;
return;
}
TOH(d-1,t1,t3,t2);
cout<<"\nShift top disk from tower"<<t1<<" to tower"<<t2;
TOH(d-1,t3,t2,t1);
}
int main()
{
int disk;
cout<<"Enter the number of disks:"; cin>>disk;
if(disk<1)
cout<<"There are no disks to shift";
else
cout<<"There are "<<disk<<"disks in tower 1\n";
TOH(disk, '1','2','3');
cout<<"\n\n"<<disk<<"disks in tower 1 are shifted to tower 2";
return 0;
}
Output:
   /tmp/k3mB8nwaFv.o
Enter the number of disks:3There are 3disks in tower 1

Shift top disk from tower1 to tower2
Shift top disk from tower1 to tower3
Shift top disk from tower2 to tower3
Shift top disk from tower1 to tower2
Shift top disk from tower3 to tower1
Shift top disk from tower3 to tower2
Shift top disk from tower1 to tower2

3disks in tower 1 are shifted to tower 2                  
                     

// Write a C++ program to find  MST Using  Kruskal’s algorithm.
                     
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;
struct Graph
{
int V, E;
vector< pair<int, iPair> > edges;
Graph(int V, int E)
{
this->V = V;
this->E = E;
}
void addEdge(int u, int v, int w)
{
edges.push_back({w, {u, v}});
}
int kruskalMST();
};

struct DisjointSets
{
int *parent, *rnk;
int n;
DisjointSets(int n)
{
this->n = n;
parent = new int[n+1];
rnk = new int[n+1];
for (int i = 0; i <= n; i++)
{
rnk[i] = 0;
parent[i] = i;
}
}
int find(int u)
{
if (u != parent[u])
parent[u] = find(parent[u]);
return parent[u];
}
void merge(int x, int y)
{
x = find(x), y = find(y);
if (rnk[x] > rnk[y])
parent[y] = x;
else // If rnk[x] <= rnk[y]
parent[x] = y;
if (rnk[x] == rnk[y])
rnk[y]++;
}
};
int Graph::kruskalMST()
{
int mst_wt = 0; 
sort(edges.begin(), edges.end());
DisjointSets ds(V);
vector< pair<int, iPair> >::iterator it;
for (it=edges.begin(); it!=edges.end(); it++)
{
int u = it->second.first;
int v = it->second.second;
int set_u = ds.find(u);
int set_v = ds.find(v);
if (set_u != set_v)
{
cout << u << " - " << v << endl;
mst_wt += it->first;
ds.merge(set_u, set_v);
}
}
return mst_wt;
}
int main()
{
int V = 9, E = 14;
Graph g(V, E);
g.addEdge(0, 1, 4);
g.addEdge(0, 7, 8);
g.addEdge(1, 2, 8);
g.addEdge(1, 7, 11);
g.addEdge(2, 3, 7);
g.addEdge(2, 8, 2);
g.addEdge(2, 5, 4);
g.addEdge(3, 4, 9);
g.addEdge(3, 5, 14);
g.addEdge(4, 5, 10);
g.addEdge(5, 6, 2);
g.addEdge(6, 7, 1);
g.addEdge(6, 8, 6);
g.addEdge(7, 8, 7);
cout << "Edges of MST are \n";
int mst_wt = g.kruskalMST();
cout << "\nWeight of MST is " << mst_wt;
return 0;
} 
   
output:
   Edges of MST are 
6 - 7
2 - 8
5 - 6
0 - 1
2 - 5
2 - 3
0 - 7
3 - 4

Weight of MST is 37
   
   
//Write a C++ program to find   MST using Prim’s algorithm..
   
   #include <bits/stdc++.h>
using namespace std;
#define V 5
int minKey(int key[], bool mstSet[])
{
int min = INT_MAX, min_index;
for (int v = 0; v < V; v++)
if (mstSet[v] == false && key[v] < min)
min = key[v], min_index = v;
return min_index;
}
void printMST(int parent[], int graph[V][V])
{
cout<<"Edge \tWeight\n";
for (int i = 1; i < V; i++)
cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}

void primMST(int graph[V][V])
{
int parent[V];
int key[V];
bool mstSet[V];
for (int i = 0; i < V; i++)
key[i] = INT_MAX, mstSet[i] = false;
key[0] = 0;
parent[0] = -1; // First node is always root of MST
for (int count = 0; count < V - 1; count++)
{
int u = minKey(key, mstSet);
mstSet[u] = true;
for (int v = 0; v < V; v++)
if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
parent[v] = u, key[v] = graph[u][v];
}
printMST(parent, graph);
}
int main()
{
int graph[V][V] = { { 0, 2, 0, 6, 0 },
{ 2, 0, 3, 8, 5 },
{ 0, 3, 0, 0, 7 },
{ 6, 8, 0, 0, 9 },
{ 0, 5, 7, 9, 0 } };
primMST(graph);
return 0;
}
output:
       Edge 	Weight
0 - 1 	2 
1 - 2 	3 
0 - 3 	6 
1 - 4 	5                                                        
                                                              
                                                              
