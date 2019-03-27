#include<iostream>
#include<vector>
using namespace std;

vector<int> merge(vector<int> &a, vector<int> &b){
    vector<int> vec;
    int a_n = a.size();
    int b_n = b.size();
    int x = 0,y = 0;
    while(x<a_n&&y<b_n){
        if(a[x]>b[y]){
            vec.push_back(b[y]);
            y++;
        }
        else{
            vec.push_back(a[x]);
            x++;
        }
    }
    if(x==a_n){
        for(int i = y; i <b_n;i++){
            vec.push_back(b[i]);
        }
    }
    if(y==b_n){
        for(int i = x; i <a_n;i++){
            vec.push_back(a[i]);
        }
    }
    return vec;
}

vector<int> merge_sort(vector<int> &a){
    vector<int> vec1,vec2;
    if(a.size()>1){
        //split and call mergesort
        for(int  i = 0; i < a.size()/2; i++){
            vec1.push_back(a[i]);
        }
        for(int  i = a.size()/2; i < a.size(); i++){
            vec2.push_back(a[i]);
        }
        vec1 = merge_sort(vec1);
        vec2 = merge_sort(vec2);
        a = merge(vec1,vec2);
    }
    return a;
}



int main(){
    int n;
    cin>>n;
    vector<int>a;
    for(int i = 0; i < n; i ++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    a = merge_sort(a);
    for(int i = 0; i < n; i ++){
        cout<<a[i]<<" ";
    }
}
