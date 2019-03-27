#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<climits>
#include<list>
#include<unordered_set>
#include<unordered_map>
#define NIL -1
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define pp pair< int , pair< int,int > >
using namespace std;
int sI(){
    int c = getchar_unlocked();
    bool flag = true;
    if(c=='-'){
        flag =false;
        c = getchar_unlocked();
    }
    int n = 0;
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




class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
    void bridgeUtil(int v, bool visited[], int disc[], int low[],
                    int parent[],unordered_set< int > &n_cy);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    void bridge(unordered_set< int > &n_cy);    // prints all bridges
    void dfs(int current, int num_wrong_edges, unordered_set<int>&n_cy, unordered_map<int, int> &map_idx,unordered_set<int>&visited, list<int>&path,vector<int> &ans);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}

void Graph::bridgeUtil(int u, bool visited[], int disc[],
                       int low[], int parent[],unordered_set< int > &n_cy)
{
    static int time = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of u
        if (!visited[v])
        {
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent, n_cy);
            low[u]  = min(low[u], low[v]);
            if (low[v] > disc[u]){
//                cout << u <<" is a bridge edge  lalalala" << v << endl;
                n_cy.insert(u*1e6 + v);
                n_cy.insert(v*1e6 + u);
            }
            
        }
        
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}

void Graph::bridge(unordered_set< int > &n_cy)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    
    // Initialize parent and visited arrays
    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
    }
    
    // Call the recursive helper function to find Bridges
    // in DFS tree rooted with vertex 'i'
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent,n_cy);
}


void Graph::dfs(int current, int num_wrong_edges, unordered_set<int>&n_cy, unordered_map<int, int> &map_idx,unordered_set<int>&visited, list<int>&path, vector<int> &ans){

    visited.insert(current);
    path.push_back(current);
//    cout<<"current is "<<current+1<<"\n";
    
    for(auto x:adj[current]){
//        if(done.find(start*1e6+x)!=done.end()){
//            continue;
//        }
        if(visited.find(x)==visited.end()){
            if(n_cy.find(x*1e6+current)==n_cy.end()){
                //edge present in cycle
                if(num_wrong_edges==0){
                    //increment edge
//                    int idx = map_idx[x*1e6+current];
//                    ans[idx]++;
//                    cout<<" num wrong edges is "<<num_wrong_edges<<" the edge in question is "<<x+1<<"\n";
                    //mark as visited
                    visited.insert(x);
                    path.push_back(x);
//                    //update ans
//                    for(auto x:path){
//                        cout<<x+1<<" ";
//                    }
//                    cout<<"thi si s the oath\n";
                    
                    
                    int i = 0;
                    int node_1,node_2;
                    for(auto z: path){
                        if(i%2==0){
                            node_1=z;
                        }
                        if(i%2==1){
                            node_2=z;
                            int idx = map_idx[node_1*1e6+node_2];
                            ans[idx]++;
                        }
//                        cout<<z<<" ";
                        i++;
                    }
//                    cout<<"this is the path \n\n";
                    
                    
                    //perform dfs
                    dfs(x,1,n_cy,map_idx,visited,path,ans);
//                    done.insert(start*1e6+x);
//                    done.insert(x*1e6+start);
                    path.pop_back();
                    visited.erase(x);
                }
            }
            else{
                //bridge edge
                
//                int idx = map_idx[x*1e6+current];
//                ans[idx]++;
//                cout<<" num wrong edges is "<<num_wrong_edges<<" the edge in question is "<<x+1<<"\n";
//                //mark as visited
//                visited.insert(x);
//                //perform dfs
//                dfs(start,x,target,0,map_idx,n_cy,visited,ans,done,path);
//                done.insert(start*1e6+x);
//                done.insert(x*1e6+start);
                
                visited.insert(x);
                path.push_back(x);
                int i = 0;
                int node_1,node_2;
                for(auto z: path){
                    if(i%2==0){
                        node_1=z;
                    }
                    if(i%2==1){
                        node_2=z;
                        int idx = map_idx[node_1*1e6+node_2];
                        ans[idx]++;
                    }
//                    cout<<z<<" ";
                    i++;
                }
////                cout<<"this is the path \n\n";
//                for(auto x:path){
//                    cout<<x+1<<" ";
//                }
////                cout<<"thi si s the oath\n";
                
                dfs(x,num_wrong_edges,n_cy,map_idx,visited,path,ans);
                //                    done.insert(start*1e6+x);
                //                    done.insert(x*1e6+start);
                path.pop_back();
                visited.erase(x);
            }
        }
    }
//    cout<<"\n\n";
    path.pop_back();
}






//// Driver program to test above function
//int main()
//{
//    // Create graphs given in above diagrams
//    cout << "\nBridges in first graph \n";
//    Graph g1(5);
//    g1.addEdge(1, 0);
//    g1.addEdge(0, 2);
//    g1.addEdge(2, 1);
//    g1.addEdge(0, 3);
//    g1.addEdge(3, 4);
//    g1.bridge();
//
//    cout << "\nBridges in second graph \n";
//    Graph g2(4);
//    g2.addEdge(0, 1);
//    g2.addEdge(1, 2);
//    g2.addEdge(2, 3);
//    g2.bridge();
//
//    cout << "\nBridges in third graph \n";
//    Graph g3(7);
//    g3.addEdge(0, 1);
//    g3.addEdge(1, 2);
//    g3.addEdge(2, 0);
//    g3.addEdge(1, 3);
//    g3.addEdge(1, 4);
//    g3.addEdge(1, 6);
//    g3.addEdge(3, 5);
//    g3.addEdge(4, 5);
//    g3.bridge();
//
//    return 0;
//}




int main(){
    int t = sI();
    REP(i,t){
        int n = sI(), m = sI();
        Graph g(n);
        vector<int> ans(m,0);
        unordered_map<int, int> map_idx;
        REP(i,m){
            int x = sI(), y = sI();
            x--;
            y--;
            g.addEdge(x,y);
            
            map_idx[x*1e6+y]=i;
            map_idx[y*1e6+x]=i;
        }
        unordered_set< int > n_cy;
        g.bridge(n_cy);
        unordered_set<int>done;
        list<int>path;
        REP(i,n){
            unordered_set<int>visited;
            g.dfs(i,0,n_cy,map_idx,visited,path,ans);
        }
        for(auto x:ans){
            cout<<x/2<<"\n";
        }




    }
}


//void Graph::dfs(int start,int current, int target, int num_wrong_edges, unordered_map<int, int> &map_idx, unordered_set<int>&n_cy, unordered_set<int>&visited,vector<int>&ans,unordered_set<int>&done){
//    if(current==target){
//        return;
//    }
//
//    visited.insert(current);
//    cout<<"current is "<<current+1<<" target is "<<target+1<<"\n";
//
//    for(auto x:adj[current]){
//        //        if(done.find(start*1e6+x)!=done.end()){
//        //            continue;
//        //        }
//        if(visited.find(x)==visited.end()){
//            if(n_cy.find(x*1e6+current)==n_cy.end()){
//                //edge present in cycle
//                if(num_wrong_edges==0){
//                    //increment edge
//                    int idx = map_idx[x*1e6+current];
//                    ans[idx]++;
//                    cout<<" num wrong edges is "<<num_wrong_edges<<" the edge in question is "<<x+1<<"\n";
//                    //mark as visited
//                    visited.insert(x);
//                    //perform dfs
//                    dfs(start,x,target,1,map_idx,n_cy,visited,ans,done);
//                    done.insert(start*1e6+x);
//                    done.insert(x*1e6+start);
//                }
//            }
//            else{
//                //bridge edge
//
//                int idx = map_idx[x*1e6+current];
//                ans[idx]++;
//                cout<<" num wrong edges is "<<num_wrong_edges<<" the edge in question is "<<x+1<<"\n";
//                //mark as visited
//                visited.insert(x);
//                //perform dfs
//                dfs(start,x,target,0,map_idx,n_cy,visited,ans,done);
//                done.insert(start*1e6+x);
//                done.insert(x*1e6+start);
//            }
//        }
//    }
//    cout<<"\n\n";
//}
