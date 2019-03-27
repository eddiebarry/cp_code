#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
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


int num(int x){
    int ans = 0;
    while(x>0){
        ans+=x%2;
        x/=2;
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = sI();
    int a[n];
    int b[n];
    int c[n];
    REP(i,n){
        a[i]=sI();
    }
    REP(i,n){
        b[i]=sI();
    }
    REP(i,n){
        c[i]=sI();
    }
    int ans = 0;
    
    REP(i,n){
        FOR(j,i+1,n,1){
            if(num(a[i]&a[j])==b[j]){
                FOR(k,j+1,n,1){
                    if(num(a[j]|a[k])==c[k]){
                        FOR(l,k+1,n,1){
                            if(num(a[k]&a[l])==b[l]){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    
    
    return 0;
}


//FOR(l,k+1,n,1){
//    if(num(a[i]&a[j])==b[j] && num(a[j]|a[k])==c[k] && num(a[k]&a[l])==b[l]){
//        ans++;
//    }
//}


//FOR(k,j+1,n,1){
//    FOR(l,k+1,n,1){
//        if(num(a[i]&a[j])==b[j] && num(a[j]|a[k])==c[k] && num(a[k]&a[l])==b[l]){
//            ans++;
//        }
//    }
//}
