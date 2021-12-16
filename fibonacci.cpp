/*
  FIBONACCI USING MEMOIZATION
  - All we did here was store the smaller values,
      so that we do not have to find them again using recursion and
      again. That was simple and easy :D
  - So, simply store them and use them later 
      condition //123 is where I did this.
*/
#include<iostream>
#include<cstring>
using namespace std;
int memo[100+1];        // generally memo[n+1]
int fibonacci(int n){
    if(memo[n]!=-1)       //123   (want to know what's this, see up ^)
        return memo[n];
    if(n==0 || n==1)
        return n;
    memo[n] = fibonacci(n-1) + fibonacci(n-2);
    return memo[n];
}
int main(){
    int n;
    cout<<"If fibonacci starts from 0 1 1 2 ... \t starting from position 0"<<endl;
    cout<<"Enter no. of element to be found: ";
    cin>>n;
    memset(memo,-1,sizeof(memo));
    cout<<"Element present at "<<n<<" position is: "<<fibonacci(n);
    return 0;
}
