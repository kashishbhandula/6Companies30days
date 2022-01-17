// { Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());

        while (tc-- > 0) {
            String[] nk = br.readLine().trim().split(" ");
            int n = Integer.parseInt(nk[0]);
            int k = Integer.parseInt(nk[1]);

            String[] str = br.readLine().trim().split(" ");
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(str[i]);
            }

            Solution sln = new Solution();
            ArrayList<ArrayList<Integer>> ans = sln.fourSum(a, k);
            for (ArrayList<Integer> v : ans) {
                for (int u : v) {
                    System.out.print(u + " ");
                }
                System.out.print("$");
            }
            if (ans.isEmpty()) {
                System.out.print(-1);
            }
            System.out.println();
        }
    }
}// } Driver Code Ends


// User function Template for Java

// arr[] : int input array of integers
// k : the quadruple sum required
class Pair
{
    int data1,data2,data3,data4;
    Pair(int data1,int data2,int data3,int data4)
    {
        this.data1=data1;
        this.data2=data2;
        this.data3=data3;
        this.data4=data4;
        
    }
}
class Solution {
    public ArrayList<ArrayList<Integer>> fourSum(int[] arr, int k) {
        // code here
        int n=arr.length;
         Set<Pair> st = new HashSet<Pair>();
         ArrayList<ArrayList<Integer>> ans=new  ArrayList<ArrayList<Integer>>();
         Arrays.sort(arr);
         for(int i=0;i<n-3;i++)
         {
             for(int j=i+1;j<n-2;j++)
             {
                 int diff=arr[i]+arr[j];
                 int start=j+1,end=n-1;
                 while(start<end)
                 {
                     if(diff+arr[start]+arr[end]==k)
                     {
                       ArrayList<Integer>list=new ArrayList<Integer>(Arrays.asList(arr[i],arr[j],arr[start],arr[end]));
                          if(!ans.contains(list))
                            {
                                ans.add(list);
                            }        
                        
                        
                         
                         start++;
                         end--;
                         continue;
                         
                     }
                     if(diff+arr[start]+arr[end]>k)end--;
                     else start++;
                 }
                 
             }
         }
         return ans;
    }
}