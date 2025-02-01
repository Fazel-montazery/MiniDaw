src := src/main.c src/log.c src/state.c
target := bin/Daw.out
flags := -O2 -Wall
cc := gcc

all: main

main: ${src}
	${cc} -o ${target} ${src} ${flags} $$(pkg-config --cflags --libs libpipewire-0.3)

run:
	./${target}

clean:
	rm ${target}
