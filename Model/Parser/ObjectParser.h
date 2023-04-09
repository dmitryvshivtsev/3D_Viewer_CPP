#ifndef INC_3D_OBJECTPARSER_H
#define INC_3D_OBJECTPARSER_H

#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

namespace s21 {
class ObjectParser {
 public:
  static ObjectParser* ParserInstance();

  void MainParser(std::string path);

  // getters
  std::vector<double> GetV();
  std::vector<unsigned int> GetF();
  std::pair<double, double> GetMinMax();
  int GetEdge() { return this->EdgeCount(); }

 private:
  static ObjectParser* parser_;

  ObjectParser() { ; }
  ~ObjectParser() { delete parser_; }

  std::vector<double> v_array_;
  std::vector<unsigned int> f_array_;
  std::pair<double, double> min_max_;

  int EdgeCount();
  std::pair<int, int> EdgePair(int a, int b);

  void ParsingV(std::string& line);
  void ParsingF(std::string& line);
  void FindMinAndMax(std::vector<double> vertex_array);
};
}  // namespace s21

#endif  // INC_3D_OBJECTPARSER_H
