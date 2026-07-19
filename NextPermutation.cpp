// QUESTION
// You are given an array of integers that represents a permutation of numbers.
//  Your task is to find the next lexicographical permutation of the array. 
//  If such a permutation does not exist (i.e., the array is sorted in descending order), 
//  rearrange the array to its smallest permutation (sorted in ascending order).



#include <iostream>
#include <algorithm>
using namespace std;
	
int main(){
	
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}	

	// 1. Find the break point
	int i = n-2;
	while(i >= 0 and a[i] > a[i+1]) {
		i--;
	}

	if(i == -1){
		// Poora array descending order mei hai
		
		int k = 0, l = n-1;
		while(k<l){
			swap(a[k++], a[l--]);
		}

		for (int i = 0; i < n; ++i)
		{
			cout << a[i] << " ";
		}
		cout << endl;

		return 0; // exit
	}

	// Find the index
	int indx;
	for (int j = i+1; j < n ; ++j)
	{
		if(a[j] > a[i]){
			indx = j;
		}
		else{
			break;
		}
	}

	// 3. Swap
	swap(a[i], a[indx]);

	// 4. reverse
	int k = i+1, l = n-1;
	while(k<l){
		swap(a[k++], a[l--]);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}