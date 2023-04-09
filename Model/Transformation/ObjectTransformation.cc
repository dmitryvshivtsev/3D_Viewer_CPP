#include "ObjectTransformation.h"

namespace s21 {

ObjectTransformation *ObjectTransformation::transformation_ = nullptr;

ObjectTransformation *ObjectTransformation::TransformationInstance() {
  if (!transformation_) transformation_ = new ObjectTransformation();
  return transformation_;
}

void ObjectTransformation::Zoom(double k) {
  for (double &i : v_array_) {
    i *= k;
  }
}

void ObjectTransformation::Move(std::map<std::string, double> &move_axes) {
  this->MoveX(move_axes["x"]);
  this->MoveY(move_axes["y"]);
  this->MoveZ(move_axes["z"]);
}

void ObjectTransformation::MoveX(double a) {
  for (unsigned int i = 0; i < this->v_array_.size(); i += 3)
    this->v_array_[i] += a;
}

void ObjectTransformation::MoveY(double a) {
  for (unsigned int i = 1; i < this->v_array_.size(); i += 3)
    this->v_array_[i] += a;
}

void ObjectTransformation::MoveZ(double a) {
  for (unsigned int i = 2; i < this->v_array_.size(); i += 3)
    this->v_array_[i] += a;
}

void ObjectTransformation::Rotation(
    std::map<std::string, double> &rotation_axes) {
  this->RotationByX(rotation_axes["x"]);
  this->RotationByY(rotation_axes["y"]);
  this->RotationByZ(rotation_axes["z"]);
}

void ObjectTransformation::RotationByX(double angle) {
  for (unsigned int i = 0; i < this->v_array_.size(); i++) {
    i++;
    double temp_y = this->v_array_[i];
    i++;
    double temp_z = this->v_array_[i];
    this->v_array_[i - 1] = cos(angle) * temp_y + sin(angle) * temp_z;
    this->v_array_[i] = -1 * sin(angle) * temp_y + cos(angle) * temp_z;
  }
}

void ObjectTransformation::RotationByY(double angle) {
  for (unsigned int i = 0; i < this->v_array_.size(); i++) {
    double temp_x = this->v_array_[i];
    i += 2;
    double temp_z = this->v_array_[i];
    this->v_array_[i - 2] = cos(angle) * temp_x + sin(angle) * temp_z;
    this->v_array_[i] = sin(angle) * temp_x * -1 + cos(angle) * temp_z;
  }
}

void ObjectTransformation::RotationByZ(double angle) {
  for (unsigned int i = 0; i < this->v_array_.size(); i += 2) {
    double temp_x = this->v_array_[i];
    i++;
    double temp_y = this->v_array_[i];
    this->v_array_[i - 1] = cos(angle) * temp_x + sin(angle) * temp_y;
    this->v_array_[i] = sin(angle) * temp_x * -1 + cos(angle) * temp_y;
  }
}

std::vector<double> ObjectTransformation::GetV() { return v_array_; }

void ObjectTransformation::setV(std::vector<double> v_array) {
  v_array_ = v_array;
}

}  // namespace s21
