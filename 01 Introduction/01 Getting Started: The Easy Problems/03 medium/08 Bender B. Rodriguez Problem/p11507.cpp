#include <iostream>
#include <string>

using namespace std;

int main() {
  int L;
  cin >> L;

  while (L) {
    string lastDir = "+x";
    for (int i = 0; i < L - 1; ++i)
    {
      string move;
      cin >> move;

      if (move == "+y") {
        if (lastDir != "+z" && lastDir != "-z") {
          if (lastDir == "+y") {
            lastDir = "-x";
          } else if (lastDir == "-y") {
            lastDir = "+x";
          } else if (lastDir == "+x") {
            lastDir = "+y";
          } else if (lastDir == "-x") {
            lastDir = "-y";
          }
        }
      } else if (move == "-y") {
        if (lastDir != "+z" && lastDir != "-z") {
          if (lastDir == "+y") {
            lastDir = "+x";
          } else if (lastDir == "-y") {
            lastDir = "-x";
          } else if (lastDir == "+x") {
            lastDir = "-y";
          } else if (lastDir == "-x") {
            lastDir = "+y";
          }
        }
      } else if (move == "+z") {
        if (lastDir != "+y" && lastDir != "-y") {
          if (lastDir == "+z") {
            lastDir = "-x";
          } else if (lastDir == "-z") {
            lastDir = "+x";
          } else if (lastDir == "+x") {
            lastDir = "+z";
          } else if (lastDir == "-x") {
            lastDir = "-z";
          }
        }
      } else if (move == "-z") {
        if (lastDir != "+y" && lastDir != "-y") {
          if (lastDir == "+z") {
            lastDir = "+x";
          } else if (lastDir == "-z") {
            lastDir = "-x";
          } else if (lastDir == "+x") {
            lastDir = "-z";
          } else if (lastDir == "-x") {
            lastDir = "+z";
          }
        }
      }
    }

    cout << lastDir << endl;

    cin >> L;
  }
  
  return 0;
}