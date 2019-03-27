#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;
int sI(){
    register int c;
    cin>>c;
    return c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = sI();
    if(n%4==1||n%4==2){
        if(n==1||n==2){
            cout<<"NO";
        }
        else{
            cout<<1<<" "<<n<<"\n";
            cout<<n-1<<" ";
            REP(i,n-1){
                cout<<i+1<<" ";
            }
        }
        
        
        
        
    }
    else if(n%4==0){
        vector<int>a;
        vector<int>b;
        REP(i,n){
            int x = i+1;
            if(x%4==0||x%4==1){
                a.push_back(x);
            }
            else{
                b.push_back(x);
            }
        }
        cout<<a.size()<<" ";
        for(auto x: a){
            cout<<x<<" ";
        }
        cout<<"\n";
        cout<<b.size()<<" ";
        for(auto x: b){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    else{
        vector<int>a;
        vector<int>b;
        REP(i,n-3){
            int x = i+4;
            if(x%4==0||x%4==3){
                a.push_back(x);
            }
            else{
                b.push_back(x);
            }
        }
        a.push_back(3);
        b.push_back(1);
        b.push_back(2);
        cout<<a.size()<<" ";
        for(auto x: a){
            cout<<x<<" ";
        }
        cout<<"\n";
        cout<<b.size()<<" ";
        for(auto x: b){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
//    int arr[9];
//    REP(i,9){
//        arr[i]=i+1;
//    }
//    REP(i,512){
//
//    }
    
    
    return 0;
}

