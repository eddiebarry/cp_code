#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<climits>
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
#define HASH_SIZE 1000
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



int fold(int n){
    int x = n;
    vector<int>vec;
    while(x>0){
        vec.push_back(x%1000);
        x/=1000;
    }
    int idx = 0;
    for(auto x:vec){
        idx+=x;
    }
    return idx%HASH_SIZE;
}

int main(){
    cout<<"enter number of elements to insert\n";
    int hash_table[HASH_SIZE];
    REP(i,HASH_SIZE){
        hash_table[i]=-1;
    }
    int n = sI();
    REP(i,n){
        int x = sI();
        int idx = fold(x);
        cout<<"\n"<<idx<<"\n";
        if(hash_table[idx]!= -1){
            cout<<"collision ha soccured\n";
        }
        else{
            hash_table[idx]=x;
        }
        
    }
    int t = sI();
    cout<<"enter number of times to search\n";
    REP(i,t){
        int x = sI();
        int idx = fold(x);
        if(hash_table[idx]==x){
            cout<<"element found\n";
        }
        else{
            cout<<"element not found\n";
        }
    }

}
