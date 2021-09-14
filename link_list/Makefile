SOURCE = $(wildcard *.c)
TARGETS = $(patsubst %.c, %, $(SOURCE))

CXX = gcc
CXXFLAGS = -Wall -g
LDFLAGS = 

BASE_OBJ = base/list.o

all:$(TARGETS)

$(TARGETS):%:%.c $(BASE_OBJ)
	$(CXX) $< $(BASE_OBJ) $(CXXFLAGS) $(LDFLAGS) -o $@

.PHONY:clean all

clean:
	@-rm -rf $(TARGETS) $(BASE_OBJ)
