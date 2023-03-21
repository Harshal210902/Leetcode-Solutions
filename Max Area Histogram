#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(false);
#define print(array)      \
    for (auto it : array) \
    cout << it << " "
#define sortit(array) sort(array.begin(), array.end())
const int M = 1e9 + 7;

int largestRectangleArea(vector<int>& heights) {
        int n =heights.size();
    vector<int> leftsmall(n,0);
    vector<int> rightsmall(n,n-1);
    stack<int> st;
    for(int i =0;i<n;i++)
    {
        while(!st.empty() && heights[st.top()]>=heights[i])
        {
            st.pop();
        }
        if(!st.empty()) leftsmall[i] = st.top()+1;
        st.push(i);
    }

    
    while(!st.empty())
    {
        st.pop();
    }

    for(int i =n-1;i>=0;i--)
    {
        while(!st.empty() && heights[st.top()]>=heights[i])
        {
            st.pop();
        }
        if(!st.empty()) rightsmall[i] = st.top()-1;
        st.push(i);
    }
    
    while(!st.empty())
    {
        st.pop();
    }
    int maxi=0;
    for(int i =0;i<n;i++)
    {
        maxi = max(maxi, (rightsmall[i]-leftsmall[i]+1)*heights[i]);
    }

    return maxi;
    }
    
int main()
{
    vector<int> heights = {2,1,5,6,2,3};
    cout<<largestRectangleArea(heights);
}
