#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct yearage{
     int zodiac = 0;
     int year = 0;
};
int main(){

     //freopen("triangles.in","r",stdin);
     //freopen("triangles.out","w",stdout);
     map<string,int>zodiac = {{"Rat",1},{"Ox",2},{"Tiger",3},{"Rabbit",4},{"Dragon",5},{"Snake",6},{"Horse",7},{"Lamb",8},{"Monkey",9},{"Chicken",10},{"Dog",11},{"Pig",12},};
     // Rat Ox Tiger Rabit Dragon Snake Horse Lamb Monkey Chicken Dog Pig
     int n = 0;
     cin>>n;
     map<string,yearage>cows = {{"Bessie",{2,0}}};
     for(int i = 0;i<n;i++){
          vector<string>s(8);
          for(int j = 0;j<=7;j++){
               cin>>s[j];
          }
          string c1 = s[0],newCowZodiac = s[4],c2 = s[7];
          int cyear = cows[c2].year;
          int existingCowsZodiac = cows[c2].zodiac;
          if(s[3]=="previous"){
               cyear += zodiac[newCowZodiac];
               cyear -= existingCowsZodiac;
               cyear -= 12;
          }
          else if(s[3]=="next"){
               cyear += zodiac[newCowZodiac];
               cyear -= existingCowsZodiac;
          }
          cows.insert({c1,{zodiac[newCowZodiac],cyear}});
     }
     cout<<cows["Elsie"].year;
}
//Mildred born in previous Dragon year from Bessie -9
//Paulina born in next Dog year from Bessie +9