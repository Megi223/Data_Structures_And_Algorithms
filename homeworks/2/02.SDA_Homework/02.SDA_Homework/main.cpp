#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
	string name;
	int score;
	Student(string _name, int _score) {
		this->name = _name;
		this->score = _score;
	}
};

bool criteria(const Student& first, const Student& sec) {
	if (first.score != sec.score) {
		return first.score > sec.score;
	}
	return first.name < sec.name;
}

void sortStudents(vector<Student>& students) {
	sort(students.begin(), students.end(), &criteria);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int size;
	cin >> size;
	string currName;
	vector<string> names;
	for (int i = 0; i < size; i++)
	{
		cin >> currName;
		names.push_back(currName);
	}
	int currScore;
	vector<Student> students;
	for (int i = 0; i < size; i++)
	{
		cin >> currScore;
		students.push_back(Student(names[i], currScore));
	}
	sortStudents(students);
	for (int i = 0; i < students.size(); i++)
	{
		cout << students[i].name << ' ' << students[i].score << '\n';
	}
}