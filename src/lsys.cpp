#include <cstdio>
#include <iostream>

using namespace std;

#include "lsys.hpp"

string expand(int gen, string x)
{
  int i;
  string ns;
  for(; gen; gen--, x = ns)
  {
    ns = "";
    for(i = 0; i <= x.length(); i++)
    {
      if(x[i] == 'A')
      {
        ns += exp_A;
        continue;
      }
      if(x[i] == 'B')
      {
        ns += exp_B;
        continue;
      }
      ns += x[i];
    }
  }
  return x;
}

int main()
{
  cout << expand(generations, axiom) << "\n";
  return 0;
}
