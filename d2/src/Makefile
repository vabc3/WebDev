.PHONY : all test clean

CC		= clang
CFLAGS	= -Wall -O2 -g
TARGETS = a

all		: $(TARGETS)

test	: $(TARGETS)
	find . -type f -perm /u+x -exec ./{} \;

clean 	:
	rm -rf $(TARGETS) *.o *.out *~

$(TARGETS)	: a.o
