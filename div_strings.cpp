#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#define ll long long
#define ull unsigned long long
#define LD long double
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define ll long long
#define intpair pair<int,int>
#define MP(i,j) make_pair(i,j)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MOD 1000000007
using namespace std;
int sI(){
	int c;
	cin >>c;
	return c;
   }
int v[100000][24];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n = sI();

   string s;
   cin>>s;
   int idx = 0;
   for(auto x : s){
   	v[idx][x-'a']++;
   	if(idx++ == 0){
   			continue;
	}
	else{
		idx--;
		REP(i,'z'-'a'){
   		v[idx][i] += v[idx-1][i];
   		}
   		idx++;
	}
   	
   }


   FOR(i, 0, n - 1, 1){
   	FOR(j, i+1, n, 1){
   		std::vector<int> temp('z'-'a');
   		int sz = j - i + 1;
   		bool imp = true;
   		REP(z, 'z' - 'a'){
   			temp[z] = v[j][z] - v[i][z];
   			if(temp[z] > sz / 2){
   				 imp = false;
   				 break;
   			}
   		}
   		if(imp){
   			cout<<"YES\n";
   			FOR(a,i,j+1,1){
   				cout<<s[a];
   			}
   			cout<<"\n";
   			return 0;
   		}
   	}
   }
   cout<<"NO\n";







   return 0;
}