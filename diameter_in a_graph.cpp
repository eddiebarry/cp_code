
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
#define sqrt_dt long
# define INF 0x3f3f3f3f
using namespace std;

int sI(){
    long c = getchar_unlocked();
    bool flag = true;
    if(c=='-'){
        flag =false;
        c = getchar_unlocked();
    }
    long n = 0;
    for( ; (c<48 || c>57); c = getchar_unlocked() );
    for( ; (c>47 && c<58); c = getchar_unlocked() ){
        n = (n<<1) + (n<<3) +c -48;
    }
    if(flag){
        return n;
    }
    else{
        return n*-1;
    }
}



pair<long, long> pai = make_pair(0,0);


////////////////////////////graph
// C++ program to print connected components in
// an undirected grap

// Graph class represents a undirected graph
// using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    
    // Pointer to an array containing adjacency lists
    list<int> *adj;
    
    // A function used by DFS
    void DFSUtil(int v, bool visited[], long div);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);
    void connectedComponents();
};

// Method to print connected components in an
// undirected graph
void Graph::connectedComponents()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int v = 0; v < V; v++)
        visited[v] = false;
    bool *backward = new bool[V];
    for(int v = 0; v < V; v++)
        backward[v] = false;
    
    vector<long> ans;
    for(int i = 0; i < V; i++){
        if(visited[i]){
            continue;
        }
        long div = 0;
        DFSUtil(i, visited,div);
        int second = pai.second;
        
        DFSUtil(second, backward,div);
        ans.push_back(pai.first);
        
        pai = make_pair(0,0);
    }
    long max = -1;
    for(auto x: ans){
        if(x>max){
            max = x;
        }
    }
    cout<<max-1;
}

void Graph::DFSUtil(int v, bool visited[], long div)
{
    // Mark the current node as visited and print it
    visited[v] = true;
    div++;
    if(div > pai.first){
        pai = make_pair(div,v);
    }
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited,div);
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

// method to add an undirected edge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}





int main(){
    int n = sI(), k = sI();
    int arr[n];
    REP(i,n){
        arr[i]=sI();
    }
    int V = n+1;
    Graph g(V);
    REP(z,n-1){
        int i = sI(), j = sI();
        if(arr[i-1]%k==0 && arr[j-1]%k==0){
            g.addEdge(i,j);
        }
    }
    g.connectedComponents();
}

