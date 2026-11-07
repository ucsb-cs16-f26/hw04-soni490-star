#include <cctype>
#include <iostream>
using namespace std;
#include <string>

void usage() {
  cout << "USAGE: substitution [-ed] [key]\n";
}

string cipher(bool isEncoding, string s, string key){
  if(isEncoding){
    for (size_t i = 0; i < s.length(); i++) {
    if (isupper(s[i])) {
      for (int j = 0; j < 26; j++) {
        if (('A' + j) == s[i]) {
          s[i] = toupper(key[j]);
          break;
        }
      }
    } else if (islower(s[i])) {
      for (int j = 0; j < 26; j++) {
        if (('a' + j) == s[i]) {
          s[i] = tolower(key[j]);
          break;
        }
      }
    }
  }
  return s;
  } else {
    for (size_t i = 0; i < s.length(); i++) {
    if (isupper(s[i])) {
      for (int j = 0; j < 26; j++) {
        if (toupper(key[j]) == s[i]) {
          s[i] = 'A' + j;
          break;
        }
      }
    } else if (islower(s[i])) {
      for (int j = 0; j < 26; j++) {
        if (tolower(key[j]) == s[i]) {
          s[i] = 'a' + j;
          break;
        }
      }
    }
  }
  return s;
  }
}

int main(int argc, char** argv) {
  if(argc != 3) {
    usage();
    return 1;
  }

  string action = argv[1];
  string key = argv[2];
  if (action != "-e" && action != "-d") {
    usage();
    return 1;
  }
  bool encoding = false;
  if (action=="-e")
    encoding=true;
  else if (action=="-d")
    encoding=false;  
  
  string line;
  while (getline(cin, line)) {
    cout << cipher(encoding, line, key) << '\n';
  }
  return 0;
}
