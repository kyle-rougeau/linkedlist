.RECIPEPREFIX = >
objects = IntSLLNode.o IntSLList.o main.o

SLL : $(objects)
> g++ -o SLL $(objects)
   
clean :
> rm $(objects)
