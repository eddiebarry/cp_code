//
//  Djikstra.cpp
//
//  Created by Edgar Monis on 03/02/18.
//
#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<stdlib.h>  //for rand testing purpose
#define node_labl long
#define node_edge_wt long
#define INF 10000000000
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;

int sI(){
    register int c = getchar_unlocked();
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
//graph is zero indexed
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
    
    void Djikstra(node_labl src, int n, int m){
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
//        int i = 0;
//        for(auto x: parent){
//            cout<<i<<" parent is "<<x<<"\n";
//            i++;
//        }
        int maxi = -1;
        for(auto x: dist){
            if(x>maxi){
                maxi = x;
            }
        }
        cout<<maxi<<"\n";
        
    }
    
    ~graph(){
        for(int i = 0 ; i < num_nodes ; i++){
            while(!edge_list[i].empty()){
                edge_list[i].pop_front();
            }
        }
//        delete edge_list[i];
    }
    
};



int main(){
    
    int t = sI();
    REP(i,t){
        int n = sI(), m = sI();
        int cst[n][m];
        int cng[n][m];
        
        REP(i,n){
            REP(j,m){
                cst[i][j]=sI();
            }
        }
        
        REP(i,n){
            REP(j,m){
                cng[i][j]=sI();
            }
        }
        
        
        
        graph g(n*m*2 + 2);
        REP(i,n){
            REP(j,m-1){
                g.add_edge(i*m + j+1, i*m + j+2, cst[i][j]);
//                cout<<"adding edge between "<<i*m + j+1<<" "<<i*m + j+2<<"\n";
            }
        }
        
        REP(i,n-1){
            REP(j,m){
                g.add_edge(n*m+i*m + j+1,n*m+ (i+1)*m + j+1, cst[i][j]);
//                                cout<<"adding edge between "<<n*m+i*m + j+1<<" "<<n*m+i*m + j+2<<"\n";
            }
        }
        
        
        REP(i,n){
            REP(j,m){
                g.add_edge(i*m+j+1, i*m+j+1 + n*m,cng[i][j]);
            }
        }
        g.add_edge(0,1,0);
        g.add_edge(0,n*m+1,0);
        
        g.add_edge(n*m*2, n*m *2 +1 , 0);
        g.add_edge(n*m*2, n*m *2 +1 , 0);
        
        g.Djikstra(0,n,m);
    }
    
    

}

//    int n  = 10;
//
//    graph g(n);
//    //adding edges
//    g.add_edge(0, 1, 4);
//    g.add_edge(0, 7, 8);
//    g.add_edge(1, 2, 8);
//    g.add_edge(1, 7, 11);
//    g.add_edge(2, 3, 7);
//    g.add_edge(2, 8, 2);
//    g.add_edge(2, 5, 4);
//    g.add_edge(3, 4, 9);
//    g.add_edge(3, 5, 14);
//    g.add_edge(4, 5, 10);
//    g.add_edge(5, 6, 2);
//    g.add_edge(6, 7, 1);
//    g.add_edge(6, 8, 6);
//    g.add_edge(7, 8, 7);
//    //djikstra
//    g.Djikstra(0);
//    //displaying edges
//    g.display_edges();
//    //

