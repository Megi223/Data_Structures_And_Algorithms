#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int Q;
	cin >> N >> Q;
	vector<int> participantWeights;
	int currentWeight;
	for (int i = 0; i < N; i++)
	{
		cin >> currentWeight;
		participantWeights.push_back(currentWeight);
	}
	int minWeight;
	int maxWeight;
	// size -> Q
	vector<int> minWeights;
	vector<int> maxWeights;
	for (int i = 0; i < Q; i++)
	{
		cin >> minWeight >> maxWeight;
		minWeights.push_back(minWeight);
		maxWeights.push_back(maxWeight);
	}
	sort(participantWeights.begin(), participantWeights.end());
	
	vector<int> result;
	for (int i = 0; i < Q; i++)
	{
		int currentMin = minWeights[i];
		int currentMax = maxWeights[i];
		if (currentMin <= currentMax) {
			//auto up = upper_bound(participantWeights.begin(), participantWeights.end(), currentMin - 1) - 1;

			//auto low = upper_bound(participantWeights.begin(), participantWeights.end(), currentMax) - 1;
			//auto up = upper_bound(participantWeights.begin(), participantWeights.end(), currentMin - 1);
			auto up = lower_bound(participantWeights.begin(), participantWeights.end(), currentMin);
			auto low = upper_bound(participantWeights.begin(), participantWeights.end(), currentMax);
			//cout << up - participantWeights.begin() << ' ' << low - participantWeights.begin() << endl;
			int countParticipants = low - up;
			result.push_back(countParticipants);
		}
		else {
			result.push_back(0);
		}
		
	}
	for (int i = 0; i < Q; i++)
	{
		cout << result[i] << '\n';
	}
}