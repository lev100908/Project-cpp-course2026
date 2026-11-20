#include "TetraminoStrategyFabric.h"
#include <random>

TetraminoComponents StrategyFactory::createRandomStrategy()
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, static_cast<int>(Config::TetraminoType::len) - 1);

    Config::TetraminoType random_tetramino_type = static_cast<Config::TetraminoType>(dist(rd));

    switch (random_tetramino_type) {
        case Config::TetraminoType::I:
            return {
                std::make_unique<IStrategy>(),
                std::make_shared<ITetraminoCellState>()
            };
        case Config::TetraminoType::O:
            return {std::make_unique<OStrategy>(),
                std::make_shared<OTetraminoCellState>()};

        case Config::TetraminoType::T:
            return {std::make_unique<TStrategy>(),
                std::make_shared<TTetraminoCellState>()};

        case Config::TetraminoType::S:
            return {std::make_unique<SStrategy>(),
                std::make_shared<STetraminoCellState>()};

        case Config::TetraminoType::Z:
            return {std::make_unique<ZStrategy>(),
                std::make_shared<ZTetraminoCellState>()};

        case Config::TetraminoType::J:
            return {std::make_unique<JStrategy>(),
                std::make_shared<JTetraminoCellState>()};

        case Config::TetraminoType::L:
            return {std::make_unique<LStrategy>(),
                std::make_shared<LTetraminoCellState>()};
        }
    return {};
}