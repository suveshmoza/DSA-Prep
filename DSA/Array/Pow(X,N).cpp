//* Brute
double myPow(double x, int n) {
    if(n==0) return 1;
    else if(n>0){
      return x*myPow(x,n-1);
    }else{
      return (1/x)*myPow(x,n+1); 
    }
}

//* optimal
double myPow(double x, int n) {
    double ans=1.0;
    long long int n1=n;
    if(n1<0) n1*=-1;
    while(n1){
        if(n1%2==0){
            x*=x;
            n1/=2;
        }else{
            ans*=x;
            n1--;
        } 
    }
    if(n<0) return 1.0/ans;
    return ans;
}

//! 2^10 === (2*2)^5 === 4^5 === 4*4^4
//! 4^4 === (4*4)^2 === 16^2 === 256

