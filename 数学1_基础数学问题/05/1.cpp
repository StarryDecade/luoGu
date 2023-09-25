#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	
	cout << a*b*c / __gcd(b, c) / __gcd(a, b * c / __gcd(b, c));
}
