#include <cstdio>
#include<iostream>
using namespace std;
 
const int MAX = 200000; 

int tree[MAX];
int lazy[MAX];

inline int update_tree(int node, int a, int b, int i, int j) {

  	if(lazy[node]) { 
        
        tree[node] = (b-a+1) - tree[node]; 
               
		if(a != b) {
			lazy[node*2] ^= 1; 
    		lazy[node*2+1] ^= 1; 
		}
 
   		lazy[node] = 0; 
  	}
  
	  if(a > b || a > j || b < i)
        return 0;

    
  	if(a >= i && b <= j) { 

        tree[node] = (b-a+1) - tree[node]; 

       if(a != b) { 
			lazy[node*2] ^= 1;
			lazy[node*2+1] ^= 1;
		}
 
    		return 0;
	}
 
	update_tree(node*2, a, (a+b)/2, i, j); 
	update_tree(1+node*2, 1+(a+b)/2, b, i, j); 
 
	tree[node] = tree[node*2] + tree[node*2+1]; 

    return 0;
}
 

inline int query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return 0; 
 
	if(lazy[node]) { 

        tree[node] = (b-a+1) - tree[node];
 
		if(a != b) {
			lazy[node*2] ^= 1;
			lazy[node*2+1] ^= 1; 
		}
 
		lazy[node] = 0;
	}
 
	if(a >= i && b <= j)
		return tree[node];
 
	int q1 = query_tree(node*2, a, (a+b)/2, i, j); 
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);
 
	int res = q1 + q2;
	
	return res;
}
 
int main() {
    int nooflights, testcases, cmd, lb, ub;
    scanf ("%d%d",&nooflights,&testcases);
    
    memset(lazy, 0, sizeof(lazy));
    memset(tree, 0, sizeof(tree));

    while (testcases) {
        scanf ("%d%d%d",&cmd,&lb,&ub);
     
        !cmd ? update_tree(1,0,nooflights-1,lb-1,ub-1) : printf("\n%d", query_tree(1,0,nooflights-1,lb-1,ub-1));


        testcases --;
       
    }
	return 0;
}


