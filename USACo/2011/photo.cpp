#include<iostream>
#include<vector>   
#include<algorithm>         
#include <map>
#include<set>
using namespace std;
int main(){
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    int cownum=0;
    cin>>cownum;
    vector<pair<int,int>>v;
    set<int> s;
    for(int i=0;i<cownum;i++){
        int pos,id;
        cin>>pos>>id;
        v.push_back({pos,id});
        s.insert(id);
    }
    sort(v.begin(),v.end());
    int left=0,right=0;
    int counter=0;
    map<int,int> m;
    int minsize=INT_MAX;
    int unique=s.size();
    while(right<v.size()){
        if(counter== unique){
            while(counter== unique){
                m[v[left].second]--;
                if(m[v[left].second]==0){
                    counter--;
                }
                left++;
            }
            minsize=min(minsize,v[right].first-v[left].first);
        }
        else{
            if(m[v[right].second]==0){
                counter++;
            }
            m[v[right].second]++;
            right++;
        }
    }
    cout<<minsize;
}