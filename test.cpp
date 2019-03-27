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

//q 1
int main(){
    int t = sI();
    REP(i,t){
        int n = sI();
        int arr[n];
        REP(i,n){
            arr[i]=sI();
        }
        REP(i,n){
            if(arr[i]!=arr[i+1]){
                cout<<arr[i]<<"\n";
                break;
            }
            i++;
        }
    }
}
//q2 give linked list specs
//psuedocode
//extract entire linked list into string
//check palindrome


//q3
//assuming any step can be reached from one jump and no backtracking
int main(){
    int t = sI();
    //nc1 + nc2 +nc3 ... +ncn = 2^n - 1;
    int x = 1;
    while(n--){
        x = x<<1;
    }
    cout<<x-1<<"\n";
}
//if backtracking ans = infinity
//if max jump sz = x, use dp




//q4
int main(){
    int t = sI();
    REP(i,t){
        int n = sI();
        vector<int> arr(n);
        REP(i,n){
            arr[i]=sI();
        }
        sort(arr.begin(),arr.end());
        REP(i,n){
            if(arr[i]!=i+1){
                cout<<i+1<<"\n";
                break;
            }
        }
    }
}


//q5
//form state graph of every config
//give each face an id number and each face the colourc
//calculate all possible moves from one state
//ie upper half turn, upper full turn
//form DAG
//uses states in hashmap to avoid backtracking , dont add these edges to graph
//check every possible move, from every possible state
//god number for 2*2 cube is 8/15 -  i dont remember.
//
//O(2^n)



