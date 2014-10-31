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
  cout<< "Enter a word"<< endl;
  cin>> input;

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


  set<string> word;
  vector<string> wordvec;

  char_separator<char> sepW(". ");
  tokenizer<char_separator<char> > tokenW(fulltext, sepW);

  for ( tokenizer<char_separator<char> >::iterator it = tokenW.begin();
         it != tokenW.end();
         ++it)
   {
      word.insert (*it);

   }
 set<string>::const_iterator iter;

  for(iter = word.begin(); iter != word.end(); iter++)
    {
      wordvec.push_back(*iter);
    }


//Completing words by case match and hamming distance---------------------------
  vector<int> hamdist;

  int distance;
  vector<string> match;
  string temp;
  int tempham;  
  for(int i=0; i<wordvec.size(); i++)
  {
//    cout<< wordvec[i]<<endl;
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
//show------------------------------------------------------------------------   
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

//-(---------------------------------------------------------------------------

  vector<int> hammingdistance;
  vector<int> allstringsize;
  vector<string> allmatch;
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

    cout<< "WORD correction for: "<<input<<endl;
    for(int i=0; i<10;i++)
    cout<<allmatch[i]<<hammingdistance[i]<<endl;
  
    
  













}

