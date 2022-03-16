 CC = gcc
CFLAGS = -lm
SRC = ./
BIN = ./bin/

%: $(SRC)%.c
	$(CC) $(CFLAGS) $< -o $(BIN)$@
   
.PHONY: clean
   
clean: 
	rm $(BIN)* 
