//binary search
//23.04.17
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>


using namespace std;

void fill_arr(vector<int> &, int SIZE);
int bin_search(vector<int> &, int left, int right, int number);

int main() {
	const int SIZE = 10;
	int number;
	cout << "Enter a number in range [0 : 10)\n";
	cin >> number;
	vector<int> nums(SIZE);

	fill_arr(nums, SIZE);
	sort(nums.begin(), nums.end());
	int result = bin_search(nums, 0, SIZE - 1, number);
	for (auto x : nums) {
		cout << x << " ";
	}
	cout << endl;
	if (result != -1) {
		cout << "Your number here on index " << result << endl;
	}
	else {
		cout << "No such number in random array. Sorry...\n";
	}

	system("pause");
	return 0;
}

int bin_search(vector<int> & arr, int left, int right, int number)
{
	int mid = left + (right - left) / 2;

	if (left > right) {
		return -1;
	}

	if (left <= right) {
		if (number == arr[mid]) {
			return mid;
		}
		else if (number > arr[mid]) {
			bin_search(arr, mid + 1, right, number);
		}
		else {
			bin_search(arr, left, mid - 1, number);
		}
	}
}

void fill_arr(vector<int> & nums, int SIZE) {
	srand(time(0));
	for (int i = 0; i < SIZE; i++) {
		nums[i] = rand() % 10;
	}
}
