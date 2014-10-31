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
  string input;
  string text;
  string fulltext;

  cout<<"Enter a string"<< endl;
  cin>>input;

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

  vector <string> broken_phrase;
  vector <vector<string> > phrase_template;
  vector <string> temp_phrase(sentence.begin(), sentence.end());
  set <string> phrase;
  vector <string> phrasetemp;
  vector <string> transfer;
  string p;

  char_separator<char> sepP(". ");
  int lengthofvector = sentence.size();
  int lengthofstring = temp_phrase.size();
    for(iter = sentence.begin(); iter != sentence.end(); iter++)
     {//take one sentence from the sentence set
      string p =*iter;
      tokenizer<char_separator<char> > tokenP(p, sepP);
      for(tokenizer<char_separator<char> >::iterator itt = tokenP.begin();
         itt != tokenP.end();
         ++itt)
      {
        broken_phrase.push_back (*itt);
      }//parse sentence p into words and stores it as a vector (broken_phrase)
    phrase_template.push_back(broken_phrase);
    broken_phrase.clear();

    }

    for(int index =0; index< lengthofstring;++index)
    {//MASTER CONTROL, checks which sentence is being examined

      if(phrase_template[index].size()<2)
      {
        int useless=1;
      }

      else if(phrase_template[index].size()<6)
      {
        int end= phrase_template[index].size()-1;
        for(int front=0; front<end; front++)
        {
          for(int endrange=front+1; endrange<=end; endrange++)
          {
            for(int forwarditer= front; forwarditer<=endrange; forwarditer++)
            {
              phrasetemp.push_back(phrase_template[index][forwarditer]);
            }
             for(  vector<string>::const_iterator iter = phrasetemp.begin(); iter != phrasetemp.end(); iter++)
             p= p+" "+ *iter;

             p.erase(0,1);//gets rid of first white space
             phrase.insert(p);
             p.clear();


             phrasetemp.clear();
         }
        }
      }//If the sentence is less than 5 words
      else
      {
 for(int end=4; end<=phrase_template[index].size()-1;end++)
        {
          for(int front=end-4; front<end;front++)
          {
            for(int endrange=front+1; endrange<=end; endrange++)
            {
              for(int forwarditer= front; forwarditer<=endrange; forwarditer++)
              {
                phrasetemp.push_back(phrase_template[index][forwarditer]);
              }
                for(  vector<string>::const_iterator iter = phrasetemp.begin(); iter != phrasetemp.end(); iter++)
                p= p+" "+ *iter;

             p.erase(0,1);//gets rid of first white space
             phrase.insert(p);
             p.clear();


             phrasetemp.clear();
            }
          }
        }
      }//else sentence is greater than 5 words
    }

  vector<string> phrasevec;

//set<string>::const_iterator iter;
//----------------------------------------------------------------------------
  for(iter = phrase.begin(); iter != phrase.end(); iter++)
    {
      phrasevec.push_back(*iter);
    }




vector<int> hamdist;
int distance;
vector <string> match;
string temp;
int tempham;
 for(int i=0; i < phrasevec.size(); i++)
  {
    temp= phrasevec[i];
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
    cout<< "PHRASE completion for: "<<input<<endl;
    for(int i=0; i<match.size();i++)
    cout<<match[i]<<endl;
  }

  else
  {
    cout<< "PHRASE completion for: "<<input<<endl;
    for(int i=0; i<10;i++)
    cout<<match[i]<<endl;
  }
//------------------------------------------------------------------------------

  vector<int> hammingdistance;
  vector<int> allstringsize;
  vector<string> allmatch;
  int tempham2;
  int stringsize;
  string temp2;
  int inputsize = input.size();

  for(int i=0; i<phrasevec.size();i++)
  {
    int allhamdist=0;
    temp2=phrasevec[i];
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

    cout<< "PHRASE correction for: "<<input<<endl;
    for(int i=0; i<10;i++)
    cout<<allmatch[i]<<endl;










}

