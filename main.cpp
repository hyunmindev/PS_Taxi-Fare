#include <iostream>
#include <vector>

using namespace std;

int solution(int node_count, int s, int a, int b, vector<vector<int>> fare_vec) {
  vector<vector<int>> dist_vec_vec(node_count + 1, vector<int>(node_count + 1, 19900001));
  for (auto fare : fare_vec) {
    dist_vec_vec[fare[0]][fare[1]] = fare[2];
    dist_vec_vec[fare[1]][fare[0]] = fare[2];
  }
  for (int i = 1; i <= node_count; i++) {
    dist_vec_vec[i][i] = 0;
  }
  for (int i = 1; i <= node_count; i++) { // 중간
    for (int j = 1; j <= node_count; j++) { // 출발
      for (int k = 1; k <= node_count; k++) { // 도착
        dist_vec_vec[j][k] = min(dist_vec_vec[j][k], dist_vec_vec[j][i] + dist_vec_vec[i][k]);
      }
    }
  }
  int output = 19900001;
  for (int k = 1; k <= node_count; k++) {
    output = min(output, dist_vec_vec[s][k] + dist_vec_vec[k][a] + dist_vec_vec[k][b]);
  }
  return output;
}

int main() {
  cout << solution(6, 4, 6, 2,
                   {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 42}, {5, 1, 24}, {4, 6, 50},
                       {2, 4, 66}, {2, 3, 22}, {1, 6, 25}}) << endl;
//  cout << solution(7,3,4,1,
//                   {{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}}) << endl;
  return 0;
}