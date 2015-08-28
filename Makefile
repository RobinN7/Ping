CXX = g++
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

SRCS = src/main.cpp
OBJS = $(SRCS:.cpp=.o)


## Targets ##

all: ping

ping: $(OBJS)
	$(CXX) $(OBJS) -o ping $(LIBS)

clean:
	@echo "** Removing object files and executable..."
	rm -f ping $(OBJS)

%.o: %.cpp
	$(CXX) -c $< -o $@

