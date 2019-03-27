#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll seg[4000005],lazy[4000005],a[1000001],n,m,x,l,r,y,z;
void check(ll p,ll s,ll e) {
    if(lazy[p]!=0) {
        seg[p] +=lazy[p];
        if(s!=e) {
            lazy[2*p] += lazy[p];
            lazy[2*p+1] += lazy[p];
        }
        lazy[p] = 0;
    }
}
void build(ll p,ll s,ll e) {
    check(p,s,e);
    
    if(s==e) {
        seg[p] = a[s];
        return;
    }
    
    build(2*p,s,(s+e)/2);
    build(2*p+1,(s+e)/2+1,e);
    
    seg[p] = (seg[2*p] + seg[2*p+1]);
}
void update(ll p,ll s,ll e,ll a,ll b,ll v) {
    check(p,s,e);
    
    if(s>=a && e<=b) {
        seg[p] +=v;
        
        if(s!=e) {
            lazy[2*p] += v;
            lazy[2*p+1] += v;
        }
        
        return;
    }
    
    if(s>b || e<a)
        return;
    
    update(2*p,s,(s+e)/2,a,b,v);
    update(2*p+1,(s+e)/2+1,e,a,b,v);
    
    seg[p] = (seg[2*p] + seg[2*p+1]);
}
ll get(ll p,ll s,ll e,ll a,ll b) {
    check(p,s,e);
    
    if(s>=a && e<=b)
        return seg[p];
    
    if(s>b || e<a)
        return INT_MAX;
    
    return (get(2*p,s,(s+e)/2,a,b)+get(2*p+1,(s+e)/2+1,e,a,b));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(seg,0,sizeof(seg));
    cin>>n>>m;
    for(ll i=0;i<n;i++)cin>>a[i];
    build(1,0,n-1);
    while(m--)
    {
        char c;
        cin>>c>>x>>y;
        x--,y--;
        if(c=='u')
        {
            cin>>z;
            update(1,0,n-1,x,y,z);
            continue;
        }
        cout<<get(1,0,n-1,x,y)<<'\n';
        
        
    }
    
    return 0;
}
