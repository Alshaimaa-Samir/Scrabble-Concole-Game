#include<bits/stdc++.h>
using namespace std;

int main(){
string temp;
stringstream ss;
freopen("dictionary.txt","r",stdin);
for(int i=0;i<61207;i++){
    cin>>temp;
    ss<<"\""<<temp<<"\",\n";
}
freopen("dictionary_new.txt","w",stdout);
cout<<ss.str();
}
