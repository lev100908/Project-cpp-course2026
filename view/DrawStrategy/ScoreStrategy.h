#pragma once
#include "../DrawingStrategy.h"

class ScoreStrategy final : public BaseDrawingStrategy
{
public:
    void draw(sf::RenderWindow& window, const DrawingContext& context) const override;
};
