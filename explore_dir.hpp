#ifndef EXPLORE_DIR
#define EXPLORE_DIR
#include "dirent.h"
#include <string>
#include <vector>

using namespace std;

class explore_dir{
private:
  vector<string> files;
  DIR * dir;
  int number_files;
public:
  explore_dir(string);
  void write_in_file(string,string);
  void display(ostream &)const;
  bool isDir(string);
  bool exists(string);
  void read_file(string);
  void back_to_begening();
  int getNumberfiles();
  void seek_at_pos(long);
  long tellpos();
  ~explore_dir();
  friend ostream & operator<<(ostream &,explore_dir &);
};

#endif
