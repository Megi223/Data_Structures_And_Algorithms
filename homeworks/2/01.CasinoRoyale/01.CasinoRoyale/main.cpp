#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int size;
	cin >> size;
	int currentNumberBet;
	vector<int> bets;
	int cntEven = 0;
	for (int i = 0; i < size; i++)
	{
		cin >> currentNumberBet;
		bets.push_back(currentNumberBet);
		if (currentNumberBet % 2 == 0) {
			cntEven++;
		}
	}

	int* sortedVect = new int[size];
	int curIdxEven = 0;
	int curIdxOdd = cntEven;
	for (int i = 0; i < size; i++)
	{
		if (bets[i] % 2 == 0) {
			sortedVect[curIdxEven] = bets[i];
			curIdxEven++;
		}
		else {
			sortedVect[curIdxOdd] = bets[i];
			curIdxOdd++;
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << sortedVect[i] << '\n';
	}

	delete[] sortedVect;
}

// Second way
/*int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int currentNumber;
	vector<int> numbers;
	vector<int> copyNumbers;
	int maxEl = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> currentNumber;
		numbers.push_back(currentNumber);
		copyNumbers.push_back(currentNumber);
		if (currentNumber > maxEl) {
			maxEl = currentNumber;
		}
	}

	int newSize = 2;
	int* cntArr = new int[newSize] {0};
	for (int i = 0; i < n; i++)
	{
		if (numbers[i] % 2 == 0) {
			cntArr[0]++;
		}
		else {
			cntArr[1]++;
		}
	}

	cntArr[1] += cntArr[0];

	for (int i = n - 1; i >= 0; i--)
	{
		numbers[cntArr[(copyNumbers[i] % 2)] - 1] = copyNumbers[i];
		cntArr[(copyNumbers[i] % 2)]--;
	}
	for (int i = 0; i < n; i++)
	{
		cout << numbers[i] << '\n';

	}
}*/
