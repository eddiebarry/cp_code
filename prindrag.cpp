#include<queue>
#include<stack>
#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<climits>
#include<algorithm>
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define pp pair< int , pair< int,int > >
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

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string
 This function takes three parameters:
 1. String
 2. Starting index of the string
 3. Ending index of the string. */
int p;

void permute(int *a, int l, int r, int n,vector<int>&an)
{
    int i;
    if (l == r){
//        printf("%d\n", a);
//        for(int i = 0; i <n ; i++){
//            cout<<a[i]<<" ";
//        }
//        cout<<"\n";
        REP(i,n){
            int curr_idx = i;
            int ans=0;
            //check right
            int sum = a[curr_idx];
            FOR(i,curr_idx+1,n,1){
                sum+=a[i];
                if(sum>=p){
                    ans++;
                }
            }
            sum = a[curr_idx];
            RFOR(i,curr_idx-1,0,1){
                sum+=a[i];
                if(sum>=p){
                    ans++;
                }
            }
            if(a[i]>=p){
                ans++;
            }
            if(ans>an[curr_idx]){
                an[curr_idx]=ans;
            }
        }
        
        
    }
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a+l), (a+i));
            permute(a, l+1, r,n,an);
            swap((a+l), (a+i)); //backtrack
        }
    }
}


int main()
{
    int t = sI();
    REP(i,t){
        int n =sI();
        p = sI();
        int arr[n];
        REP(i,n){
            arr[i]= sI();
        }
        vector<int>ans(n);
        permute(arr, 0, n-1,n,ans);
        REP(i,n){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        
    }
    
    return 0;
}

//
//
//int main(){
//    int t = sI();
//
//
//    REP(i,t){
//        int n = sI(), p = sI();
//        vector<int>vec(n);
//        vector<int>ans(n);
//        REP(i,n){
//            vec[i]=sI();
//        }
//        sort(vec.begin(),vec.end());
//        int sum = vec[n-1];
//        if(sum>=p){
//            REP(i,n){
//                cout<<n<<" ";
//            }
//            cout<<"\n";
//            continue;
//        }
//        int x = 0;
//        REP(i,n-1){
//            x++;
//            sum+=vec[n-2-i];
//            if(sum>=p){
//                break;
//            }
//        }
//        if(sum>=p){
//            //x exists
////            calculate y;
//            int start_point = n-1 - x -1;
//            int y = 0;
//            int sum = vec[n-1];
//            RFOR(i,start_point,0,1){
//                y++;
//                sum+=vec[i];
//                if(sum>=p){
//                    break;
//                }
//            }
//            if(sum>=p){
//                //x and y exist
////                cout<<"x and y exist \n";
//                ans[0]=n-x;
//                ans[n-1]=n-x;
//                REP(i,n){
//                    if(ans[i+1]!=0){
//                        break;
//                    }
//                    if(i+1==y){
//                        while(ans[i+1]==0){
//                            ans[i+1]=ans[i];
//                            ans[n-1 - i - 1] = ans[i+1];
////                            cout<<"marked "<<i+1<<" in the while loop "<<n-1 - i - 1<<"\n";
//                            i++;
//                        }
//                    }
//                    else{
//                        if(ans[i]-1>0){
//                            ans[i+1] = ans[i]-1;
//                            ans[n-1 - i - 1] = ans[i+1];
//                        }
//
////                        cout<<"marked "<<i+1<<"  "<<n-1 - i - 1<<"\n";
//                    }
//                }
//                REP(i,n){
//                    cout<<ans[i]<<" ";
//                }
//                cout<<"\n";
//            }
//            else{
//                //x exists and y doesnt exist
////                cout<<"x exists and y doesnt exist\n";
//
//                ans[0]=n-x;
//                ans[n-1]=n-x;
//                REP(i,n-x){
//                    if(ans[i+1]!=0){
//                        break;
//                    }
//                    if(n-i-1-x>0){
//                        ans[i+1] = n - i - 1 -x;
//                        ans[n-1 - i - 1] = ans[i+1];
//                    }
//
//                }
//                REP(i,n){
//                    cout<<ans[i]<<" ";
//                }
//                cout<<"\n";
//            }
//        }
//        else{
////            /x doesnt exist
//            REP(i,n){
//                cout<<0<<" ";
//            }
//            cout<<"\n";
//        }
//    }
//}
