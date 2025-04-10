#include "BaseCharacter.h"
#include "raylib.h"

class Character : public BaseCharacter
{
public:
    Character(int windowWidth, int windowHeight);
    void tick(float deltaTime);

private:
    float textureDirection{1.f};
};