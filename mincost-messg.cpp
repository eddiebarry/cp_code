#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<unordered_map>
#include<climits>
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
using namespace std;
long sI(){
    long c;
    cin>>c;
    return c;
}

int main(){
    long n = sI(), k = sI(), m = sI();
    vector<string>words;
    vector<long>cost;
    REP(i,n){
        string s;
        cin>>s;
        words.push_back(s);
    }
    REP(i,n){
        long s;
        cin>>s;
        cost.push_back(s);
    }
    long min_cost[k];
    //long word_id[n];
    
    unordered_map<string,long> word_map;
    
    REP(i,k){
        min_cost[i]= 1000000001;
        long x = sI();
        REP(j,x){
            long idx = sI();
            idx--;
            word_map[words[idx]]=i;
            if(cost[idx]<min_cost[i]){
                min_cost[i]=cost[idx];
            }
        }
    }
    long long ans = 0;
    REP(i,m){
        string s;
        cin>>s;
        ans += min_cost[ word_map[s] ];
    }
    cout<<ans;
    return 0;
}

