#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#define ll long long
#define intpair pair<int,int>
#define MP(i,j) make_pair(i,j)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;
ll sI(){
    ll x;
    cin>>x;
    return x;
}

ll max(ll a, ll b){
    return a<b ?b:a;
}

ll min(ll a, ll b){
    return a>b ?b:a;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n = sI(), k = sI();
    
    if(n==1){
        cout<<0;
        return 0;
    }
    vector<int>freq(2*100000+1,0);
    
    
    
    
    int min = 3*100000;
    
    REP(i,n){
        int x = sI();
        freq[x]++;
        
        if(x<min){
            min = x;
        }
    }
    
    
    
    ll sum = 0;
    
    ll ans = 0;
    
    ll num_idx = 0;
    
    REP(i,2*100000){
        int idx = 2*100000 - i;
        
        
        if(idx==min){
            if(sum > 0){
                ans++;
            }
            break;
        }
        
        
        num_idx += freq[idx];
        sum += num_idx;
        
//        cout<<num_idx<<" "<<sum<<" "<<idx<<"\n";
        if(sum>k){
            ans++;
//            sum = num_idx;
            i--;
            num_idx -= freq[idx];
            sum = 0;
        }
        
        

        
    }
    
    
    cout<<ans<<"\n";
    
    
    
    
    
    
    
    
    
    return 0;
}
//if(idx == min){
//    if(sum>0){
//        ans++;
//    }
//    break;
//}
//else{
//}
//            num_idx += freq[idx];
//            sum += freq[idx];
//            if(sum<=k){
////                num_idx += freq[idx];
//                sum += num_idx;
//            }
//            else{
//                cout<<"making a cut at "<<idx<<"\n";
//                ans++;
//                sum = 0;
//                i--;
//            }





