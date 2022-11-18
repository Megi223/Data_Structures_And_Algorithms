#include <iostream>
#include <vector>
using namespace std;

bool isMinMax(long long int idx, vector<int> vect, int teams) {
    long long int sum = 0;


    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i] > idx) { return false; }
        sum += vect[i];
        if (sum > idx) {
            sum = 0;
            sum += vect[i];
            teams--;
        }
    }
    if (teams < 0) {
        return false;
    }
    return true;
    
}

void binary_Search(long long int &minMax, vector<int> vect, int teams)
{
    long long int l = 0, r = minMax;
    while (l <= r) {
        long long int m = l + (r - l) / 2;

        if (!isMinMax(m, vect, teams)) {
            
            l = m + 1;
        }
      
        else { minMax = m; r = m - 1;  }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0, T = 0;
    cin >> N >> T;
    vector<int> abilities;
    int current = 0;
    long long int totalSum = 0;
    int maxEl = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> current;
        abilities.push_back(current);
        totalSum += current;
        if (current > maxEl) {
            maxEl = current;
        }
    }
  
    long long int minMax = totalSum;
    if (T == 1) {
        minMax = totalSum;
    }
    else if (T >= N) {
        minMax = maxEl;
    }
    else {
        
        binary_Search(minMax,abilities, T-1);
    }
    cout << minMax;
}