#include<bits/stdc++.h>
#include<stack>
using namespace std;
int main(){

    vector<int>arr =  {1, 3, 2, 4};  // [-1 -1 3 -1]
    stack<int>st;
    int n = arr.size();
    vector<int>ans;
    for(int i=0; i<n; i++){
        
        if(st.empty()) ans.push_back(-1);

        else if(!st.empty()  &&  st.top() > arr[i]) ans.push_back(st.top());

        else if(!st.empty() && st.top() <= arr[i]){

            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }
            if(st.empty()) ans.push_back(-1);
            else if(st.top() > arr[i]) ans.push_back(arr[i]);
        }

        st.push(arr[i]);
    }
    
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
