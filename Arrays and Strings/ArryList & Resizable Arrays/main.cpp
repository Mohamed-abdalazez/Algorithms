#include "bits/stdc++.h"

using namespace std;

vector<string> mereg(vector<string> words, vector<string> more)
{
	vector<string> sentence;
	for (auto it : words)
		sentence.push_back(it);
	for (auto it : more)
		sentence.push_back(it);
	return sentence;
}

int main()
{
	int n;
	cin >> n; // The length of both arrays
	vector<string> words(n), more(n), sentence;
	for (auto &it : words)
		cin >> it;
	for (auto &it : more)
		cin >> it;
	for (auto it : mereg(words, more))
	{
		cout << it << " ";
	}
	cout << endl;
}