cd build
make
cd ..\apps
g++ main.cpp -I ..\dependencies\glad\include -I ..\dependencies\glfw\include -I ..\src\include -L ..\build\dependencies\glad -lglad -L ..\build\dependencies\glfw\src -lglfw3 -L ..\build -lsquirrel_engine -lgdi32 -lopengl32 -o app
cd ..\