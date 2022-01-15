
// { Driver Code Starts
import java.util.*;
import java.io.*;

class GFG {
    public static void main(String[] args) {

        // taking input using Scanner class
        Scanner sc = new Scanner(System.in);

        // taking count of testcases
        int t = sc.nextInt();
        while (t-- > 0) {

            // taking count of houses
            int n = sc.nextInt();
            int arr[] = new int[n];

            // inserting money present in
            // each house in the array
            for (int i = 0; i < n; ++i)
                arr[i] = sc.nextInt();

            // calling method FindMaxSum() of class solve
            System.out.println(new Solution().FindMaxSum(arr, n));
        }
    }
}// } Driver Code Ends

class Solution {
    // Function to find the maximum money the thief can get.
    public int FindMaxSum(int arr[], int n) {
        // Your code here
        int dp[][] = new int[2][10004];
        dp[1][0] = arr[0];
        dp[0][0] = 0;
        for (int i = 1; i < n; i++) {
            if (i >= 2)
                dp[1][i] = Math.max(dp[1][i - 2], dp[0][i - 2]);
            dp[1][i] = Math.max(dp[1][i], dp[0][i - 1]);
            dp[1][i] += arr[i];
            dp[0][i] = Math.max(dp[1][i - 1], dp[0][i - 1]);

        }
        return Math.max(dp[0][n - 1], dp[1][n - 1]);
    }
}