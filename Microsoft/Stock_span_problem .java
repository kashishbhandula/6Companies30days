
// { Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class gfg {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int a[] = new int[n];

            int i = 0;
            for (i = 0; i < n; i++)
                a[i] = sc.nextInt();

            int[] s = new Solution().calculateSpan(a, n);

            for (i = 0; i < n; i++) {
                System.out.print(s[i] + " ");
            }

            System.out.println();
        }
    }

}// } Driver Code Ends

class Solution {
    // Function to calculate the span of stockâ€™s price for all n days.
    public static int[] calculateSpan(int arr[], int n) {
        // Your code here
        Stack<Integer> st = new Stack<>();
        int dp[] = new int[n];
        // dp[n]=0;
        for (int i = n - 1; i >= 0; i--) {
            // dp[i]=1;
            while (!st.isEmpty() && arr[i] > arr[st.peek()]) {
                dp[st.peek()] = st.peek() - i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.isEmpty()) {
            dp[st.peek()] = st.peek() + 1;
            st.pop();
        }
        return dp;

    }

}