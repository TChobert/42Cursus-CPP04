##### VARIABLES #####

## COLORS ##

GREEN =\033[0;32m
YELLOW =\033[0;33m
RESET =\033[0m

## TARGET ##

NAME := Materias

## COMPILATION ##

CC := c++

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -std=c++98

ifeq ($(d), 1)
		CFLAGS += -g3
endif

ifeq ($(d), 2)
		CFLAGS += -fsanitize=address,undefined -g3
endif

## SOURCES ##

SRCS += main.cpp
SRCS += AMateria.cpp
SRCS += Character.cpp
SRCS += Cure.cpp
SRCS += Ice.cpp
SRCS += MateriaSource.cpp

## INCLUDES ##

INCLUDES_DIR := .

INCLUDES += AMateria.hpp
INCLUDES += Character.hpp
INCLUDES += Cure.hpp
INCLUDES += Ice.hpp
INCLUDES += ICharacter.hpp
INCLUDES += IMateriaSource.hpp
INCLUDES += MateriaSource.hpp


## OBJECTS ##

OBJS := $(SRCS:.cpp=.o)

## RULES ##

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Materias compiled!$(RESET)"

$(OBJS): %.o: %.cpp
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re%
