#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<unordered_map>
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


long long score(char s[], int sz){
    long long sc = 0;
    long long temp = 1;
    for(int i = 0; i <sz; i++){
        if(s[i]=='C'){
            temp*=2;
        }
        else{
            sc+=temp;
        }
    }
    return sc;
}

int main(){
    int t;
    cin>>t;
    REP(z,t){
        long long D;
        string str;
        cin>>D>>str;
        int num_sz = str.size();
        char str_arr[num_sz];
        for(int i = 0; i < num_sz; i++){
            str_arr[i]=str[i];
        }
        long long scr = score(str_arr,num_sz);
        if(scr<=D){
            cout<<"Case #"<<z+1<<": "<<0<<"\n";
        }
        else{
            int swaps = 0;
            bool flag = true;
            for(int i = num_sz-2; i>=0; i--){
                if(str_arr[i]=='C'&&str_arr[i+1]=='S'&& i+1 != num_sz){
                    str_arr[i]^=str_arr[i+1];
                    str_arr[i+1]^=str_arr[i];
                    str_arr[i]^=str_arr[i+1];
                    swaps++;
                    i+=2;
                }
//                REP(i,num_sz){
//                    cout<<str_arr[i]<<" ";
//                }
//                cout<<"\n";
                scr = score(str_arr,num_sz);
                if(scr<=D){
                    cout<<"Case #"<<z+1<<": "<<swaps<<"\n";
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout<<"Case #"<<z+1<<": IMPOSSIBLE\n";
            }
        }
        
        //        cout<<"scr is "<<scr<<"\n";
    }
}


//            //find first D that can be swapped and swap it
//            //find first swappable d
//            for(;temp<num_sz;temp++){
//                if(str_arr[temp]=='C'&&str_arr[temp-1]=='S'){
//                    //swap
//                    char tem = str_arr[temp];
//                    str_arr[temp]=str_arr[temp-1];
//                    str_arr[temp-1]=tem;
//                    swaps++;
//                    temp--;
//                    break;
//                }
//                if(str_arr[temp]=='S'&&temp==num_sz-1){
//                    flag=false;
//                }
//            }
//            REP(i,num_sz){
//                cout<<str_arr[i]<<" ";
//            }
//            cout<<"\n";
//            scr = score(str_arr,num_sz);



//        cin>>D;
//        cout<<D<<"\n";
//        string str;
//        cin>>str;
//        cout<<s<<"\n";
//        int swaps = 0;
//        long long sc = score(s);
//        cout<<sc<<"\n";
//        int temp = 1;
//        bool flag = true;
//        while (sc>D && flag) {
//            for(; temp < str.size(); temp++){
//                if(temp==str.size()-1 && s[temp]=='S'){
//                    flag = false;
//                    break;
//                }
//                if(s[temp]=='D' && s[temp-1]!='D'){
//                    break;
//                }
//            }
//            cout<<temp<<"\n";
//            if(s[temp]=='D' && s[temp-1]!='D'){
//                swaps++;
//                s[temp]='Z';
//                s[temp-1]^=s[temp];
//                s[temp]^=s[temp-1];
//                temp-=2;
//            }
//            cout<<s<<"\n";
//            sc = score(s);
//            cout<<"the changed score is "<<sc<<"\n";
//        }
//        if(sc>D){
//            cout<<"IMPOSSIBLE\n";
//        }
//        else{
//            cout<<swaps<<"\n";
//        }

