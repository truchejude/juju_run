/*
** EPITECH PROJECT, 2021
** sfml_t
** File description:
** main
*/

#include <SFML/Graphics/Text.hpp>
#include <string>
#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <cmath>

#include "pigon.hpp"
#include "vie.hpp"
#include "velo.hpp"
#include "game_speed.hpp"
#include "juju.hpp"

char key_put();

pigon::pigon(void) {
    if (!texture_pigon.loadFromFile("image/pigon.png"))
        exit (84);
    texture_pigon.setSmooth(true);
    pigon_sprite.setTexture(texture_pigon);
    pigon_sprite.setTextureRect((sf::IntRect){0, 0, 100, 100});
    pigon_sprite.setPosition((sf::Vector2f){2000, float(rand() % 250) + 20});
}

//########################################################################################

void draw_nuage_text(sf::RenderWindow &window, sf::Sprite nuage_s, sf::Text textAdire, sf::Text textDit)
{
    nuage_s.setPosition((sf::Vector2f){920, 0});
    window.draw(nuage_s);
    window.draw(textDit);
    window.draw(textAdire);
}

void game_event(sf::RenderWindow &window, sf::Event &event, bool &key_relacher, juju_p &juju) {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyReleased)
            key_relacher = true;
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
            juju.jujuJump(true);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
            printf("roule\n");
        if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Right))
            printf("narge\n");
    }
}

void draw_the_game(\
sf::RenderWindow &window, \
sf::Sprite nuage, \
sf::Sprite planet_f, \
sf::Sprite planet, \
sf::Sprite babe_sprite, \
juju_p juju, \
velo le_cyclist, \
std::vector <pigon*> &pigon_tab, \
vie heal_bar, \
sf::Text textAdire, \
sf::Text textDit, \
sf::Sprite nuage_text\
) {
    window.clear(sf::Color::Blue);
    window.draw(nuage);
    window.draw(planet_f);
    window.draw(planet);
    window.draw(babe_sprite);
    window.draw(juju.get_sprite());
    window.draw(le_cyclist.get_sprite());
    heal_bar.draw(window);
    textAdire.setString(juju.get_say());
    textDit.setString(juju.get_speek());
    draw_nuage_text(window, nuage_text, textAdire, textDit);
    for (std::vector <pigon*>::iterator ii = pigon_tab.begin(); ii != pigon_tab.end(); ii++) {
        window.draw((*ii)->get_sprite());
        (*ii)->move();
        (*ii)->anime();
        if ((*ii)->free_pigon_(window)) {
            pigon_tab.erase(ii);
        }
        if (ii == pigon_tab.end())
            break;
    }
    window.display();
}

void key_bord_games(bool &key_relacher, juju_p &juju, sf::Clock &run_clock, int &segondeOfRun)
{
    char c_key_juju = key_put();
    int je_suis_la = 0;

    if (c_key_juju != 0 && key_relacher && c_key_juju != '-') {
        juju.add_letter_in_speek(c_key_juju);
        key_relacher = false;
    }
    if (c_key_juju == '-') {
        juju.clear_say();
    }
    je_suis_la = juju.get_say().size();
    if (juju.speek_cmp() == 1) {
        run_clock.restart();
        segondeOfRun = je_suis_la;
    }
}

int game(sf::RenderWindow &window, sf::Event &event)
{
    // clock et tout et tout
    sf::Clock run_clock;
    int segondeOfRun = 10;

// les TEXT
    sf::Font font;
    sf::Text textAdire;
    sf::Text textDit;
    if (!font.loadFromFile("jujuascii.ttf"))
        exit (84);
    textDit.setFont(font);
    textAdire.setFont(font);
    textAdire.setString("Hello world");
    textAdire.setCharacterSize(24);
    textAdire.setFillColor(sf::Color::Red);
    textAdire.setPosition((sf::Vector2f){1000, 100});
    textDit.setCharacterSize(24);
    textDit.setFillColor(sf::Color::Red);
    textDit.setPosition((sf::Vector2f){1000, 200});

    float i_rotation = 0;
    float i_rotation_f = 0;

//creation des pigon
    std::vector <pigon*> pigon_tab;
    pigon le_pigon[100];

    vie heal_bar;
    juju_p juju;

//creation de la planette principale
    sf::Sprite planet;
    sf::Texture texture_planette;
    if (!texture_planette.loadFromFile("image/planet.png"))
        return (84);
    texture_planette.setSmooth(true);
    planet.setTexture(texture_planette);
    float size = (float)planet.getTextureRect().height;
    planet.setOrigin((sf::Vector2f){size/2, size/2});
    planet.setPosition((sf::Vector2f){960, size * 3200 / 5000});

//creation de la planette de fond
    sf::Sprite planet_f;
    sf::Texture texture_planette_f;
    if (!texture_planette_f.loadFromFile("image/planet_f.png"))
        return (84);
    texture_planette_f.setSmooth(true);
    planet_f.setTexture(texture_planette_f);
    float size_f = (float)planet_f.getTextureRect().height;
    planet_f.setOrigin((sf::Vector2f){size_f/2, size_f/2});
    planet_f.setPosition((sf::Vector2f){960, size * 3200 / 5000});

//creation des Nuage
    sf::Sprite nuage;
    sf::Texture nuage_texture;
    if (!nuage_texture.loadFromFile("image/nuage.png"))
        return (84);
    nuage_texture.setSmooth(true);
    nuage.setTexture(nuage_texture);

//creation des Nuage de dialogue
    sf::Sprite nuage_text;
    sf::Texture nuage_text_texture;
    if (!nuage_text_texture.loadFromFile("image/nuage_text.png"))
        return (84);
    nuage_text_texture.setSmooth(true);
    nuage_text.setTexture(nuage_text_texture);

//creation de babe
    float babeSpeed = 0.12;
    float babeRotation = 17;
    sf::Sprite babe_sprite;
    sf::Texture texture_babe;
    if (!texture_babe.loadFromFile("image/babe.png"))
        return (84);
    texture_babe.setSmooth(true);
    babe_sprite.setTexture(texture_babe);
    babe_sprite.setTextureRect((sf::IntRect){0, 0, 100, 100});
    babe_sprite.setOrigin((sf::Vector2f){(float)100, float(size / 2)});
    babe_sprite.setPosition((sf::Vector2f){960, float(size / 2) + 670});
    babe_sprite.setRotation(babeRotation);

//init velo
    velo le_cyclist;
    le_cyclist.set_origin_planet(size);

    sf::Clock clock_fraim;
    bool key_relacher = true;

//========================= BOUCLE DU JEUX ========================================
    while (window.isOpen() && babeRotation > -18 && heal_bar.get_heal() > 0) {
        key_bord_games(key_relacher, juju, run_clock, segondeOfRun);

        if (rand() % 10 == 0 && pigon_tab.size() < 70) {
            pigon_tab.push_back(new pigon);
        }

        game_event(window, event, key_relacher, juju);
        if (run_clock.getElapsedTime().asSeconds() < ((float)segondeOfRun) / 2 || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if (game_speed < 0.15)
                game_speed += 0.001;
        } else {
            if (game_speed > 0)
            game_speed -= 0.001;
        }
        juju.jujuJump(false);
        draw_the_game(window, nuage, planet_f, planet, babe_sprite, juju, le_cyclist, pigon_tab, heal_bar, textAdire, textDit, nuage_text);

//les animation et rotation...
        i_rotation -= game_speed;
        i_rotation_f -= game_speed * 0.5;
        planet.setRotation(i_rotation);
        planet_f.setRotation(i_rotation_f);
        le_cyclist.anime();
        le_cyclist.velo_move();
        babe_sprite.setRotation(babeRotation);
        babeRotation -= game_speed - babeSpeed;
        juju.anime();

//Domage the juju.
        if (le_cyclist.get_int_rotate() <= -17 \
        && le_cyclist.get_int_rotate() > -22) {
            if (juju.get_sprite().getPosition().y > 700)
                heal_bar.domage();
        }
//pas si vitte :) pour eviter que les pc trop puisant aille trop vitte
        while (clock_fraim.getElapsedTime().asMilliseconds() < 1000/60);
        clock_fraim.restart();
    }
    return 0;
}

int main()
{
    sf::Event event;
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");

    game(window, event);
    return (0);
}