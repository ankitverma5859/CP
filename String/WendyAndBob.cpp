/*
Given a string colors, where each character is either white or black, Wendy and Bob play a game to manipulate this string as follows:
• They perform moves alternatively in turns and Wendy makes the first move.

• In a single move, Wendy can remove from the string any white character that has exactly 2 white neighbors.

• Similarly, in a single move, Bob can remove from string any black character that has exactly 2 black neighbors.

• When a character is removed, the strings shrink itself, so if a character Y had neighbors X and Z on its left and right 
respectively before the move, after the move is made, X and Z become each other's neighbors.

• The first player who cannot perform a move loses the game. For example, if the colors string is wwwbb, with the first move Wendy 
will change it to wwbb, and Bob can no longer perform a move. Determine who has a winning strategy assuming that both Wendy and Bob play optimally
*/

#include <iostream>
using namespace std;

int main() {
	string s;
	cin>>s;
	
	int n = s.size();
	int w_cnt = 0, b_cnt = 0;
	
	if(n == 0)
	{
		cout<<"Winner: bob"<<endl;
		return 0;
	}	
	
	for(int i=1;i<n-1;i++){
		if(s[i] == 'w'){
			if(s[i-1] == 'w' and s[i+1] == 'w')
				w_cnt++;
		}
		
		if(s[i] == 'b'){
			if(s[i-1] == 'b' and s[i+1] == 'b')
				b_cnt++;
		}
	}
	
	cout<<"W: "<<w_cnt<<" B: "<<b_cnt<<endl;
	cout<<"Winner: ";
	if(w_cnt == 0) cout<<"bob"<<endl;   			    //since wendy starts the game and cannot remove anything, bob wins
	else if(b_cnt == 0) cout<<"wendy"<<endl;		  //since bob cannot remove anything, wendy wins
	else if(w_cnt <= b_cnt) cout<<"bob"<<endl;    //when wendy gets less or equal number of chances to remove from the 
													                      //the string, it will run out of removals fast than bob,
													                      //and hence bob wins
	else cout<<"wendy"<<endl;						          //wendy wins if bob runs out of removals

	return 0;
}
