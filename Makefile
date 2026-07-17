CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic
TEST_BIN := tests/test_vector

.PHONY: all test clean

all: $(TEST_BIN)

$(TEST_BIN): tests/test_vector.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

test: $(TEST_BIN)
	./$(TEST_BIN)

clean:
	rm -f $(TEST_BIN)
