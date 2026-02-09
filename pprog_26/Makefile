
# Variables
CC = gcc
CFLAGS = -Wall -g
LIBS = -lscreen
LDFLAGS = -L.
TARGET = castle

# Regla principal: compila todo el proyecto 
all: $(TARGET)

$(TARGET): *.c
	$(CC) -o $(TARGET) $(CFLAGS) *.c $(LIBS) $(LDFLAGS) 

# Regla para ejecutar el juego con el archivo de datos por defecto
run: all
	./$(TARGET) castle.dat

# Limpieza de archivos temporales y ejecutable 
.PHONY: clean
clean:
	rm -f *.o $(TARGET)
