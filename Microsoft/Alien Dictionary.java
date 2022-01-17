public class Alien Dictionary {
    
}
// { Driver Code Starts
/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
import java.math.*;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = Integer.parseInt(sc.next());
        while (t-- > 0) {
            int n = Integer.parseInt(sc.next());
            int k = Integer.parseInt(sc.next());

            String[] words = new String[n];

            for (int i = 0; i < n; i++) {
                words[i] = sc.next();
            }

            Solution ob = new Solution();
            // System.out.println(T.findOrder(words,k));
            String order = ob.findOrder(words, n, k);
            if (order.length() == 0) {
                System.out.println(0);
                continue;
            }
            String temp[] = new String[n];
            for (int i = 0; i < n; i++)
                temp[i] = words[i];

            Arrays.sort(temp, new Comparator<String>() {

                @Override
                public int compare(String a, String b) {
                    int index1 = 0;
                    int index2 = 0;
                    for (int i = 0; i < Math.min(a.length(), b.length())
                            && index1 == index2; i++) {
                        index1 = order.indexOf(a.charAt(i));
                        index2 = order.indexOf(b.charAt(i));
                    }

                    if (index1 == index2 && a.length() != b.length()) {
                        if (a.length() < b.length())
                            return 1;
                        else
                            return 0;
                    }

                    if (index1 < index2)
                        return 1;
                    else
                        return 0;

                }
            });

            int flag = 1;
            for (int i = 0; i < n; i++) {
                if (!words[i].equals(temp[i])) {
                    flag = 0;
                    break;
                }
            }

            System.out.println(flag);
        }
    }

}
// } Driver Code Ends

// User function Template for Java

class Solution {
    public void TopoSort(int node, ArrayList<ArrayList<Integer>> graph, int vis[], Stack<Integer> st) {
        vis[node] = 1;
        for (int it : graph.get(node)) {
            if (vis[it] == 0) {
                TopoSort(it, graph, vis, st);

            }

        }
        st.add(node);
    }

    public String findOrder(String[] dict, int N, int K) {
        // Write your code here
        ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < 26; i++)
            graph.add(new ArrayList<Integer>());
        for (int i = 0; i < N - 1; i++) {
            int j = 0;
            int n = Math.min(dict[i].length(), dict[i + 1].length());
            while (j < n && dict[i].charAt(j) == dict[i + 1].charAt(j))
                j++;
            if (j < n)
                graph.get(dict[i].charAt(j) - 'a').add(dict[i + 1].charAt(j) - 'a');

        }
        Stack<Integer> st = new Stack<Integer>();
        int vis[] = new int[26];
        TopoSort(0, graph, vis, st);
        String ans = "";
        while (!st.isEmpty()) {
            ans += (char) ('a' + st.peek());
            st.pop();
        }
        return ans;

    }
}