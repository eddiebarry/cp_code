#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <set>
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = sI();
    int b = sI();
    
    multiset< pair<pair<double, int>, int> > classes;
    
    REP(i,n){
        int num = sI();
        
        classes.insert(make_pair(make_pair(num,num),1));
        
    }
    
    REP(i,b-n){
        auto it = classes.rbegin();
        
        pair<pair<double, int>, int> temp = (*it);
        
        double cakes_per = (*it).first.first;
        
        int students = (*it).first.second;
        
        int cake = (*it).second;
        
        
        classes.erase(classes.lower_bound(temp));
        
        
        cake++;
        
        cakes_per = (students*1.0/cake);
        
        
        classes.insert(make_pair(make_pair(cakes_per,students),cake));
        
    }
    auto it = classes.rbegin();
    cout<<ceil((*it).first.first)<<"\n";
    
    return 0;
}

