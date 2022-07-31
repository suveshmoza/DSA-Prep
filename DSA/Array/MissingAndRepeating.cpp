pair<int,int> missingAndRepeating(vector<int> &arr, int n){
    ll sum1 = ( (ll)n * (ll)(n+1) )/2;
    ll sum2 = ( (ll)n * (ll)(n+1) * (ll)(2*n+1) )/6;
    ll sum3=0, sum4=0;
    for(int i=0;i<n;i++){
        sum3 += ( (ll)arr[i] );
        sum4 += ( (ll)arr[i] * (ll)arr[i] );
    }
    ll sub=sum3-sum1;
    ll add=(sum4-sum2)/sub;
    return {add-(add+sub)/2,(add+sub)/2};
}   