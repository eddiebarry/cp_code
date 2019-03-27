#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <cmath>
#include <iomanip>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
#define fenwick_tree_dt long long
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

class BIT{
public:
    //initialise in O(n)
    BIT(vector<fenwick_tree_dt> arr){
        tree = vector<fenwick_tree_dt>(arr.size()+1,0);
        for(long long idx = 0; idx < arr.size(); idx++ ){
            tree[idx+1] = arr[idx];
        }
        for(long long idx = 1; idx < tree.size(); idx++ ){
            long long temp = (idx&-idx) + idx;
            if(temp < tree.size() ){
                tree[temp] +=tree[idx];
            }
        }
    }
    //only works for range sum with updates
    fenwick_tree_dt prefix_query(long long idx){
        fenwick_tree_dt result = 0;
        for(++idx; idx > 0; idx -= idx&-idx){
            result+=tree[idx];
        }
        return result;
    }
    //this operation will not give correct values for range updates
    fenwick_tree_dt range_query(long long from, long long to){
        return prefix_query(to) - prefix_query(from-1);
    }
    //gives correct for range updates
    fenwick_tree_dt point_query(long long idx){
        return prefix_query(idx) - prefix_query(idx-1);
    }
    //updates the value by add
    void update(long long idx , fenwick_tree_dt add){
        for(++idx; idx < tree.size(); idx+=idx & -idx){
            tree[idx] +=add;
        }
    }
    
private:
    vector<fenwick_tree_dt> tree;
};

int main(){
    int t = sI();
    REP(i,t){
        int n = sI();
        int arr[n];
        REP(i,n){
            arr[i]=sI();
        }
        long forward_sum[n];
        long backward_sum[n];
        forward_sum[0] = arr[0];
        backward_sum[n-1] = arr[n-1];
        REP(i,n-1){
            forward_sum[i+1] = arr[i+1] + forward_sum[i];
            backward_sum[n-2-i] = arr[n-2-i] + backward_sum[n-1-i];
        }
//        REP(i,n){
//            cout<<forward_sum[i]<<" ";
//        }
//        cout<<"\n backward sum si\n";
//        REP(i,n){
//            cout<<backward_sum[i]<<" ";
//        }
//        cout<<"\n\n";
        set <long long> forward_set, backward_set;
        unordered_map<long ,int> forward_map, backward_map;
        REP(i,n){
            forward_set.insert(forward_sum[i]);
            forward_map[forward_sum[i]] = i;
            
            backward_set.insert(backward_sum[i]);
            backward_map[backward_sum[i]] = i;
        }
        vector<long long> ans(n);
        BIT bit(ans);
        REP(i,n){
//            cout<<"\n\\n\n\n i is "<<i<<"\n";
            long forward_search_term = forward_sum[i] + arr[i];
//            cout<<"for war search term is "<<forward_search_term<<"\n";
            auto itr = forward_set.upper_bound(forward_search_term);
            if(itr!=forward_set.end()){
                //ans[i] = forward_map[forward_search_term] - i;
//                cout<<"index to update is "<<forward_map[*itr]<<"\n";
                bit.update(i+1,1);
                bit.update(forward_map[*itr]+1,-1);
            }
            else{
                --itr;
                bit.update(i+1,1);
//                cout<<"index to update is "<<forward_map[*itr]<<" from i\n";
                bit.update(forward_map[*itr]+1,-1);
            }
            //
            long backward_search_term = backward_sum[i] + arr[i];
            
//            cout<<"back war search term is "<<backward_search_term<<"\n";
            itr = backward_set.upper_bound(backward_search_term);
            if(itr!=backward_set.end()){
//                ans[i]-= backward_map[*itr] - i;
//                cout<<"index to update is "<<backward_map[*itr]<<" to i\n";
                bit.update(backward_map[*itr],1);
                bit.update(i,-1);
            }
            else{
                --itr;
                
//                cout<<"index to update is "<<backward_map[*itr]<<" to i\n";
                bit.update(backward_map[*itr],1);
                bit.update(i,-1);
            }
            
        }
        REP(i,n){
            cout<<bit.prefix_query(i)<<" ";
        }
        cout<<"\n";
    }
}

