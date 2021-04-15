 #include<stdio.h>
#include<stdlib.h>
 int count=0;
typedef struct node 
{ 
    int key; 
    struct node *left, *right; 
} Node; 
  
// A utility function to create a new BST Node 
Node *newNode(int item) 
{ 
    Node *temp =(Node *)malloc(sizeof(Node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// Stores inoder traversal of the BST 
// in arr[] 
void storeSorted(Node *root, int arr[], int* i) 
{ 
    if (root != NULL) 
    { 
        storeSorted(root->left, arr, i); 
        arr[(*i)++] = root->key; 
        storeSorted(root->right, arr, i); 
    } 
} 
  
/* A utility function to insert a new 
   Node with given key in BST */
Node* insert(Node* node, int key) 
{ 
count++;
    /* If the tree is empty, return a new Node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key <= node->key) 
        node->left  = insert(node->left, key); 
    else
        node->right = insert(node->right, key); 
  
    /* return the (unchanged) Node pointer */
    return node; 
} 
  
// This function sorts arr[0..n-1] using Tree Sort 
void treeSort(int arr[], int n) 
{ 
    Node *root = NULL; 
  
    // Construct the BST 
    root = insert(root, arr[0]); 
    for (int i=1; i<n; i++) 
        insert(root, arr[i]); 
  
    // Store inoder traversal of the BST 
    // in arr[] 
    int i = 0; 
    storeSorted(root, arr, &i); 
} 
  
// Driver Program to test above functions 
int main() 
{ int N,i,j,a[1000],b[1000],c[1000];
  printf("Enter n\n");
scanf("%d",&N);
printf("Enter n values\n");
for(i=0;i<N;i++)
scanf("%d",a+i);
    int up = 1;   // means sort in ascending order 
    treeSort(a, N); 
  
    printf("Sorted array: \n"); 
    for (int i=0; i<N; i++) 
        printf("%d ", a[i]); 

        printf("\n%d \n", count); 


	printf("\n\nsize\tasc\tdesc\trandom\n");
	for(i=4;i<520;i*=2)
	{
		for(j=0;j<i;j++)
		{
			a[j]=j;
			b[j]=i-j;
			c[j]=rand()%i;
		}
		count=0;
		treeSort(a,i);
		printf("\n%d\t%d\t",i,count);

		count=0;
		treeSort(b,i);
		printf("%d\t",count);

		count=0;
		treeSort(c,i);
		printf("%d\n",count);
	}
    return 0;
    }
