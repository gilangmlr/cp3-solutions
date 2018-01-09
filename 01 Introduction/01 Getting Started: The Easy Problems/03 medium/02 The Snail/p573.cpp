#include <iostream>

using namespace std;

int main() {
  int H, U, D, F;
  cin >> H >> U >> D >> F;

  while (H != 0) {
    float currH = 0.0, f = U * (F / 100.0);
    int day = 1;
    bool success = false;
    while (true) {
      float initH = currH;
      float dClimbed = U - ((day - 1) * f);
      if (dClimbed < 0) {
        dClimbed = 0;
      }
      currH += dClimbed;
      float hClimbed = currH; 
      currH -= D;
      float hSlide = currH;

      if (hClimbed > H) {
        success = true;
        break;
      } else if (currH < 0) {
        success = false;
        break;
      }

      day++;
    }

    if (success) {
      cout << "success on day " << day << endl;
    } else {
      cout << "failure on day " << day << endl;
    }

    cin >> H >> U >> D >> F;
  }
  
  return 0;
}