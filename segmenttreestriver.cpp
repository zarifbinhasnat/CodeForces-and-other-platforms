//segment tree is a data structure which is very good and efficient for range queries
//segment tree is a binary tree which is used to store the intervals or segments.
//Each node in the segment tree represents an interval.
//The root node of the segment tree represents the whole array.
//The segment tree is a full binary tree, which means that each node has either 0 or 2 children.
//The segment tree is a binary tree, so the height of the tree is log(n) where n is the number of elements in the array.
//The segment tree is a binary tree, so the number of nodes in the tree is 2n-1 where n is the number of elements in the array.
//The segment tree is a binary tree, so the number of leaf nodes in the tree is n where n is the number of elements in the array.
//The segment tree is a binary tree, so the number of internal nodes in the tree is n-1 where n is the number of elements in the array.
//The segment tree is a binary tree, so the number of nodes at level i in the tree is 2^i where i is the level of the tree. 
#include<bits/stdc++.h>
using namespace std;
 class segmenttree{
    private:
    vector<int> tree;
    vector<int> arr;
    int n;
    public:
    segmenttree(vector<int> a){
        arr=a;
        n=a.size();
        tree.resize(4*n);
        build(1,0,n-1);
    }
    void build(int node,int start,int end){
        if(start==end){
            tree[node]=arr[start];
        }
        else{
            int mid=(start+end)/2;
            build(2*node,start,mid);
            build(2*node+1,mid+1,end);
            tree[node]=tree[2*node]+tree[2*node+1];
        }
    }
    //update function
    //idx is the index of the element to be updated
    //val is the value to be updated
    void update(int idx,int val){
        update(1,0,n-1,idx,val);
    }
    //query function
    int query(int node,int start,int end,int l,int r){
        if(r<start || end<l){
            return 0;
        }
        if(l<=start && end<=r){
            return tree[node];
        }
        int mid=(start+end)/2;
        int p1=query(2*node,start,mid,l,r);
        int p2=query(2*node+1,mid+1,end,l,r);
        return p1+p2;
    }
    void update(int node,int start,int end,int idx,int val){
        if(start==end){
            arr[idx]=val;
            tree[node]=val;
        }
        else{
            int mid=(start+end)/2;
            if(start<=idx && idx<=mid){
                update(2*node,start,mid,idx,val);
            }
            else{
                update(2*node+1,mid+1,end,idx,val);
            }
            tree[node]=tree[2*node]+tree[2*node+1];
        }
    }

 };