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
#include<climits>
#include<stdlib.h>  //for rand testing purpose
#define node_labl int
#define node_edge_wt int
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
int k;
int V;
int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    
    return min_index;
}


void printMST( std:: vector<int> &parent , int n, std::vector < std::vector <int> >  &graph, std::set<pp> &edges)
{
    for (int i = 1; i < V; i++){
        pair<int,int> temp = make_pair(parent[i], i);
        pp temp1 = make_pair(graph[i][parent[i]] , temp);
        edges.insert(temp1);
        
        temp = make_pair(i ,parent[i]);
        temp1 = make_pair(graph[i][parent[i]] , temp);
        edges.insert(temp1);
    }
    
}


void primMST(std::vector < std::vector <int> >  &graph, std:: vector<int> &parent, std::set<pp> &edges)
{
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST
    for (int count = 0; count < V-1; count++)
    {
        
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            
            if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
                parent[v]  = u, key[v] = graph[u][v];
    }
    printMST(parent, V, graph,edges);
}

class graph{
public:
    list< pair<node_labl , node_edge_wt > > *edge_list;
    long num_nodes;
    graph(long num){
        this->num_nodes = num;
        edge_list = new list< pair<node_labl , node_edge_wt > >[num];
    }
    void add_edge(node_labl i, node_labl j, node_edge_wt wt){
        edge_list[i].push_back(make_pair(j,wt));
        edge_list[j].push_back(make_pair(i,wt));
    }
    
    
    bool Djikstra(node_labl src, std::vector< std::vector< int > > &vec,string &ans, int & num, set<pp>edges){
        vector<node_edge_wt>dist(num_nodes,INF);
        vector<node_labl>parent(num_nodes,INF);
        set< pair<node_edge_wt,node_labl > >min_que;
        dist[src]=0;
        parent[0]=-1;
        min_que.insert(make_pair(0,src));
        while (!min_que.empty()) {
            node_labl temp = min_que.begin()->second;
            node_edge_wt edg_wt = min_que.begin()->first;
            for(auto x : edge_list[temp]){
                if(dist[x.first] > dist[temp] + x.second){
                    if(dist[x.first]!=INF){
                        min_que.erase(make_pair(dist[x.first],x.first));
                    }
                    parent[x.first] = temp;
                    dist[x.first] = dist[temp] + x.second;
                    min_que.insert(make_pair(dist[x.first],x.first));
                    
                }
            }
            min_que.erase(min_que.begin());
        }
//        for(auto x : dist){
//            cout<<x<<"\n";
//        }
//        cout<<"\n\n\n";
//        for(auto x : parent){
//            cout<<x<<"\n";
//        }
        set<pp>min_tree;
        int i = 0;
        for(auto x : parent){
            int min = i;
            int max = x;
            if(max==-1){
                goto lab;
            }
            if(min>max){
                min^=max;
                max^=min;
                min^=max;
            }
//            cout<<min<<" "<<max<<"is the"<<-1*vec[min][max]<<"is the weight\n";
            //pair<int,int> temp  = make_pair(min,max);
            min_tree.insert(make_pair(-1*vec[min][max], make_pair(min,max)));
        lab:
            i++;
        }
        bool changes = false;
        for(auto x : min_tree){
            if(edges.find(x)==edges.end()){
                changes = true;
                int wt = x.first;
                int min = x.second.first;
                int max = x.second.second;
                edge_list[min].remove(make_pair(max,wt));
                edge_list[max].remove(make_pair(min,wt));
                num++;
                min++;
                max++;
                ans+= std::to_string(min);
                ans+=" ";
                ans+= std::to_string(max);
                ans+="\n";
                if(num==k){
                    return false;
                }
            }
        }
        return changes;
    }
    
    
};



int main(){
    int n  = sI();
    k = sI();
    std::vector< std::vector< int > > arr( n, std::vector< int >( n ) );
    std::vector< std::vector< int > > MST( n, std::vector< int >( n ) );
    REP(i,n){
        REP(j,n){
            arr[i][j]=sI();
            MST[i][j]= -1 * arr[i][j];
        }
    }
    
    V = n;
    vector <int> parMST(V);
    set <pp> edges;
    primMST(MST,parMST,edges);
    //edges contains the MAXIMUM st
//    for(auto x : edges){
//        cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<"\n";
//    }
    
    graph g(n);
    REP(i,n){
        REP(j,n){
            if(i<j && arr[i][j]!=-1){
                g.add_edge(i,j,arr[i][j]);
            }
        }
    }
    bool flag = true;
    int num = 0;
    string ans="";
    while(num!=k && flag){
        //flag =
        flag = g.Djikstra(0,arr,ans,num,edges);
    }
    cout<<num<<"\n"<<ans<<"\n";
    
    
    
    
}

