/**
 * In this code we have a very large array called arr, and very large set of operations
 * Operation #1: Increment the elements within range [i, j] with value val
 * Operation #2: Get max element within range [i, j]
 * Build tree: build_tree(1, 0, N-1)
 * Update tree: update_tree(1, 0, N-1, i, j, value)
 * Query tree: query_tree(1, 0, N-1, i, j)
 */
#include <cstdio>
#include<iostream>
using namespace std;
 
const int MAX = 200000; // Why? :D


int tree[MAX];
int lazy[MAX];
 
/**
 * Increment elements within range [i, j] with value value
 */
inline int update_tree(int node, int a, int b, int i, int j) {

  	if(lazy[node]) { // This node needs to be updated

        tree[node] = (b-a+1) - tree[node]; // Update it
       
		if(a != b) {
			lazy[node*2] ^= 1; // Mark child as lazy
    		lazy[node*2+1] ^= 1; // Mark child as lazy
		}
 
   		lazy[node] = 0; // Reset it
  	}
  
	  if(a > b || a > j || b < i) // Current segment is not within range [i, j]
        return 0;

    
  	if(a >= i && b <= j) { // Segment is fully within range

        tree[node] = (b-a+1) - tree[node]; // Update it

       if(a != b) { // Not leaf node
			lazy[node*2] ^= 1;
			lazy[node*2+1] ^= 1;
		}
 
    		return 0;
	}
 
	update_tree(node*2, a, (a+b)/2, i, j); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j); // Updating right child
 
	tree[node] = tree[node*2] + tree[node*2+1]; // Updating root with max value

    return 0;
}
 
/**
 * Query tree to get on element value within range [i, j]
 */
inline int query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return 0; // Out of range
 
	if(lazy[node]) { // This node needs to be updated

        tree[node] = (b-a+1) - tree[node]; // Update it
 
		if(a != b) {
			lazy[node*2] ^= 1; // Mark child as lazy
			lazy[node*2+1] ^= 1; // Mark child as lazy
		}
 
		lazy[node] = 0; // Reset it
	}
 
	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];
 
	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child
 
	int res = q1 + q2; // Return final result
	
	return res;
}
 
int main() {
    int nooflights, testcases, cmd, lb, ub;
    scanf ("%d",&nooflights);
    scanf ("%d",&testcases);

    memset(lazy, 0, sizeof(lazy));
    memset(tree, 0, sizeof(tree));

    while (testcases) {
        scanf ("%d%d%d",&cmd,&lb,&ub);
        //scanf ("%d",&lb);
        //scanf ("%d",&ub);

        !cmd ? update_tree(1,0,nooflights-1,lb-1,ub-1) : printf("\n%d", query_tree(1,0,nooflights-1,lb-1,ub-1));


        testcases --;
       
    }
	return 0;
}

