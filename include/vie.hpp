/*
** EPITECH PROJECT, 2021
** sfml_t
** File description:
** vie
*/

#ifndef VIE_HPP_
#define VIE_HPP_

#include <SFML/Graphics.hpp>
#include "game_speed.hpp"

class vie
{
private:
    sf::Clock invincible;
    sf::Sprite sprite;
    sf::Texture texture;
    int heal = 3;
public:
    vie() {
        if (!texture.loadFromFile("image/coeur.png")) {
            exit (84);
            printf("coeur ERROR\n");
        }
        texture.setSmooth(true);
        sprite.setTexture(texture);
        sprite.setTextureRect((sf::IntRect){0, 0, 150, 100});
        sprite.setPosition((sf::Vector2f){50, 50});
    }
    ~vie() {
    }
    void draw(sf::RenderWindow &window) {
        if (invincible.getElapsedTime().asSeconds() < 2 && invincible.getElapsedTime().asMicroseconds() % 2 == 0)
            return;
        sprite.setTextureRect((sf::IntRect){0, 0, 150, 50});
        window.draw(sprite);
        sprite.setTextureRect((sf::IntRect){0, 50, 150 - ((3 - heal) * 50), 50});
        window.draw(sprite);
    }
    int domage() {
        if (invincible.getElapsedTime().asSeconds() < 3)
            return (0);
        game_speed = 0;
        invincible.restart();
        heal -= 1;
        return (1);
    }
    int get_heal() {
        return (heal);
    }
};

#endif /* !VIE_HPP_ */
