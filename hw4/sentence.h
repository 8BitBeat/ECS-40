#ifndef SENTENCE_H
#define SENTENCE_H
#include "element.h"

class Sentence:public element
{
  public:
  Sentence(string str);
  virtual void complete(const Dict &d);
  virtual void check(const Dict &d);
  virtual void show()const;
  private:
  string input;
  vector<string> sentencevec;
  vector<string> allmatch;
  vector<string> match;
 

};

#endif
