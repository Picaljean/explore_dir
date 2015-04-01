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

void explore_dir::write_in_file(string file,string text){
  ofstream ofs(file,ios::app);
  if(ofs.is_open()){
  ofs << text;
  }else{
    cerr<<"Cannot load file"<<endl;
  }
}

void explore_dir::seek_at_pos(long pos){
  seekdir(dir, pos);
}

void explore_dir::back_to_begening(){
  rewinddir(dir);
}

long explore_dir::tellpos(){telldir(dir);}


int explore_dir::getNumberfiles(){return number_files;}

void explore_dir::display(ostream & os)const{
  copy(files.begin(), files.end(), ostream_iterator<string>(os, "\n"));
}

bool explore_dir::isDir(string file){
  if(file.find('.')){
    return false;
  }else{
    return true;
  }
}

bool explore_dir::exists(string file){
  auto it = find(files.begin(),files.end(),file);
  if(it!=files.end()){
    return true;
  }else{
    return false;
  }
}

void explore_dir::read_file(string file){
  ifstream ifs(file,ios::in);
  
}

explore_dir::~explore_dir(){
  closedir(dir);
}

ostream & operator <<(ostream & os,explore_dir & d){
  d.display(os);
}

