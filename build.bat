cd build
make
cd ..\apps
g++ -o app main.cpp -L ..\build -lsquirrel_engine -I ..\src\include -L ..\build\dependencies\glfw\src -lglfw3 -I ..\dependencies\glfw\include
cd ..\