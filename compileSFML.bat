:: compile to object file (.o)
g++ -IC:\sfml\SFML-2.5.1\include -c main.cpp -o main.o

g++ -LC:\sfml\SFML-2.5.1\lib .\main.o -o main.exe -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main -mwindows