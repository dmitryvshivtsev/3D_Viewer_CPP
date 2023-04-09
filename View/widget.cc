#include "widget.h"

Widget::Widget(QWidget* parent) : QOpenGLWidget{parent} {
  controller = new s21::Controller();
}

void Widget::initializeGL() { glEnable(GL_DEPTH_TEST); }

Widget::~Widget() { delete controller; }

void Widget::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void Widget::Start(std::string filename) {
  controller->CallParser(filename);
  this->f_array_ = this->controller->GetF();
  this->v_array_ = this->controller->GetParserV();
  update();
}

void Widget::ZoomWidget(double value) {
  controller->ZoomObject(value);
  this->v_array_ = controller->GetTransformV();
  update();
}

void Widget::MoveObjectXYZ(double val_x, double val_y, double val_z) {
  std::map<std::string, double> move_axes = {
      {"x", val_x}, {"y", val_y}, {"z", val_z}};
  controller->MoveObject(move_axes);
  this->v_array_ = controller->GetTransformV();
  update();
}

void Widget::RotateWidget(double angle_x, double angle_y, double angle_z) {
  std::map<std::string, double> rotate_axes = {
      {"x", angle_x}, {"y", angle_y}, {"z", angle_z}};
  controller->RotateObject(rotate_axes);
  this->v_array_ = controller->GetTransformV();
  update();
}

void Widget::paintGL() {
  glClearColor(back_red, back_green, back_blue, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  SetProjection();
  SetLineType();

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glRotatef(xRot, 1, 0, 0);
  glRotatef(yRot, 0, 1, 0);
  glRotatef(zRot, 0, 0, 1);

  SetVertexType();
  DrawObj();

  glDisable(GL_POINT_SMOOTH);
  glDisable(GL_LINE_STIPPLE);
}

void Widget::DrawObj() {
  glVertexPointer(3, GL_DOUBLE, 0, this->v_array_.data());
  glEnableClientState(GL_VERTEX_ARRAY);
  if (v_type) {
    glColor3d(ver_red, ver_green, ver_blue);
    glDrawArrays(GL_POINTS, 0, this->v_array_.size() / 3);
  }
  glColor3d(line_red, line_green, line_blue);
  glDrawElements(GL_LINES, this->f_array_.size(), GL_UNSIGNED_INT,
                 this->f_array_.data());
  glDisableClientState(GL_VERTEX_ARRAY);
}

void Widget::SetVertexType() {
  if (v_type) {
    glPointSize(ver_size);
    if (v_type == 2) {
      glEnable(GL_POINT_SMOOTH);
    }
  } else {
    glPointSize(0);
  }
}

void Widget::SetProjection() {
  double min = this->controller->GetMinMax().first;
  double max = this->controller->GetMinMax().second;
  if (projection)
    glFrustum(min, max, min, max, 100 * min, 100 * max);
  else
    glOrtho(min, max, min, max, 100 * min, 100 * max);
}

void Widget::SetLineType() {
  glLineWidth(line_width);
  if (line) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00F0);
  }
}

void Widget::mousePressEvent(QMouseEvent* mo) { mPos = mo->pos(); }

void Widget::mouseMoveEvent(QMouseEvent* mo) {
  xRot += 1 / M_PI * (mo->pos().y() - mPos.y());
  yRot += 1 / M_PI * (mo->pos().x() - mPos.x());
  update();
}

void Widget::wheelEvent(QWheelEvent* event) {
  if (event->angleDelta().y() > 0) {
    ZoomWidget(1.1);
  } else {
    ZoomWidget(0.9);
  }
}

std::vector<unsigned int> Widget::GetFacets() { return this->f_array_; }

std::vector<double> Widget::GetVectors() { return this->v_array_; }
