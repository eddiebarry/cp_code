
#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<algorithm>
#include<climits>
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
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
long long sLL(){
    long long c = getchar_unlocked();
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
long long sum_to(int start, int end, long long arr[]){
    return start==0?arr[end]:arr[end]-arr[start-1];
}

int main(){
    long n = sI();
    long long k = sLL();
//    cin>>k;
    int arr[n];
    REP(i,n){
        arr[i]=sI();
    }
    vector<long long> sum(n);
    sum[0]=arr[0];
    REP(i,n-1){
        sum[i+1]=arr[i+1]+sum[i];
    }
    unordered_map<long long, int>freq;
    unordered_map<long long, int>left;
    unordered_map<long long, int>right;
    int prev = 0;
    REP(i,n){
        freq[sum[i]]++;
        if(prev==sum[i]){
            right[sum[i]]=i;
        }
        else{
            left[sum[i]]=i;
            right[sum[i]]=i;
        }
        prev=sum[i];
    }
    int max_sz = -1;
    int ans = 0;
    for(int i = lower_bound(sum.begin(), sum.end(), k) - sum.begin(); i < n; i++){
//        if(binary_search(sum.begin(), sum.end(), sum[i]-k)){
//            ans += freq[sum[i]]*freq[sum[i]-k];
//
//            int sz = right[sum[i]] - left[sum[i]-k] + 1;
//            if(sz>max_sz){
//                max_sz = sz;
//            }
//        }
        int to_search = sum[i]-k;
        if(to_search==0){
            ans+=1;
            int sz = right[sum[i]] + 1;
            if(sz>max_sz){
                max_sz = sz;
            }
        }
        else{
            if(binary_search(sum.begin(), sum.end(), sum[i]-k)){
                ans += freq[sum[i]-k];
            
                int sz = right[sum[i]] - left[sum[i]-k] + 1;
                if(sz>max_sz){
                    max_sz = sz;
                }
            }
        }
    }
    cout<<ans<<" "<<n-max_sz;
}
