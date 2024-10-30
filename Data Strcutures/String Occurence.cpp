#include <bits/stdc++.h>
using namespace std;

string removeOddIndexCharacters(string s)
{

	string new_string = "";

	for (int i = 0; i < s.length(); i++) {

		if (i % 2 == 1) {

			continue;
		}

		new_string += s[i];
	}

	return new_string;
}

int main()
{
	string str = "abcdef";

	cout << removeOddIndexCharacters(str);

	return 0;
}
