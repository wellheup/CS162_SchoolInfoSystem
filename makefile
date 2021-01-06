CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += O3
LDFLAGS = -lboost_date_time

#you can use either {} or () to contain sets of instructions

OBJS = main.o isValidInput.o menuShell.o building.o person.o student.o instructor.o university.o

SRCS = isValidInput.cpp menuShell.cpp main.cpp building.cpp person.cpp student.hpp instructor.hpp university.hpp

HEADERS = isValidInput.hpp menuShell.hpp building.hpp person.hpp student.hpp instructor.hpp university.hpp

DOCUMENTS = flipBuildings.txt flipPeople.txt

#target: dependencies
#	rules to build

main: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean: ${OBJS}
	rm -f *.o main 

zip: ${SRCS} ${HEADERS} ${DOCUMENTS}
	lab4_Wellheuser_Phillip.zip ${HEADERS}${SRCS}${DOCUMENTS}

#all: clean 



