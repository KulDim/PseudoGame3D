all: compile link run

PREF_SRC = ./src/
PREF_OBJ = ./obj/


compile:

	
	g++ -c $(PREF_SRC)player.cpp -IC:\SFML-2.5.1\include -DSFML_STATIC -o $(PREF_OBJ)player.o

	g++ -c $(PREF_SRC)main.cpp -IC:\SFML-2.5.1\include -DSFML_STATIC -o $(PREF_OBJ)main.o




link:
	g++ $(PREF_OBJ)*.o -o main -LC:\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lwinmm -lgdi32 -Wall 
run: 
	main.exe



# -fobjc-weak -fobjc-arc


# g++ -c $(PREF_SRC)map.cpp -IC:\SFML-2.5.1\include -DSFML_STATIC -o $(PREF_OBJ)map.o
# g++ -c $(PREF_SRC)deltaTime.cpp -IC:\SFML-2.5.1\include -DSFML_STATIC -o $(PREF_OBJ)deltaTime.o


# g++ -c $(PREF_SRC)imgui/imgui.cpp -o $(PREF_OBJ)imgui.o
# g++ -c $(PREF_SRC)imgui/imgui_draw.cpp -o $(PREF_OBJ)imgui_draw.o
# g++ -c $(PREF_SRC)imgui/imgui-SFML.cpp -IC:\SFML-2.5.1\include -DSFML_STATIC -o $(PREF_OBJ)imgui-SFML.o
# g++ -c $(PREF_SRC)imgui/imgui_tables.cpp -o $(PREF_OBJ)imgui_tables.o
# g++ -c $(PREF_SRC)imgui/imgui_widgets.cpp -o $(PREF_OBJ)imgui_widgets.o