.RECIPEPREFIX = >
objects = intSLLNode.o main.o

SLL : $(objects)
> g++ -o SLL $(objects)
   
clean :
> rm $(objects)
