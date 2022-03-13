SOURCE = $(wildcard *.cpp)
TARGETS = $(patsubst %.cpp, %, $(SOURCE))

CXX = g++
CXXFLAGS = -Wall -g
LDFLAGS = 

all:$(TARGETS)

$(TARGETS):%:%.cpp
	$(CXX) $< $(CXXFLAGS) $(LDFLAGS) -o $@

.PHONY:clean all

clean:
	@-rm -rf $(TARGETS)
