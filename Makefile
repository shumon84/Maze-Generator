PROGRAM=Maze
OBJS=Maze.o Define.o Union-Find.o Random.o Kruskal.o

CC=g++
CFRAGS=-O3
RM=rm -fv

INC=include

MAZE_INC=$(INC)/Maze.h $(INC)/Templet.h $(INC)/Define.h $(INC)/Union-Find.h $(INC)/Random.h $(INC)/Kruskal.h
DEFINE_INC=$(INC)/Define.h $(INC)/Templet.h
RANDOM_INC=$(INC)/Random.h $(INC)/Templet.h
KRUSKAL_INC=$(INC)/Kruskal.h $(INC)/Templet.h $(INC)/Define.h $(INC)/Union-Find.h
UNION_FIND_INC=$(INC)/Union-Find.h  $(INC)/Define.h

.SUFFIXES : .cpp .o

$(PROGRAM) : $(OBJS)
	$(CC) -o $(PROGRAM) $^

.cpp.o:
	$(CC) $(CFRAGS) -c $<

.PHONY : all
all : clean $(PROGRAM)

Maze.o : Maze.cpp $(MAZE_INC)
Define.o : Define.cpp $(DEFINE_INC)
Random.o : Random.cpp $(RANDOM_INC)
Kruskal.o : Kruskal.cpp $(KRUSKAL_INC)
Union-Find.o : Union-Find.cpp $(UNION_FIND_INC)

.PHONY : clean
clean :
	$(RM) $(PROGRAM) $(OBJS)
