//Assignment No.2 a)

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void childprocess(int n , int arr[])
{
  //bubble sort  
  for(int i=0;i<n;i++)
  {
    for(int j=i+1 ; j<n;j++)
    {
      if(arr[i]>arr[j])
      {
         int temp=arr[i];
         arr[i]=arr[j];
         arr[j]=temp;
      }
   }
 }
}
 // insertion sort Sort function

void parentprocess(int arr[], int n) 
{
  for (int i = 1; i < n; i++)
   {  // Start from the second element (index 1)
	    int key = arr[i];
	    int j = i - 1;

	    while (j >= 0 && arr[j] > key)
	     {  // Compare with elements before
	      arr[j + 1] = arr[j];
	      j = j - 1;
	    }
	    arr[j + 1] = key;
  }
}


int main(void)
{
 
  int n;
  
  printf("Enter the Number of elements:\n");
  scanf("%d",&n);
  
  int arr[n];
  printf("Enter the Numbers:\n");
  for(int i=0;i<n;i++)
  {
     scanf("%d",&arr[i]);
  } 
  int p;
  p=fork();
  if(p==-1)
  {
    printf("There is an error while calling fork()\n");
  }
  else if(p==0)
  {
    printf("We are in the child process (Bubble Sort) \n");
    printf("child  => PID:%d\n",getpid());
    printf("Parent => PID: %d\n", getppid());
    childprocess(n,arr);
    for(int i=0 ;i<n;i++)
    {
    printf("%d\n",arr[i]);
   
    }
  }
  else
  {
     wait(NULL);
     printf("We are in the parent process (Quick sort)\n");
     printf("Parent => PID: %d\n", getpid());
     parentprocess(arr,n);
     for(int i=0 ;i<n;i++)
     {
     printf("%d\n",arr[i]);
   
     }
 }
  
  return 0;
}

