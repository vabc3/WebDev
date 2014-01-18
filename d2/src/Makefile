.PHONY : all test clean

CC			= clang
CXX			= clang++
CFLAGS		= -Wall -O2 -g
CXXFLAGS	= -Wall -O2 -g -std=c++11
SRCS		= b.cpp logger.cpp
OBJS		= $(subst .cpp,.o,$(SRCS))

TARGETS = b

all		: $(TARGETS)

test	: $(TARGETS)
	find . -type f -perm /u+x -exec ./{} \;

clean	:
	rm -rf $(TARGETS) *.o *.out *~ .depend

$(TARGETS)	: $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGETS) $^

depend	: .depend

.depend	: $(SRCS)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^ > ./.depend

include .depend

