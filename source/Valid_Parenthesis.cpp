// 
#include<iostream>
#include<stack>
#include<unordered_map>

using namespace std;

class solution
{
public:
	bool isValid(string s)
	{
		unordered_map<char, char> mapping = {
			{')', '('},
			{'}', '{'},
			{']', '['}
		};
		stack<char> st;
		for (char c : s)
		{
			// if c is a closing bracket (found in mapping), check stack
			if(mapping.find(c) != mapping.end())
			{

				if (st.empty() || st.top() != mapping[c])
				{
					return false;
				}
				st.pop();
			}
			else
			{
				// otherwise treat as potential opening bracket and push
				if (c == '(' || c == '{' || c == '[')
				{
					st.push(c);
				}
				// ignore non-bracket characters
			}
		}
		return st.empty();
	}
};	