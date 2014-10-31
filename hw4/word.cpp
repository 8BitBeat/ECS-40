#include "word.h"
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <set>
#include <iterator>
#include <algorithm>
#include <cstring>
#include <vector>
#include "dict.h"

Word::Word (string str){input = str;}

void Word::complete(const Dict &d)
{
     
 set<string>::const_iterator iter;

  for(iter = d.word.begin(); iter != d.word.end(); iter++)
    {
      wordvec.push_back(*iter);
    }
  vector<int> hamdist;
  int distance;
//  vector<string> match;
  string temp;
  int tempham;
  for(int i=0; i<wordvec.size(); i++)
  {
    temp= wordvec[i];
    int correct=strncmp(input.c_str(), temp.c_str(), input.size());
    if(correct==0)
    {
      distance= temp.size()-input.size();
      hamdist.push_back(distance);
      match.push_back(temp);
    }
  }

  for(int i=1;i<hamdist.size();i++)
  {
    for(int j= i-1; j>=0&& hamdist[j+1]<hamdist[j];j--)
    {
      int temp = hamdist[j+1];
      hamdist[j+1] = hamdist[j];
      hamdist[j]= temp;

      string temps = match[j+1];
      match[j+1]=match[j];
      match[j]=temps;

    }
  }
}

void Word:: check(const Dict &d)
{
  vector<int> allstringsize;
//  vector<string> allmatch;
  int tempham2;
  int stringsize;
  string temp2;
  int inputsize = input.size();

  for(int i=0; i<wordvec.size();i++)
  {
    int allhamdist=0;
    temp2=wordvec[i];
    stringsize= temp2.size();

    if(inputsize>stringsize)
    {
      for(int k=0; k<stringsize; k++)
      {
        if(temp2.substr(k,1)!= input.substr(k,1))
        allhamdist+=1;
      }
      allhamdist+=inputsize-stringsize;
    }



    else if(stringsize>inputsize)
    {
      for(int k=0; k<inputsize; k++)
      {
        if(input.substr(k,1)!= temp2.substr(k,1))
        allhamdist+=1;
      }
      allhamdist+=stringsize-inputsize;
    }


    else
    {
      for(int k=0; k<inputsize; k++)
      {
        if(input.substr(k,1)!= temp2.substr(k,1))
        allhamdist+=1;
      }
    }
  allmatch.push_back(temp2);
  hammingdistance.push_back(allhamdist);
  }



  for(int i=1;i<hammingdistance.size();i++)
  {
    for(int j= i-1; j>=0&& hammingdistance[j+1]<hammingdistance[j];j--)
    {
      int temp = hammingdistance[j+1];
      hammingdistance[j+1] = hammingdistance[j];
      hammingdistance[j]= temp;

      string temps = allmatch[j+1];
      allmatch[j+1]=allmatch[j];
      allmatch[j]=temps;

    }
  }

}

void Word:: show() const
{
  if(match.size()<10)
  {
    cout<< "WORD completion for: "<<input<<endl;
    for(int i=0; i<match.size();i++)
    cout<<match[i]<<endl;
  }

  else
  {
    cout<< "WORD completion for: "<<input<<endl;
    for(int i=0; i<10;i++)
    cout<<match[i]<<endl;
  }

    cout<< "WORD correction for: "<<input<<endl;
    for(int i=0; i<10;i++)
    cout<<allmatch[i]<<hammingdistance[i]<<endl;

}

