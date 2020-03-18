#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);


	ll t;
	cin >> t;

	while(t--)
	{

		string s;
        cin >> s;

        stack<int> st;

        bool flag = true;;

        for(ll i = 0; i<s.length(); i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
             { 
                   st.push(s[i]);
             }

            else
            {
                char c;

                if(st.empty()==false)
                {
                        c = st.top();
                        st.pop();
                }

                else
                    {
                        flag = false;
                        break;
                    }
                   

                if(c=='[' && s[i]!=']' )
                {
                    flag = false;
                    break;
                }

                
                if(c=='{' && s[i]!='}' )
                {
                    flag = false;
                    break;
                }

                
                if(c=='(' && s[i]!=')' )
                {
                    flag = false;
                    break;
                }


            }
            
        }

        if(st.empty()==false)
            flag = false;

        if(flag == true)
            cout << "balanced" << "\n";

        else
            cout << "not balanced" <<"\n";
        
	}
}
