# Makefile for p5 - CS 320 Fall 2021
# @author Dominic Griffith
CC=g++
CFLAGS=-g -Wall -std=c++11

p5 : driver.cpp fraction.o
	$(CC) $(CFLAGS) -o p5 $^
fraction.o: fraction.cpp fraction.h fraction_exception.h
	${CC} $(CFLAGS) -c fraction.cpp
clean:
	rm *.o p5