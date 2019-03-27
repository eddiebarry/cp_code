#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<climits>
#include<stdlib.h>
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
int main(){
    string ip_filename = string("sam22.txt");
    ifstream fil1;
    fil1.open(ip_filename.c_str());
    
    int n, m;
    fil1>>n;
    fil1>>m;
    
    //creating substrings
    string sub[m/n];
    
    string s;
    fil1>>s;
    
    ofstream myfile;
    myfile.open ("opsam22.txt");
    
    REP(i,m){
        sub[i/n]+=s[i];
    }
    string ans = "";
    
//    REP(i,m/n){
//        cout<<sub[i]<<"\n";
//    }
    for(int i = 2*((m/n)/2) ; i >=2 ; i-=2){
        ans+=sub[i-1];
//        cout<<i<<" ";
    }
    ans+=sub[0];
    for(int i = 3 ; i <= m/n ; i+=2){
        ans+=sub[i-1];
//        cout<<i<<" ";
    }
    myfile<<ans;
    
}
