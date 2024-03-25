#include <iostream>
#include <vector>
#include <set>
using namespace std;

// To execute C++, please define "int main()"
int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> arr(n);
    set<int> mex_set;
    for(int j = 0; j < n; j++){
      cin >> arr[j];
      mex_set.insert(arr[j]);
    }
    int mex = 0;
    while(mex_set.contains(mex)){
      mex++;
    }
    vector<int> splits;
    int counter = 0;
    mex_set.clear();
    while(mex_set.size() != mex && counter != n) {
      if(arr[counter] < mex)
        mex_set.insert(arr[counter]);
      counter++;
    }
    if(mex_set.size() != mex){
      cout << "-1\n";
      continue;
    }
    int mid = counter;
    mex_set.clear();
    while(counter != n){
      if(arr[counter] < mex)
        mex_set.insert(arr[counter]);
      counter++;
    }
    if(mex_set.size() != mex){
      cout << "-1\n";
      continue;
    }
    if(mid == 0)
      mid++;
    cout << "2\n";
    cout << "1 " << mid << "\n";
    cout << mid+1 << " " << n << "\n";
    // todo second loop.

  }
}
