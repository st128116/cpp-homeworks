CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
GTEST_LIBS = -lgtest -lgtest_main -pthread

SRC = tests/test_hw2.cpp tests/test_hw5.cpp
TARGET = hw6_tests

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(GTEST_LIBS)

clean:
	rm -f $(TARGET)
