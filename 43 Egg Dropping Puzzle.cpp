int t[205][205];
    int solve(int eggs, int flor){
        // base condition 
        if(flor==0 || flor==1) return flor;
        
        if(eggs==1) return flor;
        
        if(t[eggs][flor]!=-1)
        return t[eggs][flor];
        
        int mn = INT_MAX;
        for(int k=1;k<=flor;k++){
            int temp = 1+max(solve(eggs-1,k-1),solve(eggs,flor-k));
            mn = min(mn,temp);
        }
        return t[eggs][flor]=mn ;
    }
    int eggDrop(int n, int k)
    {
       for(int i=0; i<n+1; i++){
            for(int j=0; j<k+1; j++){
                t[i][j]=-1;
            }
     }
      return solve(n,k);
    }
