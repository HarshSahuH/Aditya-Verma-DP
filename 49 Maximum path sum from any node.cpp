int solve(Node*root,int &res){
        // base condition 
        if(root==NULL) return 0;

        // hypothesis
        int lef = solve(root->left,res);
        int rig = solve(root->right,res);

        // induction 
        int temp = max( (max(lef,rig)+root->data),(root->data) );
        int ans = max(temp,(lef+rig+root->data));
        res = max(res,ans);
        return temp;

    }
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
        int res = INT_MIN;
        solve(root,res);
        return res;
    }
