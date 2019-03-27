#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<list>
#include<math.h>
#include<limits>
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;
typedef std::numeric_limits< double > dbl;

int sI(){
    int c;
    cin>>c;
    return c;
}
int mod(int a){return a<0?-a:a;}
int main(){
    int n = sI(), m = sI();
    vector< vector <int>  > matrix(n, vector<int>(m));
    REP(i,n){
        REP(j,m){
            matrix[i][j]=sI();
        }
    }
    long long ans = 0;
    REP(i,n*m){
        REP(j,n*m){
            if(i==j){
                continue;
            }
            int i_x = i/n, i_y = i%m;
            int j_x = j/n, j_y = j%m;
            if(i_x==0||j_x==0||i_x==m-1||j_x==m-1){
                continue;
            }
            if(i_y==m-1||j_y==m-1||i_y==0||j_y==0){
                continue;
            }
            if(mod(i_x-j_x)+mod(i_y-j_y)>=3){
                long long temp = 0;
                temp+= matrix[i_x][i_y]*matrix[j_x][j_y];
                temp+= matrix[i_x-1][i_y]*matrix[j_x-1][j_y];
                temp+= matrix[i_x+1][i_y]*matrix[j_x+1][j_y];
                temp+= matrix[i_x][i_y-1]*matrix[j_x][j_y-1];
                temp+= matrix[i_x][i_y+1]*matrix[j_x][j_y+1];
                if(temp>ans){
                    ans = temp;
                }
            }
        }
    }
    cout<<ans<<"\n";
}
