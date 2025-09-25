NAME		= santorini

#export LD_LIBRARY_PATH=$HOME/rush_boardgame/SFML-2.6.0/lib

CXX			= g++
CXXFLAGS	= -Wall -Wextra
DEPFLAGS	= -MMD -MP
LDFLAGS		= -L./$(LIB)lib -lsfml-graphics -lsfml-window -lsfml-system
INCFLAGS	= -I./$(INC) -I./$(LIB)include

BUILDDIR	= build/
INC			= inc/
LIB			= SFML-2.6.0/

SRC			= main.cpp
OBJ			= $(patsubst %.cpp, $(BUILDDIR)%.o, $(SRC))
DEP			= $(OBJ:.o=.d)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(BUILDDIR)%.o: %.cpp | $(BUILDDIR)
			$(CXX) $(CXXFLAGS) $(DEPFLAGS) $(INCFLAGS) -c $< -o $@

$(BUILDDIR):
			mkdir -p $@

-include $(DEP)

clean:
			rm -rf $(BUILDDIR)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

debug:		CXXFLAGS += -g -DDEBUG
debug:		$(NAME)

.PHNOY:		all clean fclean re debug


