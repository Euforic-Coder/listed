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

	if(flag_file && read.good()){
		if(flag_include){
			for(int i = 0; i < list.size(); ++i){
				string line = list[i];
				if(has(include, line)){
					buffer.push_back(line);
				}
			}
			list = buffer;
			buffer.clear();
		}

		if(flag_sort()){
			sort(list.begin(), list.end());
		}

		if(flag_write){
			for(int i = 0; i < list.size(); ++i){
				string line = list[i];
				write << line;
			}
			write.close();
		}

		for(int i = 0; i < list.size(); ++i){
			string line = list[i];
			cout << line << endl;
		}

		read.close();

	}else{
		cout << "No file given (-f)" << endl;
		exit(0);
	}

	return 0;
}
