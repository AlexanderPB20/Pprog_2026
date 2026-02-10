# Variables
CC = gcc
CFLAGS = -Wall -g
LIBS = -lscreen
LDFLAGS = -L.
TARGET = castle

# Regla principal: compila todo el proyecto 
all: $(TARGET)

game_loop.o: game_loop.c game.h command.h game_actions.h graphic_engine.h
	$(CC) $(CFLAGS) -o $@ -c $<

game.o: game.c game.h space.h command.h types.h game_reader.h player.h object.h
	$(CC) $(CFLAGS) -o $@ -c $<

space.o: space.c space.h types.h
	$(CC) $(CFLAGS) -o $@ -c $<

command.o: command.c command.h types.h
	$(CC) $(CFLAGS) -o $@ -c $<

graphic_engine.o: graphic_engine.c graphic_engine.h game.h libscreen.h space.h types.h
	$(CC) $(CFLAGS) -o $@ -c $<

game_actions.o: game_actions.c game_actions.h game.h command.h types.h
	$(CC) $(CFLAGS) -o $@ -c $<

game_reader.o: game_reader.c game.h game_reader.h space.h
	$(CC) $(CFLAGS) -o $@ -c $<

object.o: object.c object.h types.h
	$(CC) $(CFLAGS) -o $@ -c $<

player.o: player.c player.h types.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(TARGET): *.c
	$(CC) -o $(TARGET) $(CFLAGS) *.c $(LIBS) $(LDFLAGS) 


# Regla para ejecutar el juego con el archivo de datos por defecto
run: all
	./$(TARGET) castle.dat

# Limpieza de archivos temporales y ejecutable 
.PHONY: clean
clean:
	rm -f *.o $(TARGET)

