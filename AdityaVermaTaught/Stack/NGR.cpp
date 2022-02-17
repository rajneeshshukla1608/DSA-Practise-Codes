#include<bits/stdc++.h>
using namespace std;

vector<int> NeareterGreaterToLeft(int *arr, int count){
    vector<int> v;
    stack<int> s;
    for (int i = count - 1; i >= 0; i--)
    {
        if(s.size() == 0) v.push_back(-1);
        else if(s.size() > 0 && s.top() > arr[i]) v.push_back(s.top());
        else if(s.size() > 0 && s.top() <= arr[i]){
            while(s.size() > 0 && s.top() <= arr[i]){
                s.pop();
            }
            if(s.size() == 0) v.push_back(-1);
            else v.push_back(s.top());
        }
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}

 int main(){
    int n;
    int save;
    cout<<"Enter the size of the array";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements to the array";
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    
    vector<int> vec = NeareterGreaterToLeft(arr, n);
    for (auto x : vec)
        cout << x << ' ';
    
    return 0;
 }