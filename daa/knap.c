 #include<stdio.h>
// A utility function that returns maximum of two integers 
int max(int a, int b) { return (a > b)? a : b; } 
  
// Returns the maximum value that can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int K[n+1][W+1]; 
  
   // Build table K[][] in bottom up manner 
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
                 
       } 
   } 
   printf(" n= %d  w= %d\n",n,W);
   /*
   for (i = 0; i <= n; i++) 
   { 
        printf("%d.\t", i ); 
        for (w = 0; w <= W; w++) 
            printf("%d\t", K[i][w] ); 
        printf("\n"); 
   } 
   */
   int res=K[n][W];
   w=W;
   printf("\nitems:\t");
    for (i = n; i > 0 && res > 0; i--) { 
          
        if (res == K[i - 1][w])  
            continue;         
        else { 
    
            printf("%d(wt=%d)\t",i, wt[i - 1]); 
              
            res = res - val[i - 1]; 
            w = w - wt[i - 1]; 
        } 
    } 
   printf("\n\n");
   
  
   return K[n][W]; 
} 
  
int main() 
{ 
int i;
    int  W; 
    int n ; 
	printf("enter the number of items:\n");
	scanf("%d",&n); 
    int val[n]; 
    int wt[n]; 
	printf("enter the value of items:\n");
	for(i=0;i<n;i++)
	scanf("%d",val+i); 
	printf("enter the weight of respective items:\n");
	for(i=0;i<n;i++)
	scanf("%d",wt+i); 
	printf("enter the knapsac capacity:\n");
	scanf("%d",&W); 
    printf("total weight = %d\n\n", knapSack(W, wt, val, n)); 
    return 0; 
} 
