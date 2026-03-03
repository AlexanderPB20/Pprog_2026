# Variables
CC = gcc
CFLAGS = -Wall -g
LIBS = -lscreen
LDFLAGS = -L.
TARGET = castle

# Added character.o and set.o to the OBJ list
OBJ = game_loop.o game.o space.o command.o graphic_engine.o game_actions.o game_reader.o object.o player.o character.o set.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(CFLAGS) $(OBJ) $(LIBS) $(LDFLAGS)

game_loop.o: game_loop.c command.h types.h game.h space.h object.h player.h game_actions.h graphic_engine.h
	$(CC) $(CFLAGS) -c game_loop.c

game.o: game.c game.h command.h types.h space.h object.h player.h game_reader.h
	$(CC) $(CFLAGS) -c game.c

space.o: space.c space.h types.h
	$(CC) $(CFLAGS) -c space.c

command.o: command.c command.h types.h
	$(CC) $(CFLAGS) -c command.c

graphic_engine.o: graphic_engine.c graphic_engine.h game.h command.h types.h space.h object.h player.h libscreen.h
	$(CC) $(CFLAGS) -c graphic_engine.c

game_actions.o: game_actions.c game_actions.h command.h types.h game.h space.h object.h player.h
	$(CC) $(CFLAGS) -c game_actions.c

game_reader.o: game_reader.c game_reader.h game.h command.h types.h space.h object.h player.h
	$(CC) $(CFLAGS) -c game_reader.c

object.o: object.c object.h types.h
	$(CC) $(CFLAGS) -c object.c

player.o: player.c player.h types.h
	$(CC) $(CFLAGS) -c player.c

character.o: character.c character.h types.h
	$(CC) $(CFLAGS) -c character.c

set.o: set.c set.h types.h
	$(CC) $(CFLAGS) -c set.c

run: all
	./$(TARGET) castle.dat

clean:
	rm -f *.o $(TARGET)

.PHONY: all clean run

