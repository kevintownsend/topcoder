// C++11
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <set>
#include <string>

using namespace std;

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

pair<int, int> make_move(vector<int> &grid, int N, int C) {
  auto d_grid = twoD(grid, N);
  // TODO: assign weights to grid.
  // TODO: map of highest weights empty (c, i, j) -> weight.
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
            //if (
          }
        }

      }
    }
  }

  return make_pair(0,0);
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

    endOfLoop:
    i++;
  }
}
