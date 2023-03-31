#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool flag_file = false, flag_write = false, flag_include = false, flag_sort = false;
vector<string> buffer, list;
ifstream read;
ofstream write;
string include;

int main(int argc, char * argv[]){

	int c;

  while ((c = getopt (argc, argv, "f:o:i:s")) != -1)
    switch (c)
      {
      case 'f':
        flag_read = true;
	read.open(optarg);
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

	if(flag_file){
	

	}else{
		cout << "No file given (-f)" << endl;
		exit(0);
	}
	return 0;
}
