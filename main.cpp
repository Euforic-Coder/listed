#include <iostream>
#include <getopt.h>
#include "uforia/uforia.h"

using namespace std;
using namespace uforia;

bool flag_file = false, flag_write = false, flag_include = false, flag_sort = false;
vector <string> buffer, list;
ofstream write;
string include;

int main(int argc, char * argv[]) {

  // Argument handeling with getopt
  int c;

  while ((c = getopt(argc, argv, "f:o:i:s")) != -1)
    switch (c) {
    case 'f':
      flag_file = true;
      list = from(optarg, true);
      break;
    case 'o':
      flag_write = true;
      write.open(optarg);
      break;
    case 'i':
      flag_include = true;
      include = optarg;
      break;
    case 's':
      flag_sort = true;
      break;
    }

  // If no file is given the program will end
  if (!flag_file) {
    cout << "No file given (-f)" << endl;
    exit(0);
  }

  // The option to filter lines by string
  if (flag_include) {
    for (int i = 0; i < list.size(); ++i) {
      string line = list[i];
      if (uforia::has(include, line)) {
        buffer.push_back(line);
      }
    }
    list = buffer;
    buffer.clear();
  }

  // The option to sort the lines
  if (flag_sort) {
    sort(list.begin(), list.end());
  }

  // The option to write to file
  if (flag_write) {
    for (int i = 0; i < list.size(); ++i) {
      string line = list[i];
      write << line;
    }
    write.close();
  }

  // Print lines
  for (int i = 0; i < list.size(); ++i) {
    string line = list[i];
    cout << line << endl;
  }

  return 0;
}
