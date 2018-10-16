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
#include <queue>


using namespace std;
bool SHOW = false;


typedef vector<int> VI;

typedef std::array<int, 2> AI;



ostream& operator<<(ostream& o, VI& a) {
  for (int i : a) o << i << " ";
  return o;
}

ostream& operator<<(ostream& o, deque<int>& a) {
  for (int i : a) o << i << " ";
  return o;
}


ostream& operator<<(ostream& o, AI& a) {
  for (int i : a) o << i << " ";
  return o;
}
ostream& operator<<(ostream& o, set<int>& a) {
  for (int i : a) o << i << " ";
  return o;
}


class PairCompare
{
public:
    bool operator() (pair<int, int>& lhs, pair<int, int>& rhs) {
        return lhs.first > rhs.first;
    }
};



int testcase() {
  int n; cin >> n;

  VI nums;
  for (int i = 0; i < n; i++) {
    int temp; cin >> temp; nums.push_back(temp);
  }

  priority_queue<pair<int, int>, vector<pair<int, int> >,  PairCompare> prio;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < nums[i]; j++) {
      int temp; cin >> temp;
      prio.push(make_pair(temp, i));
    }
  }


  long min_dist = 100000000000;
  queue< pair<int, int> > positions;
  vector<int> class_counter(n, 0);
  int words_found = 0;

  while (1) {
    // if (find(class_counter.begin(), class_counter.end(), 0) != class_counter.end()) {
    if (words_found < n) {
      pair<int, int> elem = prio.top(); prio.pop();
      positions.push(elem);
      class_counter[elem.second]++;
      if (class_counter[elem.second] == 1) words_found++;

      if (prio.empty()) {
        break;
      }
    } else {
      int curr_dist = positions.back().first - positions.front().first + 1;
      if (min_dist > curr_dist) {
        min_dist = curr_dist;
      }
      // pair<int, int> elem = positions.front();

      class_counter[positions.front().second]--;
      if (class_counter[positions.front().second] == 0) words_found--;
      positions.pop();
    }

  }
  cout << min_dist << endl;
  return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false); // Always!

    int t; std::cin >> t; // Read the number of test cases
    for (int i = 0; i < t; ++i)
      testcase();
        // testcase(); // Solve a particular test case
}
