CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRCDIR = src
INCDIR = include
BINDIR = bin

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(BINDIR)/%.o)
EXECUTABLE = pong

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    $(CXX) $(CXXFLAGS) $^ -o $(BINDIR)/$@ $(SFMLFLAGS)

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
    $(CXX) $(CXXFLAGS) -I$(INCDIR) -c -o $@ $<

clean:
    rm -f $(BINDIR)/*.o $(BINDIR)/$(EXECUTABLE)
