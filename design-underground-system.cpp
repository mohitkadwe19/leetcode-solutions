#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem
{
public:
  map<int, pair<int, string>> m;
  map<string, pair<int, int>> p;
  UndergroundSystem()
  {
    m.clear();
    p.clear();
  }

  void checkIn(int id, string s, int t)
  {
    m[id] = {t, s};
  }

  void checkOut(int id, string s, int t)
  {
    string d = m[id].second + " " + s;
    auto &i = p[d];
    i.first += t - m[id].first;
    i.second++;
  }

  double getAverageTime(string s, string e)
  {
    string route = s + " " + e;
    return (double)p[route].first / p[route].second;
  }
};

int main()
{
  UndergroundSystem undergroundSystem;
  undergroundSystem.checkIn(45, "Leyton", 3);
  undergroundSystem.checkIn(32, "Paradise", 8);
  undergroundSystem.checkIn(27, "Leyton", 10);
  undergroundSystem.checkOut(45, "Waterloo", 15);
  undergroundSystem.checkOut(27, "Waterloo", 20);
  undergroundSystem.checkOut(32, "Cambridge", 22);
  cout << undergroundSystem.getAverageTime("Paradise", "Cambridge") << endl;
  cout << undergroundSystem.getAverageTime("Leyton", "Waterloo") << endl;
  undergroundSystem.checkIn(10, "Leyton", 24);
  cout << undergroundSystem.getAverageTime("Leyton", "Waterloo") << endl;
  undergroundSystem.checkOut(10, "Waterloo", 38);
  cout << undergroundSystem.getAverageTime("Leyton", "Waterloo") << endl;
  return 0;
}