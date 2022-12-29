#include <iostream>
using namespace std;
int main() {
  string s="";
  cin>>s;
  for(int i=0;i<s.size()-1;i++){
    char c=s[i];
    if(c=='+'){
      cout<<" tighten ";
    }
    else if(c=='-'){
      cout<<" loosen ";
    }
    else if(c<='9'&&c>='0'&&(s[i+1]>'9'||s[i+1]<'0')){
        cout<<c<<endl;
    }
    else{
      cout<<c;
    }
  }
  cout<<s[s.size()-1];
}