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
int lcs(string s1, string s2, int m, int n){
    if(m==0 || n==0)
        return 0;
    if(s1[m-1] == s2[n-1])
        return ( 1 + lcs(s1, s2, m-1, n-1));
    return ( max(lcs(s1, s2, m-1, n),lcs(s1, s2, m, n-1)));
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
