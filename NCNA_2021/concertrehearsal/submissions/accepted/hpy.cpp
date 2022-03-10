#include <bits/stdc++.h>

#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;

bool FillSegment(int& i, ll& capacity,
                 const std::vector<ll>& students_prefix_sum,
                 const std::vector<ll>& students, ll& success_loop, int n) {
  if (students[i] > capacity) {
    return false;
  }

  ll start_point = i == 0 ? 0 : students_prefix_sum[i - 1];

  int start = i, end = n;
  while (end - start > 1) {
    int mid = (start + end) / 2;
    if (students_prefix_sum[mid] - start_point <= capacity) {
      start = mid;
    } else {
      end = mid;
    }
  }
  capacity -= (students_prefix_sum[start] - start_point);
  i = start + 1;
  if (i == n) {
    i = 0;
    success_loop += 1;
  }
  return true;
}

ll solve(const std::vector<ll>& students,
         const std::vector<ll>& students_prefix_sum, ll hall_time, ll days,
         int n, ll total_length) {
  std::unordered_map<int, std::pair<ll, ll>> first_head_visit;
  ll temp_sum = 0, current_day = 0, success_loop = 0;
  int i = 0;
  ll circle_start_day = -1, circle_end_day = -1;
  ll circle_loop = 0;
  ll capacity = 0;
  ll loop_length = -1, loop_number = 0;

  bool can_fill = true;
  bool loop_happened = false;

  while (current_day < days) {
    auto it = first_head_visit.find(i);
    // cout << "trying to find " << i << " found? "
    //      << (it != first_head_visit.end()) << std::endl;
    if (it != first_head_visit.end() && !loop_happened) {
      loop_length = current_day - it->second.first;
      circle_loop = success_loop - it->second.second;

      loop_number = (days - current_day) / loop_length;
      success_loop += loop_number * circle_loop;
      days -= loop_number * loop_length;
      loop_happened = true;
      // cout << "using loop" << std::endl;
      continue;

    } else {
      first_head_visit[i] = std::make_pair(current_day, success_loop);

      capacity = hall_time;
      can_fill = true;
      while (can_fill) {
        can_fill = FillSegment(i, capacity, students_prefix_sum, students,
                               success_loop, n);
      }

      current_day += 1;
    }
  }

  return success_loop;
}

int main() {
  ll num_students, hall_time, days;
  cin >> num_students >> hall_time >> days;

  std::vector<ll> students;
  std::vector<ll> students_prefix_sum;
  bool has_slow_student = false;
  ll temp_student = 0, total_length = 0;
  for (int i = 0; i < num_students; i++) {
    cin >> temp_student;
    students.push_back(temp_student);
    if (i == 0) {
      students_prefix_sum.push_back(students[i]);
    } else {
      students_prefix_sum.push_back(students_prefix_sum[i - 1] + students[i]);
    }
    total_length += temp_student;
    if (temp_student > hall_time) {
      has_slow_student = true;
    }
  }
  if (has_slow_student) {
    cout << 0 << endl;
    return 0;
  }

  ll inner_loop = hall_time / total_length;
  ll resi_hall_time = hall_time % total_length;
  ll resi_times = solve(students, students_prefix_sum, resi_hall_time, days,
                        num_students, total_length);

  ll ans = resi_times + inner_loop * days;

  cout << ans << endl;
}
