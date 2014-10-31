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
#include "dict.h"
using namespace std;
using namespace boost;

int main(){
  Dict d("data.txt");

  return 0;
}

Dict::Dict(string f)
{
  string text;
  string fulltext;

  ifstream fp("data.txt");
  while (fp.good())
  {
    getline (fp, text);
    fulltext = fulltext+ ' ' + text;
  }//Reads the data.txt and inputs it to string fulltext (gets ridof pesky newline characters
  unsigned findfirstspace= fulltext.string::find_first_of(" ");
  fulltext.erase (findfirstspace, findfirstspace+1);


 set <string> sentencewspace;

  char_separator<char> sepS(".");
  tokenizer<char_separator<char> > tokenS(fulltext, sepS);

  for ( tokenizer<char_separator<char> >::iterator it = tokenS.begin();
         it != tokenS.end();
         ++it)
   {
      sentencewspace.insert (*it+'.');


   }//parse into sentences and placing it into sentence set

  set<string>::const_iterator iter;
  string s;
  set<string> sentence;
  vector<string> sentencevec;
  string o;


  for(iter = sentencewspace.begin(); iter != sentencewspace.end(); iter++)
  {
    s=*iter;
    s.erase(0,1);
    sentence.insert(s);
    s.clear();
  }//This removes white space in the beginning of each sentence



  int sentencecounter=1;
  for(iter = sentence.begin(); iter != sentence.end(); iter++)
  {
    if (iter==sentence.begin())
    int useless=1;

    else
    {o= *iter;
    sentencevec.push_back(o);
    }
  }
//  for(int i=0; i< sentencevec.size();i++)
//  cout<< sentencevec[i]<<endl;





//-------------------------------------------------------------------------------------------------------------------------------------------------------------

string input = "i dont";
vector<int> hamdist;
int distance;
vector <string> match;
string temp;
int tempham;
 for(int i=0; i < sentencevec.size(); i++)
  {
    temp= sentencevec[i];
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

  if(match.size()<10)
  {
    cout<< "SENTENCE completion for: "<<input<<endl;
    for(int i=0; i<match.size();i++)
    cout<<match[i]<<endl;
  }

  else
  {
    cout<< "SENTENCE completion for: "<<input<<endl;
    for(int i=0; i<10;i++)
    cout<<match[i]<<endl;
  }
//-----------------------------------------------------------------------------


  vector<int> hammingdistance;
  vector<int> allstringsize;
  vector<string> allmatch;
  int tempham2;
  int stringsize;
  string temp2;
  int inputsize = input.size();

  for(int i=0; i<sentencevec.size();i++)
  {
    int allhamdist=0;
    temp2=sentencevec[i];
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

    cout<< "SENTENCE correction for: "<<input<<endl;
    for(int i=0; i<10;i++)
    cout<<allmatch[i]<<endl;

}
















