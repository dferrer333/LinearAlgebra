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


test_matrix: $(OBJ) $(TESTDIR)/Matrix.test.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

$(ODIR)/%.o: $(SRCDIR)%.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<
