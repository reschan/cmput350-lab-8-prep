// maybe something here...
#include "vector_util.h"
#include <SFML/System/Vector2.hpp>

struct BasicTransform {
    BasicTransform(sf::Vector2f scale, sf::Vector2f translation)
        : scale(scale), translation(translation) {

    }

    sf::Vector2f applyPoint(const sf::Vector2f& p) {
        sf::Vector2f res;

        // scale
        res = p * scale;

        // translate
        res += translation;

        return res;
    }

    sf::Vector2f applyVector(const sf::Vector2f& p) { 
        sf::Vector2f res;
        
        // scale
        res = p * scale;

        // not affected by translate

        return res;
    }

    bool operator==(const BasicTransform& other) const {
        return this->scale == other.scale && this->translation == other.translation;
    }

    sf::Vector2f scale = {1, 1};
    sf::Vector2f translation = {0, 0};
};
