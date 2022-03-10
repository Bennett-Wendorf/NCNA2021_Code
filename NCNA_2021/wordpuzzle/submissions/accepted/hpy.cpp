#include <bits/stdc++.h>

#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef int ll;

constexpr int kMod = 1000000007;
constexpr int kMax = 100005;

int dp_array[2][kMax];

int solve(const std::string& base, const std::string& type) {
  memset(dp_array, 0, sizeof(dp_array));
  // ll dp_array[2][kMax] = {0};

  int bit = 0;

  for (int i = 0; i < type.size(); i++) {
    if (i == 0) {
      ll base_number = 0;
      for (int j = 0; j < base.size(); j++) {
        if (type[i] == base[j]) {
          base_number += 1;
        }
        dp_array[bit][j] = base_number;
      }
    } else {
      for (int j = 0; j < base.size(); j++) {
        if (j < i) {
          dp_array[bit][j] = 0;
          continue;
        }
        int increase = 0;
        if (type[i] == base[j]) {
          increase = dp_array[bit ^ 1][j - 1];
        }
        dp_array[bit][j] = (dp_array[bit][j - 1] + increase);
        if (dp_array[bit][j] >= kMod) {
          dp_array[bit][j] %= kMod;
        }
      }
    }
    bit ^= 1;
  }
  return dp_array[bit ^ 1][base.size() - 1];
}

int main() {
  string base, type, new_type;
  std::cin >> base >> type;

  int ans = 0;
  new_type = type;
  unordered_set<std::string> visited;
  for (int i = 0; i < type.size(); i++) {
    // cout << "type input= " << new_type << std::endl;
    if (visited.find(new_type) == visited.end()) {
      ans = (ans + solve(base, new_type)) % kMod;
      visited.insert(new_type);
    }
    new_type = new_type.substr(type.size() - 1, 1) +
               new_type.substr(0, type.size() - 1);
  }
  cout << ans << endl;
}
