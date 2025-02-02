#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;
#define ll long long
#define vll vector<long long>  
#define MOD 998244353
const int N=1000005;
ll int fact[N],invfact[N];

//OPTIMISATION TO SOLVE IN CONST TIME INSTEAD OF LOGN
ll int pow(ll int a,ll int b,ll int m){
    ll int ans =1;
    while(b){
        if(b&1)
        ans=(ans*a)%m;
        b/=2;
        a=(a*a)%m;
    }
    return ans;
}

ll int modinv(ll int k){
    return pow(k,MOD-2,MOD); //MOD-2->INVERSE CALCULATION
}

void precompute(){
    fact[0]=fact[1]=1;
    for(int i=2;i<N;i++){
        fact[i]=fact[i-1]*i;
        fact[i]%=MOD;
    }
    invfact[N-1]=modinv(fact[N-1]); //Optimization->logn ->O(1)
    for(int i=N-2;i>=0;i--){
        invfact[i]=invfact[i+1]*(i+1);
        infact[i]%=MOD;
    }
}
ll int nCr(ll int x,ll int y){
    if(y>x)
    return 0;
    ll int num=fact[x];
    num*=invfact[y];
    num%=MOD;
    num*=invfact[x-y];
    num%=MOD;
    return num;
    
}

void main(){
    precompute();

    int t;
    cin>>t;
    while(t--){

    }
    return 0;
}