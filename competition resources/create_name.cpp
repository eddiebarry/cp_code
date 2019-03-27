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

void swap(char *x, char *y)
{
    char temp;
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

void permute(char *a, int l, int r, int n)
{
    int i;
    if (l == r){
        //        printf("%d\n", a);
                for(int i = 0; i <n ; i++){
                    cout<<a[i];
                }
                cout<<"\n";
        
        
    }
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a+l), (a+i));
            permute(a, l+1, r,n);
            swap((a+l), (a+i)); //backtrack
        }
    }
}



int main(){
    
    int n ;
    cin>>n;
    char vec[n];
    getchar();
    REP(i,n){
        vec[i]=getchar();
    }
    permute(vec,0,n-1,n);
}


