SHELL := /bin/bash

IDIR=include
CXX=g++
CXXFLAGS=-I$(IDIR) -Wall -Werror

SRCDIR=src
TESTDIR=src/test
ODIR=obj
BDIR=bin

_DEPS = Matrix.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Matrix.o MatrixFactories.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

include makefiles/*.mk

$(ODIR)/%.test.o: $(TESTDIR)/%.test.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: clean

clean:
	find ./$(ODIR) ./$(BDIR) -type f ! -name README.md | xargs rm
