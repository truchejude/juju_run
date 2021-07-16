/*
** EPITECH PROJECT, 2021
** sfml_t
** File description:
** velo
*/

#ifndef VELO_HPP_
#define VELO_HPP_

#include <SFML/Graphics.hpp>

class velo
{
private:
    float rotation = 0;
    sf::Clock anim_c;
    sf::Sprite velo_sprite;
    sf::Texture texture_velo;
    float speed = float(((rand() % 50) + 50) / 10);
public:
    velo() {
        if (!texture_velo.loadFromFile("image/velo.png")) {
            exit (84);
            printf("VELO ERROR\n");
        }
        texture_velo.setSmooth(true);
        velo_sprite.setTexture(texture_velo);
        velo_sprite.setTextureRect((sf::IntRect){0, 0, 200, 200});
    }
    ~velo() {
    }
    sf::Sprite get_sprite() {
        return (velo_sprite);
    }
    void anime() {
        int anime_fraime = ((int)(anim_c.getElapsedTime().asMilliseconds() / 70));

        if (anime_fraime > 4) {
            anime_fraime = 0;
            anim_c.restart();
        }
        velo_sprite.setTextureRect((sf::IntRect){anime_fraime * 200, 0, 200, 200});
    }
    void set_origin_planet(int size) {
        velo_sprite.setOrigin((sf::Vector2f){(float)100, float(size / 2)});
        velo_sprite.setPosition((sf::Vector2f){960, float(size / 2) + 610});
    }
    void velo_move() {
        if (rotation < -360)
            rotation += 360;
        rotation -= game_speed + 0.4;
        velo_sprite.setRotation(rotation);
    }
    int get_int_rotate() {
        return ((int)rotation);
    }
};

#endif /* !VELO_HPP_ */
