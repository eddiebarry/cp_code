#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <vector>
#include <math.h>
#include <set>
#include <queue>
#include <list>
#include <set>

#define NUM_NODES 100
#define TRANS_POWER .0001
#define CIRCUIT_POWER .0001
#define RECIE_POWER .0001
#define FIELD_X 100
#define FIELD_Y 100
#define INIT_POWER 10
#define TRANS_CALC_DELAY 100
#define C 3*1e8
#define INF 0x3f3f3f3f

using namespace std;
int DISTANCES[NUM_NODES][NUM_NODES];
int BS_DIST = 100;

double trans(int i, int y){
    if(y!=-1){
        return TRANS_POWER*pow(DISTANCES[i][y],2) + CIRCUIT_POWER;
    }
    else{
        return TRANS_POWER*pow(BS_DIST,2);
    }
}




class Graph
{
    int V;    // No. of vertices
    
    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair<int, int> > *adj;
    
public:
    Graph(int V);  // Constructor
    
    // function to add an edge to graph
    void addEdge(int u, int v, double w);
    
    // prints shortest path from s
    double shortestPath(int s);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<int, int> >[V];
}

void Graph::addEdge(int u, int v, double w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
double Graph::shortestPath(int src)
{
    // Create a set to store vertices that are being
    // prerocessed
    set< pair<int, int> > setds;
    
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<double> dist(V, INF);
    
    // Insert source itself in Set and initialize its
    // distance as 0.
    setds.insert(make_pair(0, src));
    dist[src] = 0;
    
    /* Looping till all shortest distance are finalized
     then setds will become empty */
    while (!setds.empty())
    {
        // The first vertex in Set is the minimum distance
        // vertex, extract it from set.
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
        
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = tmp.second;
        
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            double weight = (*i).second;
            
            //  If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                /*  If distance of v is not INF then it must be in
                 our set, so removing it and inserting again
                 with updated less distance.
                 Note : We extract only those vertices from Set
                 for which distance is finalized. So for them,
                 we would never reach here.  */
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));
                
                // Updating distance of v
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    
    // Print shortest distances stored in dist[]
    double max = -1;
//    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i){
//        printf("%f \t\t %d\n", i, dist[i]);
        if(dist[i]>max&&dist[i]!=INF){
            max = dist[i];
        }
    }
    
    return max;
    
}

double MAX_DELAY(vector<pair<int,int> > &tree,int head){
    int V = NUM_NODES;
    Graph g(V);
    for(auto x:tree){
        g.addEdge(x.first,x.second,DISTANCES[x.first][x.second]/C + TRANS_CALC_DELAY);
    }
    return g.shortestPath(head);
}





















void init_distances(){
    int x;
    cin>>x;
    srand(x);
    vector< pair<int, int> > vec;
    int a = NUM_NODES;
    while(a--){
        int x = rand()%FIELD_X;
        int y = rand()%FIELD_Y;
        vec.push_back(make_pair(x,y));
    }
    int i=0,j=0;
    for(auto x:vec){
        for(auto y:vec){
            DISTANCES[i][j]= pow(x.first-y.first,2) + pow(x.second-y.second,2);
            DISTANCES[i][j] = sqrt(DISTANCES[i][j]);
            j++;
        }
        i++;
        j=0;
    }
//     for(int i = 0; i <NUM_NODES; i++){
//         for(int j = 0; j <NUM_NODES; j++){
//             cout<<DISTANCES[i][j]<<" ";
//         }
//         cout<<endl;
//     }
    
}



vector< pair<int ,int> > form_peg(vector<double>&power){
    int num = 0;
    for(auto x:power){
        if(x>0){
            num++;
        }
    }
    vector<pair <int, int> > vec;
    vector<int> marked(NUM_NODES,1);
    
    
    if(num>1){
        //find min edge
        int start = -1, end = -1;
        double min_edge = FIELD_X*FIELD_Y*FIELD_X*FIELD_Y;
        for(int i = 0; i <NUM_NODES; i++){
            for(int j = i+1; j <NUM_NODES; j++){
                if(DISTANCES[i][j]<min_edge&&power[i]>0&&power[j]>0){
                    min_edge = DISTANCES[i][j];
                    start = i;
                    end = j;
                }
            }
            // cout<<endl;
        }
        marked[start]=0;
        marked[end]=0;
        vec.push_back(make_pair(start,end));
        num-=2;
        //add n-2 edges
        while(num--){
            //find smallest edge from start
            double min_edge = FIELD_X*FIELD_Y*FIELD_X*FIELD_Y;
            int start_cand= -1;
            for(int j = 0; j <NUM_NODES; j++){
                if(DISTANCES[start][j]<min_edge && power[j]>0 && start!=j &&marked[j]==1){
                    start_cand = j;
                    min_edge = DISTANCES[start][j];
                }
            }

            min_edge = FIELD_X*FIELD_Y*FIELD_X*FIELD_Y;
            int end_cand= -1;
            for(int j = 0; j <NUM_NODES; j++){
                if(DISTANCES[end][j]<min_edge && power[j]>0 && end!=j &&marked[j]==1){
                    end_cand = j;
                    min_edge = DISTANCES[end][j];
                }
            }

            if(DISTANCES[start][start_cand]<DISTANCES[end][end_cand]){
                vec.push_back(make_pair(start,start_cand));;
                start = start_cand;
                marked[start]=0;
            }
            else{
                vec.push_back(make_pair(end,end_cand));
                end = end_cand;
                marked[end]=0;
            }
        }
    }

//     for(auto x:vec){
//         cout<<x.first<<" "<<x.second<<endl;
//     }

    return vec;
}
//
//
vector< pair<int ,int> > form_MST(vector<double>&power){
    int num = 0;
    for(auto x:power){
        if(x>0){
            num++;
        }
    }
    vector<pair <int, int> > vec;
    vector<int> marked(NUM_NODES,1);
    if(num>1){
        //find min add edge
        int start = -1, end = -1;
        double min_edge = FIELD_X*FIELD_Y*FIELD_X*FIELD_Y;
        for(int i = 0; i <NUM_NODES; i++){
            for(int j = i+1; j <NUM_NODES; j++){
                if(DISTANCES[i][j]<min_edge&&power[i]>0&&power[j]>0){
                    min_edge = DISTANCES[i][j];
                    start = i;
                    end = j;
                }
            }
            // cout<<endl;
        }

        set< pair<double, pair<int,int> > > pq;
        marked[start]=0;
        marked[end]=0;
        for(int j = 0; j <NUM_NODES; j++){
            if(DISTANCES[start][j]!=0 && power[j]>0 && start!=j){
                pq.insert(make_pair(DISTANCES[start][j],make_pair(start,j)));
            }
            if(DISTANCES[end][j]!=0 && power[j]>0 && end!=j){
                pq.insert(make_pair(DISTANCES[end][j],make_pair(end,j)));
            }
        }
        vec.push_back(make_pair(start,end));
        num-=2;
        while(num--){
            while(true){
                pair<double, pair<int,int> > temp = *pq.begin();
                int x = temp.second.first;
                int y = temp.second.second;
                if(marked[x]==0&&marked[y]==0){
                    pq.erase(pq.begin());
                }
                else{
                    if(marked[x]==0){
                        marked[y]=0;
                        vec.push_back(make_pair(x,y));
                        x=y;

                    }
                    else{
                        marked[x]=0;
                        vec.push_back(make_pair(x,y));
                    }
                    //add all edges associated with x
                    for(int j = 0; j <NUM_NODES; j++){
                        if(DISTANCES[x][j]!=0 && power[j]>0 && marked[j]==1){
                            pq.insert(make_pair(DISTANCES[x][j],make_pair(x,j)));
                        }
                    }
                    break;
                }
            }
        }

    }
//    for(auto x:vec){
//        cout<<x.first<<" "<<x.second<<"\n";
//    }
    return vec;
}



double calc_score(vector<pair<int,int> > tree){
    double x =0;
    for(auto y:tree){
        x+= DISTANCES[y.first][y.second]*DISTANCES[y.first][y.second];
    }
    return x;
}


int run_round(int head,vector<pair<int,int> > &tree,vector<double>&power){
    if(power[head]<0){
        return 0;
    }
    
    //removing recieving power
    double total_en = 0;
    vector<int> num_child(NUM_NODES,0);
    for(auto x:tree){
        num_child[x.first]++;
        num_child[x.second]++;
    }
    num_child[head]++;
    for(int i = 0; i <NUM_NODES; i++){
        num_child[i]--;
    }
    for(int i = 0; i <NUM_NODES; i++){
        power[i] -= num_child[i]*RECIE_POWER;
//        total_en += num_child[i]*RECIE_POWER;
    }


    vector<int>edge[NUM_NODES];
    for(auto x:tree){
        edge[x.first].push_back(x.second);
        edge[x.second].push_back(x.first);
    }
    
    queue<int>q;
    vector<int>marked(NUM_NODES,1);
    vector<int>parents(NUM_NODES,-1);
    q.push(head);
    while(!q.empty()){
        int head = q.front();
        marked[head] = 0;
        q.pop();
        for(auto x: edge[head]){
            if(marked[x]==1){
                parents[x] = head;
                marked[x] = 0;
                q.push(x);
            }

        }
    }
//    for(auto x:parents){
//        cout<<x<<" -- ";
//    }
//    cout<<"\n";
    
    for(int i = 0; i <NUM_NODES; i++){
        power[i] -= trans(i,parents[i]);
//        total_en += trans(i,parents[i]);
    }

    return 1;
}

void run_sim_peg(){
//    init_distances();

    vector<double>power_peg(NUM_NODES,INIT_POWER);
    vector<pair<int,int> > peg_chn;
    
    int head = 0,num_alive=0,rounds = 0;
    bool flag1 =true,flag2 = true,flag3 =true,flag4 = true,flag5 =true,flag6 = true,flag7 =true,flag8 = true,flag9 =true,flag10 = true;
    while(flag1){
        num_alive = 0;
        for(auto x:power_peg){
            if(x>0){
                num_alive++;
            }
        }
        peg_chn = form_peg(power_peg);
        if(run_round(head++%NUM_NODES,peg_chn,power_peg)==1){
            rounds++;
        }
        if(head < 5){
            cout<<MAX_DELAY(peg_chn,head-1)<<"is the trans delays in peg\n";
        }
        
        
        
        if(num_alive <= 0.9*NUM_NODES&&flag9){
            flag9 = false;
            cout<<"90 percent @ "<<rounds<<endl;
        }
        else if(num_alive <= 0.8*NUM_NODES&&flag8){
            flag8 = false;
            cout<<"80 percent @ "<<rounds<<endl;
        }
        else if(num_alive <= 0.7*NUM_NODES&&flag7){
            flag7 = false;
            cout<<"70 percent @ "<<rounds<<endl;
        }
        else if(num_alive <= 0.6*NUM_NODES&&flag6){
            flag6 = false;
            cout<<"60 percent @ "<<rounds<<endl;
        }
        else if(num_alive <= 0.5*NUM_NODES&&flag5){
            flag5 = false;
            cout<<"50 percent @ "<<rounds<<endl;
        }
        else if(num_alive <= 0.4*NUM_NODES&&flag4){
            flag4 = false;
            cout<<"40 percent @ "<<rounds<<endl;
        }
        else if(num_alive <= 0.3*NUM_NODES&&flag3){
            flag3 = false;
            cout<<"30 percent @ "<<rounds<<endl;
        }
        else if(num_alive <= 0.3*NUM_NODES&&flag2){
            flag2 = false;
            cout<<"20 percent @ "<<rounds<<endl;
        }
        else if(num_alive <= 0.1*NUM_NODES&&flag1){
            flag1 = false;
            cout<<"10 percent @ "<<rounds<<endl;
        }
    }
}

void run_sim_mst(){
    //    init_distances();
    
    vector<double>power_mst(NUM_NODES,INIT_POWER);
    vector<pair<int,int> > mst;
    
    int head = 0,num_alive=0,rounds = 0;
    bool flag1 =true,flag2 = true,flag3 =true,flag4 = true,flag5 =true,flag6 = true,flag7 =true,flag8 = true,flag9 =true,flag10 = true;
    while(flag1){
        num_alive = 0;
        for(auto x:power_mst){
            if(x>0){
                num_alive++;
            }
        }
        
        mst = form_MST(power_mst);
        if(run_round(head++%NUM_NODES,mst,power_mst)==1){
            rounds++;
        }
//        cout<<"1 "<<endl;
        if(head < 5){
            cout<<MAX_DELAY(mst,head-1)<<"is the trans delays in mst\n";
        }
//        cout<<"1 "<<endl;
        if(num_alive <= 0.9*NUM_NODES&&flag9){
            flag9 = false;
            cout<<"90 percent @ "<<rounds<<endl;
        }
        else if(num_alive <= 0.8*NUM_NODES&&flag8){
            flag8 = false;
            cout<<"80 percent @ "<<rounds<<endl;
        }
        else if(num_alive <= 0.7*NUM_NODES&&flag7){
            flag7 = false;
            cout<<"70 percent @ "<<rounds<<endl;
        }
        else if(num_alive <= 0.6*NUM_NODES&&flag6){
            flag6 = false;
            cout<<"60 percent @ "<<rounds<<endl;
        }
        else if(num_alive <= 0.5*NUM_NODES&&flag5){
            flag5 = false;
            cout<<"50 percent @ "<<rounds<<endl;
        }
        else if(num_alive <= 0.4*NUM_NODES&&flag4){
            flag4 = false;
            cout<<"40 percent @ "<<rounds<<endl;
        }
        else if(num_alive <= 0.3*NUM_NODES&&flag3){
            flag3 = false;
            cout<<"30 percent @ "<<rounds<<endl;
        }
        else if(num_alive <= 0.3*NUM_NODES&&flag2){
            flag2 = false;
            cout<<"20 percent @ "<<rounds<<endl;
        }
        else if(num_alive <= 0.1*NUM_NODES&&flag1){
            flag1 = false;
            cout<<"10 percent @ "<<rounds<<endl;
        }
    }
}


void run_sim(){
    init_distances();
    run_sim_peg();
    run_sim_mst();
}




int main()
{
//    init_distances();
//    vector<double>power_peg(NUM_NODES,INIT_POWER);
//    vector<pair<int,int> > peg_chn = form_peg(power_peg);
//    vector<pair<int,int> > MST = form_MST(power_peg);
    run_sim();
    
    return 0;
}



//run_sim();
//    init_distances();
//    vector<double>power(NUM_NODES,10);
//    vector<pair<int,int> > peg_chn = form_peg(power);
//    cout<<calc_score(peg_chn)<<endl<<"\n";
//    vector<pair<int,int> > MST = form_MST(power);
//    cout<<calc_score(MST)<<endl<<"\n";
//    power[0]=-1;
//    peg_chn = form_peg(power);
//    cout<<calc_score(peg_chn)<<endl<<"\n";
//    MST = form_MST(power);
//    cout<<calc_score(MST)<<endl<<"\n";
