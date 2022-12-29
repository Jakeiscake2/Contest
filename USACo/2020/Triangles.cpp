#include<iostream>
#include<vector>
using namespace std;
int main(){
    
     freopen("triangles.in","r",stdin);
     freopen("triangles.out","w",stdout);
    int n=0;
    cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        cin>>v[i].second;
    }
    int maxarea=0;
    for(int i=0;i<v.size();i++){
        
        int maxy=0,maxx=0;
        for(int j=0;j<v.size();j++){
            if(v[i].second==v[j].second){
                maxx=max(maxx,abs(v[i].first-v[j].first));
            }
        }

        for(int j=0;j<v.size();j++){
            if(v[i].first==v[j].first){
                maxy=max(maxy,abs(v[i].second-v[j].second));
            }
        }
        maxarea=max(maxarea,maxy*maxx);
    }
    cout<<maxarea;
}

