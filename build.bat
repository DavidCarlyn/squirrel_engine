cd build
make
cd ..\apps
g++ -o app main.cpp -L ..\build\dependencies\glfw\src -lglfw3 -lgdi32 -lopengl32 -I ..\dependencies\glfw\include -L ..\build -lsquirrel_engine -I ..\src\include
cd ..\