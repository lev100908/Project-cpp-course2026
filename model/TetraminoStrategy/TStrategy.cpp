#include "TStrategy.h"

std::array<Config::Position, 4>
TStrategy::getRelativePositions(Config::Rotation rotation) const
{
    switch (rotation)
    {
        case Config::Rotation::Up: return {{{-1, 0}, {0, 0}, {1, 0}, {0, -1}}};
        case Config::Rotation::Right: return {{{0, -1}, {0, 0}, {0, 1}, {1, 0}}};
        case Config::Rotation::Down: return {{{-1, 0}, {0, 0}, {1, 0}, {0, 1}}};
        case Config::Rotation::Left: return {{{0, -1}, {0, 0}, {0, 1}, {-1, 0}}};
    }
    return {{{0, 0}, {0, 0}, {0, 0}, {0, 0}}};
}

Config::Position TStrategy::getStartCenterPositions() const
{
    return Config::T_START_POS_CENTER;
}
