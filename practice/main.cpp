#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*02.Themes for project*/
/*bool binarySearch(vector<unsigned long long int>& numbers, long long l, long long r, unsigned long long target) {
    if (l > r) { return false; }
    long long m = l + (r - l) / 2;
    if (target == numbers[m]) {
        return true;
    }
    else if (target > numbers[m]) {
        return binarySearch(numbers, m + 1, r, target);
    }
    else {
        return binarySearch(numbers, l, m - 1, target);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned long long int n, m;
    cin >> n >> m;
    unsigned long long int currentThemeNumber = 0;
    vector<unsigned long long int> themes;
    for (unsigned long long i = 0; i < n; i++) {
        cin >> currentThemeNumber;
        themes.push_back(currentThemeNumber);
    }
    unsigned long long int currentTeamNumber = 0;
    vector<unsigned long long int> teams;
    for (unsigned long long i = 0; i < m; i++) {
        cin >> currentTeamNumber;
        teams.push_back(currentTeamNumber);
    }
    unsigned long long int result = 0;
    for (unsigned long long int i = 0; i < m; i++) {
        //auto upper = upper_bound(themes.begin(),themes.end(),teams[i]);
        bool res = binarySearch(themes, 0, themes.size() - 1, teams[i]);
        //cout << res << ' ';
        if (res) {
            result = teams[i];
        }
        else {
            long long target = teams[i];
            auto upperBigger = upper_bound(themes.begin(), themes.end(), teams[i]);
            auto upperSmaller = upper_bound(themes.begin(), themes.end(), teams[i]);
            unsigned long long indexBigger = upperBigger - themes.begin();
            if (indexBigger == themes.size()) {
                indexBigger--;
            }
            unsigned long long indexSmaller = upperSmaller - themes.begin() == 0 ? 0 : upperSmaller - themes.begin() - 1;
            long long themesBigger = themes[indexBigger];
            long long themesSmaller = themes[indexSmaller];
            long long diff1 = themesBigger - target >= 0 ? themesBigger - target : -1*(themesBigger - target);
            long long diff2 = target - themesSmaller >= 0 ? target - themesSmaller : -1*(target - themesSmaller);
            if ((diff1) >= (diff2)) {
                result = themes[indexSmaller];
            }
            else {
                result = themes[indexBigger];
            }

        }
        cout << result << '\n';
    }
    return 0;
}*/

/*03.Demons*/
struct Hero {
    unsigned long int attack;
    unsigned long int defense;
    Hero(unsigned long int _attack, unsigned long int _defense) {
        attack = _attack;
        defense = _defense;
    }
    bool operator>(const Hero& other) const { return  attack > other.attack; }
    bool operator<(const Hero& other) const { return  attack < other.attack; }
    bool operator==(const Hero& other) const { return  attack == other.attack; }

};

int getElementToReplaceIndex(vector<Hero>& defences, int start, int end, Hero targetDefence) {
    while ((end - start) > 1) {
        int middle = start + (end - start) / 2;
        if (defences[middle].attack >= targetDefence.attack) {
            end = middle;
        }
        else {
            start = middle;
        }
    }

    return end;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Hero> heroes;
    
    unsigned long long int currentAttack;
    unsigned long long int currentDefense;
    for (int i = 0; i < n; i++) {
        cin >> currentDefense >> currentAttack;
        Hero hero(currentAttack, currentDefense);
        heroes.push_back(hero);
    }
    vector<Hero> ans;
    ans.push_back(heroes[0]);
    for (int i = 1; i < n; i++)
    {
        Hero current = heroes[i];
        if (current < ans[0]) {
            ans[0] = current;
        }
        else if (current > ans.back()) {
            ans.push_back(current);
        }
        else if(current<ans.back()) {
            //auto upper = upper_bound(ans.begin(), ans.end(), current);
            //ans[upper - ans.begin()] = current;
            int index = getElementToReplaceIndex(ans, -1, ans.size() - 1, current);
            ans[index] = current;
        }
    }
    cout << "----------------------" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].defense << ' ' << ans[i].attack << endl;
    }
    cout << ans.size();
    /*sort(heroes.begin(), heroes.end(), sortDescByAttack);
    cout << "--------------------------------------" << endl;

    for (int i = 0; i<n; i++) {
        cout << heroes[i].attack << ' ' << heroes[i].defense << endl;
    }
    unsigned long long int attack = heroes[0].attack;
    unsigned long long int defense = heroes[0].defense;
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (heroes[i].attack < attack && heroes[i].defense < defense) {
            count++;
            attack = heroes[i].attack;
            defense = heroes[i].defense;
        }
    }
    int maxCount = count;
    sort(heroes.begin(), heroes.end(), sortDescByDef);
    cout << "--------------------------------------" << endl;
    for(int i = 0; i<n;i++){
        cout << heroes[i].attack << ' ' << heroes[i].defense << endl;
    }
    attack = heroes[0].attack;
    defense = heroes[0].defense;
    count = 1;
    for (int i = 1; i < n; i++) {
        if (heroes[i].attack < attack && heroes[i].defense < defense) {
            count++;
            attack = heroes[i].attack;
            defense = heroes[i].defense;
        }
    }
    if (count < maxCount) {
        maxCount = count;
    }

    cout << maxCount;
    return 0;*/
}
