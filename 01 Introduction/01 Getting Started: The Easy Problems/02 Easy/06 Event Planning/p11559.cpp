#include <iostream>

using namespace std;

int main() {
  int N, B, H, W;
  cin >> N >> B >> H >> W;

  while (cin.good() && !cin.eof()) {
    int minCost = 200 * 500000;
    bool found = false;

    for (int i = 0; i < H; i++)
    {
      int p, a;
      cin >> p;
      int hCost = p * N;

      int ws[13] = {0};

      for (int j = 0; j < W; j++)
      {
        cin >> a;
        ws[j] = a;
      }
      for (int j = 0; j < W; j++)
      {
        if (ws[j] > N && !(hCost > B || hCost >= minCost)) {
          found = true;
          minCost = hCost;
          break;
        }
      }
    }

    if (found) {
      cout << minCost << endl;
    } else {
      cout << "stay home" << endl;
    }

    cin >> N >> B >> H >> W;
  }
  
  return 0;
}