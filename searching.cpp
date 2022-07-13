#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> A, int target) {
	int n = A.size();

	for (int i=0; i < n; i++) {
		if (A[i] == target) {
			return i;
		} else {
			return -1;
		}
	}
}

int binarySearch(vector<int> A, int target) {
	int high = A.size();
	int low = 0;
	while (high != low) {
		int mid = (low + high) / 2;
		if (A[mid] == target) {
			return mid;
		} else if (A[mid] < target) {
			low = mid + 1;
		} else if (A[mid] > target) {
			high = mid - 1;
		} else {
			return -1;
		}
	}
}

int main(void) {
	vector<int> a = {1, 5, 10, 23, 45, 87, 92};
	int t = 23;
	cout << binarySearch(a, t) << endl;
	return 0;
}
