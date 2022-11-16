#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string sequence;
	cin >> sequence;
	int length = sequence.length();
	char maxEl = 0;
	for (int i = 0; i < length; i++)
	{
		if (sequence[i] > maxEl) {
			maxEl = sequence[i];
		}
	}
	vector<int> countVect((int)maxEl + 1, 0);
	for (int i = 0; i < length; i++)
	{
		countVect[sequence[i]]++;
	}
	vector<int> ans;
	for (int i = 0; i < (int)maxEl + 1; i++)
	{
		if (countVect[i] == 1) {
			for (int j = 0; j < length; j++)
			{
				if (i == sequence[j]) {
					ans.push_back(j);
					break;
				}
			}
		}
	}
	sort(ans.begin(),ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << ' ';
	}
}