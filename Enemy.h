#include "BaseCharacter.h"
#include "Character.h"
#include "raylib.h"

class Enemy : public BaseCharacter
{
public:
    Enemy(Vector2 position, Texture2D idleTexture, Texture2D runTexture);
    void setTarget(Character *character) { target = character; }
    virtual void tick(float deltaTime) override;

private:
    Character *target{};
};