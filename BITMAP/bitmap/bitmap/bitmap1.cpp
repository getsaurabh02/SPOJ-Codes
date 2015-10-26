/*
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
 
int scan[185][185];
int ans[185][185];
int nx[35000];
int ny[35000];
int N,M,test;
//computing distance
 int dis(int i,int j,int k ,int l){
        inone=i-k;
        int two=j-l;
        if (one<0)one*=-1;
        if (two<0)two*=-1;
        return one+two;
    }
 
 
//my dfs function 
void dfs(int n,int m,int i,int j){

        if(i>=0&&i<N&&j>=0&&j<M){

        if (scan[i][j]==1)return;

        int d=dis(n,m,i,j);

        if(ans[i][j]<=d)return;

        ans[i][j]=d;

        dfs(n,m,i,j+1);
        dfs(n,m,i,j-1);
        dfs(n,m,i-1,j);
        dfs(n,m,i+1,j);
	}
	else return;
}
 
 
 
int main(){
 
      int n;
      string s;
                //getting number of testcase
      scanf("%d",&test);
       for(int t=0;t<test;t++){
           n=0;
                        //getting row and column
           scanf("%d %d",&N,&M);
           for(int i=0;i<N;i++)
                for(int j=0;j<M;j++)ans[i][j]=35000;
 
                        //getting input
           for(int i=0;i<N;i++){
               cin>>s;
               for(int j=0;j<M;j++){   
                   scan[i][j]=s[j]-'0';
                   if(scan[i][j]==1){
                            nx[n]=i;ny[n]=j;
                            n++;
                   }                                     
               }
           }
           //starts searching
           for(int i=0;i<n;i++){
               ans[nx[i]][ny[i]]=0;
               dfs(nx[i],ny[i],nx[i],ny[i]+1);
               dfs(nx[i],ny[i],nx[i],ny[i]-1);
               dfs(nx[i],ny[i],nx[i]+1,ny[i]);
               dfs(nx[i],ny[i],nx[i]-1,ny[i]);
           }
 
           //printing
           for(int i=0;i<N;i++){
               for(int j=0;j<M;j++){
                   printf("%d ",ans[i][j]);
                } 
               printf("\n");
           }
 
       }
        return 0;
}
*/