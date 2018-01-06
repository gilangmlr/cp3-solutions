#include <iostream>

using namespace std;

int main() {
  int q;
  cin >> q;

  while (q != 0) {
    int n, m;
    cin >> n >> m;

    while (q--) {
      int x, y;
      cin >> x >> y;

      if (x == n || y == m) {
        cout << "divisa" << endl;
        continue;
      }

      if (y > m) {
        cout << "N";
      } else if (y < m) {
        cout << "S";
      } else {
        cout << "?";
      }

      if (x > n) {
        cout << "E" << endl;
      } else if (x < n) {
        cout << "O" << endl;
      } else {
        cout << "?" << endl;
      }
    }

    cin >> q;
  }

  return 0;
}