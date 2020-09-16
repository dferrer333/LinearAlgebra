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


test_matrix: $(BDIR)/test_matrix
$(BDIR)/test_matrix: $(OBJ) $(ODIR)/Matrix.test.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

$(ODIR)/%.test.o: $(TESTDIR)/%.test.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: clean

clean:
	rm $(ODIR)/*.o $(BDIR)/*.exe
