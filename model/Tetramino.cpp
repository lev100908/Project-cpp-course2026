#include "Tetramino.h"

Tetromino::Tetromino(std::unique_ptr<const BaseTetrominoStrategy> strategy) : strategy_(std::move(strategy)), center_(strategy_->getStartCenterPositions()), rotation_(Config::Rotation::Up) {}

void Tetromino::setStrategy(std::unique_ptr<const BaseTetrominoStrategy> strategy)
{
    strategy_ = std::move(strategy);
    center_ = strategy_->getStartCenterPositions();
    rotation_ = Config::Rotation::Up;
}

void Tetromino::move(int dx, int dy)
{
    center_.x += dx;
    center_.y += dy;
}

void Tetromino::rotate()
{
    rotation_ = static_cast<Config::Rotation>(
        (static_cast<int>(rotation_) + 1) % 4
    );
}

void Tetromino::rotateBack()
{
    rotation_ = static_cast<Config::Rotation>(
        (static_cast<int>(rotation_) + 3) % 4
    );
}

std::array<Config::Position, 4> Tetromino::getPositions() const
{
    std::array<Config::Position, 4> relative_positions =
        strategy_->getRelativePositions(rotation_);

    std::array<Config::Position, 4> absolute_positions;

    for (int i = 0; i < 4; ++i)
    {
        absolute_positions[i] = {
            center_.x + relative_positions[i].x,
            center_.y + relative_positions[i].y
        };
    }

    return absolute_positions;
}
