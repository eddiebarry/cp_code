#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
#define sqrt_dt long
# define INF 0x3f3f3f3f
using namespace std;

int main(){
    long long t;
    cin>>t;
    REP(i,t){
//        cout<<endl;
        long long n, k,v;
        cin>>n>>k>>v;
//        cout<<n<<" "<<k<<" "<<v<<"\n";
        long long temp = ((v-1)*k)%n;
//        cout<<"temp is "<<temp<<"\n";
        vector<string> vec;
        REP(i,n){
            string s;
            cin>>s;
            vec.push_back(s);
        }
//        for(auto x:vec){
//            cout<<x<<"  ";
//        }
        
        set< pair<int,string> >s;
        REP(i,k){
            s.insert(make_pair((temp+i)%n,vec[(temp+i)%n]));
        }
        cout<<"Case #"<<i+1<<": ";
        for(auto x:s){
            cout<<x.second<<" ";
        }
        cout<<endl;
        
    }
}
