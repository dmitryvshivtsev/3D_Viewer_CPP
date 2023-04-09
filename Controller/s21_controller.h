#ifndef INC_3D_S21_CONTROLLER_H
#define INC_3D_S21_CONTROLLER_H

#include "../Model/s21_model.h"

namespace s21 {
class Controller {
 public:
  static Controller *ControllerInstance();

  Controller() { model_ = s21::Model::ModelInstance(); }
  ~Controller() { delete controller_; }

  void CallParser(std::string &path);
  void MoveObject(std::map<std::string, double> &move_axes);
  void RotateObject(std::map<std::string, double> &rotation_axes);
  void ZoomObject(double k);

  std::vector<double> GetParserV();
  std::vector<double> GetTransformV();
  std::vector<unsigned int> GetF();
  std::pair<double, double> GetMinMax();
  int GetEdge();

 private:
  static Controller *controller_;

  Model *model_;
};
} // namespace s21

#endif  // INC_3D_S21_CONTROLLER_H
