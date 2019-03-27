#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <vector>
#include <math.h>
#include <set>
#include <queue>

#define NUM_NODES 100
#define TRANS_POWER .0001
#define CIRCUIT_POWER .0001
#define RECIE_POWER .0001
#define FIELD_X 100
#define FIELD_Y 100
#define INIT_POWER 10


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
double NODE_LOSE_P;

void init_distances(){
    int x;
    cin>>x;
    srand(x);
    cin>>NODE_LOSE_P;
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
            
            pair<double, pair<int,int> > temp = *pq.begin();
            int x = temp.second.first;
            int y = temp.second.second;
            while(marked[x]==0&&marked[y]==0){
                pq.erase(pq.begin());
                temp = *pq.begin();
                x = temp.second.first;
                y = temp.second.second;
            }
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

double total_energy_used = 0;

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
        if(power[i]>0){
            power[i] -= num_child[i]*RECIE_POWER;
            total_en += num_child[i]*RECIE_POWER;
            power[i] -= trans(i,parents[i]);
            total_en += trans(i,parents[i]);
        }
    }
    total_energy_used+=total_en;
    return 1;
}

void run_sim_peg(vector<double>&power_peg){
    //    init_distances();
    cout<<"this is the PEG sim\n";
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
        if(run_round(head++%NUM_NODES,peg_chn,power_peg)==1){
            rounds++;
        }
        peg_chn = form_peg(power_peg);
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
            cout<<total_energy_used/rounds<<"\n";
        }
    }
}

void run_sim_mst(vector<double>&power_mst){
    //    init_distances();
    cout<<"this is the mst sim\n";
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
        if(run_round(head++%NUM_NODES,mst,power_mst)==1){
            rounds++;
        }
        //        cout<<"1 "<<endl;
        mst = form_MST(power_mst);
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
            cout<<total_energy_used/rounds<<"\n";
        }
    }
}


void run_sim(){
    init_distances();
    total_energy_used = 0;
    vector<double>power_peg(NUM_NODES,INIT_POWER);
    vector<double>power_mst(NUM_NODES,INIT_POWER);
    for(int i = 0 ; i < NODE_LOSE_P*NUM_NODES; i++){
        int x = rand()%NUM_NODES;
        power_mst[x]=-1;
        power_peg[x]=-1;
    }
    run_sim_peg(power_peg);
    total_energy_used = 0;
    run_sim_mst(power_mst);
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
