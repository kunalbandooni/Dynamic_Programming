/*
Problem : We have to cut the rod in either a, b or c pieces, to
          obtain maximum no. of pieces exactly cut equal to "n".
          Given that, c > b > a
Input : 
    n: 5
    a: 1
    b: 2
    c: 3
Output : 5
  (1 + 1 + 1 + 1 + 1)        


Input : 
    n: 25
    a: 11
    b: 12
    c: 13
Output : 2
  (12 + 13)

*/
#include<iostream>
using namespace std;

// RECURSIVE METHOD
int max(int a,int b,int c){
    if(a>b&&a>c)
        return a;
    if(b>a&&b>c)
        return b;
    return c;
}
int max_c(int n,int a,int b,int c){
    if(n<0)
        return -1;
    if(n==0)
        return 0;
    int res=max(max_c(n-a,a,b,c),max_c(n-b,a,b,c),max_c(n-c,a,b,c));
    if(res<0)
        return -1;
    return res+1;
}

// MEMOIZATION (not working yet)
/*
int max_c(int n,int a,int b,int c){
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=-1;
        if(i-a>=0)
            dp[i]=max(dp[i],dp[i-a]);
        if(i-b>=0)
            dp[i]=max(dp[i],dp[i-b]);
        if(i-c>=0)
            dp[i]=max(dp[i],dp[i-c]);
    }
    return dp[n];
}
*/
int main(){
    int n,a,b,c;
    cout<<"n: ";
    cin>>n;
    cout<<"a: ";
    cin>>a;
    cout<<"b: ";
    cin>>b;
    cout<<"c: ";
    cin>>c;
    cout<<"Largest no. of pieces to cut into: "<<max_c(n,a,b,c);
    return 0;
}
