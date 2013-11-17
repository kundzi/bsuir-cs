#pragma once

#include <QPainter>
#include <QMainWindow>

#include "paintwidget.hpp"

namespace Ui {
class xPaintWindow;
}

class xPaintWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit xPaintWindow(QWidget *parent = 0);
  ~xPaintWindow();

private slots:
  void on_actionRect_triggered();

  void on_actionEllipse_triggered();

  void on_actionRemove_Last_triggered();

  void on_actionClear_All_triggered();

  void on_actionLine_triggered();

  void on_actionRed_triggered();

  void on_actionGreen_triggered();

  void on_actionBlue_triggered();

  void on_actionIncWidth_triggered();

  void on_actionDecWidth_triggered();

  void on_actionPolyline_triggered();

private:
  Ui::xPaintWindow *ui;
  PaintWidget * _paintWidget;
};
