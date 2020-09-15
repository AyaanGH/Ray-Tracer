#ifndef RAY_TRACER_ENTITY_LIST_H
#define RAY_TRACER_ENTITY_LIST_H



#include "Entity.h"
#include <vector>
#include <memory>





class Entity_list: public Entity {
public:

    std::vector<std::shared_ptr<Entity>> objects;

    Entity_list(std::shared_ptr<Entity> object);

    //Methods

    void add(std::shared_ptr<Entity> object);

    void clear();

    bool intersect(const Ray &r, double t_min, double t_max, hit_record &record) const override;


};


#endif
