# Makefile for p4 - CS 320 Fall 2021
# @author Dominic Griffith
CC=g++
CFLAGS=-g -Wall -std=c++11

p4 : testcounter.cpp counter.o
	$(CC) $(CFLAGS) -o p4 $^
counter.o: counter.cpp counter.h
	${CC} $(CFLAGS) -c counter.cpp
clean:
	rm *.o p4