#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Abort called
bool ternarySearch(vector<long long int> & vect,long long int counter,long long int left,long long int right) {
	
	if (right == left) { vect[left] = counter;  return false; }

	long long int mid1 = (left + (right - left) / 3 ) + 1;
	long long int mid2 = (right - (right - left) / 3) - 1;
	
	for (long long int i = mid1 ; i <= mid2; i++)
	{
		vect[i]= counter;
	}
	
	ternarySearch(vect, counter + 1 ,left, mid1 - 1);
	return ternarySearch(vect,counter + 1, mid2 + 1, right);
}

long long int ternary_Search(long long int target, long long int left, long long int right, int counter) {
	counter++;
	if (right <= left) return counter;

	long long int mid1 = (left + (right - left) / 3) + 1;
	long long int mid2 = (right - (right - left) / 3) - 1;
	if (mid1 <= target && mid2 >= target) { return counter; }

	if (mid1 > target) return ternary_Search(target, left, mid1 - 1,counter);
	
	else {
		return ternary_Search(target, mid2 + 1, right, counter);

	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int P;
	int N;
	cin >> P >> N;
	vector<long long int> guests;
	long long int currentGuestNumber;
	for (int i = 0; i < N; i++)
	{
		cin >> currentGuestNumber;
		guests.push_back(currentGuestNumber);
	}
	
	long long int size = pow(3, P);
	/*vector<long long int> vect(size,0);
	
	ternarySearch(vect,1,0,size-1);
	
	for (long long int i = 0; i < N; i++)
	{
		cout << vect[guests[i] - 1] << '\n';
	}*/
	
	for (long long int i = 0; i < N; i++)
	{
		cout << ternary_Search(guests[i]-1,0,size-1,0) << '\n';
	}
}