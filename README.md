# datastructure
<1> binary search
#include<iostream>
using namespace std;
int main()
{
	int i,arr[10],num,first,last,mid;
	cout<<"enter 10 element in asceding order:";
	for(i=0;i<10;i++)
	cin>>arr[i];
	cout<<"\n enter element to be search;";
	cin>>num;
	first=0;
	last=9;
	mid=(first+last)/2;
	while(first<=last)
	{
		if(arr[mid]<num)
		first=mid+1;
		else if(arr[mid]==num)
		{
			cout<<"\n the number"<<num<<"found at position"<<mid+1;
			break;
		}
		else
		last=mid-1;
		mid=(first+last)/2;
	}
	if(first>last)
	cout<<"\n the number"<<num<<"is not found in given array"<<endl;
	return 0;
}
