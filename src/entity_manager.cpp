#include "entity_manager.h"

EntityManager::EntityManager()
{
}

void EntityManager::update()
{
  for (auto e : m_entities_to_add)
  {
    m_entities.push_back(e);
  }

  m_entities_to_add.clear();
}

std::shared_ptr<Entity> EntityManager::add_entity(EntityTag tag)
{
  auto entity = std::shared_ptr<Entity>(new Entity(m_total_entities++, tag));
  m_entities_to_add.push_back(entity);
  return entity;
}

const EntityVec &EntityManager::get_entities()
{
  return m_entities;
}
