#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<climits>
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;
int sI(){
    int c = getchar_unlocked();
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


int quadratic_hash(int idx,int sz){
    return (((idx*idx)%sz)+idx)%sz;
}

int modulo_hash(int idx,int sz){
    return idx%sz;
}



int main(){
    cout<<"enter number of elements to be stored\n";
    int n;
    cin>>n;
    
    int quadratic[n];
    int modulo[n];
    int linear_probe[n];
    REP(i,n){
        quadratic[i]=-1;
        modulo[i]=-1;
        linear_probe[i]=-1;
    }
    
    
    REP(i,n){
        int x = sI();
        int idx = quadratic_hash(x,n);
        int idx2 = modulo_hash(x,n);
        int idx3 = idx2;
        //check if value is occupied
        if(quadratic[idx]!=-1){
            //collision
            cout<<"collision in quadratic hash\n";
            cout<<x <<" "<<idx<< "in the quad hash\n";
        }
        else{
            quadratic[idx]=x;
            cout<<x <<" "<<idx<< "in the quad hash\n";
        }
        
        
        //check if value is occupied
        if(modulo[idx2]!=-1){
            //collision
            cout<<"collision in modulo hash\n";
        }
        else{
            modulo[idx2]=x;
        }
        
        //check if value is occupied
        if(linear_probe[idx3]!=-1){
            //collision
            cout<<"collision in linear hash\n";
            while(linear_probe[idx3%n]!=-1){
                if(idx3/n >= 2){
                    break;
                }
                idx3++;
            }
            linear_probe[idx3]=x;
        }
        else{
            linear_probe[idx3]=x;
        }
        
//        cout<<idx<<idx2<<idx3<<"\n";
    }
    
    cout<<"enter number of elements to be search\n";
    int t = sI();
    REP(i,t){
        cout<<"enter 1 for searching in quadratic hash\n";
        cout<<"enter 2 for searching in modulo hash\n";
        cout<<"enter 3 for searching in linear probe\n";

        int dec = sI();
        cout<<"enter element to be found\n";
        if(dec==1){

            int srchtrm = sI();
            int idx = quadratic_hash(srchtrm,n);
            if(quadratic[idx]==srchtrm){\
                cout<<"elem has been found \n";
            }
            else{
                cout<<"elem has not been found \n";
            }
        }
        else if(dec ==2){
            int srchtrm = sI();
            int idx = modulo_hash(srchtrm,n);
            if(modulo[idx]==srchtrm){\
                cout<<"elem has been found \n";
            }
            else{
                cout<<"elem has not been found \n";
            }
        }
        else{
            int srchtrm = sI();
            int idx = modulo_hash(srchtrm,n);
            if(linear_probe[idx]==srchtrm){\
                cout<<"elem has been found \n";
            }
            else{
                while(linear_probe[idx++%n]!=srchtrm){
                    if(idx/n>=2){
                        cout<<"elem has not been found \n";
                        break;
                    }
                }
            }
        }
    }
    
}
