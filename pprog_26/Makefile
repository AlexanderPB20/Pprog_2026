# Variables
CC = gcc
CFLAGS = -Wall -g
LIBS = -lscreen
LDFLAGS = -L.
TARGET = castle

# Lista de objetos necesarios para el ejecutable
OBJ = game_loop.o game.o space.o command.o graphic_engine.o game_actions.o game_reader.o object.o player.o

# Regla principal
all: $(TARGET)

# Enlazado final: utiliza la lista de objetos $(OBJ) en vez de *.c
$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(CFLAGS) $(OBJ) $(LIBS) $(LDFLAGS)

# Reglas de compilación de módulos
game_loop.o: game_loop.c game.h command.h game_actions.h graphic_engine.h
	$(CC) $(CFLAGS) -c game_loop.c

game.o: game.c game.h space.h command.h types.h game_reader.h player.h object.h
	$(CC) $(CFLAGS) -c game.c

space.o: space.c space.h types.h
	$(CC) $(CFLAGS) -c space.c

command.o: command.c command.h types.h
	$(CC) $(CFLAGS) -c command.c

graphic_engine.o: graphic_engine.c graphic_engine.h game.h libscreen.h space.h types.h
	$(CC) $(CFLAGS) -c graphic_engine.c

game_actions.o: game_actions.c game_actions.h game.h command.h types.h
	$(CC) $(CFLAGS) -c game_actions.c

game_reader.o: game_reader.c game.h game_reader.h space.h
	$(CC) $(CFLAGS) -c game_reader.c

object.o: object.c object.h types.h
	$(CC) $(CFLAGS) -c object.c

player.o: player.c player.h types.h
	$(CC) $(CFLAGS) -c player.c

# Regla para ejecutar el juego
run: all
	./$(TARGET) castle.dat

# Limpieza de archivos
clean:
	rm -f *.o $(TARGET)

.PHONY: all clean run


