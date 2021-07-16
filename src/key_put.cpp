/*
** EPITECH PROJECT, 2021
** sfml_t
** File description:
** key_put
*/

#include <SFML/Window/Keyboard.hpp>

char key_put()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        return ('a');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        return ('b');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        return ('c');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        return ('d');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        return ('e');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        return ('f');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        return ('g');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
        return ('h');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        return ('i');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
        return ('j');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        return ('k');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        return ('l');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        return ('m');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
        return ('n');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
        return ('o');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        return ('p');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        return ('q');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        return ('r');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        return ('s');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
        return ('t');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
        return ('u');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
        return ('v');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        return ('w');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        return ('x');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
        return ('y');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        return ('z');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        return (' ');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
        return ('-');
    return (0);
}