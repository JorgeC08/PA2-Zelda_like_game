#include "Entity.h"
#include "StaticEntity.h"

void StaticEntity::renderOverworld() {
    overworldSprite.draw(renderX, renderY, ow, oh);
}
void StaticEntity::tickOverworld(){
}
StaticEntity::StaticEntity(int ox, int oy, int ow, int oh, string overworldPath) : Entity(ox, oy, ow, oh, overworldPath){
}