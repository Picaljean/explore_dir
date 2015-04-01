#ifndef EXPLORE_DIR
#define EXPLORE_DIR
#include "dirent.h"
#include "file_tools.hpp"
#include <string>
#include <vector>

#ifndef WIN32
    #include <sys/types.h>
#endif

using namespace std;

class explore_dir : public file_tools{
private:
  vector<string> files;
  DIR * dir;
  int number_files;
public:
  explore_dir(string);
  void display(ostream &)const;
  bool is_in_dir(string);
  vector<string> getFiles();
  void back_begening_dir();
  int getNumberfiles();
  void seek_at_pos(long);
  long tellpos();
  ~explore_dir();
  friend ostream & operator<<(ostream &,explore_dir &);
};

#endif
