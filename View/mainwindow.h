#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include <cstdlib>
#include <iostream>

#include "qgifimage.h"
#include "widget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:

  // Functions for menu buttons
  void connect_buttons();
  void Delay(int ms);
  void EditPath();
  void ZoomButton();
  void MoveButton();
  void RotateButton();
  void LineColorEdit();
  void VertexColorEdit();
  void BackgroundColorEdit();

  // Settings of app
  void SaveSettings();
  void SetSettings();

  // Save image
  void SaveImageButton();
  void GifButton();
  void GifCreate();

  // ComboBox fields
  void on_comboBox_lineType_activated(int index);
  void on_comboBox_projection_activated(int index);
  void on_comboBox_V_type_activated(int index);

  // SpinBox fields
  void on_doubleSpinBox_line_width_valueChanged(double arg1);
  void on_doubleSpinBox_v_size_valueChanged(double arg1);

 private:
  Ui::MainWindow *ui;
  QTimer *timer_;
  QGifImage *gif_;
  QImage *image_;
  QString gifPath_;
  int time_;
  int time_flag_ = 0;
  int path_flag_ = 0;
};

#endif  // MAINWINDOW_H
