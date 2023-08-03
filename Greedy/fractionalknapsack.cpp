#include <bits/stdc++.h>
using namespace std;

struct Item {
	int profit, weight;

	Item(int profit, int weight){
		this->profit = profit;
		this->weight = weight;
	}
};

static bool cmp(struct Item a, struct Item b){
	double r1 = (double)a.profit / (double)a.weight;
	double r2 = (double)b.profit / (double)b.weight;
	return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int sz){   /// sort by profit/weight
	sort(arr, arr + sz, cmp);
	double maxi = 0.0;
	for (int i = 0; i < sz; i++) {

		if (arr[i].weight <= W) {
			W -= arr[i].weight;
			maxi += arr[i].profit;
		}
		else {
			maxi += arr[i].profit * ((double)W / (double)arr[i].weight);
			break;
		}
	}
	return maxi;
}

int main(){
	Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int Weight = 50;
	cout << fractionalKnapsack(Weight, arr, sz);
	return 0;
}
