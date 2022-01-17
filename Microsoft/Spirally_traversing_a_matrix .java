// { Driver Code Starts
    import java.io.*;
    import java.util.*;
    class GFG
    {
        public static void main(String args[])throws IOException
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            
            while(t-- > 0)
            {
                int r = sc.nextInt();
                int c = sc.nextInt();
                
                int matrix[][] = new int[r][c];
                
                for(int i = 0; i < r; i++)
                {
                    for(int j = 0; j < c; j++)
                     matrix[i][j] = sc.nextInt();
                }
                Solution ob = new Solution();
                ArrayList<Integer> ans = ob.spirallyTraverse(matrix, r, c);
                for (Integer val: ans) 
                    System.out.print(val+" "); 
                System.out.println();
            }
        }
    }// } Driver Code Ends
    
    
    class Solution
    {
        //Function to return a list of integers denoting spiral traversal of matrix.
        static ArrayList<Integer> spirallyTraverse(int mat[][], int r, int c)
        {
            // code here 
            int nRows = r;
            if (nRows == 0) {
                //System.out.print("");
                return new ArrayList<Integer>();
            }
            
            int mCols = c;
    
            int i, rowStart = 0, colStart = 0;
    
            int numElements = nRows * mCols, count = 0;
            ArrayList<Integer>list=new ArrayList<Integer>();
            
            while(count < numElements){
                for(i = colStart; count < numElements && i < mCols; ++i) {
                    list.add(mat[rowStart][i]);
                    count++;
                }           
                rowStart++;
    
                for(i = rowStart; count < numElements && i < nRows; ++i) {
                    list.add(mat[i][mCols - 1]);
                    count++;
                }
                mCols--;
    
                for(i = mCols - 1; count < numElements && i >= colStart; --i) {
                    list.add(mat[nRows - 1][i]);
                    count++;
                }
                nRows--;
    
                for(i = nRows - 1; count < numElements && i >= rowStart; --i) {
                    list.add(mat[i][colStart]);
                    count++;
                }
                colStart++;
            }
            return list;
        }
    }
    