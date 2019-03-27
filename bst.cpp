#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
    int data;
    node* left_child;
    node* right_child;
};

node* new_node(int data){
    node* x = new node;
    x->left_child=NULL;
    x->right_child=NULL;
    x->data = data;
    return x;
}

node* find_successor(node* x){
    if(x==NULL){
        return x;
    }
    while(x->left_child!=NULL){
        x=x->left_child;
    }
//    cout<<x<<"\n";
    return x;
}

node* find_predecessor(node* x){
    if(x==NULL){
        return x;
    }
    while(x->right_child!=NULL){
        x=x->right_child;
    }
//    cout<<x<<"\n";
    return x;
}

void insert(node *x,int data){
    //insert at right
    if(data > x->data){
        if(x->right_child!=NULL){
            insert(x->right_child,data);
        }
        else{
            x->right_child = new_node(data);
        }
    }
    
    //insert at left
    if(data < x->data){
        if(x->left_child!=NULL){
            insert(x->left_child,data);
        }
        else{
            x->left_child = new_node(data);
        }
    }
}

void pre_order(node* x){
    if(x==NULL){
        return;
    }
    cout<<x->data<<" --- ";
    pre_order(x->left_child);
    pre_order(x->right_child);
}

void post_order(node* x){
    if(x==NULL){
        return;
    }
    post_order(x->left_child);
    post_order(x->right_child);
    cout<<x->data<<" --- ";
}

void in_order(node* x){
    if(x==NULL){
        return;
    }
    in_order(x->left_child);
    cout<<x->data<<" --- ";
    in_order(x->right_child);
   
}

void del(node *x, int data){
    if(x==NULL){
        return;
    }
    if(data < x->data){
        del(x->left_child,data);
    }
    else if(data > x->data){
        del(x->right_child,data);
    }
    else{
        //x->data== data;
        if(x->left_child==NULL && x->right_child==NULL){
            cout<<"x is "<<x<<"\n";
            delete x;
            cout<<x->data<<"\n";
            cout<<"node has been deleted\n";
        }
        else if(x->left_child!=NULL){
            node* temp = find_predecessor(x->left_child);
            x->data = temp->data;
            cout<<temp<<"\n";
            del(x->left_child, temp->data);
        }
        else if(x->right_child!=NULL){
            node* temp = find_successor(x->right_child);
            x->data = temp->data;
//            cout<<temp<<"\n";
            del(x->right_child, temp->data);
        }
        
    }
}

int main(){
    node* root;
    cout<<"insert no of elements\n";
    int x;
    cin>>x;
    
    x--;
    int ruut;
    cin>>ruut;
    root = new_node(ruut);
    while(x--){
        int x;
        cin>>x;
        insert(root,x);
    }
    pre_order(root);
    cout<<"\n\n";
    del(root, 45);
//    del(root, 2);

    pre_order(root);
    cout<<"\n";
    post_order(root);
    cout<<"\n";
    in_order(root);
    cout<<"\n";
}



