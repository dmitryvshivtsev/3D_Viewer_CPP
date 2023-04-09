#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  QPixmap pix(":/img/img/fi.jpeg");
  int w = ui->Image->width();
  int h = ui->Image->height();
  ui->Image->setPixmap(pix.scaled(w, h));

  SetSettings();
  setWindowTitle("3D Viewer");
  setFixedSize(size());

  connect_buttons();
}

MainWindow::~MainWindow() {
  SaveSettings();
  delete ui;
}

void MainWindow::connect_buttons() {
  connect(ui->pushButton_edit, SIGNAL(clicked()), this, SLOT(EditPath()));
  connect(ui->pushButton_start_gif, SIGNAL(clicked()), this, SLOT(GifButton()));
  connect(ui->pushButton_zoom, SIGNAL(clicked()), this, SLOT(ZoomButton()));
  connect(ui->pushButton_move, SIGNAL(clicked()), this, SLOT(MoveButton()));
  connect(ui->pushButton_back_col, SIGNAL(clicked()), this,
          SLOT(BackgroundColorEdit()));
  connect(ui->pushButton_line_col, SIGNAL(clicked()), this,
          SLOT(LineColorEdit()));
  connect(ui->pushButton_ver_col, SIGNAL(clicked()), this,
          SLOT(VertexColorEdit()));
  connect(ui->pushButton_rotate, SIGNAL(clicked()), this, SLOT(RotateButton()));
  connect(ui->pushButton_save_image, SIGNAL(clicked()), this,
          SLOT(SaveImageButton()));
}

void MainWindow::SaveSettings() {
  QSettings mySettings;
  mySettings.setValue("vertex size", ui->doubleSpinBox_v_size->value());
  mySettings.setValue("line width", ui->doubleSpinBox_line_width->value());
  mySettings.setValue("move x", ui->doubleSpinBox_move_x->value());
  mySettings.setValue("move y", ui->doubleSpinBox_move_y->value());
  mySettings.setValue("move z", ui->doubleSpinBox_move_z->value());
  mySettings.setValue("rotate x", ui->doubleSpinBox_rotate_x->value());
  mySettings.setValue("rotate y", ui->doubleSpinBox_rotate_y->value());
  mySettings.setValue("rotate z", ui->doubleSpinBox_rotate_z->value());
  mySettings.setValue("zoom", ui->doubleSpinBox_zoomVal->value());
  mySettings.setValue("line type", ui->widget->line);
  mySettings.setValue("projection", ui->widget->projection);
  mySettings.setValue("vertex type", ui->widget->v_type);
  mySettings.setValue("back red", ui->widget->back_red);
  mySettings.setValue("back green", ui->widget->back_green);
  mySettings.setValue("back blue", ui->widget->back_blue);
  mySettings.setValue("line red", ui->widget->line_red);
  mySettings.setValue("line green", ui->widget->line_green);
  mySettings.setValue("line blue", ui->widget->line_blue);
  mySettings.setValue("ver red", ui->widget->ver_red);
  mySettings.setValue("ver green", ui->widget->ver_green);
  mySettings.setValue("ver blue", ui->widget->ver_blue);
}

void MainWindow::SetSettings() {
  QSettings mySettings;
  ui->doubleSpinBox_move_x->setValue(mySettings.value("move x").toDouble());
  ui->doubleSpinBox_move_y->setValue(mySettings.value("move y").toDouble());
  ui->doubleSpinBox_move_z->setValue(mySettings.value("move z").toDouble());
  ui->doubleSpinBox_rotate_x->setValue(mySettings.value("rotate x").toDouble());
  ui->doubleSpinBox_rotate_y->setValue(mySettings.value("rotate y").toDouble());
  ui->doubleSpinBox_rotate_z->setValue(mySettings.value("rotate z").toDouble());
  ui->doubleSpinBox_zoomVal->setValue(mySettings.value("zoom").toDouble());
  ui->widget->ver_size = mySettings.value("vertex size").toDouble();
  ui->doubleSpinBox_v_size->setValue(ui->widget->ver_size);
  ui->widget->line_width = mySettings.value("line width").toDouble();
  ui->doubleSpinBox_line_width->setValue(ui->widget->line_width);
  ui->widget->line = mySettings.value("line type").toInt();
  ui->comboBox_lineType->setCurrentIndex(ui->widget->line);
  ui->widget->projection = mySettings.value("projection").toInt();
  ui->comboBox_projection->setCurrentIndex(ui->widget->projection);
  ui->widget->v_type = mySettings.value("vertex type").toInt();
  ui->comboBox_V_type->setCurrentIndex(ui->widget->v_type);
  ui->widget->back_red = mySettings.value("back red").toDouble();
  ui->widget->back_green = mySettings.value("back green").toDouble();
  ui->widget->back_blue = mySettings.value("back blue").toDouble();
  ui->widget->line_red = mySettings.value("line red").toDouble();
  ui->widget->line_green = mySettings.value("line green").toDouble();
  ui->widget->line_blue = mySettings.value("line blue").toDouble();
  ui->widget->ver_red = mySettings.value("ver red").toDouble();
  ui->widget->ver_green = mySettings.value("ver green").toDouble();
  ui->widget->ver_blue = mySettings.value("ver blue").toDouble();
}

void MainWindow::EditPath() {
  setlocale(LC_ALL, "C");
  setenv("LC_NUMERIC", "C", 1);
  QString str =
      QFileDialog::getOpenFileName(this, NULL, NULL, "Obj Files (*.obj)");
  ui->label->setText(str);
  std::string filename_str = ui->label->text().toStdString();
  if (filename_str == "") {
    QMessageBox::warning(this, "Warning", "Please, choose a file");
    path_flag_ = 1;
  } else {
    path_flag_ = 0;
    ui->widget->is_object_open = true;
    ui->widget->Start(filename_str);
    QString num_of_v, num_of_f;
    ui->label_number_of_v->setText(
        num_of_v.setNum(ui->widget->controller->GetParserV().size() / 3));
    ui->label_number_of_f->setText(
        num_of_f.setNum(ui->widget->controller->GetEdge()));
  }
}

void MainWindow::GifButton() {
  if (ui->widget->is_object_open) {
    time_ = 0;
    timer_ = new QTimer(this);
    timer_->setInterval(200);
    image_ = new QImage;
    gif_ = new QGifImage(QSize(640, 480));
    connect(timer_, SIGNAL(timeout()), this, SLOT(GifCreate()));
    timer_->start(1000);
  } else {
    QMessageBox::warning(this, "Warning", "No files uploaded");
  }
}

void MainWindow::Delay(int ms) {
  QElapsedTimer et;
  et.start();
  while (true) {
    qApp->processEvents();
    if (et.elapsed() > ms) break;
  }
}

void MainWindow::GifCreate() {
  time_++;
  ui->label_timer->setText(QString::number(time_));
  for (auto i = 0; i < 10; i++) {
    gif_->setDefaultDelay(100);
    ui->widget->RotateWidget(0, 0.10, 0);
    *image_ = ui->widget->grabFramebuffer();
    gif_->addFrame(*image_);
    Delay(100);
  }
  if (time_ == 5) {
    timer_->stop();
    gifPath_ = NULL;
    gifPath_ = QFileDialog::getSaveFileName(this, NULL, NULL, "GIF (*.gif)");
    if (!gifPath_.isNull())
      gif_->save(gifPath_);
    else
      QMessageBox::warning(this, "Warning", "Empty path!");
  }
}

void MainWindow::ZoomButton() {
  double val = ui->doubleSpinBox_zoomVal->value();
  ui->widget->ZoomWidget(val);
}

void MainWindow::SaveImageButton() {
  if (ui->widget->is_object_open) {
    QString s =
        QFileDialog::getSaveFileName(this, "Save as", "Choose a filename",
                                     "BMP(*.bmp);; JPEG(*.jpg *.jpeg)");
    ui->widget->grabFramebuffer().save(s);
  } else {
    QMessageBox::warning(this, "Warning", "No files uploaded");
  }
}

void MainWindow::MoveButton() {
  double x = ui->doubleSpinBox_move_x->value();
  double y = ui->doubleSpinBox_move_y->value();
  double z = ui->doubleSpinBox_move_z->value();
  ui->widget->MoveObjectXYZ(x, y, z);
}

void MainWindow::RotateButton() {
  double x = ui->doubleSpinBox_rotate_x->value();
  double y = ui->doubleSpinBox_rotate_y->value();
  double z = ui->doubleSpinBox_rotate_z->value();
  ui->widget->RotateWidget(x, y, z);
}

void MainWindow::on_comboBox_lineType_activated(int index) {
  ui->widget->line = index;
  ui->widget->update();
}

void MainWindow::on_comboBox_projection_activated(int index) {
  ui->widget->projection = index;
  ui->widget->update();
}

void MainWindow::on_comboBox_V_type_activated(int index) {
  ui->widget->v_type = index;
  ui->widget->update();
}

void MainWindow::BackgroundColorEdit() {
  QColor back_col = QColorDialog::getColor(Qt::white, this, "Choose color");
  ui->widget->back_red = back_col.redF();
  ui->widget->back_green = back_col.greenF();
  ui->widget->back_blue = back_col.blueF();
  ui->widget->update();
}

void MainWindow::LineColorEdit() {
  QColor line_col = QColorDialog::getColor(Qt::white, this, "Choose color");
  ui->widget->line_red = line_col.redF();
  ui->widget->line_green = line_col.greenF();
  ui->widget->line_blue = line_col.blueF();
  ui->widget->update();
}

void MainWindow::VertexColorEdit() {
  QColor ver_col = QColorDialog::getColor(Qt::white, this, "Choose color");
  ui->widget->ver_red = ver_col.redF();
  ui->widget->ver_green = ver_col.greenF();
  ui->widget->ver_blue = ver_col.blueF();
  ui->widget->update();
}

void MainWindow::on_doubleSpinBox_line_width_valueChanged(double arg1) {
  ui->widget->line_width = arg1;
  ui->widget->update();
}

void MainWindow::on_doubleSpinBox_v_size_valueChanged(double arg1) {
  ui->widget->ver_size = arg1;
  ui->widget->update();
}
