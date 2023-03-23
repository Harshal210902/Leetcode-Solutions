int kConcatenationMaxSum(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = arr.size();
    int ans = 0;
    int sum =0;
    long long ttsum =0;
    for(int i =0;i<n*min(2,k);i++)
    {
         if(i<n)ttsum+=arr[i];
        sum+=arr[i%n];
        if(sum<arr[i%n])
        {
            sum = arr[i%n];
        }
        ans = max(ans,sum);

    }
    arr.clear();
    return (max(0ll,max((long long)ans,ttsum* max(0,k-2)+ans)))%1000000007;
}
