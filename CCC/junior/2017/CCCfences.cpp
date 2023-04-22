#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int n;
    cin>>n;
    int array[2000];
    
    vector<int> v(n);
    for(int i = 0;i<n;i++){
        int j;
        cin>>j;
        v[j]++;
    }

    
    if(n<=2){
        cout<<"1 1";
        return 0;
    }
    int most_length = 0,ways_for_max = 0;
    for(int i = 0;i<=2000;i++){
        int count_pairs = 0;
        for(int j = 0;j<=i;j++){
            count_pairs += min(v[j],v[i-j]);
        }
        if(count_pairs==most_length&&count_pairs!=0){
            ways_for_max++;
        }
        else if(count_pairs>most_length){
            most_length = count_pairs;
            ways_for_max = 1;
        }
    }
    cout<<most_length<<" "<<ways_for_max;
}


//counting array 1 to 2000
//adj kinda
//if need 5 
//go through, 1, is there a 4, 2, is there a 3
//n time complexity
