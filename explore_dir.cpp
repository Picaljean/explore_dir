#include "explore_dir.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstring>

explore_dir::explore_dir(string dirname):number_files(0){
  dir = opendir(dirname.c_str());
  if(dir!=0){
    struct dirent * tmp = NULL;
     while((tmp = readdir(dir)) != NULL){
       if(strcmp(tmp->d_name, ".") != 0 && strcmp(tmp->d_name, "..") != 0){
	  number_files++;
	  files.push_back(string(tmp->d_name));
       }
     }
     sort(files.begin(),files.end(),[](const string & s1,const string & s2){
	 return s1 < s2;
       });
  }else{
    cerr<<"Cannot load directory"<<endl;
  }
}

void explore_dir::seek_at_pos(long pos){
  seekdir(dir, pos);
}

void explore_dir::back_begening_dir(){
  rewinddir(dir);
}

long explore_dir::tellpos(){telldir(dir);}


int explore_dir::getNumberfiles(){return number_files;}

void explore_dir::display(ostream & os)const{
  copy(files.begin(), files.end(), ostream_iterator<string>(os, "\n"));
}

bool explore_dir::is_in_dir(string file){
  auto it = find(files.begin(),files.end(),file);
  if(it!=files.end()){
    return true;
  }else{
    return false;
  }
}

explore_dir::~explore_dir(){
  closedir(dir);
}

ostream & operator <<(ostream & os,explore_dir & d){
  d.display(os);
}

vector<string> explore_dir::getFiles(){return files;}
