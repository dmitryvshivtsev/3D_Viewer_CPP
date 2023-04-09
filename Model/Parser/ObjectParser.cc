#include "ObjectParser.h"

namespace s21 {

ObjectParser *ObjectParser::parser_ = nullptr;

ObjectParser *ObjectParser::ParserInstance() {
  if (!parser_) parser_ = new ObjectParser();
  return parser_;
}

void ObjectParser::MainParser(std::string path) {
  if (!v_array_.empty()) v_array_.clear();
  if (!f_array_.empty()) f_array_.clear();
  std::ifstream in(path);
  std::string line;
  if (!in) {
    throw std::invalid_argument("Can't open file");
  }
  while (getline(in, line)) {
    if (line[0] == 'v' && line[1] == ' ')
      this->ParsingV(line);
    else if (line[0] == 'f' && line[1] == ' ')
      this->ParsingF(line);
  }
  FindMinAndMax(v_array_);
  in.close();
}

void ObjectParser::ParsingV(std::string &line) {
  std::string nums = "-1234567890.eE";
  for (std::string::size_type i = 2; i < line.length(); ++i) {
    if (nums.find(line[i]) != std::string::npos) {
      this->v_array_.push_back(std::stod(line.c_str() + i));
      while (nums.find(line[i]) != std::string::npos) {
        i++;
      }
    }
  }
}

void ObjectParser::ParsingF(std::string &line) {
  std::string nums = "1234567890";
  unsigned int stored = 0;
  for (std::size_t i = 2; i < line.length(); i++) {
    if (line[i] == ' ') ++i;
    /* if "i == 2" it means that "i" is first number in string
       and we should duplicate this digit into end of string */
    if (i == 2 && isdigit(line[i])) {
      stored = std::stoi(line.c_str() + i) - 1;
      this->f_array_.push_back(stored);
    }
    if (nums.find(line[i]) != std::string::npos && line[i - 1] == ' ' &&
        i != 2) {
      unsigned int current = std::stoi(line.c_str() + i) - 1;
      for (auto j = 0; j < 2; j++) f_array_.push_back(current);
    }
  }
  this->f_array_.push_back(stored);
}

void ObjectParser::FindMinAndMax(std::vector<double> vertex_array) {
  this->min_max_.first = *min_element(vertex_array.begin(), vertex_array.end());
  this->min_max_.second =
      *max_element(vertex_array.begin(), vertex_array.end());
}

int ObjectParser::EdgeCount() {
  std::set<std::pair<int, int>> edges;
  for (size_t i = 0; i < f_array_.size(); i += 2) {
    int par1 = f_array_[i] - 1;
    int par2 =
        (i == f_array_.size() - 1) ? f_array_[0] - 1 : f_array_[i + 1] - 1;
    edges.insert(EdgePair(par1, par2));
  }
  return edges.size();
}

std::pair<int, int> ObjectParser::EdgePair(int a, int b) {
  auto max = std::max(a, b);
  auto min = std::min(a, b);
  return std::pair<int, int>{min, max};
}

std::vector<double> ObjectParser::GetV() { return v_array_; }

std::vector<unsigned int> ObjectParser::GetF() { return f_array_; }

std::pair<double, double> ObjectParser::GetMinMax() { return min_max_; }

}  // namespace s21
