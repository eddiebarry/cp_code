#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <set>
#define ll long long
#define intpair pair<int,int>
#define MP(i,j) make_pair(i,j)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;
int sI(){
    register int c = getchar();
    bool flag = true;
    if(c=='-'){
        flag =false;
        c = getchar();
    }
    int n = 0;
    for( ; (c<48 || c>57); c = getchar() );
    for( ; (c>47 && c<58); c = getchar() ){
        n = (n<<1) + (n<<3) +c -48;
    }
    if(flag){
        return n;
    }
    else{
        return n*-1;
    }
}

//bool primeFactors(int n)
//{
//    // Print the number of 2s that divide n
//    set<int> fact;
//    multiset<int> fact_i;
//    while (n%2 == 0)
//    {
//        fact.insert(2);
//        fact_i.insert(2);
//        n = n/2;
//    }
//
//    // n must be odd at this point.  So we can skip
//    // one element (Note i = i +2)
//    for (int i = 3; i <= sqrt(n); i = i+2)
//    {
//        // While i divides n, print i and divide n
//        while (n%i == 0)
//        {
//            fact.insert(i);
//            fact_i.insert(i);
////            printf("%d ", i);
//            n = n/i;
//        }
//    }
//
//    // This condition is to handle the case when n
//    // is a prime number greater than 2
//    if (n > 2){
//        fact.insert(n);
//        fact_i.insert(n);
//    }
//
//    return fact.size() == fact_i.size() && fact_i.size()==4;
//
//}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = sI();
    
    vector<int> primes;
    
    FOR(j,2,201,1){
        bool flag = true;
        for(int i = 2; i * i <= j; i++){
            if(j%i==0){
                flag = false;
            }
        }
        if(flag){
            primes.push_back(j);
        }
    }
    
    set<int> semi_primes;
    int sz = primes.size();
    
    REP(i,sz){
        REP(j,sz){
            if(i==j){
                continue;
            }
            int x = primes[i]*primes[j];
            semi_primes.insert(x);
        }
    }
    
    
    
    
    while(t--){
        int x = sI();
        bool flag =  false;
        for(auto z : semi_primes){
            if(semi_primes.find(x - z)!=semi_primes.end()){
                flag =  true;
                break;
            }
        }
        if(flag){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

    }
    
    
    
    
    
    
    
    
    
    return 0;
}



