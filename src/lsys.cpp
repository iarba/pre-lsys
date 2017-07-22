#include <cstdio>
#include <iostream>
#include <cstdint>

using namespace std;

#include "lsys.hpp"

void load_rules(char* file, string *rules, string *replacement, string *axiom, int *gens)
{
  FILE *f = fopen(file, "r");
  char *buf = new char[1000](); 
  int size, k;
  char origin;
  if(fscanf(f, AXIOM" %s%n\n", buf, &size) == 1)
  {
    *axiom = string(buf);
  }
  if(fscanf(f, GENERATION" %d%n\n", &k, &size) == 1)
  {
    *gens = k;
  }
  if(fscanf(f, AXIOM" %s%n\n", buf, &size) == 1)
  {
    *axiom = string(buf);
  }
  while(fscanf(f, RULE" %c -> %s%n\n", &origin, buf, &size) == 2)
  {
    rules[(uint8_t)origin] = string(buf);
  }
  while(fscanf(f, REPLACE" %c -> %s%n\n", &origin, buf, &size) == 2)
  {
    replacement[(uint8_t)origin] = string(buf);
  }
  delete[] buf;
  fclose(f);
}

int main(int argc, char **argv)
{
  int i, generations;
  string axiom;
  string* rules = new string[256]();
  string* replacement = new string[256]();
  for(i = 0; i <= 255; i++)
  {
    rules[i] += (char)i;
    replacement[i] += (char)i;
  }
  char *file = (char *)DEF_config_file;
  if(argc >= 2)
  {
    file = argv[2];
  }
  load_rules(file, rules, replacement, &axiom, &generations);
//  cout << expand(generations, axiom) << "\n";
  delete[] rules;
  return 0;
}
