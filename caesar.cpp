#include <cctype>
#include <iostream>
using namespace std;
#include <string>

void usage() {
  std::cout << "USAGE: caesar [-ed] [key]\n";
}

int main(int argc, char** argv) {
  if(argc != 3) {
    usage();
    return 1;
  }

  string action = argv[1];
  int key = stoi(argv[2]);

  if (key < 0 || (action != "-e" && action != "-d")){
    usage();
    return 1;
  }
  string base = "abcdefghijklmnopqrstuvwxyz";
  string message = "Veni, vidi, vici";

  if (action == "-e"){
    cout << base << "\n" << base.substr(key%26) << base.substr(0,key%26) 
    << endl;
    // e.g.: (key=4) prints abc...xyz \n defg...xyzabc

  }
  else if (action == "-d") {
    cout << base.substr(key%26) << base.substr(0,key%26) << "\n" << base 
    << endl;
    // e.g.: (key=12) prints lmn...xyzabc...ijk \n abc...xyz
  }

  // TODO: Finished this program
}
