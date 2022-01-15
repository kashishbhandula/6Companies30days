
// { Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int n = Integer.parseInt(s[0]);
            int m = Integer.parseInt(s[1]);
            int[][] grid = new int[n][m];
            for (int i = 0; i < n; i++) {
                String[] S = br.readLine().trim().split(" ");
                for (int j = 0; j < m; j++) {
                    grid[i][j] = Integer.parseInt(S[j]);
                }
            }
            Solution obj = new Solution();
            int ans = obj.findMaxArea(grid);
            System.out.println(ans);
        }
    }
}// } Driver Code Ends

class Solution {
    // Function to find unit area of the largest region of 1s.
    int dp[][] = new int[501][501];
    int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
    int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };

    public int Recursion(int x, int y, int grid[][]) {
        int n = grid.length;
        int m = grid[0].length;
        int cnt = 1;
        // int ans=0;
        if (dp[x][y] != -1)
            return dp[x][y];
        for (int k = 0; k < 8; k++) {
            int i = x + dx[k];
            int j = y + dy[k];

            if (i >= 0 && j >= 0 && i < n && j < m) {

                if (grid[i][j] == 1) {
                    grid[i][j] = 2;
                    cnt += Recursion(i, j, grid);
                    // grid[i][j]=1;
                }

            }

        }
        return dp[x][y] = cnt;

    }

    public int findMaxArea(int[][] grid) {
        // Code here
        int n = grid.length;
        int m = grid[0].length;
        int cnt = 0;
        for (int i = 0; i < 501; i++) {
            for (int j = 0; j < 501; j++) {
                dp[i][j] = -1;
            }

        }
        // int cnt=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 2;
                    cnt = Math.max(cnt, Recursion(i, j, grid));
                    // grid[i][j]=1;
                }
            }
        }
        return cnt;

    }
}