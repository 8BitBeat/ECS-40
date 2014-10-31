#include "dict.h"

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
//  int findfirstspace= fulltext.string::find_first_of(" ");
//  fulltext.erase (findfirstspace, findfirstspace+1);
//cout<<fulltext;
//Senternce Parsing-------------------------------------------------------------
 
  set <string> sentencewspace;
 
  char_separator<char> sepS(".");
  tokenizer<char_separator<char> > tokenS(fulltext, sepS);

  for ( tokenizer<char_separator<char> >::iterator it = tokenS.begin();
         it != tokenS.end();
         ++it)
   {    
      sentencewspace.insert (*it+'.'); 
 //     unsigned findfirstSENTspace = 


   }//parse into sentences and placing it into sentence set

  set<string>::const_iterator iter;
  string s;
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
  //  cout<<*iter<<sentencecounter<<endl;
  //  sentencecounter++;
  }//Test to see if it works
  
//  for(int i=0; i<sentence1.size();i++)
//  {
//    cout<<sentence1[i]<<i+1<<endl;
//  }    
  
  
//Word Parsing------------------------------------------------------------------

  
  char_separator<char> sepW(". ");
  tokenizer<char_separator<char> > tokenW(fulltext, sepW);

  for ( tokenizer<char_separator<char> >::iterator it = tokenW.begin();
         it != tokenW.end();
         ++it)
   {
      word.insert (*it);

   }//parse into words and place it into word set
 
 
//  for(iter = word.begin(); iter != word.end(); iter++)
//  cout<<*iter<< endl;  
//  testing purposes(words)

//Phrase Parsing--------------------------------------------------------------
  vector <string> broken_phrase;
  vector <vector<string> > phrase_template;
  vector <string> temp_phrase(sentence.begin(), sentence.end());
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
   
    }//stores broken_phrase vector as an element to vector of vectors (phrase_template)
   
//  for(int i = 0; i < lengthofstring; ++i)
//    {
//        for(int j = 0; j < phrase_template[i].size(); ++j)
//            cout << phrase_template[i][j]<< " ";
//        cout << endl;
//    }
      
  
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
      

    
//int counter=1; 
//        for(  set<string>::const_iterator iter = phrase.begin(); iter != phrase.end(); iter++)
//              {cout<<*iter<<counter<<endl; 
//                counter++;}

//-----------------------------------------------------------------------------
}//constructor


