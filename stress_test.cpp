#include <bits/stdc++.h>
#define mp(a,b)   make_pair(a,b)
#define ll        long long
#define mp(a,b)   make_pair(a,b)
#define si(n)     scanf("%d",&n)
#define sl(n)     scanf("%lld",&n)
#define pi(n)     printf("%d\n",n)
#define pl(n)     printf("%lld\n",n)
#define           newline cout << endl;
#define           ff first
#define           ss second
#define           pii pair<int, int>
#define           pll pair<ll, ll>
using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.ff<<", "<<p.ss<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const int size = 10;
pair<ll,pair<ll,ll> > cnt[size]; //-1,-1 dist ek aur value shift second->first new->second

int main(){
  //clock_t tStart = clock();
  int test;
  // test=1;
  si(test);
  while(test--){
    int n;
    si(n);
    int arr[n];
    for(int i=0;i<size;i++){
      cnt[i].ff=cnt[i].ss.ff=-1;
      cnt[i].ss.ss=1e9;
    }
    int firstoccurence=-1;
    for(int i=0;i<n;i++){
      si(arr[i]);
      if(arr[i]!=-1 && firstoccurence==-1) firstoccurence=i;
      if(arr[i]==-1) continue;
      if(cnt[arr[i]].ff==-1){
        cnt[arr[i]].ff=i;
      }
      else if(cnt[arr[i]].ff!=-1 && cnt[arr[i]].ss.ff==-1){
        cnt[arr[i]].ss.ff=i;
        cnt[arr[i]].ss.ss = min(cnt[arr[i]].ss.ss, cnt[arr[i]].ss.ff-cnt[arr[i]].ff);
      }
      else{
        cnt[arr[i]].ff=cnt[arr[i]].ss.ff;
        cnt[arr[i]].ss.ff=i;
        cnt[arr[i]].ss.ss = min(cnt[arr[i]].ss.ss, cnt[arr[i]].ss.ff-cnt[arr[i]].ff);
      }
    }
    // for(int i=0;i<10;i++){
    //   if(cnt[i].ss.ss!=1e9){
    //     trace("i,f,s,t", i,cnt[i].ff, cnt[i].ss.ff, cnt[i].ss.ss);
    //   }
    // }
    ll mini = 1e9;
    for(int i=0;i<size;i++){
      mini = min(mini, cnt[i].ss.ss);
    }
    for(int i=0;i<n;i++){
      if(i!=n-1){
        if(arr[i]!=-1&&arr[i+1]==1){
          mini = arr[i];
          break;
        }
      }
    }
    // trace("mini",mini);
    int check_output=0;
    if(mini==1e9){
      if(firstoccurence==-1){
        check_output++;
        cout << "inf" << endl;
      }
      else{
        bool f = 0;
        int curr = arr[firstoccurence];
        int k_cand = 1e9+10;
        int last = -1;
        int num_1 = 0;
        for(int i=firstoccurence;i<n;i++){
          // cout<<"blah\n";
          // trace("arr[i]", arr[i]);
          if(arr[i]==-1){
            curr++;
            num_1++;
          }
          else{
            if(arr[i]==curr){
              curr++;
              num_1 = 0;
              last = arr[i];
            }
            else if(arr[i]<curr){
              // cout<<num_1<<" "<<last<<" "<<arr[i]+1<<"\n";
              ll temp = last+num_1 - arr[i]+1;
              if(k_cand>temp){
                k_cand=temp;
                // cout<<k_cand<<"is k cand\n";
              }
              curr = arr[i]+1;
            }
            else{
              f=1;
              break;
            }
          }
        }
        if(f&&k_cand==1e9+10) {
          check_output++;
          cout << "impossible" << endl;
        }
        else if (k_cand==1e9+10){
          cout << "inf" << endl;
          check_output++;
        }
        else{
          //check for k_cand
          mini= k_cand;
          bool f = 0;
          int curr = arr[firstoccurence];
          for(int i=firstoccurence;i<n;i++){
            if(arr[i]==-1){
              curr++;
            }
            else{
              if(arr[i]==curr){
                curr++;
              }
              else{
                f=1;
                break;
              }
            }
            if(curr==mini+1) curr=1;
          }
          if(f) {
            check_output++;
            cout << "impossible" << endl;
          }
          else {
            check_output++;
            cout << mini << endl;
          }
        }
      }
    }
    else{
      bool f = 0;
      int curr = arr[firstoccurence];
      for(int i=firstoccurence;i<n;i++){
        if(arr[i]==-1){
          curr++;
        }
        else{
          if(arr[i]==curr){
            curr++;
          }
          else{
            f=1;
            break;
          }
        }
        if(curr==mini+1) curr=1;
      }
      if(f) {
        check_output++;
        cout << "impossible" << endl;
      }
      else {
        check_output++;
        cout << mini << endl;
      }
    }
    assert(check_output==1);
  }
  //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  return 0;
}