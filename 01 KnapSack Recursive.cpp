#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	if(n == 0 || maxWeight == 0){
        return 0;
    }
    
    if(weight[n-1] <= maxWeight){
        return max(value[n-1] + knapsack(weight,value, n-1, maxWeight-weight[n-1]), knapsack(weight,value,n-1,maxWeight));
    } 
    else if (weight[n-1] > maxWeight){
        return knapsack(weight, value, n-1, maxWeight);
    }
}
