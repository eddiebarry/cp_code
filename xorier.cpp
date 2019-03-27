#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <unordered_map>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
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
    for( ; (c>47 && c<58); c = getchar_unlocked() );}
class BIT {
    // Implementation of a Binary Indexed Tree (Fennwick Tree)
public:
    /*BIT(std::vector<int> list) {
     // Initialize BIT with list in O(n*log(n))
     m_array = std::vector<int>(list.size() + 1, 0);
     for (int idx = 0; idx < list.size(); idx++) {
     update(idx, list[idx]);
     }
     }*/
    
    BIT(std::vector<int> list) {
        // Initialize BIT with list in O(n)
        m_array = std::vector<int>(list.size() + 1, 0);
        for (int idx = 0; idx < list.size(); idx++) {
            m_array[idx + 1] = list[idx];
        }
        
        for (int idx = 1; idx < m_array.size(); idx++) {
            int idx2 = idx + (idx & -idx);
            if (idx2 < m_array.size()) {
                m_array[idx2] += m_array[idx];
            }
        }
    }
    
    int prefix_query(int idx) {
        // Computes prefix sum of up to including the idx-th element
        int result = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            result += m_array[idx];
        }
        return result;
    }
    
    int range_query(int from_idx, int to_idx) {
        // Computes the range sum between two indices (both inclusive)
        return prefix_query(to_idx) - prefix_query(from_idx - 1);
    }
    
    void update(int idx, int add) {
        // Add a value to the idx-th element
        for (++idx; idx < m_array.size(); idx += idx & -idx) {
            m_array[idx] += add;
        }
    }
    
private:
    std::vector<int> m_array;
};//fenwick tree


//int xnor(int a, int b)
//{
//    // Make sure a is larger
//    if (a < b)
//        swap(a, b);
//
//    if (a == 0 && b == 0)
//        return 1;
//
//    int a_rem = 0; // for last bit of a
//    int b_rem = 0; // for last bit of b
//
//    // counter for count bit
//    // and set bit  in xnornum
//    int count = 0;
//
//    // to make new xnor number
//    int xnornum = 0;
//
//    // for set bits in new xnor number
//    while (a)
//    {
//        // get last bit of a
//        a_rem = a & 1;
//
//        // get last bit of b
//        b_rem = b & 1;
//
//        // Check if current two
//        // bits are same
//        if (a_rem == b_rem)
//            xnornum |= (1 << count);
//
//        // counter for count bit
//        count++;
//        a = a >> 1;
//        b = b >> 1;
//    }
//    return xnornum;
//}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = sI();
    while(t--){
        int n = sI();
        int num_even = 0;
        int num_odd = 0;
        unordered_map<int,int> map;
        vector<int>vec;
        REP(i,n){
            int x = sI();
            map[x]++;
            if(x%2==0){
                num_even++;
            }
            else{
                num_odd++;
            }
            vec.push_back(x);
        }
        
        long long ans = 0;
        REP(i,n){
            map[vec[i]]--;
            if(vec[i]%2==0){
                num_even--;
                ans+=num_even;
                //0 case
                ans-=map[vec[i]];
                //2 case
                int x = vec[i];
                int to_find = x^2;
//                cout<<"to find is "<<to_find<<"\n";
                ans-=map[to_find];
            }
            else{
                num_odd--;
                ans+=num_odd;
                //the 0 case
                ans-=map[vec[i]];
                int x = vec[i];
                int to_find = x^2;
//                cout<<"to find is "<<to_find<<"\n";
                ans-=map[to_find];
            }
        }
        cout<<ans<<"\n";
//        cout<<!(2^1);
    }
    return 0;
}

