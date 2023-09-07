CC=tcc

# For debugging
CARGS= -ggdb

.PHONY: all build run clean

build: $(clean)
	@[ -d "./build/" ] || mkdir -v ./build/
	$(CC) $(CARGS) "src/main.c" -I./include -o ./build/bot.elf75

clean:
	@rm -rvf ./build/bot.elf75

run:
	@ python -c "print('#'*100)"
	./build/bot.elf75

# ELF75 NEXT LEVEL XD
