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

long long calc_score(int n, double a){
    long long ans= 0;
    REP(i,n){
        long long x = ((i+1)*a);
        ans += x;
    }
    return ans;
}

int main(){
    int t = sI();
    REP(i,t){
        int n = sI();
        long long x;
        cin>>x;
        long long prev = -1,curr = -2;
        double high = x;
        double low = 0;
        int rounds = 0;
        while(high!=low){
            double med = (high+low)/2;
//            cout<<med<<"is med\n";
            curr = calc_score(n,med);
//            cout<<curr<<"is curr\n";
            if(curr==prev){
                rounds++;
                if(rounds==20){
                    break;
                }
            }
            if(curr>x){
                high = med;
                prev = curr;
            }
            else if(curr<x){
                low = med;
                prev = curr;
            }
            else{
                long long ans = med;
                cout<<ans<<"\n";
                goto label;
            }
            if(curr!=prev){
                rounds=0;
            }
        }
        cout<<"-1\n";
        
    label:
        {
            
        }
    }
}
