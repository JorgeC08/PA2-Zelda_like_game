#include "Entity.h"
#include "StaticEntity.h"

Entity::Entity(int ox, int oy, int ow, int oh, string overworldPath) {
    this->ox = ox;
    this->oy = oy;
    this->oh = oh;
    this->ow = ow;
    
    //this->health = health;
    //this->baseDamage = baseDamage;

    // fightingSprite.load(fightingPath);
    overworldSprite.load(overworldPath);
}

void Entity::renderOverworld() {
    overworldSprite.draw(ox, oy, ow, oh);
}

void StaticEntity::renderOverworld() {
    overworldSprite.draw(renderX, renderY, ow, oh);
}

// void Entity::renderFighting() {
//     fightingSprite.draw(fx, fy, fw, fh);
// }

bool Entity::collides(Entity* entity){
    return this->getBounds().intersects(entity->getBounds());
}

ofRectangle Entity::getBounds(){
    return ofRectangle(ox, oy, ow, oh);
}

ofRectangle Entity::getBounds(int ox, int oy){
    return ofRectangle(ox, oy, ow, oh);
}

void StaticEntity::tickOverworld(){

}

StaticEntity::StaticEntity(int ox, int oy, int ow, int oh, string overworldPath) : Entity(ox, oy, ow, oh, overworldPath){
}