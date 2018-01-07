#include <iostream>

using namespace std;

int main() {
  int lMonths, deps;
  float dp, lValue;
  cin >> lMonths >> dp >> lValue >> deps;

  while (lMonths >= 0) {
    float depsArr[100 + 10] = {0.0};

    for (int i = 0; i < deps; i++)
    {
      int month;
      float dep;
      cin >> month >> dep;

      depsArr[month] = dep;
    }

    float dep = 0.0, carWorth = dp + lValue, moneyOwe = lValue, payMonthly = lValue / lMonths;
    for (int i = 0; i <= lMonths; i++)
    {
      if (depsArr[i] != 0.0)
      {
        dep = depsArr[i];
      }
      
      if (i > 0) {
        moneyOwe -= payMonthly;
      }

      carWorth -= carWorth * dep;

      if (moneyOwe < carWorth) {
        if (i == 1) {
          cout << i << " month" << endl;
        } else {
          cout << i << " months" << endl;
        }

        break;
      }
    }

    cin >> lMonths >> dp >> lValue >> deps;
  }
  
  return 0;
}