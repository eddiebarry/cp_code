#include<iostream>
#include<vector>
using namespace std;


void qsort(int a[], int start,int end){
    //pick random(first element;
    int x = a[start];
    //partition
    int st = start, en = end-1;
    int i = st;
    while(st!=en){
        while(a[i]>x){
            int temp = a[i];
            a[i]=a[en];
            a[en]=temp;
            en--;
        }
        while(a[i]<x){
            int temp = a[i];
            a[i]=a[st];
            a[st]=temp;
            st++;
        }
        i++;
        for(int x = start; x <end; x++){
            cout<<a[x]<<" ";
        }
    }
    for(i = start; i <end; i++){
        cout<<a[i]<<" ";
    }
    
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i ++){
        int x;
        cin>>x;
        arr[i]=x;
    }
    qsort(arr,0,n);
    for(int i = 0; i < n; i ++){
        cout<<arr[i]<<" ";
    }
}
