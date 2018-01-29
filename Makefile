GCC = g++

OBJS = Cart_Point.o Cart_Vector.o Game_Object.o Oxygen_Depot.o Space_Station.o Person.o Astronaut.o Model.o Game_Command.o View.o main.o

default: main

main: $(OBJS)
	$(GCC) -o pa3 $(OBJS)

Cart_Point.o: Cart_Point.cpp Cart_Point.h
	$(GCC) -c Cart_Point.cpp -o Cart_Point.o

Cart_Vector.o: Cart_Vector.cpp Cart_Vector.h
	$(GCC) -c Cart_Vector.cpp -o Cart_Vector.o

Game_Object.o: Game_Object.cpp Game_Object.h
	$(GCC) -c Game_Object.cpp -o Game_Object.o

Oxygen_Depot.o: Oxygen_Depot.cpp Oxygen_Depot.h
	$(GCC) -c Oxygen_Depot.cpp -o Oxygen_Depot.o

Space_Station.o: Space_Station.cpp Space_Station.h
	$(GCC) -c Space_Station.cpp -o Space_Station.o

Person.o: Person.cpp Person.h
	$(GCC) -c Person.cpp -o Person.o

Astronaut.o: Astronaut.cpp Astronaut.h
	
	$(GCC) -c Astronaut.cpp -o Astronaut.o

Model.o: Model.cpp Model.h
	$(GCC) -c Model.cpp -o Model.o

Game_Command.o: Game_Command.cpp Game_Command.h
	$(GCC) -c Game_Command.cpp -o Game_Command.o
	
View.o: View.cpp View.h
	$(GCC) -c View.cpp -o View.o

main.o: main.cpp Cart_Point.h Cart_Vector.h Game_Object.h Oxygen_Depot.h Space_Station.h Person.h Astronaut.h Model.h Game_Command.h View.h
	$(GCC) -c main.cpp -o main.o

clean:
	rm $(OBJS) main

