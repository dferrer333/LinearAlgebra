TEST_ROOT=src/test
TEST_ODIR=obj/test
TEST_BDIR=bin/test

TEST_DEPS=$(IDIR)/Matrix.h


TEST_MATRIX_SRC=$(wildcard $(TEST_ROOT)/Matrix/*.test.cpp)
TEST_MATRIX_OBJ= $(patsubst $(TEST_ROOT)/Matrix/%.cpp,$(TEST_ODIR)/Matrix/%.o,\
														$(TEST_MATRIX_SRC))

test_matrix: $(TEST_MATRIX_OBJ)
	mkdir -p $(TEST_BDIR)/Matrix
	$(CXX) -o $@ $< $(CXXFLAGS)

$(TEST_ODIR)/Matrix/%.o: $(TEST_ROOT)/Matrix/%.test.cpp \
												 $(TEST_ROOT)/Matrix/RunUnitTests.cpp $(TEST_DEPS)
	mkdir -p $(TEST_ODIR)/Matrix
	$(CXX) -c -o $@ $^ $(CXXFLAGS)

test_clean:
	find $(TEST_ODIR)/*/ $(TEST_BDIR)/*/ -type f -name "*" | xargs rm
