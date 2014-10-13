#include<iostream>

using namespace std;

int main() {
	string s;
	int res = 0;
	cin >> s;
	for(char& i : s)
		if (i=='a'||i=='e'||i=='i'||i=='o'||i=='u'||i=='1'||i=='3'||i=='5'||i=='7'||i=='9')
			res += 1;
	cout << res << endl;
	return 0;
}
