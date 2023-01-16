#include <iostream>
#include <unordered_map>


using namespace std;
vector<size_t> numbers;
//unordered_map<size_t,size_t> numbers;
const long long int sum = 10080;

long long int dp[1001][11000];
size_t N;
void findCnt()
{
	//for (int i = 1; i <= sum; i++)
		//dp[0][i] = 0;
	dp[0][0] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			// if the value is greater than the sum
			if (numbers[i - 1] > j)
				dp[i][j] = dp[i - 1][j];
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - numbers[i - 1]];
			}

		}
	}

}


void fillDp(size_t i)
{
	if (i == N + 1) { return; }
	for (int j = 0; j <= sum; j++)
	{
		if (numbers[i - 1] <= j) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - numbers[i - 1]];
		}

		else
		{
			dp[i][j] = dp[i - 1][j];
		}

	}
	fillDp(i + 1);
}


/*void recursion(long long int i, long long int j) {
	/*if (i == 0 && j == 0) {
		return dp[i][j];
	}*/
	/*/if (i == N + 1 || i == 0) {
		return;
	}
	if (j == sum + 1) {
		return;
	}


	if (i <= N) {
		if (j <= sum) {
			if (numbers[i - 1] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - numbers[i - 1]];
			}

			recursion(i, j + 1);
		}
		else {
			recursion(i + 1, 0);
		}
	}


}*/



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	size_t num;
	cin >> N;

	unordered_map<size_t, size_t> encounters;

	for (size_t i = 0; i < 1001; i++)
	{
		for (size_t j = 0; j < 11000; j++)
		{
			dp[i][j] = 0;
		}
	}


	for (size_t i = 0; i < N; i++)
	{
		cin >> num;
		numbers.push_back(num);
		//numbers[i] = num;
	}
	dp[0][0] = 1;
	fillDp(1);
	/*for (size_t i = 1; i <= N; i++)
	{
		fillDp(i);
	}*/
	//recursion(1, 0);
	//findCnt();
	long long int ans = 0;

	for (size_t j = 0; j <= 10080; j++)
	{
		ans += dp[N][j];
		/*if (dp[N][j] > 0) {
			cout << j << ' ';

		}*/

	}
	cout << ans % 1000000007;

}
