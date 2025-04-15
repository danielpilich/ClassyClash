#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight) : windowWidth(winWidth), windowHeight(winHeight)
{
    idle = LoadTexture("assets/characters/hero_idle.png");
    run = LoadTexture("assets/characters/hero_run.png");
    texture = idle;

    width = texture.width / maxFrames;
    height = texture.height;
}

Vector2 Character::getScreenPosition()
{
    return Vector2{
        static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(windowHeight) / 2.0f - scale * (0.5f * height)};
}

void Character::tick(float deltaTime)
{
    if (!getAlive())
        return;

    // Update character movement
    if (IsKeyDown(KEY_A))
        velocity.x -= 1.0;
    if (IsKeyDown(KEY_D))
        velocity.x += 1.0;
    if (IsKeyDown(KEY_W))
        velocity.y -= 1.0;
    if (IsKeyDown(KEY_S))
        velocity.y += 1.0;

    BaseCharacter::tick(deltaTime);

    Vector2 origin{};
    Vector2 offset{};
    float rotation{};
    if (textureDirection > 0.f)
    {
        origin = {0.f, weapon.height * scale};
        offset = {38.f, 55.f};
        rotation = 35.f;
        weaponCollisionRectangle = {
            getScreenPosition().x + offset.x,
            getScreenPosition().y + offset.y - weapon.height * scale,
            weapon.width * scale,
            weapon.height * scale};

        rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? 35.f : 0.f;
    }
    else
    {
        origin = {weapon.width * scale, weapon.height * scale};
        offset = {26.f, 55.f};
        weaponCollisionRectangle = {
            getScreenPosition().x + offset.x - weapon.width * scale,
            getScreenPosition().y + offset.y - weapon.height * scale,
            weapon.width * scale,
            weapon.height * scale};

        rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? -35.f : 0.f;
    }

    // Draw the sword
    Rectangle swordSource{0.f, 0.f, static_cast<float>(weapon.width) * textureDirection, static_cast<float>(weapon.height)};
    Rectangle swordDest{getScreenPosition().x + offset.x, getScreenPosition().y + offset.y, weapon.width * scale, weapon.height * scale};
    DrawTexturePro(weapon, swordSource, swordDest, origin, rotation, WHITE);
}

void Character::takeDamage(float damage)
{
    health -= damage;
    if (health <= 0.f)
        setAlive(false);
}