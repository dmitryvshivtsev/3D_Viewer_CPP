#ifndef WIDGET_H
#define WIDGET_H

#define GL_SILENCE_DEPRECATION

#include <QtOpenGLWidgets/qopenglwidget.h>

#include <QColorDialog>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QTimer>
#include <QWidget>
#include <QtOpenGL>

#include "../Controller/s21_controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QOpenGLWidget {
  Q_OBJECT

 public:
  Widget(QWidget* parent = nullptr);
  ~Widget();
  s21::Controller* controller;
  std::vector<unsigned int> GetFacets();
  std::vector<double> GetVectors();

  // Statement flags
  int line = 0, projection = 0;
  double ver_size, line_width, v_type;
  bool is_object_open = false;

  // Color params
  double back_red = 1, back_green = 1, back_blue = 1;
  double ver_red = 0, ver_green = 0, ver_blue = 0;
  double line_red = 0, line_green = 0, line_blue = 0;

  // PaintGL functions
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void SetLineType();
  void SetProjection();
  void SetVertexType();
  void DrawObj();

  // Mouse move functions
  void mousePressEvent(QMouseEvent* mo) override;
  void mouseMoveEvent(QMouseEvent* mo) override;
  void wheelEvent(QWheelEvent* event) override;

  // Change object state
  void ZoomWidget(double value);
  void Start(std::string filename);
  void MoveObjectXYZ(double val_x, double val_y, double val_z);
  void RotateWidget(double angle_x, double angle_y, double angle_z);

 private:
  std::vector<double> v_array_ = {};
  std::vector<unsigned int> f_array_ = {};
  float xRot, yRot, zRot;
  QPoint mPos;
};

#endif  // WIDGET_H
