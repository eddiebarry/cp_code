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


bool check(int a, int b, vector<int> &vec){
    REP(i,10){
        if(vec[i]==a&&vec[i+1]==b){
            return true;
        }
        i++;
    }
    return false;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = sI();
    while(t--){
        
        vector<int> vec;
        REP(i,10){
            vec.push_back(sI());
        }
        
//        for(auto x: vec){
//            cout<<x<<" ";
//        }
//
        bool flag = false;
        REP(i,10){
            int x = vec[i];
            int y = vec[i+1];
//            flag = false;
            
            if(check(x,y+1, vec)&& check(x,y-1,vec)){
                if(check(x+1,y+1, vec)&& check(x-1,y+1,vec)){
                    flag = true;
                }
                else if(check(x+1,y-1, vec)&& check(x-1,y-1,vec)){
                    flag = true;
                }
            }
            if(!flag){
                if(check(x-1,y, vec)&& check(x+1,y,vec)){
                    if(check(x-1,y+1, vec)&& check(x-1,y-1,vec)){
                        flag = true;
                    }
                    else if(check(x+1,y-1, vec)&& check(x+1,y+1,vec)){
                        flag = true;
                    }
                }
            }
            
            
            i++;
        }
        if(flag){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    
    
    return 0;
}

