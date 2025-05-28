#include<bits/stdc++.h>
using namespace std;
int main(){
    int low =1000, high = 9999;
    vector<int>ans;
    //123, 234, 345, ...  
    for(int digit=low; digit<= high; digit++){
        
        string str = to_string(digit);
        bool flag = true;
        for(int i=0; i<str.length()-1; i++)
        {
            if(str[i+1] - str[i] != 1 ) { flag = false; break;}
        }
        if(flag) ans.push_back(stoi(str));
    }
    // cout<<"HEL";
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}