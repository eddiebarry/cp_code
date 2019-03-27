#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <set>
#include <unordered_map>
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = sI(), k = sI();
    vector<int> pos(n,0);
    vector<int> ran(n,0);
    vector<int> iq(n,0);

    set<int>s;
    REP(i,n){
        int x = sI(), r = sI(), q = sI();
        //perform compression on q
        pos[i]=x;
        ran[i] = r;
        iq[i] = r;
        s.insert(iq[i]);
    }
    //create compression
    int id = 0;
    unordered_map<int,int> ids;
    for(auto x: s){
        ids[x] = id;
        id++;
    }
    vector<int> indexes[id];
    REP(i,n){
        int id_i =  ids[iq[i]];
        indexes[id_i].push_back(pos[i]);
    }
    REP(i,id){
        sort(indexes[i].begin(), indexes[i].end() );
    }
    long long ans = 0;

    REP(i,n){
        int po = pos[i];
        int range = po + ran[i];

        //check

        int IQ = iq[i];

        FOR(to_find, IQ - k, IQ + k + 1, 1){
            if( s.find(to_find)!=s.end() ){
                //find number of elements less than
                int cmp_idx = ids[to_find];

                auto it = lower_bound( indexes[cmp_idx].begin(),  indexes[cmp_idx].end(), range );
                int num = it - indexes[cmp_idx].begin();
                if(*it!= range){
                    num--;
                }


                auto itr = lower_bound( indexes[cmp_idx].begin(),  indexes[cmp_idx].end(), po );
                int num_1 = itr - indexes[cmp_idx].begin();
                if(*itr!= po){
                    num_1--;
                }

                ans += num - num_1;
            }
        }
    }

    cout<<ans<<"\n";








    return 0;
}
