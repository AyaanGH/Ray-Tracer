#include "Entity_list.h"


Entity_list::Entity_list(std::shared_ptr<Entity> object)
{
    add(object);
}

void Entity_list::add(std::shared_ptr<Entity> object) {

    objects.push_back(object);

}

void Entity_list::clear() {
    objects.clear();

}

bool Entity_list::intersect(const Ray &r, double t_min, double t_max, hit_record &record) const {


    hit_record myRecord;
    bool hit_anything = false;
    auto closest_so_far = t_max;

    for (const auto& object : objects) {
        if (object->intersect(r, t_min, closest_so_far, myRecord)) {
            hit_anything = true;
            closest_so_far = myRecord.t;
            record = myRecord;
        }
    }

    return hit_anything;


}
