#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<unordered_map>
#include<algorithm>
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
    int c = getchar();
    bool flag = true;
    if(c=='-'){
        flag =false;
        c = getchar();
    }
    int n = 0;
    for( ; (c<48 || c>57); c = getchar() );
    for( ; (c>47 && c<58); c = getchar() ){
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
    REP(z,t){
        int n = sI();
        vector<int> vec1;
        vector<int> vec2;
        REP(i,n){
            if(i%2==0){
                vec1.push_back(sI());
            }
            else{
                vec2.push_back(sI());
            }
        }
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());
        
        vector<int>final_vec;
        REP(i,n){
            int next_elem;
            if(i%2==0){
                next_elem = vec1[i/2];
            }
            if(i%2==1){
                next_elem = vec2[i/2];
            }
            final_vec.push_back(next_elem);
        }
        bool flag = true;
        REP(i,n-1){
            if(final_vec[i+1]<final_vec[i]){
                cout<<"Case #"<<z+1<<": "<<i<<"\n";
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<"Case #"<<z+1<<": OK\n";
        }
        
    }
}


