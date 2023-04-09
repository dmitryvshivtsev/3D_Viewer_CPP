#include "s21_model.h"

#include <map>
#include <utility>

namespace s21 {
Model *s21::Model::model_ = nullptr;

Model *Model::ModelInstance() {
  if (!model_) model_ = new Model();
  return model_;
}

void Model::Begin(std::string &path) {
  parser_->MainParser(path);
  transform_->setV(parser_->GetV());
}

void Model::ZoomModel(double k) {
  transform_->Zoom(k);
}

void Model::MoveModel(std::map<std::string, double> &move_axes) {
  transform_->Move(move_axes);
}

void Model::RotationModel(std::map<std::string, double> &rotation_axes) {
  transform_->Rotation(rotation_axes);
}

std::pair<double, double> Model::GetMinMax() { return parser_->GetMinMax(); }

std::vector<unsigned int> Model::GetF() { return parser_->GetF(); }

std::vector<double> Model::GetParserV() { return parser_->GetV(); }

std::vector<double> Model::GetTransformV() { return transform_->GetV(); }

int Model::GetEdge() { return parser_->GetEdge(); }

}  // namespace s21
