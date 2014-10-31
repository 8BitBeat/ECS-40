#ifndef PHRASE_H
#define PHRASE_H
#include "element.h"

class Phrase:public element
{
  public:
  Phrase (string str);
  virtual void complete(const Dict &d);
  virtual void check(const Dict &d);
  virtual void show()const;
  private:
  string input;
  vector<string> phrasevec;
  vector<string> allmatch;
  vector<string> match;

};
#endif

