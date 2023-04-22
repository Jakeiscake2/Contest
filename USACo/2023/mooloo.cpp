#include <iostream>
using namespace std;
int main() {
    long long n,k;
    cin>>n>>k;

    k+=1;
    long long spent = k;
    long long last_bought=0;
    cin>>last_bought;
    
    for(long long i=0;i<n-1;i++){
        long long today;
        cin>>today;
        long long time_passed = today - last_bought;
        spent+=min(k,time_passed);
        last_bought=today;
    }
        cout<<spent;
}

//if difference between days is greater than k
//buy new
//else buy one