// { Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class DriverClass {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[][] arr = new int[n][n];

            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    arr[i][j] = sc.nextInt();

            GFG g = new GFG();
            g.rotate(arr);
            printMatrix(arr);
        }
    }

    static void printMatrix(int arr[][]) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++)
                System.out.print(arr[i][j] + " ");
            System.out.println("");
        }
    }
}// } Driver Code Ends

// User function Template for Java

class GFG {
    static void rotate(int arr[][]) {
        // Code Here
        for (int i = 0; i < arr.length; i++) {
            for (int j = i; j < arr[0].length; j++) {
                int temp = arr[j][i];
                arr[j][i] = arr[i][j];
                arr[i][j] = temp;
            }
        }
        for (int i = 0; i < arr.length; i++) {
            int j = 0, k = arr[0].length - 1;
            while (j < k) {
                int temp = arr[j][i];
                arr[j][i] = arr[k][i];
                arr[k][i] = temp;
                j++;
                k--;
            }

        }
    }

}