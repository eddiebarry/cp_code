#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#define FOR(i, j, k, in) for (int  i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int  i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;
int  sI(){
    int  c;
    cin>>c;
    return c;
}
int  sLL(){
    register int  c = getchar_unlocked();
    bool flag = true;
    if(c=='-'){
        flag =false;
        c = getchar_unlocked();
    }
    int  n = 0;
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
    register int  c = getchar_unlocked();
    for( ; (c<48 || c>57); c = getchar_unlocked() );
    for( ; (c>47 && c<58); c = getchar_unlocked() );}


int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int  min(int  a,int  b){return a<b?a:b;}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int  t = sI();
    while(t--){
        int  x = sI(), y = sI();
        string a;
        cin>>a;
        int  h = sI(), w = sI();
        string b;
        cin>>b;
        int  gcd_h = gcd(x,h);
        int  gcd_w = gcd(y,w);
        
        int  lcm_h = (x) * (h/gcd_h);
        int  lcm_w = (y) * (w/gcd_w);
        
        int  x_mult = lcm_h/x;
        int  y_mult = lcm_w/y;
        
        int  h_mult = lcm_h/h;
        int  w_mult = lcm_w/w;
        
        int  prev_idx = 0;
        int  prev_idx_str = 0;
        int  prev_idx_end = h_mult - 1;
        
        vector< pair<int ,int  > > to_check[x];
        
        
        REP(i,x){
            int  idx1 = 2*i;
            int  idx2 = 2*i+1;
            
            int  final_range = (i+1)*x_mult - 1;
            
            
            while(final_range>=prev_idx_str){
                bool flag = false;
                int  num = min(final_range, prev_idx_end);
                if(num==final_range){
                    flag = true;
                }
                num -= prev_idx_str;
                num++;
                if(num > 0){
                    to_check[i].push_back(make_pair(prev_idx,num) );
                }
                
                
                if(flag){
                    prev_idx_str = (i+1)*x_mult;
                    break;
                }
                else{
                    prev_idx++;
                    prev_idx_str = h_mult*prev_idx;
                    prev_idx_end = prev_idx_str+h_mult-1;
                }
                
            }
            
        }
        prev_idx = 0;
        prev_idx_str = 0;
        prev_idx_end = w_mult - 1;
        
        vector< pair<int ,int  > > to_check_w[y];
        
        
        REP(i,y){
            int  idx1 = 2*i;
            int  idx2 = 2*i+1;
            
            int  final_range = (i+1)*y_mult - 1;
            
            
            while(final_range>=prev_idx_str){
                bool flag = false;
                int  num = min(final_range, prev_idx_end);
                if(num==final_range){
                    flag = true;
                }
                num -= prev_idx_str;
                num++;
                if(num > 0){
                    to_check_w[i].push_back(make_pair(prev_idx,num) );
                }
                
                
                if(flag){
                    prev_idx_str = (i+1)*y_mult;
                    break;
                }
                else{
                    prev_idx++;
                    prev_idx_str = w_mult*prev_idx;
                    prev_idx_end = prev_idx_str+w_mult-1;
                }
                
            }
            
            
        }
        
        long long  final_ans = 0;
        
        REP(i,x){
            int  lin_fir = i;
            
            FOR(to_check_idx,0,to_check[lin_fir].size(),1){
                pair<int, int> scnd_lin = to_check[lin_fir][to_check_idx];
                int  ans = 0;
                
                REP(row_idx ,y){
                    FOR(to_check_w_idx,0,to_check_w[row_idx].size(),1){
                        pair<int, int> scnd_row_idx = to_check_w[row_idx][to_check_w_idx];
                        
                        char c = a[lin_fir*y+row_idx];
                        char t = b[scnd_lin.first*w+scnd_row_idx.first];
                        
                        if(c==t){
                            ans+=scnd_row_idx.second;
                        }
                        
                    }
                    
                }
                ans*= scnd_lin.second;
                
                final_ans+=ans;
                
                
            }
            
            
            
            
        }
        cout<<final_ans<<"\n";
        
        
        
        
    }
    
    
    return 0;
}
