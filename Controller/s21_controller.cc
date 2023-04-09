#include "s21_controller.h"

namespace s21 {
Controller *s21::Controller::controller_ = nullptr;

Controller *Controller::ControllerInstance() {
  if (!controller_) controller_ = new Controller();
  return controller_;
}

void Controller::CallParser(std::string &path) { model_->Begin(path); }

void Controller::MoveObject(std::map<std::string, double> &move_axes) {
  model_->MoveModel(move_axes);
}

void Controller::RotateObject(std::map<std::string, double> &rotation_axes) {
  model_->RotationModel(rotation_axes);
}

void Controller::ZoomObject(double k) { model_->ZoomModel(k); }

std::vector<double> Controller::GetParserV() { return model_->GetParserV(); }
std::vector<double> Controller::GetTransformV() {
  return model_->GetTransformV();
}
std::vector<unsigned int> Controller::GetF() { return model_->GetF(); }
std::pair<double, double> Controller::GetMinMax() {
  return model_->GetMinMax();
}
int Controller::GetEdge() { return model_->GetEdge(); }

} // namespace s21
