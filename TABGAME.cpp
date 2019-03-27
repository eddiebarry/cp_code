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
    int c;
    cin>>c;
    return c;
}
long long sLL(){
    register int c = getchar_unlocked();
    bool flag = true;
    if(c=='-'){
        flag =false;
        c = getchar_unlocked();
    }
    long long n = 0;
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



int max(int a,int b){
    return a>b?a:b;
}
int min(int a,int b){
    return a<b?a:b;
}

int DP[10000+1][10000+1];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = sI();
    while(t--){
        string a,b;
        cin>>a>>b;
//        cout<<a<<" "<<b<<"\n";
        
        int a_sz = a.size();
        int b_sz = b.size();

        
        //DP[M][N]
        REP(i,a_sz){
            DP[i+1][0] = a[i]-'0';
        }
        REP(i,b_sz){
            DP[0][i+1] = b[i]-'0';
        }
        
        
        
        
        DP[0][0]=0;
        REP(i,a_sz){
            REP(j,b_sz){
                int x = i+1, y = j+1;
                if(DP[x-1][y]==1&&DP[x][y-1]==1){
                    DP[x][y]=0;
                }
                else{
                    DP[x][y]=1;
                }
            }
        }
        
        
        
        
        
        REP(i,a_sz+1){
            REP(j,b_sz+1){
                cout<<DP[i][j]<<" ";
            }
            cout<<"\n";
        }
        
//        int q = sI();
//        string ans="";
//        while(q--){
//            int x = sI(), y = sI();
//            ans+=to_string(DP[y][x]);
////            string temp;
////            temp+= DP[y][x];
//
//        }
//        cout<<ans<<"\n";

        
    }
    return 0;
}

//REP(i,b_sz){
//    REP(j,a_sz){
//        int x = i+1, y = j+1;
//        string temp="";
//        if(x==y){
//            temp = to_string(a_ans[0]);
//        }
//        else if(x>y){
//            temp = to_string(b_ans[x-y]);
//            if(temp=="0"){
//                if(x-y+1<a_sz){
//                    if(b_ans[x-y+1]==0){
//                        temp='1';
//                    }
//                }
//            }
//        }
//        else{
//            temp = to_string(a_ans[y-x]);
//            if(temp=="0"){
//                if(y-x+1<b_sz){
//                    if(a_ans[y-x+1]==0){
//                        temp='1';
//                    }
//                }
//            }
//        }
//        cout<<temp<<" ";
//
//    }
//    cout<<"\n";
//}