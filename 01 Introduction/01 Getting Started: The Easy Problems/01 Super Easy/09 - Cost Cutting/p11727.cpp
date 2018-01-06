#include <iostream>

using namespace std;

int main() {
  int tcf;
  cin >> tcf;
  int tc = tcf;

  while (tc) {
    int a;
    int b;
    int c;

    cin >> a >> b >> c;

    int max = a;
    if (b > max) {
      max = b;
    }
    if (c > max) {
      max = c;
    }

    int min = a;
    if (b < min) {
      min = b;
    }
    if (c < min) {
      min = c;
    }

    if (a != max && a != min) {
      cout << "Case " << tcf - tc + 1 << ": " << a << endl;
    } else if (b != max && b != min) {
      cout << "Case " << tcf - tc + 1 << ": " << b << endl;
    } else {
      cout << "Case " << tcf - tc + 1 << ": " << c << endl;
    }

    tc--;
  }

  return 0;
}