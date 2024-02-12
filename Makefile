cc = gcc
FLAG = -Wall -g

all: libclassgraph.a my_graph my_Knapsack

my_mat.o : my_mat.c my_mat.h
	$(cc) $(FLAG) -c $<

libclassgraph.a: my_mat.o
	ar rcu $@ $^

my_graph.o:my_graph.c my_mat.h

my_graph: my_graph.o libclassgraph.a
	$(cc) $(FLAG) -o $@ $< libclassgraph.a

my_Knapsack.o: my_Knapsack.c
	$(cc) $(FLAG) -c $<

my_Knapsack: my_Knapsack.o
	$(cc) $(FLAG) -o $@ $^

clean:
	rm -f *.o *.a my_graph my_Knapsack