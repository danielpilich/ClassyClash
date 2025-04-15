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

private:
    int windowWidth{};
    int windowHeight{};
    Texture2D weapon{LoadTexture("assets/characters/weapon_sword.png")};
    Rectangle weaponCollisionRectangle{};
};

#endif