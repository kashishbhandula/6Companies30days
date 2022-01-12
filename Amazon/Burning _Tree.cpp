// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
 
    int height(Node* root)
    {
        if(root==NULL)return 0;
        int ht=0;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            ht++;
            queue<Node*>st;
            while(!q.empty())
            {
                Node *curr=q.front();
                q.pop();
                if(curr->right!=NULL)
                {
                    st.push(curr->right);
                }
                if(curr->left!=NULL)
                {
                    st.push(curr->left);
                }
            }
            q=st;
            
            
        }
        return ht;
        
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        int rht=height(root->right);
        if(rht)rht++;
        //cout<<rht<<endl;
        int lht=height(root->left);
        if(lht)lht++;
        //cout<<lht<<endl;
        int tht=1;
        Node* curr=root;
        while(true)
        {
            if(curr==NULL)break;
            if((curr->data)==target)break;
            if((curr->data)>target)
            {
                tht++;
                curr=curr->right;
            }
            else
            {
                tht++;
                curr=curr->left;
            }
        }
       // cout<<tht<<endl;
       tht--;
        if(root->data<target)
        {
            return tht+rht-1+max(0,lht-tht-2-rht-tht);
        }
        else
        {
             return tht+lht-1+max(0,rht-tht-2-lht-tht);
        }
       
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends