/*
    Longest Common Subsequence
    - Here, we started checking from the last one, and kept on adding "1" 
        to the result if subsequence was equal
    INPUT : abcdefg, abduceg
    OUTPUT: 5
    Explanation : abceg    // abdeg
            (both can be the possible solutions)
*/
#include<iostream>
using namespace std;
// Tabulation
int lcs(string s1, string s2, int m, int n){
    if(m==0 || n==0)
        return 0;
    if(s1[m-1] == s2[n-1])
        return ( 1 + lcs(s1, s2, m-1, n-1));
    return ( max(lcs(s1, s2, m-1, n),lcs(s1, s2, m, n-1)));
}
// Memoization
int lcs(string s1,string s2,int n,int m){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0)
                dp[i][j]=0;
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int main(){
    string s1,s2;
    cout<<"Enter first string: ";
    cin>>s1;
    cout<<"Enter second string: ";
    cin>>s2;
    cout<<"Longest Common Subsequence: "<<lcs(s1,s2,s1.length(),s2.length());
    return 0;
}
