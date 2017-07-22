SRCDIR = src/
BINDIR = bin/
GCC    = g++
TARGET = $(BINDIR)lsys
CFLAGS = -std=c++11

.phony: all
all: build

.phony: build
build: $(BINDIR) $(TARGET)	

$(BINDIR):
	mkdir $@

$(TARGET): $(SRCDIR)lsys.cpp $(SRCDIR)lsys.hpp	
	$(GCC) $(CFLAGS) $< -o $@

.phony: run
run: clean build
	./$(TARGET)

.phony: clear
clean:
	rm -rf $(BINDIR)

