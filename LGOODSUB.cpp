#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<climits>
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
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

int main(){
    int t = sI();
    while (t--) {
        int n = sI();
        unordered_multimap<int,int>map;
        vector<int>vec(n);
        set<int>st;
        REP(i,n){
            vec[i]=sI();
            map.insert( make_pair( vec[i] , i ) );
            st.insert(vec[i]);
        }
        //        cout<<"map:\n";
        //        for(auto x:map){
        //            cout<<x.first<<" "<<x.second<<"\n";
        //        }
        //        cout<<"st:\n";
        //        for(auto x:st){
        //            cout<<x<<"\n";
        //        }
        int best_ans = 0;
        REP(i,n){
            int temp = vec[n-1-i];
            //            cout<<"temp:\n"<<temp<<"\n";
            //find successor of temp
            auto it = st.find(temp);
            while(it!=st.end()){
                auto range = map.equal_range(*it);
                for (auto it = range.first; it != range.second; ++it) {
                    int temp_ans = n-i- it->second;
                    //                    int t = *it;
                    //                    cout<<it->second<<"is the index of of successor\n";
                    if(temp_ans>best_ans){
                        best_ans = temp_ans;
                    }
                }
                it++;
            }
        }
        cout<<best_ans<<"\n";
    }
    
}
