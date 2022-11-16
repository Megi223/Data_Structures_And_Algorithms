#include <iostream>
#include <vector>

using namespace std;

int main() {
	int days;
	cin >> days;
	vector<int> prices;
	int currentPrice;
	for (size_t i = 0; i < days; i++)
	{
		cin >> currentPrice;
		prices.push_back(currentPrice);
	}
	int maxWin = 0;
	int dayBought = 0;
	int daySold = 0;
	int currentWin = 0;
	for (int i = 0; i < days - 1; i++)
	{
		currentWin = prices[i + 1] - prices[i];
		if (currentWin > 0) {
			dayBought = i;
			daySold = i + 1;
			maxWin += currentWin;
		}
	}

	cout << maxWin;
}





