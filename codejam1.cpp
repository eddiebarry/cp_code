#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <iomanip>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;

int sI(){
    int c;
    cin>>c;
    return c;
}
int main(){
    int t = sI();
    REP(z,t){
        int n = sI(), l = sI();
        set<char>st[2];
        set<string>str;
        REP(i,n){
            string s;
            cin>>s;
            str.insert(s);
            REP(i,l){
                st[i].insert(s[i]);
            }
        }
        if(l==1){
            cout<<"case #"<<z+1<<": -\n";
            continue;
        }
        bool flag = true;
        for(auto x:st[0]){
            for(auto y:st[1]){
                string temp = "";
                temp+=x;
                temp+=y;
                if(str.find(temp)==str.end()){
                    cout<<"case #"<<z+1<<": "<<temp<<"\n";
                    flag = false;
                    break;
                }
            }
            if(!flag){
                break;
            }
        }
        if(flag){
            cout<<"case #"<<z+1<<": -\n";
        }
    }
    
}
    
    
    
    
//        for(auto x: st[0]){
//            string temp = "";
//            for(auto y : st[1]){
//                temp =x+y;
//                cout<<temp<<"\n";
////                if(str.find(temp)==str.end()){
////                    cout<<"case #"<<z+1<<": "<<temp<<"\n";
////                    flag = false;
////                    break;
////                }
//            }
//            if(!flag){
//                break;
//            }
//        }

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
//    REP(z,t){
//        int n = sI(), l = sI();
//        set<string>str;
//        set<char> st[l];
//        REP(i,n){
//            string s;
//            cin>>s;
//            str.insert(s);
//            REP(i,l){
//                st[i].insert(s[i]);
//            }
//        }
////        long long l1 = 0;
//        int arr[l];
//        REP(i,l){
//            arr[i]=1;
//        }
//
////        REP(i,l){
////            for(auto x:st[i]){
////                cout<<x<<" ";
////            }
////            cout<<"\n\n\n";
////        }
//        int x = sI();
//        bool final = false;
//        while(true){
//            string temp="";
//            REP(i,l){
//                auto it = st[i].begin();
//                REP(j,arr[i]-1){
//                    it++;
//                }
//                temp+=*it;
//            }
//            if(str.find(temp)==str.end()){
//                cout<<"case #"<<z<<": "<<temp<<"\n";
//                final = false;
//                break;
//            }
//            if(final){
//                break;
//            }
//            REP(i,l){
//                if(arr[i] == st[i].size()){
//                    arr[i]=1;
//                }
//                else{
//                    arr[i]++;
//                    break;
//                }
//            }
//            REP(i,l){
//                if(arr[i] == st[i].size()){
//                    final = true;
//                }
//                else{
//                    final = false;
//                    break;
//                }
//            }
//        }
//        if(final){
//            cout<<"case #"<<z<<": -\n";
//        }
//    }
//}
//
//
//
//
//
//
//
//
//
//
//
//
////        set<string>str;
////        vector< set<char> >set;
////        REP(i,n){
////            string s;
////            cin>>s;
////            str.insert(s);
////            REP(i,l){
////
////            }
//        }
