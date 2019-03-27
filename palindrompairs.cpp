
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <unordered_map>
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
    
    int freq[26];
    vector<string> stgs;
    unordered_map<string,int> map;
    REP(i,t){
        string s;
        cin>>s;
        REP(i,26){
            freq[i]=0;
        }
        for(auto x: s){
            freq[x-'a']++;
        }
        REP(i,26){
            if(freq[i]%2==0){
                freq[i] = 0;
            }
            else{
                freq[i] = 1;
            }
        }
        string temp = "";
        REP(i,26){
            temp+= to_string(freq[i]);
        }
        stgs.push_back(temp);
        map[temp]++;
    }
    long long ans = 0;
    
    REP(i,t){
        //for a string first check everything even
        if(map.find(stgs[i])!=map.end()){
            ans+= map[stgs[i]]-1;;
        }
        
        //check one odd
        REP(j,26){
            if(stgs[i][j]=='0'){
                stgs[i][j]='1';
            }else{
                stgs[i][j]='0';
            }
            ans+= map[stgs[i]];
            if(stgs[i][j]=='0'){
                stgs[i][j]='1';
            }else{
                stgs[i][j]='0';
            }
        }
        
        
    }
    cout<<ans/2;
    
    
}
