// C++11
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <set>
#include <string>
#include <queue>

using namespace std;

// TODO: This relies on return value optimization. Not great...
vector<vector<int>> empty(int N) {
  vector<vector<int>> ret(N);
  for (int i = 0; i < N; ++i) {
    ret[i].resize(N);
  }

  return ret;
}

vector<vector<int>> twoD(vector<int> &grid, int N) {
  auto ret = empty(N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      ret[i][j] = grid[i*N+j];
    }
  }
  return ret;
}

bool check(pair<int, int> from, pair<int, int> to, vector<vector<int>> grid) {
  int n = grid.size();
  // TODO: complete check.
  std::queue<pair<int, int>> nodes;
  nodes.push(from);
  while(!nodes.empty()) {
    pair<int, int> current = nodes.front();
    nodes.pop();
    vector<pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    for (auto direction : directions) {
      int i = current.first + direction.first;
      int j = current.second + direction.second;
      if (i >= 0 && i < n && j >= 0 && j < n) {
        if (i == to.first && j == to.second) {
          return true;
        }
        if (grid[i][j] == 0) {
          grid[i][j] = 1;
          nodes.push(make_pair(i,j));
        }
      }
    }
  }
  return false;
}

pair<pair<int, int>, pair<int, int>> make_move(vector<int> &grid, int N, int C) {
  auto d_grid = twoD(grid, N);
  // TODO: assign weights to grid.
  // TODO: map of highest weights empty (c, i, j) -> weight.
  //map<tuple<int, int, int>, int> occupied_weights;
  map<int, map<pair<int, int>, int>> occupied_weights;
  map<tuple<int, int, int>, int> empty_weights;
  // TODO: map of lowest weights (c, i, j) -> weight.
  for (int c = 0; c < C; ++c) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        int weight = 0;
        vector<pair<int, int>> directions = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0}, {-1,1}};
        for (pair<int, int> direction : directions) {
          for (int x = 1; x < 5; ++x) {
            int i2 = i + x * direction.first;
            int j2 = j + x * direction.second;
            // TODO: check bounds, check color.
            if (i2 >= 0 && i2 < N && j2 >= 0 && j2 < N) {
              if (d_grid[i2][j2] == c) {
                ++weight;
              }
            }
          }
        }
        if (d_grid[i][j] == 0) {
          empty_weights[make_tuple(c, i, j)] = weight;
        }
        if (d_grid[i][j] == c) {
          occupied_weights[c][make_pair(i, j)] = weight;
        }
      }
    }
  }

  // TODO: find potential moves.
  for (auto empty_it = empty_weights.rbegin(); empty_it != empty_weights.rend(); ++empty_it) {
    auto options = occupied_weights[std::get<0>(empty_it->first)];
    for (auto occupied_it = options.begin(); occupied_it != options.end(); ++occupied_it) {
      pair<int, int> from = occupied_it->first;
      pair<int, int> to = make_pair(std::get<1>(empty_it->first), std::get<2>(empty_it->first));
      if(check(from, to, d_grid)) {
        return make_pair(from, to);
      }
    }
  }
  // TODO: dfs for valid move.

  return make_pair(make_pair(0,0), make_pair(0,0));
}

int main()
{
  int EMPTY = 0;
  int dr[] = { 0,1,0,-1};
  int dc[] = {-1,0,1, 0};

  int N;
  int C;
  int elapsedTime;
  vector<int> nextBalls(3);

  cin >> N;
  cin >> C;
  vector<int> grid(N*N);

  for (int i=0; i<1000; )
  {
    //read grid
    for (int k=0; k<N*N; k++) cin >> grid[k];

    //read next balls
    for (int k=0; k<3; k++) cin >> nextBalls[k];

    //read elapsed time
    cin >> elapsedTime;

    //make move
    auto move = make_move(grid, N, C);
    cout << move.first.first << " " << move.first.second << " ";
    cout << move.second.first << " " << move.second.second << "\n";

    /*
    for (int r=0; r<N; r++)
      for (int c=0; c<N; c++)
      {
        if (grid[r*N+c]==EMPTY) continue;

        for (int m=0; m<4; m++)
        {
          int r2=r+dr[m];
          int c2=c+dc[m];

          if (r2>=0 && r2<N && c2>=0 && c2<N && grid[r2*N+c2]==EMPTY)
          {
            cout << r << " " << c << " " << r2 << " " << c2 << endl;
            cout.flush();
            goto endOfLoop;
          }
        }
      }
      */

    endOfLoop:
    i++;
  }
}
