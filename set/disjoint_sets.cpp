#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct PR {
  size_t parent;
  size_t rank;
};

void UNION(vector<PR>& DS, size_t x, size_t y)
{
  if (x == y)
    return ;
  if (DS[x].rank < DS[y].rank)
    DS[x].parent = y;
  else if (DS[y].rank < DS[x].rank)
    DS[y].parent = x;
  else
  {
    DS[y].parent = x;
    ++DS[x].rank;
  }
}

size_t FIND(vector<PR>& DS, size_t x)
{
  stack<size_t> S;
  while (DS[x].parent != x)
  {
    S.push(x);
    x = DS[x].parent;
  }
  while (!S.empty())
  {
    DS[S.top()].parent = x;
    S.pop();
  }
  return x;
}

void print(const vector<PR>& DS)
{
  for (auto const& e : DS)
    cout << '(' << e.parent << ", " << e.rank << ')' << ' ';
  cout << endl;
}

int main()
{
  vector<PR> DS(7);
  for (size_t i = 0; i < DS.size(); ++i)
    DS[i] = {i, 0};
  UNION(DS, FIND(DS, 1), FIND(DS, 5));
  print(DS);
  UNION(DS, FIND(DS, 1), FIND(DS, 6));
  print(DS);
  UNION(DS, FIND(DS, 2), FIND(DS, 4));
  print(DS);
  UNION(DS, FIND(DS, 5), FIND(DS, 4));
  print(DS);
  return 0;
}
