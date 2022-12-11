#include<SFML/Graphics.hpp>
#include<iostream>

int main()
{
    sf::RenderWindow win(sf::VideoMode(1920,1080), "vertices");

    float offsetX[3] = {0,0,0};
    float offsetY[3] = {0,0,0};
    int selector = 0;
    bool holdkey = false;
    
    while(win.isOpen())
    {
        sf::Event e;
        while (win.pollEvent(e))
        {
            switch (e.type)
            {
            case sf::Event::Closed:
                win.close();
                break;
            }
        }
    


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        if(!holdkey)
        {
            if(selector == 2)
                selector = 0;
            
            else if(selector == 1)
                selector = 2;
            
            else if(selector == 0)
                selector = 1;
            holdkey = true;
        }
    }
    else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        holdkey = false;



    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        offsetY[selector] -= 0.5;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        offsetY[selector] += 0.5;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        offsetX[selector] -= 0.5;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        offsetX[selector] += 0.5;
    
    sf::VertexArray ver(sf::Triangles, 3);

    ver[0].position = sf::Vector2f(960 + offsetX[0],540 + offsetY[0]);
    
    ver[1].position.x = 960 + offsetX[1];
    ver[1].position.y = 540 - 50 + offsetY[1];
    
    ver[2].position.x = 960 - 50 + offsetX[2];
    ver[2].position.y = 540 + offsetY[2];

    ver[0].color = sf::Color::Red;
    ver[1].color = sf::Color::Blue;
    ver[2].color = sf::Color::Yellow;

    win.clear();

    win.draw(ver);

    win.display();
    }
}