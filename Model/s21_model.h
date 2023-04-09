#ifndef INC_3D_S21_MODEL_H
#define INC_3D_S21_MODEL_H

#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include "Parser/ObjectParser.h"
#include "Transformation/ObjectTransformation.h"

namespace s21 {
class Model {
 public:
  static Model* ModelInstance();

  Model(const Model&) = delete;
  void operator=(const Model&) = delete;

  void Begin(std::string& path);
  void ZoomModel(double k);
  void MoveModel(std::map<std::string, double>& move_axes);
  void RotationModel(std::map<std::string, double>& rotation_axes);


  // getters
  std::vector<double> GetParserV();
  std::vector<double> GetTransformV();
  std::vector<unsigned int> GetF();
  std::pair<double, double> GetMinMax();
  int GetEdge();

 private:
  static Model* model_;

  Model() {
    parser_ = s21::ObjectParser::ParserInstance();
    transform_ = s21::ObjectTransformation::TransformationInstance();
  }
  ~Model() { delete model_; }

  ObjectParser* parser_;
  ObjectTransformation* transform_;
};
}  // namespace s21

#endif  // INC_3D_S21_MODEL_H
