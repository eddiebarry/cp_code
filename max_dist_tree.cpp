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

int main(){
    int n  = sI(), t =  sI();
    int arr[n];
    REP(i,n){
        arr[i]=0;
    }
    int adj_mat[n][n];
    int start, end;
    int min = INF;
    if(t==1){
        REP(i,n){
            REP(j,n){
                int x = sI();
                adj_mat[i][j]=x;
                if(i==j){
                    adj_mat[i][j]=INF;
                }
                if(adj_mat[i][j]<min){
                    min = x;
                    start = i;
                    end = j;
                }
            }
        }
    }
    else if(t==2){
        REP(i,n){
            REP(j,n){
                int x = sI();
                double temp = x/1000000.0;
                temp = 1.0 - temp;
                temp*=x;
                adj_mat[i][j]=temp;;
                if(i==j){
                    adj_mat[i][j]=INF;
                }
                if(adj_mat[i][j]<min){
                    min = x;
                    start = i;
                    end = j;
                }
            }
        }
    }
    else{
        REP(i,n){
            REP(j,n){
                int x = sI();
                double temp = x/1000000.0;
                temp = 1.0 - temp;
                temp*=x;
                temp*=temp;
                adj_mat[i][j]=temp;;
                if(i==j){
                    adj_mat[i][j]=INF;
                }
                if(adj_mat[i][j]<min){
                    min = x;
                    start = i;
                    end = j;
                }
            }
        }
    }

//    REP(i,n){
//        REP(j,n){
//            cout<<adj_mat[i][j]<<"\n";
//        }
//    }
    
    
    string ans = "";
    ans+= to_string(start+1);
    ans+=" ";
    ans+= to_string(end+1);
    ans+="\n";
    int v = n-2;
    arr[start]=1,arr[end]=1;
    while(v--){
        //find shortest path from start not already marked
        int min_str = INF;
        int min_end = INF;
        int str_cand, end_cand;
        REP(i,n){
            if(arr[i]==0 && adj_mat[start][i] < min_str){
                min_str = adj_mat[start][i];
                str_cand = i;
            }
        }
        REP(i,n){
            if(arr[i]==0 && adj_mat[end][i] < min_end){
                min_end = adj_mat[end][i];
                end_cand = i;
            }
        }
        if(min_end<min_str){
            ans+= to_string(end+1);
            ans+=" ";
            ans+= to_string(end_cand+1);
            ans+="\n";
            end = end_cand;
            arr[end_cand]=1;
        }
        else{
            ans+= to_string(start+1);
            ans+=" ";
            ans+= to_string(str_cand+1);
            ans+="\n";
            start = str_cand;
            arr[str_cand] = 1;
        }
    }
    
    cout<<ans;
}
