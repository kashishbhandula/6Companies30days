// { Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int N = sc.nextInt();
            int P = sc.nextInt();
            int prerequisites[][] = new int[P][2];
            for (int i = 0; i < P; i++) {
                for (int j = 0; j < 2; j++) {
                    prerequisites[i][j] = sc.nextInt();
                }
            }
            Solution ob = new Solution();
            if (ob.isPossible(N, prerequisites)) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
            t--;
        }
    }

}
// } Driver Code Ends

// User function Template for Java

class Solution {
    public boolean isPossible(int N, int[][] pre) {
        // Your Code goes here
        ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < N; i++)
            graph.add(new ArrayList<Integer>());
        int edge = pre.length;
        int indegree[] = new int[N];
        for (int i = 0; i < edge; i++) {
            graph.get(pre[i][0]).add(pre[i][1]);
            indegree[pre[i][1]]++;
        }
        Queue<Integer> q = new LinkedList<Integer>();
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0)
                q.add(i);
        }
        int cnt = 0;
        while (!q.isEmpty()) {
            int node = q.peek();
            cnt++;
            q.poll();
            for (int it : graph.get(node)) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.add(it);
                }
            }
        }
        if (cnt == N)
            return true;
        else
            return false;

    }

}