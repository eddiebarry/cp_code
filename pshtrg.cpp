#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
#define sqrt_dt long
using namespace std;

long sI(){
    long c = getchar_unlocked();
    bool flag = true;
    if(c=='-'){
        flag =false;
        c = getchar_unlocked();
    }
    long n = 0;
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

bool is_tr(long a, long b, long c){
    return a + b > c && a + c > b && c + b > a;
}



////////////////////////////////////////////////
class sqrt_tree{
private:
    long num;
    long blk_sz;
    vector < pair<sqrt_dt, long > > arr;
    vector < pair<sqrt_dt, long > > sqr_arr;
public:
    sqrt_tree( vector<sqrt_dt> & vec){
        num = vec.size();
        blk_sz = sqrt(num);
        //initialising sqrt block
        int curr_block = -1;
        for(long i = 0; i < num; i++){
            if(i%blk_sz==0){
                curr_block++;
                sqr_arr.push_back( make_pair( vec[i] , i ) );
            }
            arr.push_back( make_pair( vec[i] , i ) );
            if(sqr_arr[curr_block].first < vec[i] ){
                sqr_arr[curr_block] = make_pair( vec[i] , i ) ;
            }
        }
    }
    pair<sqrt_dt, long >query(long l , long r){
        pair < sqrt_dt, long > temp = arr[l];
        while(l<r && l%blk_sz!=0 && l!=0){
            if(arr[l].first>temp.first){
                temp = arr[l];
            }
            l++;
        }
        while(l+blk_sz<=r){
            if(sqr_arr[l/blk_sz].first>temp.first){
                temp = sqr_arr[l/blk_sz];
            }
            l+=blk_sz;
        }
        while(l<=r){
            if(arr[l].first>temp.first){
                temp = arr[l];
            }
            l++;
        }
        return temp;
    }
    
    void update(long idx, sqrt_dt data){
        arr[idx] = make_pair( data, idx);
        long start = (idx/blk_sz)*blk_sz;
        long end = start + blk_sz > num ? num : start + blk_sz;
        sqr_arr[idx/blk_sz] = arr[start];
        for(long i = start; i <end; i++){
            if(sqr_arr[idx/blk_sz].first < arr[i].first){
                sqr_arr[idx/blk_sz] = arr[i];
            }
        }
    }
    
    
};


















int main(){
    long n = sI() , q = sI();
    vector<long> arr(n);
    REP(i,n){
        arr[i] = sI();
    }
    //queries
    sqrt_tree tree(arr);
    REP(i,q){
        long dec = sI();
        if(dec == 1){
            //subtracting current value
            long idx = sI();
            long x = sI();
            idx--;
            tree.update(idx,x);
            
        }
        else{
            long l = sI(), r  =sI();
            long ans = 0;
            long num = r-l;
            long suspects[3];
            long index[3];
            unordered_map<long,long>map;
            
            while(num>=2){
                REP(i,3){
                    pair<long,long> temp = tree.query(l-1,r-1);
                    suspects[i] = temp.first;
                    index[i] = temp.second;
                    //cout<<suspects[i]<<" "<<index[i]<<"\n";
                    tree.update(index[i],-1);
                }
                if(is_tr(suspects[0],suspects[1],suspects[2])){
                    ans = suspects[0] + suspects[1] + suspects[2];
                }
                map[index[0]]=suspects[0];
                REP(i,2){
                    tree.update(index[i+1],suspects[i+1]);
                }
                num--;
                if(ans!=0){
                    break;
                }
            }
            for(auto x: map){
                //cout<<x.first<<" "<<x.second<<"was considered \n";
                tree.update(x.first,x.second);
            }
            
            cout<<ans<<"\n";
        }
    }
}
