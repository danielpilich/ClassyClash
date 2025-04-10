#include "BaseCharacter.h"
#include "raylib.h"

class Enemy : public BaseCharacter
{
public:
    Enemy(Vector2 position, Texture2D idleTexture, Texture2D runTexture);
};