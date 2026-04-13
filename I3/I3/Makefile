# Variables
CC = gcc
CFLAGS = -Wall -g
LIBS = -lscreen
LDFLAGS = -L.
TARGET = castle

TEST_SPACE = space_test
TEST_SET = set_test
TEST_CHAR = character_test
TEST_PLAYER = player_test
TEST_LINK = link_test

# Added character.o and set.o to the OBJ list
OBJ = game_loop.o game.o space.o command.o graphic_engine.o game_actions.o game_reader.o object.o player.o character.o set.o link.o inventory.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(CFLAGS) $(OBJ) $(LIBS) $(LDFLAGS)

game_loop.o: game_loop.c command.h types.h game.h space.h object.h set.h character.h player.h inventory.h link.h game_actions.h graphic_engine.h game_reader.h
	$(CC) $(CFLAGS) -c game_loop.c

game.o: game.c game.h command.h types.h space.h object.h set.h character.h player.h inventory.h link.h game_reader.h
	$(CC) $(CFLAGS) -c game.c

space.o: space.c space.h types.h object.h set.h character.h
	$(CC) $(CFLAGS) -c space.c

command.o: command.c command.h types.h
	$(CC) $(CFLAGS) -c command.c

graphic_engine.o: graphic_engine.c graphic_engine.h game.h command.h types.h space.h object.h set.h character.h player.h inventory.h link.h libscreen.h
	$(CC) $(CFLAGS) -c graphic_engine.c

game_actions.o: game_actions.c game_actions.h command.h types.h game.h space.h object.h set.h character.h player.h inventory.h link.h
	$(CC) $(CFLAGS) -c game_actions.c

game_reader.o: game_reader.c game_reader.h game.h command.h types.h space.h object.h set.h character.h player.h inventory.h link.h
	$(CC) $(CFLAGS) -c game_reader.c

object.o: object.c object.h types.h
	$(CC) $(CFLAGS) -c object.c

player.o: player.c player.h types.h inventory.h set.h
	$(CC) $(CFLAGS) -c player.c

character.o: character.c character.h types.h
	$(CC) $(CFLAGS) -c character.c

set.o: set.c set.h types.h
	$(CC) $(CFLAGS) -c set.c

inventory.o : inventory.c inventory.h types.h set.h
	$(CC) $(CFLAGS) -c inventory.c

link.o : link.c link.h types.h
	$(CC) $(CFLAGS) -c link.c

$(TEST_SPACE): space_test.o space.o set.o
	$(CC) -o $(TEST_SPACE) $(CFLAGS) space_test.o space.o set.o

$(TEST_SET): set_test.o set.o
	$(CC) -o $(TEST_SET) $(CFLAGS) set_test.o set.o

$(TEST_CHAR): character_test.o character.o
	$(CC) -o $(TEST_CHAR) $(CFLAGS) character_test.o character.o

$(TEST_LINK): link_test.o link.o
	$(CC) -o $(TEST_LINK) $(CFLAGS) link_test.o link.o

$(TEST_PLAYER): player_test.o player.o inventory.o set.o
	$(CC) -o $(TEST_PLAYER) $(CFLAGS) player_test.o player.o inventory.o set.o

space_test.o: space_test.c space_test.h space.h test.h
	$(CC) $(CFLAGS) -c space_test.c

set_test.o: set_test.c set_test.h set.h test.h
	$(CC) $(CFLAGS) -c set_test.c

character_test.o: character_test.c character_test.h character.h test.h
	$(CC) $(CFLAGS) -c character_test.c

link_test.o: link_test.c link_test.h link.c link.h
	$(CC) $(CFLAGS) -c link_test.c

player_test.o: player_test.c player_test.h player.h inventory.h set.h test.h
	$(CC) $(CFLAGS) -c player_test.c

run: all
	./$(TARGET) castle.dat

runlog: all
	./$(TARGET) castle.dat -l logFile

run_tests: $(TEST_SPACE) $(TEST_SET) $(TEST_CHAR) $(TEST_LINK) $(TEST_PLAYER)
	./$(TEST_SPACE)
	./$(TEST_SET)
	./$(TEST_CHAR)
	./$(TEST_LINK)
	./$(TEST_PLAYER)

valgrind: all
	echo "e" | valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(TARGET) castle.dat

clean:
	rm -f *.o $(TARGET) $(TEST_SPACE) $(TEST_SET) $(TEST_CHAR) $(TEST_LINK) $(TEST_PLAYER)

.PHONY: all clean run run_tests valgrind
