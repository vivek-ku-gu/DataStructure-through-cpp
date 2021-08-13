#include<iostream>
#include<stack>
using namespace std;
void reverseSentence(string s)
{
 stack <string> st;
 string word="";

 for(int i=0;i<s.length();i++)
 {
      
  while (s[i] !=' ' && i<s.length())
  {
      word = word + s[i];  
      i++;
  }
  st.push(word); 
  word= "";
 }
 while(!st.empty())
 {
  cout<<st.top()<<" ";
  st.pop();
 }
}
int main()
{
string s="are you in love";
reverseSentence(s);
}