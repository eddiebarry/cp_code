#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>
#include <iomanip>
#define FOR(i, j, k, in) for (long long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define sqrt_dt long long
#define MOD 1000000007
using namespace std;

long long sI(){
    long long c;
    cin>>c;
    return c;
}

bool tri(multiset<long long> &s){
    auto it = s.begin();
    long long c = *it++;
    long long b = *it++;
    long long a = *it++;
    return ( (a >= b-c) && (a <=b+c) );
}

int main(){
    long long n = sI();
    vector <long long> arr(n);
    multiset<long long> max;
    multiset<long long> set;
    REP(i,n){
        arr[i]=sI();
    }
    
    
    long long ans = 0;
    ans+= 2*n -1;
    
    long long start = 0;
    long long end = start+2;
    bool flag = true;
    if(n>2){
        set.insert(arr[0]);
        set.insert(arr[1]);
        
        while(flag){
            //find largest in range
            //find 2 smallest
            //        cout<<"\n";
            //        FOR(i,start,end+1,1){
            //            cout<<arr[i]<<" ";
            //        }
            //        cout<<"\n";
            auto largest = set.rbegin();
            auto smallest = set.begin();
            auto temp = smallest;
            auto sec_smal = ++temp;
            //        cout<<*largest<<" "<<*smallest<<" "<<*sec_smal<<"\n";
            //        long long temp_tri = 0;
            
            //check if it meets bounds
            if(arr[end]<= *smallest + *sec_smal && arr[end] >= *largest - *smallest){
                set.insert(arr[end]);
                end++;
                //            cout<<"end has been increase\n\n";
                if(end==n){
                    long long x = end - start;
                    ans += (x-2)*(x-1)/2;
                    break;
                }
                //if yes, update end
            }
            else{
                //if not, update start
                set.erase(set.find(arr[start]));
                if(end - start> 2){
                    ans+= end-start-2;
                }
                start++;
                //            cout<<"start has been increase\n\n";
                //            temp_tri--;
                if(start == n-1){
                    break;
                }
            }
            if(end-start<=1){
                set.insert(arr[end]);
                end++;
                //            cout<<"diff was less than 2\n\n";
            }
        }
    }
    
    
    
    
    cout<<ans<<"\n";
}

