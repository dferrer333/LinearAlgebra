TEST_DIR=src/test
TEST_ODIR=obj/test
TEST_BDIR=bin/test

TEST_MATRIX_FNAMES=$(wildcard $(TEST_ROOT)/Matrix/*.test.cpp)
TEST_DEPS=$(SRCDIR)/Matrix.cpp $(IDIR)/Matrix.h $(IDIR)/TestLogger.h \
					$(TEST_DIR)/TestLogger.cpp


test_matrix: $(TEST_MATRIX_FNAMES) $(TEST_DEPS) \
						 $(TEST_DIR)/Matrix/RunUnitTests.cpp
	$(CXX) -o $(TEST_BDIR)/Matrix/$@ $^ $(CXXFLAGS)

test_clean:
	find $(TEST_ODIR)/*/ $(TEST_BDIR)/*/ -type f -name "*" | xargs rm
