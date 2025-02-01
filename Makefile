src := src/main.c
target := bin/Daw.out
flags := -O2 -Wall
cc := gcc

all: main

main: ${src}
	${cc} -o ${target} ${src} ${flags}

run:
	./${target}

clean:
	rm ${target}
