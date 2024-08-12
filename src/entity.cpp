#include "entity.h"

Entity::Entity(const size_t id, EntityTag tag) : m_id(id), m_tag(tag)
{
}

EntityTag Entity::tag() const
{
  return m_tag;
}

size_t Entity::id() const
{
  return m_id;
}
