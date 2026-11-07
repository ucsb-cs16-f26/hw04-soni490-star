#include <cctype>
#include <iostream>
using namespace std;
#include <string>

void usage() {
  cout << "USAGE: caesar [-ed] [key]\n";
}

string caesarStr(string s, int amount) {
  for (size_t i=0; i<s.length(); i++) {
    if (isupper(s[i])) {
      int position = (s[i] - 'A'+amount+26)%26;
      s[i] = 'A' + position;
    } else if (islower(s[i])) {
      int position = (s[i] - 'a'+amount+26)%26;
      s[i] = 'a' + position;
    }
  }
  return s;
}

int main(int argc, char** argv) {
  if(argc != 3) {
    usage();
    return 1;
  }

  string action = argv[1];
  int key = stoi(argv[2]);
  if (key < 0 || (action != "-e" && action != "-d")) {
    usage();
    return 1;
  }

  int shift = ((key%26)+26)%26;
  int amount;

  if (action == "-e")
    amount = shift;
  else if (action == "-d")
    amount = -1*shift;
  
  string line;
  while (getline(cin, line)) 
    cout << caesarStr(line, amount) << '\n';

  return 0;
}
