#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct node{
    int x;
};

int main(){
    node* x = (node*) malloc( sizeof( node) );
    x->x = 10;
    free( x );
    cout<<x->x;
    return 0;
}
