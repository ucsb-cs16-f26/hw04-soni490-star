#include <cctype>
#include <iostream>
using namespace std;
#include <string>

void usage() {
  std::cout << "USAGE: caesar [-ed] [key]\n";
}

int main(int argc, char** argv) {
  int key = stoi(argv[2]);

  if(argc != 3 || argv[1] != "-e" || argv[1] != "-d" || stoi(argv[2]) < 0) {
    usage();
    return 1;
  }

  string base = "abcdefghijklmnopqrstuvwxyz";

  if (argv[1] == "-e"){
    cout << base << "\n" << base.substr(key%26) << base.substr(0,key%26) 
    << endl;
    // e.g.: (key=4) prints abc...xyz \n defg...xyzabc
  }
  else if (argv[1] == "-d") {
    cout << base.substr(key%26) << base.substr(0,key%26) << "\n" << base 
    << endl;
    // e.g.: (key=12) prints lmn...xyzabc...ijk \n abc...xyz
  }

  // TODO: Finished this program
}
