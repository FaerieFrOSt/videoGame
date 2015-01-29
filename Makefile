CC = g++

SUFFIX = .cpp

PREFIX = .

EXE = a.out

SFML = $(PREFIX)/SFML-2.2

INC = -I$(PREFIX)/include -I$(SFML)/include

CFLAGS = -g -Wall -Werror -Wextra -std=c++11

LIB = -L$(SFML)/lib -lsfml-graphics -lsfml-window -lsfml-system 

SRCDIR = $(PREFIX)/src

SRCSUBDIR = $(PREFIX)/src/gui

SRC = $(wildcard $(SRCDIR)/*$(SUFFIX)) $(wildcard $(SRCSUBDIR)/*$(SUFFIX))

OBJDIR = $(PREFIX)/obj

OBJ = $(subst $(SRCDIR), $(OBJDIR), $(SRC:$(SUFFIX)=.o))

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(INC) $(LIB)

$(OBJDIR)/%.o: $(SRCDIR)/%$(SUFFIX)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXE)

re: fclean all
