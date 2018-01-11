#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main() {
  int n, p;
  cin >> n >> p;
  string tmp;
  getline(cin, tmp);

  int rfpCounter = 1;
  while (n != 0 && p != 0) {
    for (int i = 0; i < n; ++i)
    {
      string req;
      getline(cin, req);
    }

    string currentCompany = "";
    float currentPrice = numeric_limits<float>::max();
    float currentCompliant = 0.0;
    for (int i = 0; i < p; ++i)
    {
      string company;
      float d;
      int r;

      getline(cin, company);

      cin >> d >> r;
      getline(cin, tmp);

      float compliant = (float) r / (float) n;
      bool selected = false;

      if (compliant > currentCompliant) {
        selected = true;
      } else if (compliant == currentCompliant) {
        if (d < currentPrice) {
          selected = true;
        }
      }

      if (selected) {
        currentCompany = company;
        currentPrice = d;
        currentCompliant = compliant;
      }

      for (int j = 0; j < r; j++) {
        string metReq;
        getline(cin, metReq);
      }

    }

    cout << "RFP #" << rfpCounter << endl;

    cin >> n >> p;
    getline(cin, tmp);

    if (n != 0 && p != 0) {
      cout << currentCompany << endl << endl;
    } else {
      cout << currentCompany << endl;
    }


    rfpCounter++;
  }
  
  return 0;
}