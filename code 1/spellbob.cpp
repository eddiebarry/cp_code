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
    int t = sI();
    REP(i,t){
        string a,b;
        cin>>a>>b;
        REP(z,8){
            int i = z;
            int arr[3];
            REP(j,3){
                arr[j] = i%2;
                i/=2;
            }
            
            string temp = "";
            REP(i,3){
                if(arr[i]==1){
                    temp+=a[i];
                }
                else{
                    temp+=b[i];
                }
            }
            int num_b = 0, num_o = 0;
            REP(i,3){
                if(temp[i]=='b'){
                    num_b++;
                }
                if(temp[i]=='o'){
                   num_o++;
                }
            }
            if(num_b==2&&num_o==1){
                cout<<"yes\n";
                goto label;
            }
                   
        }
        cout<<"no\n";
                   
        label:{
                       
        }
    }
}
