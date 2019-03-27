#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <limits>
#include <cmath>
#define FOR(i, j, k, in) for (long long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
typedef std::numeric_limits< double > dbl;
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
double sD(){
    double x;
    cin>>x;
    return x;
}

double mod(double a){return a<0? -a:a;}

int main(){
    int t = sI();
    REP(i,t){
        int n = sI();
        double s = sD(), y = sD();
        double velocity[n];
        REP(i,n){
            velocity[i]=sD();
        }
        REP(i,n){
            int dec = sI();
            if(dec==0){
                velocity[i]*= -1.0;
            }
        }
        double position[n];
        REP(i,n){
            position[i]=sD();
        }
        double len[n];
        REP(i,n){
            len[i]=sD();
        }
        
        double lane_time = y/s;
//        cout<<"lane time for t case "<<i<<" is "<<lane_time<<"\n";
        double time = 0.00000000;
        REP(i,n){
            double curr_pos = position[i] + time*velocity[i];
            double finn_pos = curr_pos + lane_time*velocity[i];
            double left_side, right_side;
            if(velocity[i]>0){
                left_side = curr_pos - len[i];
                right_side = finn_pos;
            }
            else{
                left_side = finn_pos;
                right_side = curr_pos + len[i];
            }
            if(left_side<= 0 && 0 <=right_side){
                double v = velocity[i];
                v = v<0? -v: v;
                if(velocity[i]>0){
                    time -= left_side/v;
                }
                else{
                    time +=right_side/v;
                }
//                time+=1e-6/v;
            }
            
//            if(mod(left_side)<=1e-6||mod(right_side)<=1e-6){
//                if(mod(right_side)<=1e-6&&right_side<0){
//                    if(velocity[i]>0){
//                        time+= -left_side/velocity[i];
//                        time+=1e-6/velocity[i];
//                    }
//                    else{
//                        time+= (right_side+1e-6)/-velocity[i];
//                    }
//                }
//                else if(mod(left_side)<=1e-6&&left_side>=0){
//                    if(velocity[i]>0){
//                        time+= (1e-6 - left_side) / velocity[i];
//                    }
//                    else{
//                        time+= (right_side+1e-6)/velocity[i];
//                    }
//                }
//            }

            
            
            
            
//            cout<<"curr pos is "<<curr_pos<<" finn_pos is "<<finn_pos<<" left side is "<<left_side<<" right side is "<<right_side<<"\n";

            time+= lane_time;
        }
        cout.precision(30);
        cout<<time<<"\n";
    }
}


