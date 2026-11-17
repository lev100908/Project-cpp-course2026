
#pragma once

#include <array>
#include "../../config/config.h"

class BaseTetrominoStrategy
{
public:
    virtual ~BaseTetrominoStrategy() = default;

    virtual std::array<Config::Position, 4> getRelativePositions(Config::Rotation rotation) const = 0;

    virtual Config::Position getStartCenterPositions() const = 0;
};


