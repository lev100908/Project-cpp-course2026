#pragma once 

#include "TetraminoStrategy/BaseTetraminoStrategy.h"
#include "../config/config.h"
#include <array>
#include <memory>

class Tetromino
{
private:
    std::unique_ptr<const BaseTetrominoStrategy> strategy_;

    Config::Position center_;
    Config::Rotation rotation_;

public:
    Tetromino(
        std::unique_ptr<const BaseTetrominoStrategy> strategy
    );

    void setStrategy(std::unique_ptr<const BaseTetrominoStrategy> strategy);

    void move(int dx, int dy);
    void rotate();
    void rotateBack();
    

    std::array<Config::Position, 4> getPositions() const;
};