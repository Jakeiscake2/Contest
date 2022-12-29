#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;

int main(){
    int n = 0;
    cin>>n;
    vector<double>v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    double smallest = INT_MAX;
    for(int currentv = 1;currentv<(int)v.size()-1;currentv++){
        double forward = abs((v[currentv]-v[currentv-1])/2);
        double backward = abs((v[currentv+1]-v[currentv])/2);
        smallest = min(forward+backward,smallest);
    }
    cout<<fixed<<setprecision(1)<<smallest<<" ";
}