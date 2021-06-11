cd build
make
cd ..\apps
g++ -Wall main.cpp -I ..\dependencies\glew\include -I ..\dependencies\glfw\include -I ..\src\include -L ..\build\dependencies\glew\lib -lglewd -L ..\build\dependencies\glfw\src -lglfw3 -L ..\build -lsquirrel_engine -lgdi32 -lopengl32 -o app
cd ..\