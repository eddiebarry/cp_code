#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#define FOR(i, j, k, in) for (long long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;
long long sI(){
    register long long c = getchar_unlocked();
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
long long sLL(){
    register long long c = getchar_unlocked();
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
    register long long c = getchar_unlocked();
    for( ; (c<48 || c>57); c = getchar_unlocked() );
    for( ; (c>47 && c<58); c = getchar_unlocked() );}
class BIT {
    // Implementation of a Binary Indexed Tree (Fennwick Tree)
public:
    /*BIT(std::vector<long long > list) {
     // Initialize BIT with list in O(n*log(n))
     m_array = std::vector<long long >(list.size() + 1, 0);
     for (long long idx = 0; idx < list.size(); idx++) {
     update(idx, list[idx]);
     }
     }*/
    
    BIT(std::vector<long long > list) {
        // Initialize BIT with list in O(n)
        m_array = std::vector<long long >(list.size() + 1, 0);
        for (long long idx = 0; idx < list.size(); idx++) {
            m_array[idx + 1] = list[idx];
        }
        
        for (long long idx = 1; idx < m_array.size(); idx++) {
            long long idx2 = idx + (idx & -idx);
            if (idx2 < m_array.size()) {
                m_array[idx2] += m_array[idx];
            }
        }
    }
    
    long long prefix_query(long long idx) {
        // Computes prefix sum of up to including the idx-th element
        long long result = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            result += m_array[idx];
        }
        return result;
    }
    
    long long range_query(long long from_idx, long long to_idx) {
        // Computes the range sum between two indices (both inclusive)
        return prefix_query(to_idx) - prefix_query(from_idx - 1);
    }
    
    void update(long long idx, long long add) {
        // Add a value to the idx-th element
        for (++idx; idx < m_array.size(); idx += idx & -idx) {
            m_array[idx] += add;
        }
    }
    
private:
    std::vector<long long > m_array;
};//fenwick tree



int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long s = sI(), x = sI(), n = sI();
    if(n==0){
        cout<<ceil(s*1.0/x);
        return 0;
    }
    
    vector< pair<long long ,long long > > vec;
    REP(i,n){
        int a = sI(), b = sI();
        vec.push_back(make_pair(a,b));
    }
    
    sort(vec.begin(),vec.end());
    
    long long idx = 0;
    long long current_day = 1;
    while(s>0){
        if(current_day==vec[idx].first){
            s -=vec[idx].second;
            idx++;
            if(idx==n){
                if(s>0)
                current_day += ceil(s*1.0/x);
                s = 0;
            }
        }
        else{
            //subtract untill next
            s -=x;
        }
        cout<<current_day<<" "<<idx<<" "<<s<<"\n";
        current_day++;

    }
    cout<<current_day;
    return 0;
}

//            long long next = vec[idx].first;
////            if(ceil(vec*1.0/x) < next){
////                ans -
////            }
//            //calc untill next
//            long long to_calc = next - idx;
//
//            to_calc*=x;
//
//            if(to_calc>s){
//                ans+= ceil(s/x);
//                s-= ceil(s/x)*x;
//            }
//            else{
//                s -= to_calc;
////                ans += next - idx;
////                idx = next;
//            }

