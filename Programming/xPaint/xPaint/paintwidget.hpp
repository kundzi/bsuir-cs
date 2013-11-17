#pragma once

#include "Tool.hpp"
#include "QxPainter.hpp"

#include "gem_lib/Painter/Scene.hpp"

#include <QWidget>
#include <QMouseEvent>

class PaintWidget : public QWidget
{
  Q_OBJECT

public:
  explicit PaintWidget(QWidget *parent = 0);
  void SetTool(Tool * tool);
  painter::Scene & GetScene() { return _scene; }

signals:

public slots:
  void OnMousePress(QMouseEvent * event);
  void OnMouseRelease(QMouseEvent * event);
  void OnMouseMove(QMouseEvent * event);

protected:
  void paintEvent(QPaintEvent *event);

  void mouseMoveEvent(QMouseEvent *);
  void mousePressEvent(QMouseEvent *);
  void mouseReleaseEvent(QMouseEvent *);

private:
  QPoint _startPoint;
  QPoint _endPoint;

  QxPainter _xPainter;
  QPainter _painter;
  painter::Scene _scene;

  Tool * _tool;
  bool _isToolActive;
};
