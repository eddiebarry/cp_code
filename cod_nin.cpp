#include<iostream>
using namespace std;
int sI(){
    int x;
    cin>>x;
    return x;
}
long long mod(int a){
    return a<0?-a:a;
}

int main() {
    
    // Write your code here
    int a  = sI(), b = sI();
    
    long long ans = 0;
    
    for(int i = a; i <= b;i ++ ){
        long long sum = 1;
        if(i==1){
            sum = 0;
        }
        
        for(int x = 2; x*x <= i; x++){
            if(i%x==0){
                //i is a didivisor
                sum += x;
                sum += i/x;
            }
            if(x*x==i){
                sum -= x;
            }
        }
//        cout<<mod(i-sum)<<" ";
//        cout<<mod(sum)<<"\n";
        ans += mod(i-sum);
        
    }
    cout<<ans;
    
}
