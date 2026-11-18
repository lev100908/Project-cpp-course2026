#pragma once

#include "BaseTetraminoStrategy.h"

class IStrategy : public BaseTetrominoStrategy
{
public:
    std::array<Config::Position, 4> getRelativePositions(Config::Rotation rotation) const override;

    Config::Position getStartCenterPositions() const override;
};
