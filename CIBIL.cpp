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



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = sI();
    
    
    
    REP(i,t){
        vector< pair<pair<pair<int,int>,string>,int> >vec;
        int n = sI();
        REP(i,n){
            string s;
            cin>>s;
//            cout<<s<<"\n";
            int cib = sI(), risk = sI();
            string temp="";
            for(auto x:s){
                
                char c ='a' +'z' - x;
                if(x<'a'){
                    c = 'A' + 'Z' - x;
                }
                temp+=c;
            }
//            cout<<temp<<" is temp\n";
            vec.push_back (make_pair(make_pair(make_pair(-cib,risk),temp),i));
            
        }
        sort(vec.begin(),vec.end());
//        for(auto x: vec){
//            int cib = x.first.first.first;
//            int risk = x.first.first.second;
//            string t = x.first.second;
//            string temp="";
//            for(auto x:t){
//
//                char c ='a' +'z' - x;
//                if(x<'a'){
//                    c = 'A' + 'Z' - x;
//                }
//                temp+=c;
//            }
//            cout<<temp<<" "<<cib<<" "<<" "<<risk<<" "<<x.second<<"\n";
//        }
//
        
        int k = sI();
        k--;
        int cib = vec[k].first.first.first;
        int risk = vec[k].first.first.second;
        string t = vec[k].first.second;
        string temp="";
        for(auto x:t){
            
            char c ='a' +'z' - x;
            if(x<'a'){
                c = 'A' + 'Z' - x;
            }
            temp+=c;
        }
        cout<<temp<<" "<<-cib<<" "<<"\n";
    }
    
    
    return 0;
}

