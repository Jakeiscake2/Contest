#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
using namespace std;
int main(){

     //freopen("triangles.in","r",stdin);
     //freopen("triangles.out","w",stdout);
    long long n = 0;
    cin>>n;
    set<long long>s;
    map<long long,long long> m;
    vector<long long>v;
    for(int i = 0;i<n;i++){
        long long add;
        cin>>add;
        v.push_back(add);
    }
    sort(v.begin(),v.end());
    for(int i = 0;i<v.size();i++){
        s.insert(v[i]);
        if(m.count(v[i])==0){
            m.insert({v[i],i});
        }
    }
    long long maxMoney = 0;
    long long maxTuition = 0;
    for(long long i : s){
        long long money=0,tuition=i;
        money = (v.size()-m[i])*i;
        if(money>maxMoney){
            maxMoney = money;
            maxTuition=tuition;
        }
        else if(money==maxMoney){
            if(tuition<maxTuition){
                maxTuition = tuition ;
            }
        }
    }
    cout<<maxMoney<<" "<<maxTuition;





}

