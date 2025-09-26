SFML_VERSION = 2.6.0
SFML_DIR = SFML-$(SFML_VERSION)
SFML_TAR = SFML-$(SFML_VERSION)-linux-gcc-64-bit.tar.gz
SFML_URL = https://www.sfml-dev.org/files/$(SFML_TAR)
SOURCE = TextBox.cpp sfmltest.cpp Santorini.cpp
OBJECT = $(SOURCE:%.cpp=%.o)
TARGET = sfml-app

all: $(TARGET)

$(TARGET): $(OBJECT)
	export LD_LIBRARY_PATH=./$(SFML_DIR)/lib
	g++ $(OBJECT) -o $@ -L./$(SFML_DIR)/lib -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.cpp
	g++ -c $< -I./$(SFML_DIR)/include

$(SFML_DIR)/include/SFML/Config.hpp: $(SFML_TAR)
	tar -xzf $(SFML_TAR)
	rm $(SFML_TAR)

$(SFML_TAR):
	wget $(SFML_URL)

.PHONY: clean fclean re
clean:
	rm -rf $(OBJECT)

fclean:	clean
	rm -rf $(TARGET)

re:		fclean all
	
