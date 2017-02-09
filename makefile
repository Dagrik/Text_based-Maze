# Makefile for Final Project

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -O2
OBJS = game.o advent.o treasure.o creature.o hero.o goblin.o treasureSpace.o space.o doorSpace.o restSpace.o controlSpace.o enemySpace.o finalSpace.o
SRCS = game.cpp advent.cpp treasure.cpp creature.cpp hero.cpp goblin.cpp treasureSpace.cpp space.cpp doorSpace.cpp restSpace.cpp controlSpace.cpp enemySpace.cpp finalSpace.cpp
HEADERS = advent.hp treasure.hp creature.hp hero.hp goblin.hp treasureSpace.hpp doorSpace.hpp restSpace.hpp enemySpace.hpp space.hpp finalSpace.hpp


#Targets
all: wizard

wizard: ${OBJS} #${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o wizard

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f ${OBJS}
