CXX = g++
INCS = -I./ -I../include
CXXFLAGS = -std=c++14 -g $(INCS)
LDFLAGS = -L/usr/lib -lgtest -lgtest_main -lpthread
SRC = $(wildcard src/*.cpp)
SRC_OBJ_PATH=../build
SRC_OBJS= $(SRC_OBJ_PATH)/FileReader.o \
			$(SRC_OBJ_PATH)/BidInfo.o \
			$(SRC_OBJ_PATH)/FileReader.o \
			$(SRC_OBJ_PATH)/OrderBookController.o \
			$(SRC_OBJ_PATH)/OrderBook.o \
			$(SRC_OBJ_PATH)/OrderInfo.o
OBJS = $(SRC:.cpp=.o) $(SRC_OBJS)

testAll: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm testAll src/*.o