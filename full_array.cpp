#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp ;
}

void showArray(int arr[], int n)
{
  for(int i=0; i<n;i++)
  {cout<<arr[i]<<" ";}
  cout<<endl;
}


void fullArray(int arr[], int from, int to)
{
  if(from == to)
  {
    showArray(arr, to+1);
    
  }
  else{
  for(int i = from; i<to; i++)
  {
    swap(arr, i, from);
    fullArray(arr, i+1, to);
    swap(arr, i, from);
  }
  }
  
}

int main()
{
  int test_array[3] = {1,2,3};
  fullArray(test_array, 0, 2);
  return 0;
}
