#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<map>
#include<list>
#include<climits>
#define INF 0x3f3f3f3f
#define FOR(i, j, k, in) for (long i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (long i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define pp pair< long long , pair< long long ,long long > >
#define sqrt_dt long long

using namespace std;
const long long N = 100000;
long long n;
long long tree[2 * N];
long long nums[2 * N];




void build_tr()
{
    // insert leaf nodes in tree
    for (long long i=0; i<n; i++)
        tree[n+i] = 0;
    
    // build the tree by calculating parents
    for (long long i = n - 1; i > 0; --i)
        tree[i] = 0;
}
void build_num()
{
    // insert leaf nodes in tree
    for (long long i=0; i<n; i++)
        nums[n+i] = 0;
    
    // build the tree by calculating parents
    for (long long i = n - 1; i > 0; --i)
        nums[i] = 0;
}
void updateTreeNode_tr(long long p, long long value)
{
    // set value at position p
    tree[p+n] = value;
    p = p+n;
    
    // move upward and update parents
    for (long long i=p; i > 1; i >>= 1)
        tree[i>>1] = max(tree[i] , tree[i^1]);
}

long long query_tr(long long l, long long r)
{
    long long res = 0;
    
    // loop to find the sum in the range
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l&1)
            res = max(tree[l++],res);
        
        if (r&1)
            res = max(tree[--r],res);
    }
    
    return res;
}

void updateTreeNode_nums(long long p, long long value)
{
    // set value at position p
    nums[p+n] = value;
    p = p+n;
    
    // move upward and update parents
    for (long long i=p; i > 1; i >>= 1)
        nums[i>>1] = max(nums[i] , nums[i^1]);
}

long long query_nums(long long l, long long r)
{
    long long res = 0;
    
    // loop to find the sum in the range
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l&1)
            res = max(nums[l++],res);
        
        if (r&1)
            res = max(nums[--r],res);
    }
    
    return res;
}

/******************************************************/
long long sI(){
    long long c = getchar_unlocked();
    bool flag = true;
    if(c=='-'){
        flag =false;
        c = getchar_unlocked();
    }
    long long n = 0;
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



long long max(long long a, long long b){return a<b?b:a;}
long long min(long long a, long long b){return a<b?a:b;}

long long calc_score(set<long long >&s, multimap<long long ,long long >&map, long long size_bound, long long sz){
    //create a seg tree
        //seg tree created
    build_tr();
    build_num();
    for(auto x:s){
        long long num = x;
        auto it = map.equal_range(num);
        vector< long long >vec;
        long long size = 0;
        for(auto itr = it.first; itr!= it.second; ++itr){
            vec.push_back(itr->second);
            size++;
        }
        sort(vec.begin(),vec.end());
        FOR(i,0,size,1){
            stack<long long >stk;
            stk.push(vec[i]);
            long long max = -1;
            long long idx = vec[i];
            long long upper_bound = (sz < idx + size_bound ? sz : idx+size_bound );
            long long lower_bound = (1 > idx - size_bound ? 1 : idx -size_bound);
            lower_bound--;
                            //        cout<<upper_bound<<" is ub "<<lower_bound<<" is l_b\n";
            
            long long max_num = query_tr(lower_bound,upper_bound);
            long long max_num_stored = query_nums(lower_bound,upper_bound);
            
                            //                cout<<max_num<<" is the max num in range \n";
            if(num>max_num_stored){
//                updateTreeNode_tr(idx-1,max_num+1);
                if(max_num+1>max){
                    max = max_num+1;
                }
//                updateTreeNode_nums(idx-1,num);
            }
            else{
//                updateTreeNode_tr(idx-1,max_num);
                if(max_num>max){
                    max = max_num;
                }
//                updateTreeNode_nums(idx-1,num);
            }
            
            if(i+1<size){
                while(vec[i+1]-vec[i]<=size_bound){
                    stk.push(vec[i+1]);
                    idx  = vec[i+1];
                    upper_bound = (sz < idx + size_bound ? sz : idx+size_bound );
                    lower_bound = (1 > idx - size_bound ? 1 : idx -size_bound);
                    lower_bound--;
                    //        cout<<upper_bound<<" is ub "<<lower_bound<<" is l_b\n";
                    
                    max_num = query_tr(lower_bound,upper_bound);
                    max_num_stored = query_nums(lower_bound,upper_bound);
                    
                    //                cout<<max_num<<" is the max num in range \n";
                    if(num>max_num_stored){
                        //                updateTreeNode_tr(idx-1,max_num+1);
                        if(max_num+1>max){
                            max = max_num+1;
                        }
//                        updateTreeNode_nums(idx-1,num);
                    }
                    else{
                        //                updateTreeNode_tr(idx-1,max_num);
                        if(max_num>max){
                            max = max_num;
                        }
//                        updateTreeNode_nums(idx-1,num);
                    }
                    
                    i++;
                    if(i==size-1){
                        break;
                    }
                }
            }
            while(!stk.empty()){
                updateTreeNode_tr(stk.top()-1,max);
                updateTreeNode_nums(stk.top()-1,num);
                stk.pop();
                
            }
            
        }
        
    }
    long long ans = 0;
    REP(i,sz){
//                cout<<tree[i+n]<<" ";
        ans += tree[i+n];
    }
//        cout<<"\n";
    return ans;
    
    
    
//    REP(i,sz){
//        long long num = sorted[i].first;
//        //        num--;
//        long long idx = sorted[i].second;
    
        
//                cout<<"num to be inserted is "<<num<<" idx is "<<idx<<"\n";
        
        //        cout<<"after update array is \n";
        //        tr.prlong long _arr();
        //        cout<<"\n";
}

    //    tr.prlong long _arr();
    //    cout<<"\n\n\n\nn\n";
//    REP(i,n){
//        cout<<arr[i]<<" ";
//    }
//    cout<<"\n";







//
int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t = sI();
    REP(i,t){
        n = sI();
        long long s = sI();
        vector<long long >vec(n);
        REP(i,n){
            vec[i] = sI();
            vec[i]++;
        }
        
        if(s<n){
            cout<<0<<"\n";
            continue;
        }
        set<long long >se;
        multimap<long long ,long long >map;
        REP(i,n){
            se.insert(vec[i]);
            map.insert(make_pair(vec[i],i+1));
        }
//
//        long long ans = 0;
//        REP(i,n+1){
//            if(calc_score(se,map,i,n)<=s){
//                ans++;
//            }
//            //                    else{
//            //                        break;
//            //                    }
//        }
//        cout<<ans<<"\n";
        long long low = 0, high = n,med;
        long long x;
        while (high-low>1) {
            med = high+low;
            med /=2;
            x = calc_score(se,map,med,n);
            if(x<=s){
                low = med;
            }
            else{
                high = med;
            }
        }
        if(calc_score(se,map,high,n)<=s){
            cout<<high+1<<"\n";
        }
        else{
            cout<<low+1<<"\n";
        }
    }
}
    //        if(s==1e9){
    //            cout<<n+1<<"\n";
    //            continue;
    //        }
    //        long long ans = 0;
    //        REP(i,n+1){
    //            if(calc_score(vec,i,n)<=s){
    //                ans++;
    //            }
    //            else{
    //                break;
    //            }
    //        }
    //        cout<<ans<<"\n";
////    long long arr[] = { 1, 3, 5, 7, 9, 11 };
////    long long n = sizeof(arr) / sizeof(arr[0]);
////
////    // Build segment tree from given array
////    long long * st = constructST(arr, n);
////
////    // Prlong long max of values in array
////    // from index 1 to 3
////    cout << "Max of values in given range = "
////    << getMax(st, n, 1, 3) << endl;
////
////    // Update: set arr[1] = 8 and update
////    // corresponding segment tree nodes.
////    updateValue(arr, st, 0, n - 1, 1, 8, 0);
////
////    // Find max after the value is updated
////    cout << "Updated max of values in given range = "
////    << getMax(st, n, 1, 3) << endl;
////
////    return 0;
//}
            
            
            //            long long next = i+1 >= size ? size-1 : i+1;
            //            while(vec[next] - vec [i] < = size_bound){
            //                //do stuff
            //                stack<long long >stk;
            //                stk.push_back(vec[i]);
            //                stk.push_back(vec[next]);
            //                //calculate max
            //
            //                //add to stack
            //
            //            }
            //            else{
            //                long long idx =vec[i];
            //                long long upper_bound = min(sz, idx + size_bound);
            //                long long lower_bound = max(1, idx - size_bound);
            //                lower_bound--;
            //                //        cout<<upper_bound<<" is ub "<<lower_bound<<" is l_b\n";
            //
            //                long long max_num = query_tr(lower_bound,upper_bound);
            //                long long max_num_stored = query_nums(lower_bound,upper_bound);
            //
            //                //                cout<<max_num<<" is the max num in range \n";
            //                if(num>max_num_stored){
            //                    updateTreeNode_tr(idx-1,max_num+1);
            //                    updateTreeNode_nums(idx-1,num);
            //                }
            //                else{
            //                    updateTreeNode_tr(idx-1,max_num);
            //                    updateTreeNode_nums(idx-1,num);
            //                }
            //            }
            
            
            
            //long long main()
            //{
            //    long long a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
            //
            //    // n is global
            //    n = sizeof(a)/sizeof(a[0]);
            //
            //    // build tree
            //    build(a);
            //
            //    // prlong long the sum in range(1,2) index-based
            //    cout << query(1, 3)<<endl;
            //
            //    // modify element at 2nd index
            //    updateTreeNode(2, 1);
            //
            //    // prlong long the sum in range(1,2) index-based
            //    cout << query(1, 3)<<endl;
            //
            //    return 0;
            //}
