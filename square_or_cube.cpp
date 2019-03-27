#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <cmath>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
#define MAXN   100001
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
    for( ; (c>47 && c<58); c = getchar_unlocked() );
    
}

//void SieveOfEratosthenes(int n, vector <int> &vec)
//{
//    // Create a boolean array "prime[0..n]" and initialize
//    // all entries it as true. A value in prime[i] will
//    // finally be false if i is Not a prime, else true.
//    bool prime[n+1];
//    memset(prime, true, sizeof(prime));
//
//    for (int p=2; p*p<=n; p++)
//    {
//        // If prime[p] is not changed, then it is a prime
//        if (prime[p] == true)
//        {
//            // Update all multiples of p
//            for (int i=p*2; i<=n; i += p)
//                prime[i] = false;
//        }
//    }
//
//    // Print all prime numbers
//    for (int p=2; p<=n; p++)
//        if (prime[p])
//            vec.push_back(p);
//}




// stores smallest prime factor for every number
int spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
    
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
    
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
                
                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
void getFactorization(int x, unordered_map<int,int> &map)
{
    vector<int> ret;
    while (x != 1)
    {
        if(map.find(spf[x])==map.end()){
            map[spf[x]]=1;
        }
        else{
            map[spf[x]]++;
        }
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
}

//// driver program for above function
//int main(int argc, char const *argv[])
//{
//    // precalculating Smallest Prime Factor
//    sieve();
//    int x = 12246;
//    cout << "prime factorization for " << x << " : ";
//
//    // calling getFactorization function
//    vector <int> p = getFactorization(x);
//
//    for (int i=0; i<p.size(); i++)
//        cout << p[i] << " ";
//    cout << endl;
//    return 0;
//}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int n  = sI(), q = sI();
    vector<int> vec;
    unordered_map<int, int> map[n];
    REP(i,n){
        if(i!=0){
//            cout<<"\n\n\n\n\n\n\n";
            for(auto x: map[i-1]){
//                cout<<x.first<<" is x.first "<<x.second<<" is x.second \n";
                map[i][x.first] = x.second;
            }
        }
        vec.push_back(sI());
        int temp = vec[i];
        if(temp<0){
            temp*=-1;
            map[i][-1]++;
        }
        if(temp==0){
            map[i][0]++;
            continue;
        }
        getFactorization(temp,map[i]);
    }
    
    
    REP(i,q){
        int l = sI(), r = sI();
        l--, r--;
        l--;
        bool square = true, cube = true;
        if(l!=-1){
            for(auto x : map[r]){
                long temp;
                if(map[l].find(x.first)!=map[l].end()){
                    temp = x.second - map[l][x.first];
                }
                else{
                    temp = x.second;
                }
                if(temp%2!=0){
                    square = false;
                }
                if(temp%3!=0&&x.first!=-1){
                    cube = false;
                }
                if(x.first==0){
                    square=false;
                    cube = false;
                }
            }
        }
        else{
            for(auto x : map[r]){
                long temp = x.second;
                if(temp%2!=0){
                    square = false;
                }
                if(temp%3!=0 && x.first!=-1){
                    cube = false;
                }
                if(x.first==0){
                    square=false;
                    cube = false;
                }
            }
        }
        
        if(cube&&square){
            cout<<"Both\n";
        }
        else if(cube){
            cout<<"Cube\n";
        }
        else if(square){
            cout<<"Square\n";
        }
        else{
            cout<<"None\n";
        }
    }
    return 0;
}
