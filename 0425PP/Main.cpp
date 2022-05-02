#include <iostream>
#include <vector>

using namespace std;

template <typename T>

T sum(T a, T b) {
	return a + b;
}


int main() {

	vector<int> a;

	cout << sum<double>(5.0, 3.434) << endl;

	a.push_back(1);
	a.push_back(2);
	a.push_back(4);
	a.push_back(8);
	a.push_back(16);

	cout << a.size() << endl;
	cout << a[4];

	return 0;
}