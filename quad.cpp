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

void check(int &s, vector< vector<int> > &vec, int a, int b, int c, int d){
    
}

void combinationUtil(int arr[], int n, int r, int index, int data[], int i,int &s, vector< vector<int> > &vec)
{
    if (index == r)
    {
//        for (int j=0; j<r; j++)
            check(s,vec,data[0],data[1],data[2],data[3]);
//        printf("\n");
        return;
    }
    
    if (i >= n)
        return;
    
    data[index] = arr[i];
    combinationUtil(arr, n, r, index+1, data, i+1,s,vec);
    
    combinationUtil(arr, n, r, index, data, i+1,s,vec);
}

void printCombination(int arr[], int n, int r,int &s, vector< vector<int> > &vec)
{
    int data[r];
    
    combinationUtil(arr, n, r, 0, data, 0,s,vec);
}


//// Driver program to test above functions
//int main()
//{
//    int arr[] = {1, 2, 3, 4, 5};
//    int r = 3;
//    int n = sizeof(arr)/sizeof(arr[0]);
//    printCombination(arr, n, r);
//    return 0;
//}

int main(){
    int n = sI();
    int a[n];
    REP(i,n){
        a[i]=i;
    }
    
    
    vector< vector<int> > vec(n, vector<int>(2));
    REP(i,n){
        vec[i][0]=sI();
        vec[i][1]=sI();
    }
    int ans = 0;
    printCombination(a, n, 4,ans,vec);
    
    
    
}
