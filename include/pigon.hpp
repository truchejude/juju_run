/*
** EPITECH PROJECT, 2021
** sfml_t
** File description:
** pigon
*/

#ifndef PIGON_HPP_
#define PIGON_HPP_

#include <SFML/Graphics.hpp>

class pigon
{
private:
    sf::Clock anim_c;
    bool gauche = 1;
    sf::Sprite pigon_sprite;
    sf::Texture texture_pigon;
    float speed = float(((rand() % 50) + 50) / 10);
public:
    pigon();
    ~pigon();
    sf::Sprite get_sprite() {
        return (pigon_sprite);
    }
    void move() {
        sf::Vector2f pigon_position = pigon_sprite.getPosition();

        if (pigon_position.x < 923)
            gauche = 0;
        if (pigon_position.x > 1500)
            gauche = 1;
        if (gauche)
            pigon_sprite.move((sf::Vector2f){-speed , 0});
        else
            pigon_sprite.move((sf::Vector2f){+speed , 0});
    }
    bool free_pigon_(sf::RenderWindow &window) {
        sf::Vector2i positionM = sf::Mouse::getPosition(window);
        sf::Vector2f pigon_position = pigon_sprite.getPosition();

        positionM.x = positionM.x * 1920 / window.getSize().x;
        positionM.y = positionM.y * 1080 / window.getSize().y;

        if (positionM.x <= (pigon_position.x + 100) && positionM.x >= pigon_position.x\
        && positionM.y <= (pigon_position.y + 100) && positionM.y >= pigon_position.y \
        && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            return (1);
        return (pigon_sprite.getPosition().x < -500);
    }
    void anime() {
        int anime_fraime = ((int)(anim_c.getElapsedTime().asMilliseconds() / 70));

        if (anime_fraime >= 9) {
            anime_fraime = 0;
            anim_c.restart();
        }
        if (gauche)
            pigon_sprite.setTextureRect((sf::IntRect){(anime_fraime * 100) + 100, 0, -100, 100});
        else
            pigon_sprite.setTextureRect((sf::IntRect){(anime_fraime * 100), 0, 100, 100});
    }
};

#endif /* !PIGON_HPP_ */
