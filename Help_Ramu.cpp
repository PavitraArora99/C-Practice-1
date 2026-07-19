// //Question:-   Ramu often uses public transport. The transport in the city is of two types: cabs and rickshaws. The city has n rickshaws and m cabs, the rickshaws are numbered by integers from 1 to n, the cabs are numbered by integers from 1 to m.

// Public transport is not free. There are 4 types of tickets:

// A ticket for one ride on some rickshaw or cab. It costs c1 ruppees;
// A ticket for an unlimited number of rides on some rickshaw or on some cab. It costs c2 ruppees;
// A ticket for an unlimited number of rides on all rickshaws or all cabs. It costs c3 ruppees;
// A ticket for an unlimited number of rides on all rickshaws and cabs. It costs c4 ruppees.

// Ramu knows for sure the number of rides he is going to make and the transport he is going to use. He asked you for help to find the minimum sum of ruppees he will have to spend on the tickets


#include <iostream>
using namespace std;
int n,m;
int rick[10005], cab[10005];
int c1,c2,c3,c4;

int main(){
	 
	int t;
	cin>>t;
	while(t--){
		cin>>c1>>c2>>c3>>c4;

		cin>>n>>m;

		for (int i = 0; i < n; ++i)
		{
			cin>>rick[i];
		}

		for (int i = 0; i < m; ++i)
		{
			cin>>cab[i];
		}


		// Find the cost for rickshaws
		int totalRickshawMinCost, individualRickTotalCost = 0;

		for (int i = 0; i < n; ++i)
		{
			// rick[i]*c1 -> Individual cost for rides on rick[i]
			// pass ki cost for rick[i] -> c2
			int currentRickMinCost = min(rick[i]*c1, c2);
			individualRickTotalCost += currentRickMinCost;
		}

		// c3 -> Pass for travelling on all rickshaws
		totalRickshawMinCost = min(individualRickTotalCost, c3);


		// Cabs ki cost
		int totalCabMinCost, individualCabTotalCost = 0;

		for (int i = 0; i < m; ++i)
		{
			// Cab[i]*c1 -> Individual cost for rides on Cab[i]
			// pass ki cost for Cab[i] -> c2
			int currentCabMinCost = min(cab[i]*c1, c2);
			individualCabTotalCost += currentCabMinCost;
		}

		// c3 -> Pass for travelling on all Cabs
		totalCabMinCost = min(individualCabTotalCost, c3);


		int ans = min(totalCabMinCost + totalRickshawMinCost, c4);

		cout << ans << endl;

	}

	return 0;
}