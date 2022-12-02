#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>

using namespace std;

// 01.Brave entrepreneur
/*int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int days;
    cin >> days;
	int currentPrice;
	vector<int> prices;
	for (int i = 0; i < days; i++)
	{
		cin >> currentPrice;
		prices.push_back(currentPrice);
	}
	int totalWin = 0;
	int min = prices[0];
	int max = prices[0];
	for (int i = 1; i < days; i++)
	{
		if (prices[i - 1] > prices[i]) {
			totalWin += max - min;

			min = prices[i];
			max = prices[i];
			continue;
		}
		max = (prices[i] > max) ? prices[i] : max;
	}
	if (prices[days - 1] > prices[days - 2]) {
		totalWin += prices[days - 1] - min;
	}
	cout << totalWin;
}*/

// 02. Queue for wraps
/*int main() {
	int n;
	cin >> n;
	vector<char> queue;
	char currentSymbol;
	int firstFreeSpace = -1;
	int idxFirstPerson = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> currentSymbol;
		queue.push_back(currentSymbol);
		if (currentSymbol == '-' && firstFreeSpace == -1) {
			firstFreeSpace = i;
		}
		if (currentSymbol == 'x' && idxFirstPerson == -1) {
			idxFirstPerson = i;
		}
	}
	if (firstFreeSpace == -1) {
		cout << -1;
		return 0;
	}
	int* distances = new int[n]{-1};
	int streak = idxFirstPerson - 1;
	bool reachedFirstPerson = false;
	for (int i = 0; i < n; i++)
	{
		if (queue[i] == 'x') {
			if (i == idxFirstPerson) {
				reachedFirstPerson = true;
			}
			streak = 0;
		}
		else if (queue[i] == '-') {
			distances[i] = streak;
			if (reachedFirstPerson == false) {
				streak--;
			}
			else {
				streak++;
			}
		}
	}
	
	for (int i = n - 1; i >= 0; i--)
	{
		if (queue[i] != 'x') {
			distances[i] = min(streak, distances[i]);
			streak++;
		}
		else {
			streak = 0;
			distances[i] = -1;
		}
	}
	int ans = -1;
	for (int i = 0; i < n; i++)
	{
		if (distances[i] >= 0 && distances[i] > ans) {
			ans = distances[i];
		}
	}
	cout << ans;
	delete[] distances;
}*/

// 04.Unique Bonus

// Abort called - works but the size of the array becomes too big
bool hasUniqueNumbers(unsigned long long int number) {
	unsigned long long int copyNumber = number;
	int digits = 0;
	while (copyNumber > 0) {
		copyNumber /= 10;
		digits++;
	}
	size_t* numberToArr = new size_t[digits];
	for (int i = digits - 1; i >= 0; i--)
	{
		numberToArr[i] = number % 10;
		number /= 10;
	}
	sort(numberToArr, numberToArr + digits);
	for (int i = 0; i < digits - 1; i++)
	{
		if (numberToArr[i] == numberToArr[i + 1]) {
			return false;
		}
	}
	delete[] numberToArr;
	return true;
}


bool func(unsigned long long int n) {
	string s = to_string(n);
	set<int> uniDigits(s.begin(), s.end());
	if (s.size() == uniDigits.size()) {
		return true;
	}
}

int findDigits(unsigned long long int number) {
	unsigned long long int copyNumber = number;
	int digits = 0;
	while (copyNumber > 0) {
		copyNumber /= 10;
		digits++;
	}
	return digits;
}

int factorial(int n) {
	int factorial = 1;
	for (int i = 1; i <= n; ++i) {
		factorial *= i;
	}
	return factorial;
}

unsigned long long int MAX = 9876543210;
vector<int> Prefix = { 0 };

// Function to check if the given
// number has repeated digit or not
int repeated_digit(int n)
{

	unordered_set<int> a;
	int d;

	// Traversing through each digit
	while (n != 0)
	{
		d = n % 10;

		// if the digit is present
		// more than once in the
		// number
		if (a.find(d) != a.end())

			// return 0 if the number
			// has repeated digit
			return 0;

		a.insert(d);
		n = n / 10;
	}

	// return 1 if the number has no
	// repeated digit
	return 1;
}

// Function to pre calculate
// the Prefix array
void pre_calculation(int MAX)
{

	Prefix.push_back(repeated_digit(1));

	// Traversing through the numbers
	// from 2 to MAX
	for (int i = 2; i < MAX + 1; i++)

		// Generating the Prefix array
		Prefix.push_back(repeated_digit(i) + Prefix[i - 1]);
}

// Calclute Function
int calculate(int L, int R)
{

	// Answer
	return Prefix[R] - Prefix[L - 1];
}





int main() {
	unsigned long long int A;
	unsigned long long int B;
	cin >> A >> B;
	/*int digitsA = findDigits(A);
	int digitsB = findDigits(B);
	if (digitsA > 10 || B < A) {
		cout << 0;
		return 0;
	}
	if (digitsB > 10) {
		B = 9876543210;
	}*/
	// Pre-calculating the Prefix array.
	pre_calculation(MAX);

	// Calling the calculate function
	// to find the total number of number
	// which has no repeated digit
	cout << calculate(A, B) << endl;

	return 0;
	unsigned long long int ans = 0;
	int cnt = 0;
	for (unsigned long long int i = A; i <= B; i++)
	{
		/*bool correct = hasUniqueNumbers(i);
		if (correct) {
			ans++;
		}*/
		/*ans = ans + (findDigits(i) - 1);
		cnt++;*/
		/*unsigned long long int copy = i;
		bool visited[10] = {false};
		while (copy > 0) {
			if (visited[copy % 10]) {
				break;
			}
			visited[copy % 10] = true;
			copy /= 10;
		}
		if (copy == 0) {
			ans++;
		}*/

		// ----------------------------------------------------------
		/*string s = to_string(i);
		set<int> uniDigits(s.begin(), s.end());
		if (s.size() == uniDigits.size()) {
			ans++;
		}*/
		/*string s = to_string(i);

		ans += (s[0] - 1) * factorial(9) / factorial((9 - s.length() + 1));
		for (int i = 0; i < s.length(); i++)
		{
			ans += s[i] * factorial((9 - i)) / factorial((9 - s.length() + 1));
		}

				// don't forget N
				/*if (hasUniqueDigits(N))
					uniques += 1*/
			
	}
	string s = to_string(B);

	ans += (s[0] - 1) * factorial(9) / factorial((9 - s.length() + 1));
	for (int i = 0; i < s.length(); i++)
	{
		ans += s[i] * factorial((9 - i)) / factorial((9 - s.length() + 1));
	}
	cout << ans << endl;
	/*cout << ans << endl;
	int answer = B - A - ans ;
	cout << answer;*/
}