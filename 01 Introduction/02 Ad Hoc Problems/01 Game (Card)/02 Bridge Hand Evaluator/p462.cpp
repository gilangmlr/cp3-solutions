#include <iostream>
#include <string>

using namespace std;

void calculatePoints(int* suit, int* points) {
  bool stopped = false;
  if (*(suit + 1) == 1) {
    *(points + 0) += 4;
    stopped = true;
  }
  if (*(suit + 13) == 1) {
    *(points + 0) += 3;

    if (*(suit + 0) < 2) {
      points[0]--;
    } else {
      stopped = true;
    }
  }
  if (*(suit + 12) == 1) {
    *(points + 0) += 2;

    if (*(suit + 0) < 3) {
      *(points + 0) -= 1;
    } else {
      stopped = true;
    }
  }
  if (*(suit + 11) == 1) {
    *(points + 0) += 1;

    if (*(suit + 0) < 4) {
      *(points + 0) -= 1;
    }
  }
  if (*(suit + 0) == 2) {
    *(points + 1) += 1;
  }
  if (*(suit + 0) == 1 || *(suit + 0) == 0) {
    *(points + 1) += 2;
  }
  if (stopped) {
    *(points + 2) += 1;
  }
}

int main() {
  do {
    // first item is number of total cards in suit
    int spades[14] = {0};
    int hearts[14] = {0};
    int diamonds[14] = {0};
    int clubs[14] = {0};

    // first item is points w/o rule 5, 6 , 7, second item is points for rule 5, 6, 7, third item is number of stopped suit
    int points[3] = {0};

    for (int i = 0; i < 13; ++i)
    {
      string tmp;
      cin >> tmp;

      if (tmp.empty()) {
        return 0;
      }

      int *arr;
      if (tmp[1] == 'S') {
        arr = spades;
      } else if (tmp[1] == 'H') {
        arr = hearts;
      } else if (tmp[1] == 'D') {
        arr = diamonds;
      } else if (tmp[1] == 'C') {
        arr = clubs;
      }
      *arr = ++*arr;

      int rank;
      if (tmp[0] == 'A') {
        rank = 1;
      } else if (tmp[0] == 'K') {
        rank = 13;
      } else if (tmp[0] == 'Q') {
        rank = 12;
      } else if (tmp[0] == 'J') {
        rank = 11;
      } else if (tmp[0] == 'T') {
        rank = 10;
      } else {
        rank = (int) tmp[0] - 48;
      }
      *(arr + rank) = 1;
    }
    
    calculatePoints(spades, points);
    calculatePoints(diamonds, points);
    calculatePoints(hearts, points);
    calculatePoints(clubs, points);

    char maxSuit = 'C';
    int maxCount = clubs[0];
    if (maxCount <= diamonds[0]) {
      maxSuit = 'D';
      maxCount = diamonds[0];
    }
    if (maxCount <= hearts[0]) {
      maxSuit = 'H';
      maxCount = hearts[0];
    }
    if (maxCount <= spades[0]) {
      maxSuit = 'S';
      maxCount = spades[0];
    }

   string res = "";

    if (points[0] + points[1] < 14) {
      res = "PASS";
    } else if (points[0] >= 16 && points[2] == 4) {
      res = "BID NO-TRUMP";
    } else {
      res = "BID " + string(1, maxSuit);
    }
    cout << res << endl;

  } while (cin.good() && !cin.eof());
  
  return 0;
}