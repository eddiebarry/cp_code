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
long long RAD;
double eps = .000001;


long long point_of_intersection_line(long long x,long long y,long long seg_a_x,long long seg_a_y,long long seg_b_x,long long seg_b_y){
    if(seg_a_x ==-1 && seg_a_y == -1 && seg_b_x == -1 && seg_b_y == -1){
        return -1;
    }
    
    double num_m2 = y;
    double dem_m2 = x;
    
    double num_m1 = seg_b_y-seg_a_y;
    double dem_m1 = seg_b_x-seg_b_y;
    
    double ans;
    
    //edge case seg_b is colinear
    if(num_m1*dem_m2==num_m2*dem_m1  &&  seg_a_y*dem_m1 == seg_a_x*num_m1 ){
        //find smallest point
        if(seg_a_x<=seg_b_y){
            if(seg_a_x<=x){
                ans = sqrt((seg_a_x*seg_a_x) + (seg_a_y*seg_a_y));
            }
            else{
                return -1;
            }
        }
        else{
            if(seg_b_x<=x){
                ans =  sqrt((seg_b_x*seg_b_x) + (seg_b_y*seg_b_y));
            }
            else{
                return -1;
            }
        }
    }
    else if( num_m1*dem_m2==num_m2*dem_m1 ) {
        return -1;
    }
    else{
        double m_1 = num_m1 / dem_m1;
        double m_2 = num_m2 / dem_m2;
        //        cout<<m_1<<" is m1"<<m_2<<"\n";
        double c = seg_b_y - m_1 * seg_b_x;
        
        double p_x = c / (m_2 - m_1);
        double p_y = m_2 * p_x;
        
        
        //        cout<<p_x<<" is px "<<p_y<<"\n";
        if(p_x <= x && p_x <= max(seg_a_x+eps,seg_b_x+eps) && p_x >= min(seg_a_x-eps,seg_b_x-eps)){
            ans = sqrt((p_x*p_x) + (p_y*p_y));
        }
        else return - 1;
    }
    
    ans*= 1000;
    
    if( ans - floor(ans) >= 0.5){
        ans = ceil(ans);
    }
    else{
        ans = floor(ans);
    }
    
    return ans;
}


long long point_of_intersection_circle(long long x,long long y,long long a,long long b){
    if(a==-1&&b==-1){
        return -1;
    }
    
    double m = double(y)/x;
    //    cout<<m<<"is the slope\n";
    double r = RAD;
    double det = (a+m*b)*(a+m*b) - (1+m*m)*(a*a+b*b-r*r);
    //    cout<<det<<"is the det\n";
    if(det < 0 - eps){
        return -1;
    }
    if(det < 0){
        det *= -1;
    }
    
    double p_x = a+m*b - sqrt(det);
    p_x /= (m*m+1);
    
    double p_y = m * p_x;
    
    double ans = sqrt((p_x*p_x) + (p_y*p_y));
    ans*= 1000;
    
    if( ans - floor(ans) >= 0.5){
        ans = ceil(ans);
    }
    else{
        ans = floor(ans);
    }
    
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n = sI(), m = sI(), r = sI(), q = sI();
    RAD = r;
    
    vector< vector<long long> >circles(n);
    REP(i,n){
        circles[i].push_back(sI());
        circles[i].push_back(sI());
    }
    vector< vector<long long> >segments(m);
    REP(i,m){
        segments[i].push_back(sI());
        segments[i].push_back(sI());
        segments[i].push_back(sI());
        segments[i].push_back(sI());
    }
    
    REP(i,q){
        long long dec = sI();
        if(dec == 1){
            long long x = sI(), y = sI();
            
            double ans = sqrt((x*x) + (y*y));
            ans*= 1000;
            
            if( ans - floor(ans) >= 0.5){
                ans = ceil(ans);
            }
            else{
                ans = floor(ans);
            }
            
            for(auto circ:circles){
                double temp = point_of_intersection_circle(x,y,circ[0],circ[1]);
                if(temp < ans && temp != -1){
                    ans =temp;
                }
            }
            for(auto lin: segments){
                double temp = point_of_intersection_line(x,y,lin[0],lin[1],lin[2],lin[3]);
                if(temp < ans && temp != -1){
                    ans =temp;
                }
            }
            cout<<ans<<"\n";
        }
        else if(dec==2){
            vector<long long> temp(2);
            temp[0]=sI();
            temp[1]=sI();
            circles.push_back(temp);
        }
        else if(dec==2){
            vector<long long> temp(4);
            temp[0]=sI();
            temp[1]=sI();
            temp[2]=sI();
            temp[3]=sI();
            segments.push_back(temp);
        }
        else if(dec== 4){
            long long u =sI();
            u--;
            circles[u][0]=-1;
            circles[u][1]=-1;
        }
        else {
            long long u =sI();
            u--;
            segments[u][0]=-1;
            segments[u][1]=-1;
            segments[u][2]=-1;
            segments[u][3]=-1;
        }
    }
    
    return 0;
}



1 1 1 10
5 1
2 3 8 3
1 3 3
1 5 1
1 8 3
4 1
2 1 1
3 1 1 7 7
1 3 3
1 5 1
1 8 3
5 2
