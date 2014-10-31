#ifndef WORD_H
#define WORD_H
#include "element.h"
#include "dict.h"
class Word:public element
{
  public:
  Word (string str);
  void complete(const Dict &d);
  void check(const Dict &d);
  void show()const;
  private:
  string input;
  vector<string> wordvec;
  vector<string> allmatch;
  vector<string> match;
  vector<int> hammingdistance;

  

};
#endif

