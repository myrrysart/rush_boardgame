https://www.sfml-dev.org/learn/

Setup:
https://www.sfml-dev.org/tutorials/2.6/start-linux.php
school machines:
`ldd --version`
glibc 2.35
`strings /usr/lib/x86_64-linux-gnu/libstdc++.so.6 | grep 'GLIBCXX'`
libstdc++ 3.4.30
this means the latest stable, usable version of SFML is 2.6.0
https://www.sfml-dev.org/download/sfml/2.6.0/
```
wget https://www.sfml-dev.org/files/SFML-2.6.0-linux-gcc-64-bit.tar.gz
tar -xvf SFML-2.6.0-linux-gcc-64-bit.tar.gz
g++ -c sfmltest.cpp -I./SFML-2.6.0/include
g++ sfmltest.o -o sfml-app -L./SFML-2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system
```