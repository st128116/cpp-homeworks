CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

TARGET = hw8_array
SRC = src/main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
