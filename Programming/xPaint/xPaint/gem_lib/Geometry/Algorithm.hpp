#pragma once

#include <iostream>
#include "Geometry.hpp"

using geometry::Point2D;
using geometry::Rect;
using geometry::Line2D;
using geometry::Ellipse;
using geometry::Polyline;

namespace algo
{

template <typename T>
Rect<T> BoundingRect(Point2D<T> const & point)
{
  return Rect<T>(point, point); /// @todo this is incorrect
}

template <typename T>
Rect<T> BoundingRect(Line2D<T> const & line)
{
  return Rect<T>(line._end, line._start);
}

template <typename T>
Rect<T> BoundingRect(Rect<T> const & rect)
{
  return rect;
}

template <typename T>
Rect<T> BoundingRect(Ellipse<T> const & e)
{
  Point2D<T> tl(e._center._x - e.radiusX(), e._center._y - e.radiusY());
  Point2D<T> br(e._center._x + e.radiusX(), e._center._y + e.radiusY());
  return Rect<T>(tl, br);
}

template <typename T>
Rect<T> BoundingRect(Polyline<T> const & poly)
{

  Rect<T> r(poly._points[0], poly._points[1]);

  for (size_t i = 2; i < poly._points.size(); ++i)
    r.Inflate(poly._points[i]);

  return r;
}

template <typename T>
bool Intersects(T x, T y, Rect<T> const & r)
{
  return r.Contains(x, y);
}

template <typename T>
bool Intersects(T x, T y, Line2D<T> const & l)
{
  return BoundingRect(l).Contains(x, y);
}

template <typename T>
bool Intersects(T x, T y, Ellipse<T> const & ellipse)
{
  return BoundingRect(ellipse).Contains(x, y);
}

template <typename T>
bool Intersects(T x, T y, Polyline<T> const & poly)
{
  return poly._points.size() < 2 ? false :BoundingRect(poly).Contains(x, y);
}

}
