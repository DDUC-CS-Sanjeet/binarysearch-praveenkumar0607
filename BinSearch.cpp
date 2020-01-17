#include<iostream>
#include<algorithm>
using namespace std;

bool binarySearchReacursive(int* array, int startIndex, int lastIndex, int element)
{
	int mid;
	if(startIndex<=lastIndex)
	{
		mid=(startIndex+lastIndex)/2;
		if(array[mid]==element)
		return true;
		if(array[mid]>element)
		return binarySearchReacursive(array,startIndex,mid-1,element);
		if(array[mid]<element)
		return binarySearchReacursive(array,mid+1,lastIndex,element);
	}
  return false;
}

bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{
	int mid=(startIndex+lastIndex)/2;
	while(startIndex<=lastIndex)
	{
		if(array[mid]<element)
		{
			startIndex=mid+1;
		}
		else if(array[mid]==element)
		{
			return true;
		}
		else
		{
			lastIndex=mid-1;
		}
		mid=(startIndex+lastIndex)/2;
	}
  return false;
}

int main()
{

int arr[50];
int size,ele;
bool result;
cout<<" enter the size of array  : ";
cin>>size;
cout<<" enter your array : "<<endl;
for(int i=0;i<size;i++)
{
	cin>>arr[i];
}
sort(arr,arr+size);
cout<<" enter element to search : ";
cin>>ele;
cout<<" searching by iterative method : ";
result=binarySearchIterative(arr,0,size-1,ele);
if(result==true)
cout<<" found ";
else
cout<<" not found ";
cout<<"\n\n searching by recursive method \n\n";
result=binarySearchReacursive(arr,0,size-1,ele);
if(result==true)
cout<<" found ";
else
cout<<" not found ";
  return 0;
}
