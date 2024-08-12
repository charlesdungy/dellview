#pragma once

#include "components.h"
#include <memory>

enum EntityTag
{
  CIRCLE,
};

class Entity
{
private:
  friend class EntityManager;

  size_t    m_id = 0;
  EntityTag m_tag;

  Entity(const size_t id, EntityTag tag);

public:
  std::shared_ptr<CTransform> cTransform;
  std::shared_ptr<CShape>     cShape;
  std::shared_ptr<CCollision> cCollision;

  EntityTag tag() const;
  size_t    id() const;
};
