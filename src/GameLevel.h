#pragma once
#include <vector>
#include "sald.h"
#include "GameObject.h"

class GameLevel
{
public:
    GameLevel();
    ~GameLevel();
    // level state
    std::vector<GameObject> m_Bricks;

    // loads level from file
    void Load(const char *file, unsigned int levelWidth, unsigned int levelHeight);
    // render level
    void Draw(Sald::SpriteRenderer *renderer);
    // check if the level is completed (all non-solid tiles are destroyed)
    bool IsCompleted();
    // restores every destroyed brick
    void Reset();
private:
    // initialize level from tile data
    void Initialize(const std::vector<std::vector<unsigned int>> &tileData,
              unsigned int levelWidth, unsigned int levelHeight);
};