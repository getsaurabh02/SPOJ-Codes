//#include <stdio.h>
//
//void quick_sort(int arr[],int low,int high)
//{
// int pivot,j,temp,i;
// if(low<high)
// {
//  pivot = low;
//  i = low;
//  j = high;
// 
//  while(i<j)
//  {
//   while((arr[i]<=arr[pivot])&&(i<high))
//   {
//    i++;
//   }
// 
//   while(arr[j]>arr[pivot])
//   {
//    j--;
//   }
// 
//   if(i<j)
//   { 
//    temp=arr[i];
//    arr[i]=arr[j];
//    arr[j]=temp;
//   }
//  }
// 
//  temp=arr[pivot];
//  arr[pivot]=arr[j];
//  arr[j]=temp;
//  quick_sort(arr,low,j-1);
//  quick_sort(arr,j+1,high);
// }
//}
//
//int coins (int a[], int n, int s)
//{
//    int noofcoins = -1, i, t;
//    quick_sort(a,0,n-1);
//
//    for (i = n-1; i > 0; --i) {
//
//		if (a[i] <= s ) {
//			noofcoins += s/a[i];
//			s= s- (noofcoins * a[i]);
//		}
//    }
//	if (s<=0)
//		printf("\n%d",noofcoins);
//	else
//		printf ("\n%d",-1);
//    scanf ("%d",&t);
//	
//
//    return noofcoins;
//
//}
//
//int main (void){
//
//	int a[] = {1,3,5};
//	int s;
//    coins (a,3,11);
//    
//    return 0;
//}
//
//
