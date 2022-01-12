// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
  long long int countSubarrays(const vector<int>& arr, int n, long long k)
{
    long long start = 0, end = 0, count = 0, sum = arr[0];

    while (start < n && end < n)
    {

        if (sum < k)
        {
            end++;

            if (end >= start)
                count += end - start;

            if (end < n)
                sum *= arr[end];
        }

        else
        {
            sum/= arr[start];
            start++;
        }
    }

    return count;
}
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        return countSubarrays(a,n,k);
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends