#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

void filterSimple(bool *arr, long int maxDlina);

int main() {
	long int n{ 10000000 };
	bool* simple = new bool[n + 1];
	for (int i{0}; i < n + 1; ++i) {
		simple[i] = true;
	}
	simple[0] = simple[1] = false;

	int timeStart = clock();
	filterSimple(simple, n + 1);
	int timeEnd = clock();
	cout << timeEnd - timeStart << "ms";

	/*for (int i{0}; i < n; ++i) {
		if (simple[i]) {
			cout << i << " ";
		}
	}*/
}

void filterSimple(bool *arr, long int maxDlina) {
	for (int i{ 2 }; i <= sqrt(maxDlina); ++i) {
		if (arr[i]) {
			for (int j = i * i; j <= maxDlina; j += i) {
				arr[j] = false;
			}
		}
	}
}