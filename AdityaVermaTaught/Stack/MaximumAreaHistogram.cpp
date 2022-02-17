#include<bits/stdc++.h>
using namespace std;

// NSL starts here
vector<int> NearestSmallerToLeft(int *arr, int count){
    vector<int> left;
    stack<pair<int, int>> s;
    int pseudocode = -1;
    for (int i = 0; i < count; i++)
    {
        if(s.size() == 0) left.push_back(pseudocode);
        else if(s.size() > 0 && s.top().first < arr[i]) left.push_back(s.top().second);
        else if(s.size() > 0 && s.top().first >= arr[i]){
            while(s.size() > 0 && s.top().first >= arr[i]){
                s.pop();
            }
            if(s.size() == 0) left.push_back(pseudocode);
            else left.push_back(s.top().second);
        }
        s.push({arr[i], i});
    }
    return left;
}
// NSL ends here

// NSR starts here
vector<int> NearestSmallerToRight(int *arr, int count){
    vector<int> right;
    stack<pair<int, int>> s;
    int pseudocode = 7;
    for (int i = count - 1; i >= 0; i--)
    {
        if(s.size() == 0) right.push_back(pseudocode);
        else if(s.size() > 0 && s.top().first < arr[i]) right.push_back(s.top().second);
        else if(s.size() > 0 && s.top().first >= arr[i]){
            while(s.size() > 0 && s.top().first >= arr[i]){
                s.pop();
            }
            if(s.size() == 0) right.push_back(pseudocode);
            else right.push_back(s.top().second);
        }
        s.push({arr[i], i});
    }
    reverse(right.begin(), right.end());
    return right;
}
// NSR ends here
int main(){
    int n;
    cout<<"Enter the size of the Histogram: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements to the Histogram: ";
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    vector<int> right = NearestSmallerToRight(arr, n);
    vector<int> left = NearestSmallerToLeft(arr, n);
    vector<int> width;
    for (int i = 0; i < n; i++)
    {
        width[i] = right[i] - left[i] - 1;
    }
    vector<int> area;
    for (int i = 0; i < n; i++)
    {
        area[i] = width[i] * arr[i];
    }
    cout<<*max_element(area.begin(), area.end());
    return 0;
}