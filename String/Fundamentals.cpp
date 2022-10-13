/*
  Conversions
*/
int main() {
	string s = "5";
	char c = '5';
	int a = 10;
	double d = 10.0;
	cout<<"String to Int: "<<stoi(s)<<endl;
	cout<<"Char to INT:"<<c - '0'<<endl;			// LOOK OUT
	cout<<"Int to String:"<<to_string(a)<<endl;
	cout<<"Double to String:"<<to_string(d)<<endl;
	return 0;
}

/*
How to split a string by a delimiter?
*/

void split_string(string s, char delimiter){
  //ss is a user defined variable
  istringstream ss(s);
  
  string word;
  while(getline(ss, word, delimiter)){ 
    cout<<word;
}
