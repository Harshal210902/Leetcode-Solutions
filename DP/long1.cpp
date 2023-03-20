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

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    if (n == 0)
        return true;
    for (int i = 0; i < flowerbed.size(); i++)
    {
        if(flowerbed[i]==0 && (i==0|| flowerbed[i-1]==0) && (i==flowerbed.size()-1 || flowerbed[i+1]==0))
        {
            n--;
            if(n==0) return true;
            flowerbed[i]=1;
        }
    }
    return false;
}

int main()
{
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    cout << canPlaceFlowers(flowerbed, 2);
}