#pragma once

#include "vec2.h"

struct CTransform
{
  Vec2  pos   = {0.0, 0.0};
  Vec2  vel   = {0.0, 0.0};
  float angle = 0;

  CTransform(const Vec2 &p, const Vec2 &v, float a) : pos(p), vel(v), angle(a)
  {
  }
};
