#ifndef ENTITY_H
#define ENTITY_H

#define   STAYED         0
#define   MOVING_UP      1
#define   MOVING_DOWN    2
#define   MOVING_LEFT    10
#define   MOVING_RIGHT   20
#define   FIRING         100
#define   HITTED         1000
#define   DESTROYED      2000

class Entity {
public:
    Entity();
    Entity(const Entity& orig);
    virtual ~Entity();
protected:
    int max_health;
    int health;
    int state;
};

#endif /* ENTITY_H */

