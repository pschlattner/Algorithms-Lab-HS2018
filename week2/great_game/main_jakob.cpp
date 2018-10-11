/*
 * potw.cpp
 *  Created on: 24 Sep 2018
 *      Author: Jakob
 */

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <array>


const bool SHOW = false;
using namespace std;
typedef std::vector<int> VI;

std::ostream& operator<<(std::ostream& o, VI& a) {
  for (int i : a) o << i << " ";
  return o;
}


void great_game() {

  int n; std::cin >> n;
  int m; std::cin >> m;
  int r; std::cin >> r;
  int b; std::cin >> b;

  vector<VI> mat(n, VI());
  vector<VI> memo(n+1, VI(2, -1));

  for (int i = 0; i < m; i++) {
    int start; cin >> start;
    int end; cin >> end;
    mat[start].push_back(end);
  }

  memo[n][0] = 0;
  memo[n][1] = 0;

  for (int pos = n-1; pos > 0; pos--) {

    int max_path = 0;
    int min_path = 1000000;
    for (int dest: mat[pos]) {
      if (SHOW) cout << dest << "  dest | memo  " << memo[dest][1]+1 << "\n";
      if (memo[dest][1]+1 < min_path) min_path = memo[dest][1] + 1;
    }
    for (int dest: mat[pos]) {
      if (memo[dest][0]+1 > max_path) max_path = memo[dest][0] + 1;
    }

    memo[pos][0] = min_path;
    memo[pos][1] = max_path;
  }

  if (SHOW) cout << memo[r][0] << " " << memo[b][0] << ' ' ;
  if (memo[r][0] > memo[b][0]) {
    cout << 1 << endl;
  } else if (memo[r][0] < memo[b][0]) {
    cout << 0 << endl;
  } else if (memo[r][0] == memo[b][0]) {
    if (memo[r][0]%2 == 0) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }

  if (SHOW) {
    cout << "mat\n";
    for (VI i:mat) cout << i << endl;
    cout << "memo\n";
    for (VI i:memo) cout << i << endl;
  }

}


int main() {
    std::ios_base::sync_with_stdio(false); // Always!

    int t; std::cin >> t; // Read the number of test cases
    for (int i = 0; i < t; ++i)
        great_game(); // Solve a particular test case

    return 0; // Signals successful completion to the operating system
 }
