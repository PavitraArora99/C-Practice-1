// QUESTION
// Monu has created an elevated roof. he wants to know how much water can she save during rain.

// Given n non negative integers representing the elevation map where width of every bar is 1, Find the maximum water that he can save.

// Explanation for the Sample input Testcase:
// Elevation Map

// So the total units of water he can save is 5 units


#include <iostream>
using namespace std;
int a[100005];
int leftMax[100005];
int rightMax[100005];
int n;

void rainWater(){

	int ans = a[0];
	leftMax[0] = 0;
	for (int i = 1; i < n; ++i)
	{
		leftMax[i] = ans;
		ans = max(ans, a[i]);
	}

	// Find right max
	ans = a[n-1];
	rightMax[n-1] = 0;

	for(int i = n-2; i>=0 ; i--){
		rightMax[i] = ans;
		ans = max(ans, a[i]);
	}


	int water = 0;

	for (int i = 0; i < n; ++i)
	{
		int minHeight = min(leftMax[i], rightMax[i]);
		if(minHeight - a[i]>0){
			water += (minHeight - a[i]);
		}
	}

	cout << water<<endl;
}


int main(){
	 

	cin>>n;
	
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}	

	rainWater();

	return 0;
}