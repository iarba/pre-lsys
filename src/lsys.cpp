#include <cstdio>
#include <iostream>
#include <cstdint>
#include <string> 

using namespace std;

#include "lsys.hpp"

void load_rules(char* file, string *rules, string *replacement, string *axiom, int *gens, int *angle)
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
  if(fscanf(f, ANGLE" %d%n\n", &k, &size) == 1)
  {
    *angle = k;
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

string expand(int gen, string source, string *rules, string *replacement)
{
  unsigned int i;
  string ns;
  for(ns = ""; gen; gen--, source = ns, ns = "")
  {
    for(i = 0; i < source.length(); ns += rules[(uint8_t)source[i++]]);
  }
  for(i = 0; i < source.length(); ns += replacement[(uint8_t)source[i++]])
  {
  }
  return ns;
}

int main(int argc, char **argv)
{
  int generations = 0, angle = 90;
  unsigned char c;
  string axiom = "";
  string* rules = new string[256];
  string* replacement = new string[256];
  for(c = 0; c <= 255; c++)
  {
    rules[(uint8_t)c] = "";
    rules[(uint8_t)c] += c;
    replacement[(uint8_t)c] = "";
    if(c == 255)
    {
      break;
    }
  }
  replacement[(uint8_t)'F'] = "F";
  replacement[(uint8_t)'f'] = "f";
  replacement[(uint8_t)'-'] = "-";
  replacement[(uint8_t)'+'] = "+";
  replacement[(uint8_t)'['] = "[";
  replacement[(uint8_t)']'] = "]";
  char *file = (char *)DEF_config_file;
  if(argc >= 2)
  {
    file = argv[2];
  }
  load_rules(file, rules, replacement, &axiom, &generations, &angle);
  cout << expand(generations, axiom, rules, replacement) << "\n";
  delete[] rules;
  return 0;
}
