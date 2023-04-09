#ifndef INC_3D_OBJECTTRANSFORMATION_H
#define INC_3D_OBJECTTRANSFORMATION_H

#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace s21 {
class ObjectTransformation {
 public:
  static ObjectTransformation* TransformationInstance();

  void setV(std::vector<double> v_array);
  std::vector<double> GetV();

  void Zoom(double k);
  void Move(std::map<std::string, double>& move_axes);
  void Rotation(std::map<std::string, double>& rotation_axes);

 private:
  static ObjectTransformation* transformation_;

  ObjectTransformation() { ; };
  ~ObjectTransformation() { delete transformation_; }

  std::vector<double> v_array_;
  void MoveX(double a);
  void MoveY(double a);
  void MoveZ(double a);
  void RotationByX(double angle);
  void RotationByY(double angle);
  void RotationByZ(double angle);
};
}  // namespace s21

#endif  // INC_3D_OBJECTTRANSFORMATION_H
