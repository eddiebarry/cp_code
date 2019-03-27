
/*
 * Note: This template uses some c++11 functions , so you have to compile it with c++11 flag.
 *       Example:-   $ g++ -std=c++11 c++Template.cpp
 *
 * Author : Edgar Monis
 * Handle: the_kng_in_the_!~th
 *
 */

/********   All Required Header Files ********/
#include<bits/stdc++.h>
using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ll long long
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define node_labl long
#define node_edge_wt long
#define INF 10000000000
const double pi=acos(-1.0);
typedef pair<ll, ll> PII;
typedef vector< ll > VI;







class graph{
public:
    //adjacency list representation
    list< pair<node_labl , node_edge_wt > > *edge_list;
    long num_nodes;
    
    //constructor
    graph(long num){
        this->num_nodes = num;
        edge_list = new list< pair<node_labl , node_edge_wt > >[num];
    }
    
    //adds edge between nodes i and j of wight wt
    void add_edge(node_labl i, node_labl j, node_edge_wt wt){
        edge_list[i].push_back(make_pair(j,wt));
        edge_list[j].push_back(make_pair(i,wt));
    }
    
    //displays all edges
    void display_edges(){
        int i = 0;
        for(int i  = 0; i < num_nodes ; i++){
            for(auto y : edge_list[i] ){
                cout<<i<<" is connected to "<<y.first<<" it has a weight of "<<y.second<<"\n";
            }
            i++;
        }
    }
    
    //breadth first search
    //O(E+V)
    void BFS(node_labl start_node){
        
        //maintains list of visited nodes
        vector<bool>visited(num_nodes,false);
        
        //the order in which nodes will be visited
        queue<node_labl> to_visit;
        
        //pushing the start node onto the  queue
        to_visit.push(start_node);
        
        //stores the bfs
        vector<node_labl>bfs;
        while(!to_visit.empty()){
            //stores the current node
            node_labl curr_node = to_visit.front();
            
            //marks the node as visited
            visited[curr_node] = true;
            
            //adds the node to the bfs stored
            bfs.push_back(curr_node);
            
            //removes the curr node from the queue
            to_visit.pop();
            for(auto x : edge_list[curr_node]){
                if(!visited[x.first]){
                    //adds all neighbors to the bfs
                    to_visit.push(x.first);
                }
            }
        }
        for(auto x: bfs){
            cout<<x<<" ";
        }
        cout<<'\n';

    }
    
    
    //Depth first search
    //O(E+V)
    void DFS(node_labl start_node){
        //maintains the list of visited nodes
        vector<bool>visited(num_nodes,false);
        
        //maintains the order in which the nodes will be examined with no node being examined twice
        stack<node_labl> to_visit;
        
        //pushing the starting node
        to_visit.push(start_node);
        
        //stores the answer of the dfs
        vector<node_labl>dfs;
        while(!to_visit.empty()){
            //assigns the curr node
            node_labl curr_node = to_visit.top();
            visited[curr_node] = true;
            
            //add the curr node to the answer
            dfs.push_back(curr_node);
            
            //remove the current node from consideration
            to_visit.pop();
            for(auto x : edge_list[curr_node]){
                if(!visited[x.first]){
                    //add neigbors to the top so that they are considered in order
                    to_visit.push(x.first);
                }
            }
        }
        for(auto x: dfs){
            cout<<x<<" ";
        }
        cout<<'\n';
    }
    
    void Djikstra(node_labl src){
        //stores the best distance calculated so far
        vector<node_edge_wt>dist(num_nodes,INF);
        
        //parents
        vector<node_labl>parent(num_nodes,INF);
//        //initialises a vector of visited nodes
//        vector<bool>visited(num_nodes,false);
        
        //in djiktra, the least weighted neighbor is visited first
        //hence we can use a min priority queue/ min heap/ set
        set< pair<node_edge_wt,node_labl > >min_que;
        
        //initialising the distance of source from source to 0;
        dist[src]=0;
        parent[0]=-1;
        
        //inserting the first node in min_que
        min_que.insert(make_pair(0,src));
        
        while (!min_que.empty()) {
            //insert all the edges out of src
            node_labl temp = min_que.begin()->second;
            node_edge_wt edg_wt = min_que.begin()->first;
            
            //consider minimum weight edge
            for(auto x : edge_list[temp]){
                if(dist[x.first] > dist[temp] + x.second){
                    
                    if(dist[x.first]!=INF){
                        //the edge has already been added
                        min_que.erase(make_pair(dist[x.first],x.first));
                    }
                    
                    //updating parents
                    parent[x.first] = temp;
                    
                    //updating distances
                    dist[x.first] = dist[temp] + x.second;
                    
                    //inserting updated edge
                    min_que.insert(make_pair(dist[x.first],x.first));
                    
                }
            }
            min_que.erase(min_que.begin());
        }
        ll N = num_nodes/4;
        ll to_check = 4 *(N-1);
        bool ans = false;
        ll idx = -1;
        REP(i,4){
            if(parent[i+to_check]!=INF){
                ans = true;
                idx = i + to_check;
                break;
            }
        }
        if(ans){
            VI ans;
            while(idx!=N*4){
                ans.PB(idx%4);
                idx = parent[idx];
            }
            int sz = ans.size();
            cout<<"YES\n";
            REP(i,sz){
                cout<<ans[sz-1-i]<<" ";
            }
        }
        else{
            cout<<"NO\n";
        }
        // int i = 0;
        // for(auto x: parent){
        //     cout<<i<<" parent is "<<x<<"\n";
        //     i++;
        // }
        // i = 0;
        // for(auto x: dist){
        //     cout<<i<<" dist is "<<x<<"\n";
        //     i++;
        // }
        
    }
    
};


ll SI(){
    ll x;
    cin>>x;
    return x;
}





/********** Main()  function **********/
int main()
{
    int n = SI();
    VI a(n,0);
    VI b(n,0);

    REP(i,n-1){
        a[i]=SI();
    }
    REP(i,n-1){
        b[i]=SI();
    }
    graph g(n*4 + 1);
    REP(i,n-1){
        if(a[i]==0&&b[i]==0){
            g.add_edge(i*4, (i+1)*4,1);
        }
        if(a[i]==1&&b[i]==0){
            g.add_edge(i*4, ((i+1)*4) + 1, 1);
            g.add_edge(i*4 +1, ((i+1)*4) , 1);
        }
        if(a[i]==1&&b[i]==1){
            g.add_edge(i*4 + 1, ((i+1)*4) + 1, 1);
        }
        if(a[i]==2&&b[i]==0){
            g.add_edge(i*4, ((i+1)*4) + 2, 1);
            g.add_edge(i*4 +2, ((i+1)*4) , 1);
            // cout<<"addding edge between "<<i*4<<" "<<((i+1)*4) + 2<<"\n";
        }
        if(a[i]==2&&b[i]==2){
            g.add_edge(i*4+2, ((i+1)*4) + 2, 1);
        }
        if(a[i]==3&&b[i]==0){
            g.add_edge(i*4+2, ((i+1)*4) + 1, 1);
            g.add_edge(i*4 +1, ((i+1)*4) + 2, 1);
        }
        if(a[i]==3&&b[i]==1){
            g.add_edge(i*4+3, ((i+1)*4) + 1, 1);
            g.add_edge(i*4 +1, ((i+1)*4) + 3, 1);
        }
        if(a[i]==3&&b[i]==2){
            g.add_edge(i*4 +3, ((i+1)*4) + 2, 1);
            g.add_edge(i*4 +2, ((i+1)*4) + 3, 1);
            // cout<<"addding edge between "<<i*4 +3<<" "<<((i+1)*4) + 2<<"\n";
        }
        if(a[i]==3&&b[i]==3){
            g.add_edge(i*4+3, ((i+1)*4) + 3, 1);
        }
        g.add_edge(n*4, 0,1);
        g.add_edge(n*4, 1,1);
        g.add_edge(n*4, 2,1);
        g.add_edge(n*4, 3,1);
    }
    g.Djikstra(n*4);
    
    
    return 0;
}
