//
//  properties.h
//  YCSB-C
//
//  Created by Jinglei Ren on 12/9/14.
//  Copyright (c) 2014 Jinglei Ren <jinglei@ren.systems>.
//

#ifndef YCSB_C_PROPERTIES_H_
#define YCSB_C_PROPERTIES_H_

#include <string>
#include <map>
#include <fstream>
#include <cassert>
#include "utils.h"

namespace utils {

class Properties {
 public:
  std::string GetProperty(const std::string &key,
      const std::string &default_value = std::string()) const;
  const std::string &operator[](const std::string &key) const;
  const std::map<std::string, std::string> &properties() const;
  const std::vector<std::pair<int,std::pair<std::string, std::string>>> &KeyRanges() const;
  void SetProperty(const std::string &key, const std::string &value);
  void SetKeyRanges(const std::vector<std::pair<int,std::pair<std::string, std::string>>>& krs);
  bool Load(std::ifstream &input);
 private:
  std::map<std::string, std::string> properties_;
  std::vector<std::pair<int,std::pair<std::string, std::string>>> key_ranges_;
};

inline std::string Properties::GetProperty(const std::string &key,
    const std::string &default_value) const {
  std::map<std::string, std::string>::const_iterator it = properties_.find(key);
  if (properties_.end() == it) {
    return default_value;
  } else return it->second;
}

inline const std::string &Properties::operator[](const std::string &key) const {
  return properties_.at(key);
}
inline const std::vector<std::pair<int,std::pair<std::string, std::string>>> &Properties::KeyRanges() const {
  return key_ranges_;
}

inline const std::map<std::string, std::string> &Properties::properties() const {
  return properties_;
}

inline void Properties::SetProperty(const std::string &key,
                                    const std::string &value) {
  properties_[key] = value;
}

inline void Properties::SetKeyRanges
(const std::vector<std::pair<int,std::pair<std::string, std::string>>>& krs){
  int krs_num=krs.size();
  for(int i=0;i<krs_num;i++){
	  key_ranges_.push_back(krs[i]);
  }
}

inline bool Properties::Load(std::ifstream &input) {
  if (!input.is_open()) throw utils::Exception("File not open!");

  while (!input.eof() && !input.bad()) {
    std::string line;
    std::getline(input, line);
    if (line[0] == '#') continue;
    size_t pos = line.find_first_of('=');
    if (pos == std::string::npos) continue;
    SetProperty(Trim(line.substr(0, pos)), Trim(line.substr(pos + 1)));
  }
  return true;
}

} // utils

#endif // YCSB_C_PROPERTIES_H_
