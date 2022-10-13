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
