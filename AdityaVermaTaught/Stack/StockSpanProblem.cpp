#include<bits/stdc++.h>
using namespace std;

vector<int> NeareterGreaterToLeft(int *arr, int count){

    vector<int> v;
    stack<pair<int, int>> s;
    for (int i = 0; i < count; i++)
    {
        if(s.size() == 0) v.push_back(-1);
        else if(s.size() > 0 && s.top().first > arr[i]) v.push_back(s.top().second);
        else if(s.size() > 0 && s.top().first <= arr[i]){
            while(s.size() > 0 && s.top().first <= arr[i]){
                s.pop();
            }
            if(s.size() == 0) v.push_back(-1);
            else v.push_back(s.top().second);
        }
        s.push({arr[i], i});
    }

    for (int i = 0; i < v.size(); i++)
    {
        v[i] = i - v[i];
    }
    
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