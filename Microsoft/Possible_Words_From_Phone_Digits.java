// { Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class PhoneDigit {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();// testcases

        while (t-- > 0) {
            int n = sc.nextInt(); // input size of array
            int arr[] = new int[n]; // input the elements of array that are keys to be pressed

            for (int i = 0; i < n; i++)
                arr[i] = sc.nextInt();// input the elements of array that are keys to be pressed
            ArrayList<String> res = new Solution().possibleWords(arr, n);
            for (String i : res)
                System.out.print(i + " ");
            System.out.println();

        }
    }
}
// } Driver Code Ends

// User function Template for Java

class Solution {
    // Function to find list of all words possible by pressing given numbers.
    public static String help(int n) {
        if (n == 1)
            return "";
        if (n == 2)
            return "abc";
        if (n == 3)
            return "def";
        if (n == 4)
            return "ghi";
        if (n == 5)
            return "jkl";
        if (n == 6)
            return "mno";
        if (n == 7)
            return "pqrs";
        if (n == 8)
            return "tuv";
        if (n == 9)
            return "wxyz";
        return "";

    }

    public static ArrayList<String> Recursion(int idx, int a[], int n, String temp) {
        if (idx == n) {

            ArrayList<String> list = new ArrayList<>();
            list.add(temp);
            return list;
        }
        ArrayList<String> ans = new ArrayList<>();
        String str = help(a[idx]);

        for (int i = 0; i < str.length(); i++) {
            ans.addAll(Recursion(idx + 1, a, n, temp + str.charAt(i)));
        }
        return ans;
    }

    static ArrayList<String> possibleWords(int a[], int N) {
        // your code here
        String temp = "";
        return Recursion(0, a, N, temp);
    }
}
