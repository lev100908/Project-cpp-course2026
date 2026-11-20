#include "JStrategy.h"

std::array<Config::Position, 4>
JStrategy::getRelativePositions(Config::Rotation rotation) const
{
    switch (rotation)
    {
        case Config::Rotation::Up: return {{{-1, -1}, {-1, 0}, {0, 0}, {1, 0}}};
        case Config::Rotation::Right: return {{{0, -1}, {1, -1}, {0, 0}, {0, 1}}};
        case Config::Rotation::Down: return {{{-1, 0}, {0, 0}, {1, 0}, {1, 1}}};
        case Config::Rotation::Left: return {{{0, -1}, {0, 0}, {-1, 1}, {0, 1}}};
    }
    return {{{0, 0}, {0, 0}, {0, 0}, {0, 0}}};
}

Config::Position JStrategy::getStartCenterPositions() const
{
    return Config::J_START_POS_CENTER;
}
