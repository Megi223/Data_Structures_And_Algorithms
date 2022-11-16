#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findSmallestPositive(const vector<int>& tickets) {
	for (size_t i = 0; i < tickets.size(); i++)
	{
		if (tickets[i] > 0) {
			return i;
		}
	}
	return -1;
}

int main() {
	unsigned int numberOfPassengers;
	cin >> numberOfPassengers;
	vector<int> tickets;
	int currTicketNumber;
	for (size_t i = 0; i < numberOfPassengers; i++)
	{
		cin >> currTicketNumber;
		tickets.push_back(currTicketNumber);
	}
	sort(tickets.begin(), tickets.end());
	int smallestPositiveIndex = findSmallestPositive(tickets);
	int min = 1;
	if (smallestPositiveIndex >= 0) {
		for (size_t i = smallestPositiveIndex; i < numberOfPassengers - 1; i++)
		{
			if (tickets[i] > min) {
				break;
			}
			else if (tickets[i] == tickets[i+1]) {
				continue;
			}
			else {
				min++;
			}
		}
		if (min == tickets[numberOfPassengers - 1]) {
			min++;
		}
	}
	cout << min;
}