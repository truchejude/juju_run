/*
** EPITECH PROJECT, 2021
** sfml_t
** File description:
** juju
*/

#ifndef JUJU_HPP_
#define JUJU_HPP_

#include <SFML/Graphics/Text.hpp>
#include <string>

const std::string list_a_dir[] = {"coulou", "pana pina", "brioche", "au chibre", "super", "je suis bo", "pd", "chibrax", "bam bam bam", "juif", "ah ah"};
#define nombreDeMot 11

class dialoge
{
private:
public:
    std::string juju_speek;
    std::string need_to_say = list_a_dir[rand() % nombreDeMot];
    dialoge() {

    }
    ~dialoge() {

    }
    void add_letter_in_juju_speek(char c) {
        juju_speek.push_back(c);
    }
    void print() {
        std::cout << "juju_speek =" << juju_speek;
        std::cout << "need_to_say =" << need_to_say << '\n';
    }
    int cmp() {
        if (juju_speek.size() > need_to_say.size()) {
            juju_speek.clear();
            return (-1);
        }
        if (juju_speek == need_to_say) {
            juju_speek.clear();
            need_to_say = list_a_dir[rand() % nombreDeMot];
            return (1);
        }
        return (0);
    }
};

class juju_p
{
private:
    sf::Clock anime_clock;
    dialoge dialog;
    int jump = 0;
    sf::Clock jump_clock;
    sf::Sprite sprite;
    sf::Texture texture;
    float speed = float(((rand() % 50) + 50) / 10);
public:
    juju_p() {
        if (!texture.loadFromFile("image/juju.png"))
            exit (84);
        texture.setSmooth(true);
        sprite.setTexture(texture);
        sprite.setTextureRect((sf::IntRect){0, 0, 100, 100});
        sprite.setPosition((sf::Vector2f){100, 830});
    }
    ~juju_p() {
    }
    void anime() {
        int i = (anime_clock.getElapsedTime().asMilliseconds() * game_speed) / 10;

        if (jump == 1) {
            sprite.setTextureRect((sf::IntRect){0, 100, 100, 100});
            return;
        }

        if (i > 13) {
            i = 12;
            anime_clock.restart();
        }
        sprite.setTextureRect((sf::IntRect){i * 100, 0, 100, 100});
    }
    int speek_cmp() {
        return (dialog.cmp());
    }
    void clear_say() {
        dialog.juju_speek.clear();
    }
    std::string get_speek() {
        return (dialog.juju_speek);
    }
    std::string get_say() {
        return (dialog.need_to_say);
    }
    void add_letter_in_speek(char c) {
        dialog.add_letter_in_juju_speek(c);
    }
    void print_info_speek() {
        dialog.print();
    }
    sf::Sprite get_sprite() {
        return (sprite);
    }
    void jujuJump(bool step) {
        if (step == true && jump == 0) {
            jump = 1;
            jump_clock.restart();
        }
        if (jump == 0)
            return;
        float t = (jump_clock.getElapsedTime().asSeconds() * 7) - 10;
        sprite.setPosition((sf::Vector2f){100, (((t*t) + 10*t) * 10) + 821});
        if (t > 0.06) {
            jump_clock.restart();
            jump = 0;
        }
    }
};

#endif /* !JUJU_HPP_ */
