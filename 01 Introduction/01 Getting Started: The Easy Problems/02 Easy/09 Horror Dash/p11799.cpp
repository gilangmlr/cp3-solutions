#include <iostream>

using namespace std;

int main() {
  int tc;
  cin >> tc;
  int tcf = tc;

  while (tc--) {
    int N;
    cin >> N;

    int c;
    cin >> c;

    int max = c;
    for (int i = 0; i < N - 1; i++)
    {
      cin >> c;

      if (c > max) {
        max = c;
      }
    }

    cout << "Case " << tcf - tc << ": " << max << endl;
  }
  
  return 0;
}