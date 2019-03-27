#include<iostream> 
#include <list> 
#include <vector>
using namespace std; 
  
// Graph class represents a undirected graph 
// using adjacency list representation 
class Graph 
{ 
    int V;    // No. of vertices 
  
    // Pointer to an array containing adjacency lists 
    list<int> *adj; 
  
    // A function used by DFS 
    void DFSUtil(int v, bool visited[], vector<int> &va, int num); 
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
  
    std::vector<int> va;
    for (int v=0; v<V; v++) 
    { 
        if (visited[v] == false) 
        { 
            // print all reachable vertices 
            // from v 
            DFSUtil(v, visited,va,0); 
  
            // cout << "\n"; 
        } 
    } 
    cout<<va.size()<<"\n";
    for(auto x : va){
        cout<<x+1<<" ";
    }
    cout<<"\n";
} 
  
void Graph::DFSUtil(int v, bool visited[], vector<int> &va, int num) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
    if(num == 0){
        va.push_back(v);    
    }
  
    // Recur for all the vertices 
    // adjacent to this vertex 
    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFSUtil(*i, visited,va, num+1); 
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

int SI(){
    int x;
    cin>>x;
    return x;
}

// Drive program to test above 
int main() 
{ 
    // Create a graph given in the above diagram 
    int t = SI();
    while(t--){
        int n = SI(), m = SI();
        Graph g(n); // 5 vertices numbered from 0 to 4 
        while(m--){
            int x = SI(), y = SI();
            g.addEdge(x-1,y-1);
        }
        g.connectedComponents();
    }
   
  
    return 0; 
} 