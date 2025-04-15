#ifndef CHARACTER_H
#define CHARACTER_H

#include "BaseCharacter.h"
#include "raylib.h"

class Character : public BaseCharacter
{
public:
    Character(int winWidth, int winHeight);
    virtual void tick(float deltaTime) override;
    virtual Vector2 getScreenPosition() override;
    Rectangle getWeaponCollisionRectangle() { return weaponCollisionRectangle; }
    float getHealth() const { return health; }
    void takeDamage(float damage);

private:
    int windowWidth{};
    int windowHeight{};
    Texture2D weapon{LoadTexture("assets/characters/weapon_sword.png")};
    Rectangle weaponCollisionRectangle{};
    float health{100.f};
};

#endif