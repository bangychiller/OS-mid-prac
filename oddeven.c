#include <stdio.h>
#include <unistd.h>
int main()
{
int n;
printf("Enter the size of array : ");
scanf("%d" , &n);
int arr[n], even_sum = 0, odd_sum = 0;
printf("\nEnter the elements in the array : \n");
for(int i = 0; i < n; i++)
{
scanf("%d" , &arr[i]);
}
int pid = fork();
if(pid == 0)
{
for(int i = 0; i < n; i++)
{
if(arr[i] % 2 != 0)
odd_sum += arr[i];
}
printf("\nSum of odd numbers : %d\n", odd_sum);
printf("Get PID : %d\n", getpid());
printf("\nParent PID : %d\n", getppid());
}
else
{
for(int i = 0; i < n; i++)
{
if(arr[i] % 2 == 0)
even_sum += arr[i];
}
printf("\nSum of even numbers : %d\n", even_sum);
printf("Get PID : %d\n", getpid());
}
return 0;
}
