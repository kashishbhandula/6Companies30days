
// { Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class DriverClass {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            ArrayList<ArrayList<Integer>> list = new ArrayList<>();
            int V = sc.nextInt();
            int E = sc.nextInt();
            for (int i = 0; i < V + 1; i++)
                list.add(i, new ArrayList<Integer>());
            for (int i = 0; i < E; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                list.get(u).add(v);
                list.get(v).add(u);
            }
            int c = sc.nextInt();
            int d = sc.nextInt();

            Solution ob = new Solution();

            System.out.println(ob.isBridge(V, list, c, d));
        }
    }
}// } Driver Code Ends

// User function Template for Java

class Solution {
    // Function to find if the given edge is a bridge in graph.
    static int timer = 0;

    static void Dfs(int node, ArrayList<ArrayList<Integer>> graph, int Ins[], int Low[], int vis[],
            ArrayList<ArrayList<Integer>> st, int par) {
        vis[node] = 1;
        Ins[node] = Low[node] = timer++;
        for (int it : graph.get(node)) {
            if (par == it)
                continue;

            if (vis[it] == 0) {

                Dfs(it, graph, Ins, Low, vis, st, node);
                Low[node] = Math.min(Low[it], Low[node]);
                if (Low[it] > Ins[node]) {
                    st.add(new ArrayList<Integer>(Arrays.asList(it, node)));
                    st.add(new ArrayList<Integer>(Arrays.asList(node, it)));
                }

            } else {
                Low[node] = Math.min(Ins[it], Low[node]);
            }

        }

    }

    static int isBridge(int V, ArrayList<ArrayList<Integer>> adj, int c, int d) {
        timer = 1;
        ArrayList<ArrayList<Integer>> st = new ArrayList<ArrayList<Integer>>();
        int vis[] = new int[V];
        int Low[] = new int[V];
        int Ins[] = new int[V];
        // int vis[]=new int[V];

        for (int i = 0; i < V; i++) {
            if (vis[i] == 0)
                Dfs(i, adj, Ins, Low, vis, st, -1);
        }

        ArrayList<Integer> temp = new ArrayList<Integer>(Arrays.asList(c, d));
        if (st.contains(temp)) {
            return 1;
        }
        return 0;

        // code here
    }
}