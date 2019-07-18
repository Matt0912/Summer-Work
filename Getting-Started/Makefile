# Find the OS platform using the uname command.
Linux := $(findstring Linux, $(shell uname -s))
MacOS := $(findstring Darwin, $(shell uname -s))
Windows := $(findstring NT, $(shell uname -s))



# For Linux/MacOS, include the advanced debugging options

hello: hello.c
	clang -std=c11 -Wall -pedantic -g hello.c -o hello \
	    -fsanitize=undefined -fsanitize=address

square: square.c
	clang square.c -o square -lm

interest: interest.c
	clang interest.c -o interest
