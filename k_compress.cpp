//
//  sqrt_decomposition_tree.cpp
//
//  Created by Edgar Monis.
//  range max in O(srt(n))
//  update in O(srt(n))
//  0 indexed
//
//  update sqrt_dt with needed data type

#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<list>
#include<climits>
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define pp pair< long long , pair< long long,long long > >
#define sqrt_dt long long

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

class sqrt_tree{
private:
    long num;
    long blk_sz;
    vector <sqrt_dt>  arr;
    vector <sqrt_dt>  sqr_arr;
public:
    sqrt_tree(long long sz){
        num = sz;
        blk_sz = sqrt(num);
        //initialising sqrt block
        long long curr_block = -1;
        for(long i = 0; i < num; i++){
            if(i%blk_sz==0){
                curr_block++;
                sqr_arr.push_back( 0 );
            }
            arr.push_back( 0 );
            if(sqr_arr[curr_block] > 0 ){
                sqr_arr[curr_block] = 0 ;
            }
        }
    }
    
    sqrt_dt query(long l , long r){
        l--;
        r--;
        
        sqrt_dt  temp = arr[l];
        while(l<r && l%blk_sz!=0 && l!=0){
            if(arr[l]  > temp ){
                temp = arr[l];
            }
            l++;
        }
        while(l+blk_sz<=r){
            if(sqr_arr[l/blk_sz] > temp ){
                temp = sqr_arr[l/blk_sz];
            }
            l+=blk_sz;
        }
        while(l<=r){
            if(arr[l] > temp ){
                temp = arr[l];
            }
            l++;
        }
        return temp;
    }
    
    void update(long idx, sqrt_dt data){
        arr[idx] = data ;
        long start = (idx/blk_sz)*blk_sz;
        long end = start + blk_sz > num ? num : start + blk_sz;
        sqr_arr[idx/blk_sz] = arr[start];
        for(long i = start; i <end; i++){
            if(sqr_arr[idx/blk_sz] < arr[i] ){
                sqr_arr[idx/blk_sz] = arr[i];
            }
        }
    }
    
    long long get_score(){
        long long ans = 0;
        for(long i = 0; i < num; i++){
            ans +=arr[i];
        }
        return ans;
    }
//
    void print_arr(){
        for(auto x:arr){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
//
};


long long max(long long a, long long b){return a<b?b:a;}
long long min(long long a, long long b){return a<b?a:b;}

long long calc_score(vector<long long>&vec, long long size_bound, long long sz){
    //created a sorted list
    vector< pair <long long,long long> >sorted;
    REP(i,sz){
        sorted.push_back(make_pair(vec[i],-(i+1)));
    }
    sort(sorted.begin(),sorted.end());
    
    //create a sqrt tree
    sqrt_tree tr(sz);
    sqrt_tree nums(sz);
    for(auto x: sorted){
        long long num = x.first;
//        num--;
        long long idx = -x.second;
//        cout<<"num to be inserted is "<<num<<" idx is "<<idx<<"\n";
        long long upper_bound = min(sz, idx + size_bound);
        long long lower_bound = max(1, idx - size_bound);
//        cout<<upper_bound<<" is ub "<<lower_bound<<" is l_b\n";
        
        long long max_num = tr.query(lower_bound,upper_bound);
        long long max_num_stored = nums.query(lower_bound,upper_bound);
//        cout<<max_num<<" is the max num in range \n";
        if(num>max_num_stored){
            tr.update(idx-1, max_num+1);
            nums.update(idx-1, num);
        }
        else{
            tr.update(idx-1,max_num);
            nums.update(idx-1,num);
        }
//        cout<<"after update array is \n";
//        tr.print_arr();
//        cout<<"\n";
    }
    
//    tr.print_arr();
//    cout<<"\n\n\n\nn\n";
    return tr.get_score();
}


int main(){
    long long t = sI();
    REP(i,t){
        long long n = sI(), s = sI();
        vector<long long>vec(n);
        REP(i,n){
            vec[i] = sI();
            vec[i]++;
        }
        if(s<n){
            cout<<0<<"\n";
            continue;
        }
//        long long ans = 0;
//        REP(i,n+1){
//            if(calc_score(vec,i,n)<=s){
//                ans++;
//            }
//            else{
//                break;
//            }
//        }
//        cout<<ans<<"\n";
        int low = 0, high = n,med;
        long long x;
        while (high-low>1) {
            med = high+low;
            med /=2;
            x = calc_score(vec,med,n);
            if(x<=s){
                low = med;
            }
            else{
                high = med;
            }
        }
        if(calc_score(vec,high,n)<=s){
            cout<<high+1<<"\n";
        }
        else{
            cout<<low+1<<"\n";
        }
    }
}
















//long long n = 100;
//vector<long>vec;
//for(long long i = 0 ; i< 100; i++){
//    vec.push_back(1);
//}
//sqrt_tree tr(vec);
//cout<<tr.query(1,100)<<" ia the max \n";
//tr.update(1,1000);
//cout<<" index has been updated\n";


//        sqr = num/sqrt(num);
//        for(auto x: vec){
//            arr.push_back(x);
//        }
//        for(long i = 0; i <sqr; i++){
//            sqr_arr.push_back(0);
//        }
//        if(sqr*sqr!=num){
//            sqr_arr.push_back(0);
//        }
//        //assigning mx to the sqrt cells
//        for(long i = 0; i < num; i++){
//            if(vec[i] > sqr_arr[i/sqr]){
//                sqr_arr[i/sqr] = vec[i];
//            }
//        }
//    }
//    void update(long idx, sqrt_dt a){
//        arr[idx] = a;
//        long start = (idx/sqr) *sqr;
//        long end   = start+sqr < num ? start + sqr : num;
//        for(long i = (idx/sqr) *sqr; i %sqr != 0; i++){
//            if(vec[i] > sqr_arr[i/sqr]){
//                sqr_arr[i/sqr] = vec[i];
//            }
//        }
//    }


