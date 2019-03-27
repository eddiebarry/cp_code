#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<list>
#include<climits>
#include<algorithm>
#include <fstream>
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define pp pair< int , pair< int,int > >
using namespace std;
int sI(){
    int c;
    cin>>c;
    return c;
}


int main()
{
    int n = sI(), m = sI();
    srand(2);
    ofstream myfile;
    myfile.open ("in26.txt");
    myfile<<n<<" "<<m<<"\n";
    REP(i,n){
        REP(i,m){
            int x=rand();
//            cout<<x<<" ";
            if(x%10<=9){
                myfile<<"O";
            }
            else{
                myfile<<"X";
            }
        }
//        cout<<"\n";
        myfile<<"\n";
    }
    
    myfile.close();
    return 0;
}

