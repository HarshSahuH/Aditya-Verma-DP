struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
int solve(Node* root,int &res){
        
        // base condition 
        if(root==NULL)
        return 0;
        
        // hypothesis
        int lef = solve(root->left,res);
        int rig = solve(root->right,res);
        
        // induction 
        int temp = 1+max(lef,rig);
        int ans = 1+lef+rig;
        res = max(res,ans);
        
        return temp;
    }
    
    
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
      
      int res = INT_MIN;
      solve(root,res);
      return res;
    }
