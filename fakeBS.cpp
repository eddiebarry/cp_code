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
long long sI(){
    long long c = getchar_unlocked();
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
int FAKEBS(vector<int> &vec, int idx , int X, int x, int sz){
    int ans = 0;
    int low = 1, high = sz;
    int left_swaps = 0,right_swaps = 0;
    while(low<=high){
        int mid = (low+high)/2;
//        mid--;
//        cout<<mid<<"\n";
        if(mid==idx+1){
            break;
        }
        else if(mid <idx+1){//need to move right
            if(vec[mid-1]>vec[idx]){
                right_swaps++;
            }
            low = mid+1;
            x--;
        }
        else{
            if(vec[mid-1]<vec[idx]){
                left_swaps++;
            }
            high = mid-1;
            X--;
        }
    }
    int larger = right_swaps > left_swaps? right_swaps:left_swaps;
    int smaller = right_swaps < left_swaps? right_swaps:left_swaps;
    
    ans+=larger;
    
    if(x<0||X<0){
        return -1;
    }
    else{
        return ans;
    }
    
}




int main(){
    int t = sI();
    REP(i,t){
        int n=sI(),q=sI();
        vector<int>vec(n);
        vector<int>sortVec(n);
        unordered_map<int,int>map;
        REP(i,n){
            vec[i]=sI();
            sortVec[i]=vec[i];
            map[vec[i]]=i;
        }
        sort(sortVec.begin(), sortVec.end() );
        REP(i,q){
            int x = sI();
            auto it = lower_bound(sortVec.begin(),sortVec.end(),x);
            int idx = it - sortVec.begin();
            int larger_than = n - idx - 1;
            int smaller_than = idx;
            cout<<FAKEBS(vec,map[x],larger_than,smaller_than,n)<<"\n";
        }
        
    }
}
