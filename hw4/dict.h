#ifndef DICT_H
#define DICT_H
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <set>
#include <iterator>
#include <algorithm>
#include <cstring>
#include <vector>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

class Dict
{
  public:
    Dict(string file);
  set<string>word;
  set<string>phrase;
  set<string>sentence;
  vector<string> sentencevec;   
  protected:
  private:

};

#endif // DICT_H

