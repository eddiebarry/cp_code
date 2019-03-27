#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
#include <cmath>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;
int sI(){
    register int c = getchar_unlocked();
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
void s1(){
    register int c = getchar_unlocked();
    for( ; (c<48 || c>57); c = getchar_unlocked() );
    for( ; (c>47 && c<58); c = getchar_unlocked() );}


void perform_swap(int n, int i,vector<int>vec,unordered_map<string,int> &map){
    if(i<n){
        REP(j,n){
            //swap j and n, call funtion
            int temp = vec[i];
            vec[i]=vec[j];
            vec[j]=temp;
            perform_swap(n,i+1,vec,map);
            temp = vec[i];
            vec[i]=vec[j];
            vec[j]=temp;
        }
    }
    else{
        string t="";
        for(auto x:vec){
            //            cout<<x<<" ";
            t+=to_string(x);
            t+=" ";
        }
        //        cout<<"\n";
        map[t]++;
    }
}


void swap(int n,unordered_map<string,int> &map, long long &min, long long &max, string &mx, string &mn){
    
    vector<int>vec;
    REP(i,n){
        vec.push_back(i+1);
    }
    REP(j,n){
            //swap j and n, call funtion
        int i = rand()%n;
        int temp = vec[i];
        vec[i]=vec[j];
        vec[j]=temp;
    }
    
    string t="";
    for(auto x:vec){
            //            cout<<x<<" ";
        t+=to_string(x);
        t+=" ";
    }
        //        cout<<"\n";
    map[t]++;
    int x = map[t];
    if(x>max){
        max = x;
        mx = t;
    }
    if(x<min){
        min = x;
        mn = t;
    }
}





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>vec;
    int n = sI();
    if(n==1){
        cout<<1;
    }
    else if(n%2==1){
        REP(i,n/2 - 1){
            vec.push_back(i+2);
        }
        vec.push_back(1);
        int last = n/2;
        REP(i,n/2){
            vec.push_back(last+i+2);
        }
        vec.push_back(last+1);
        for(auto x: vec){
            cout<<x<<" ";
        }
    }
    else{
        REP(i,n/2 -1){
            vec.push_back(i+2);
        }
        vec.push_back(1);
        int last = n/2;
        REP(i,n/2-1){
            vec.push_back(last+i+2);
        }
        vec.push_back(last+1);
        for(auto x: vec){
            cout<<x<<" ";
        }
    }
    cout<<"\n";
    cout<<n<<" ";
    REP(i,n-1){
        cout<<i+1<<" ";
    }
    
//    vector<int>ve;
//
//    REP(i,n){
//        ve.push_back(i+1);
//    }
//    unordered_map<string,int> map;
//    perform_swap(n,0,ve,map);
//
//    long long max = -1, min = 1e18;
//    string mx,mn;
//    for(auto x: map){
//        cout<<x.first<<" "<<x.second<<"\n";
//        if(x.second>max){
//            max = x.second;
//            mx = x.first;
//        }
//        if(x.second<min){
//            min = x.second;
//            mn = x.first;
//        }
//    }
//    cout<<"\n"<<mx<<"\n"<<mn<<"\n";
//////    cout<<max<<" is the first iter "<<min<<"\n";
////    cout<<map[mx]<<" is the freq "<<map[mn]<<"\n";
//
//    unordered_map<string,int> mp;
//    max = -1, min = 1e18;
//    REP(i,1e8){
//        swap(n,mp,min,max,mx,mn);
//    }
//    cout<<mx<<"\n"<<mn;
//    cout<<max<<" "<<min<<"\n";
//    cout<<map[mx]<<" "<<map[mn]<<"\n";
    return 0;
}
