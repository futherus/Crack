SRC	:= main.cpp
OBJ	:= $(patsubst %.cpp, %.o, $(SRC))
BIN	:= out


build:	$(OBJ)
	gcc $(OBJ) -o $(BIN) -no-pie

run:
	./out
%.o: %.s
	nasm -f elf64 $< -o $@
	
%.o: %.cpp
	gcc -c $< -o $@ -no-pie -fno-stack-protector
	
clean:
	rm $(BIN) $(OBJ)
