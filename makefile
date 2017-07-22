SRCDIR = src/
BINDIR = bin/
GCC    = g++
TARGET = $(BINDIR)lsys
CFLAGS = 

.phony: all
all: build

.phony: build
build: $(BINDIR) $(TARGET)	

$(BINDIR):
	mkdir $@

$(TARGET): $(SRCDIR)lsys.cpp $(SRCDIR)lsys.hpp $(SRCDIR)config.hpp $(SRCDIR)decrement.hpp
	$(GCC) $(CFLAGS) $< -o $@

.phony: run
run: clean build
	./$(TARGET)

.phony: clear
clean:
	rm -rf $(BINDIR)

