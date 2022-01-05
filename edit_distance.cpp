/*
Problem: Minimum number of operations required to convert s1 into s2
      Insert / Delete / Replace charactes...
      
Input:
  s1: James Bond
  s2: James B
Output: 3
  (Delete o n d)

Input:
  s1: Saturday
  s2: Sunday
Output: 3
  (Delete a t) (Replace r with n)

*/
#include<iostream>
using namespace std;
int min(int a,int b,int c){
    if(a<b&&a<c)
        return a;
    if(b<a&&b<c)
        return b;
    return c;
}

// RECURSIVE
int edit_distance(string s1, string s2, int m, int n){
    if(m==0)
        return n;
    if(n==0)
        return m;
    if(s1[m-1]==s2[n-1])
        return edit_distance(s1,s2,m-1,n-1);
    else
        return (1 + min(edit_distance(s1,s2,m,n-1),edit_distance(s1,s2,m-1,n),edit_distance(s1,s2,m-1,n-1)));
}

// MEMOIZATION
int edit_distance(string s1, string s2, int m, int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
        }
    }
    return dp[m][n];
}

int main(){
    string s1,s2;
    cout<<"s1: ";
    cin>>s1;
    cout<<"s2: ";
    cin>>s2;
    cout<<"Output: "<<edit_distance(s1,s2,s1.length(),s2.length());
    return 0;
}
