
#include <iostream>
using namespace std;

void insertSort(int arr[], int n);
void selectSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void shellSort(int arr[], int n);
void mergeSortRecursion(int arr[], int left, int right);
void mergeSortIterative(int arr[], int n);
int my_partion(int arr[], int left, int right);
void quickSort(int arr[], int left, int right);
void countSort(int arr[], int n);

void showArray(int arr[], int n)
{
  int i=0;
  while(i < n)
  {
    cout<<arr[i++]<<" ";
  }
  cout<<endl;
}

int main()
{
  int arrays[10] = {7,3,4,5,1,3,9,2,10,6};
  showArray(arrays, 10);
  //insertSort(arrays, 10);
  //selectSort(arrays, 10);
  //bubbleSort(arrays,10);
  //shellSort(arrays,10);
  //mergeSortRecursion(arrays,0,9);
  //mergeSortIterative(arrays, 10);
  //quickSort(arrays, 0, 9);
  countSort(arrays,10);
  showArray(arrays, 10);
  //my_partion(arrays, 0, 9);
  return 0;
}
// util
void Swap(int arr[], int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int my_partion(int arr[], int left, int right)
{
  int i = left;
  int j = right-1;
  int pivot = arr[right];
  while(i <= j)
  {
    if(arr[i] <= pivot) i++;
    else if(arr[j] > pivot) j-- ;
    else Swap(arr, i, j);
  }
  Swap(arr, i, right);
  //showArray(arr, 10);
  return i;
}
int partion(int arr[], int left, int right)
{
  int temp = arr[right];
  int i = left - 1;
  for(int j = left; j< right; j++)
  {
    if(arr[j] <= temp)
    {
      Swap(arr, j, ++i);
    }
  }
  Swap(arr, i+1, right);
  return i+1;
}

void quickSort(int arr[], int left, int right)
{
  if(left >= right)
    return;
  int pivotIndex = partion(arr, left, right);
  quickSort(arr, left, pivotIndex-1);
  //cout<<"after left"<<endl;
  quickSort(arr, pivotIndex+1, right);
  //cout<<"after right"<<endl;
}

//merge
void mergeArray(int arr[], int left, int mid, int right)
{
  int len = right - left + 1;
  int *temp_arr = new int[len] ;
  int i = left;
  int j = mid +1;
  int index = 0;
  while(i <= mid && j<= right){temp_arr[index++] = (arr[i] > arr[j]? arr[j++]:arr[i++]);}
  while(i<=mid) {temp_arr[index++] = arr[i++];}
  while(j<=right) {temp_arr[index++] = arr[j++];}
  
  for(int m = 0; m < len; m++)
  {
    arr[left + m] = temp_arr[m];
  }
  delete temp_arr;
}
void mergeSortRecursion(int arr[], int left, int right)
{
  if(left == right) return;
  int mid = (left + right)/2;
  mergeSortRecursion(arr, left, mid);
  mergeSortRecursion(arr, mid+1, right);
  mergeArray(arr, left, mid, right);
}
void mergeSortIterative(int arr[], int n)
{
  int left, mid, right;
  for(int i=1; i<n; i *=2)
  {
    left = 0;
    while(left + i < n)
    {
      mid = left + i -1;
      right = (mid + i) < n? mid +i:n -1;
      mergeArray(arr, left, mid, right);
      left = right +1;
    }
  }
}



//shell
void shellSort(int arr[], int n)
{
  int cnt= 0;
  int h=0;
  while(h <= n){h = 3*h +1;}
  while(h >=1)
  {
    for(int i = h; i<n; i++)
    {
      int temp = arr[i];
      int j = i-h;
      while(j>=0 && arr[j] > temp)
      {
        arr[j+h] = arr[j];
        j -= h;
      }
      arr[j+h] = temp;
      cnt++;
    }
    h  = (h-1)/3;
  }
  cout<<"shellSort swap time="<<cnt<<endl;
}

//bubble
void bubbleSort(int arr[], int n)
{
  int cnt = 0;
  for(int i = 0; i< n-1; i++)
  {
    for(int j= 0; j < n-1-i; j++)
    {
      if(arr[j] > arr[j+1])
      {Swap(arr, j, j+1); cnt++;}
    }
  }
  cout<<"bubbleSort swap time="<<cnt<<endl;
}

//insert
void insertSort(int arr[], int n)
{
  int i,cnt,j;
  int temp;
  cnt = 0;
  for(i = 1; i<n ;i++)
  {
    j = i-1;
    temp = arr[i];
    while(j>=0 && arr[j] > temp)
    {
      arr[j+1] = arr[j];
      //arr[j+1] ^= arr[j];
      //arr[j] =arr[j+1]^arr[j];
      //arr[j+1] ^= arr[j];
      //temp = arr[j];
      //arr[j] = arr[j+1];
      //arr[j+1] =temp;
      j--;
      cnt++;
    }
    arr[j+1] = temp;
  }
  cout<< "insertSort Swap time =" <<cnt<<endl;
}

//select
void selectSort(int arr[], int n)
{
  int index;
  int cnt =0;
  for(int i=0; i<n-1; i++)
  {
    index = i;
    for(int j = i+1; j<n ; j++ )
    {
      if(arr[j]< arr[index])
      {
         index = j;
      }
    }
    if(index != i) {Swap(arr, index, i); cnt++;}
    
  }
  cout<< "selectSort Swap time = "<<cnt<<endl;  
}


void countSort(int arr[], int n)
{
  int C[100] = {0};
  for(int i=0; i<n; i++)
  {
    C[arr[i]]++;
  }
  for(int i=1; i<100; i++)
  {
    C[i] += C[i-1];
  }
  int *B = new int[n];
  for(int j = 0; j<n; j++)
  {
    B[--C[arr[j]]] = arr[j];
  }

  for(int j = 0; j< n;j++)
  {
    arr[j] = B[j];
  }
  delete B;
}





