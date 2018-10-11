/*
 * potw.cpp
 *  Created on: 24 Sep 2018
 *      Author: Jakob
 */

// maybe i should not copy the entire deque all the time

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <array>
#include <deque>

using namespace std;

typedef std::vector<int> VI;
typedef std::deque<int> DI;


bool SHOW = false;

vector<VI> memo;
VI pre_sum;


int sum_VI(VI vec) {
	int sum = 0;
	for (auto i: vec) sum += i;
	return sum;
}

std::ostream& operator<<(std::ostream& o, const VI& a) {
  for (int i : a) o << i << " ";
  return o;
}


int get_value(VI& di, int i, int j) {
	int sum = pre_sum[j] - pre_sum[i];
	if (SHOW) cout << "i " << i << "  j " << j << " sum: " << sum << endl;
	if (memo[i][j] != -1) {
		if (SHOW) cout << "memo \n";
		return memo[i][j];
	} else if (j-i == 1) {
		int res = di[j-1];
		memo[i][j] = res;
		return res;
	} else if (j-i == 2) {
		int res = max(di[j-1], di[i]);
		memo[i][j] = res;
		return res;
	} else {
		int res = max(sum - get_value(di, i, j-1),
									sum - get_value(di, i+1, j));

		memo[i][j] = res;
		return res;
	}
}



void burning_coins() {

	int n; std::cin >> n;
	memo.clear();
	memo = vector<VI>(n+1, VI(n+1, -1)); // need to do it better

	VI vi;
	for (int i = 0; i < n; i++) {
		int temp; std::cin >> temp;
		vi.push_back(temp);
	}

	// compute prefix sum
	pre_sum.clear();
	pre_sum.push_back(0);
	int temp_sum = 0;
	for (int i: vi) {
		temp_sum += i;
		pre_sum.push_back(temp_sum);
	}


	// recursive implementation
	int res = get_value(vi, 0, vi.size());

	// if (SHOW) {
	// 	std::cout << vi << " and size: " << vi.size() << std::endl;
	// 	std::cout << pre_sum << std::endl;
	// }

	std::cout << res << std::endl;
}


int main() {
    std::ios_base::sync_with_stdio(false); // Always!

    int t; std::cin >> t; // Read the number of test cases
    for (int i = 0; i < t; ++i)
        burning_coins(); // Solve a particular test case

    return 0; // Signals successful completion to the operating system
 }
