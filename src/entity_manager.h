#pragma once

#include "entity.h"
#include <memory>
#include <vector>

typedef std::vector<std::shared_ptr<Entity>> EntityVec;

class EntityManager
{
private:
  EntityVec m_entities;
  EntityVec m_entities_to_add;
  size_t    m_total_entities = 0;

public:
  EntityManager();
  void                    update();
  std::shared_ptr<Entity> add_entity(EntityTag tag);
  const EntityVec        &get_entities();
};
