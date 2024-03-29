#pragma once

#include "Painter.hpp"
#include "Paint.hpp"
#include "../Geometry/Transform.hpp"

typedef geometry::Transform<float> TransformF;

namespace painter {

class Drawable {

public:
  virtual void Draw(Painter * painter) = 0;
  virtual RectF BoundingRect() const = 0;

  virtual bool Contains(PointF const & p)          { return BoundingRect().Contains(p); }
  virtual void Transform(TransformF const & /*t*/) { /* do nothing*/ }

  virtual ~Drawable() {}

  void    SetPaint(Paint const & paint) { _paint = paint; }
  Paint & GetPaint()                    { return _paint; }
  Paint const & GetPaint() const        { return _paint; }

protected:
  Paint _paint;
};

}
