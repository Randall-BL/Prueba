# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.1.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.1.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\cmake-build-debug-mingw-csfml

# Include any dependencies generated for this target.
include CMakeFiles/ClienteCliente.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ClienteCliente.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ClienteCliente.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ClienteCliente.dir/flags.make

CMakeFiles/ClienteCliente.dir/model/main.c.obj: CMakeFiles/ClienteCliente.dir/flags.make
CMakeFiles/ClienteCliente.dir/model/main.c.obj: CMakeFiles/ClienteCliente.dir/includes_C.rsp
CMakeFiles/ClienteCliente.dir/model/main.c.obj: C:/Users/killt/Desktop/PruebaConexion/PolePositionCE/PolePosition/Cliente/model/main.c
CMakeFiles/ClienteCliente.dir/model/main.c.obj: CMakeFiles/ClienteCliente.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\cmake-build-debug-mingw-csfml\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ClienteCliente.dir/model/main.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ClienteCliente.dir/model/main.c.obj -MF CMakeFiles\ClienteCliente.dir\model\main.c.obj.d -o CMakeFiles\ClienteCliente.dir\model\main.c.obj -c C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\model\main.c

CMakeFiles/ClienteCliente.dir/model/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ClienteCliente.dir/model/main.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\model\main.c > CMakeFiles\ClienteCliente.dir\model\main.c.i

CMakeFiles/ClienteCliente.dir/model/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ClienteCliente.dir/model/main.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\model\main.c -o CMakeFiles\ClienteCliente.dir\model\main.c.s

CMakeFiles/ClienteCliente.dir/model/client.c.obj: CMakeFiles/ClienteCliente.dir/flags.make
CMakeFiles/ClienteCliente.dir/model/client.c.obj: CMakeFiles/ClienteCliente.dir/includes_C.rsp
CMakeFiles/ClienteCliente.dir/model/client.c.obj: C:/Users/killt/Desktop/PruebaConexion/PolePositionCE/PolePosition/Cliente/model/client.c
CMakeFiles/ClienteCliente.dir/model/client.c.obj: CMakeFiles/ClienteCliente.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\cmake-build-debug-mingw-csfml\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ClienteCliente.dir/model/client.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ClienteCliente.dir/model/client.c.obj -MF CMakeFiles\ClienteCliente.dir\model\client.c.obj.d -o CMakeFiles\ClienteCliente.dir\model\client.c.obj -c C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\model\client.c

CMakeFiles/ClienteCliente.dir/model/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ClienteCliente.dir/model/client.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\model\client.c > CMakeFiles\ClienteCliente.dir\model\client.c.i

CMakeFiles/ClienteCliente.dir/model/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ClienteCliente.dir/model/client.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\model\client.c -o CMakeFiles\ClienteCliente.dir\model\client.c.s

CMakeFiles/ClienteCliente.dir/model/Ventanaprueba.c.obj: CMakeFiles/ClienteCliente.dir/flags.make
CMakeFiles/ClienteCliente.dir/model/Ventanaprueba.c.obj: CMakeFiles/ClienteCliente.dir/includes_C.rsp
CMakeFiles/ClienteCliente.dir/model/Ventanaprueba.c.obj: C:/Users/killt/Desktop/PruebaConexion/PolePositionCE/PolePosition/Cliente/model/Ventanaprueba.c
CMakeFiles/ClienteCliente.dir/model/Ventanaprueba.c.obj: CMakeFiles/ClienteCliente.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\cmake-build-debug-mingw-csfml\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ClienteCliente.dir/model/Ventanaprueba.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ClienteCliente.dir/model/Ventanaprueba.c.obj -MF CMakeFiles\ClienteCliente.dir\model\Ventanaprueba.c.obj.d -o CMakeFiles\ClienteCliente.dir\model\Ventanaprueba.c.obj -c C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\model\Ventanaprueba.c

CMakeFiles/ClienteCliente.dir/model/Ventanaprueba.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ClienteCliente.dir/model/Ventanaprueba.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\model\Ventanaprueba.c > CMakeFiles\ClienteCliente.dir\model\Ventanaprueba.c.i

CMakeFiles/ClienteCliente.dir/model/Ventanaprueba.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ClienteCliente.dir/model/Ventanaprueba.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\model\Ventanaprueba.c -o CMakeFiles\ClienteCliente.dir\model\Ventanaprueba.c.s

CMakeFiles/ClienteCliente.dir/model/Ventana_inicio.c.obj: CMakeFiles/ClienteCliente.dir/flags.make
CMakeFiles/ClienteCliente.dir/model/Ventana_inicio.c.obj: CMakeFiles/ClienteCliente.dir/includes_C.rsp
CMakeFiles/ClienteCliente.dir/model/Ventana_inicio.c.obj: C:/Users/killt/Desktop/PruebaConexion/PolePositionCE/PolePosition/Cliente/model/Ventana_inicio.c
CMakeFiles/ClienteCliente.dir/model/Ventana_inicio.c.obj: CMakeFiles/ClienteCliente.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\cmake-build-debug-mingw-csfml\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ClienteCliente.dir/model/Ventana_inicio.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ClienteCliente.dir/model/Ventana_inicio.c.obj -MF CMakeFiles\ClienteCliente.dir\model\Ventana_inicio.c.obj.d -o CMakeFiles\ClienteCliente.dir\model\Ventana_inicio.c.obj -c C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\model\Ventana_inicio.c

CMakeFiles/ClienteCliente.dir/model/Ventana_inicio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ClienteCliente.dir/model/Ventana_inicio.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\model\Ventana_inicio.c > CMakeFiles\ClienteCliente.dir\model\Ventana_inicio.c.i

CMakeFiles/ClienteCliente.dir/model/Ventana_inicio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ClienteCliente.dir/model/Ventana_inicio.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\model\Ventana_inicio.c -o CMakeFiles\ClienteCliente.dir\model\Ventana_inicio.c.s

# Object files for target ClienteCliente
ClienteCliente_OBJECTS = \
"CMakeFiles/ClienteCliente.dir/model/main.c.obj" \
"CMakeFiles/ClienteCliente.dir/model/client.c.obj" \
"CMakeFiles/ClienteCliente.dir/model/Ventanaprueba.c.obj" \
"CMakeFiles/ClienteCliente.dir/model/Ventana_inicio.c.obj"

# External object files for target ClienteCliente
ClienteCliente_EXTERNAL_OBJECTS =

ClienteCliente.exe: CMakeFiles/ClienteCliente.dir/model/main.c.obj
ClienteCliente.exe: CMakeFiles/ClienteCliente.dir/model/client.c.obj
ClienteCliente.exe: CMakeFiles/ClienteCliente.dir/model/Ventanaprueba.c.obj
ClienteCliente.exe: CMakeFiles/ClienteCliente.dir/model/Ventana_inicio.c.obj
ClienteCliente.exe: CMakeFiles/ClienteCliente.dir/build.make
ClienteCliente.exe: CMakeFiles/ClienteCliente.dir/linkLibs.rsp
ClienteCliente.exe: CMakeFiles/ClienteCliente.dir/objects1.rsp
ClienteCliente.exe: CMakeFiles/ClienteCliente.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\cmake-build-debug-mingw-csfml\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable ClienteCliente.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ClienteCliente.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ClienteCliente.dir/build: ClienteCliente.exe
.PHONY : CMakeFiles/ClienteCliente.dir/build

CMakeFiles/ClienteCliente.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ClienteCliente.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ClienteCliente.dir/clean

CMakeFiles/ClienteCliente.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\cmake-build-debug-mingw-csfml C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\cmake-build-debug-mingw-csfml C:\Users\killt\Desktop\PruebaConexion\PolePositionCE\PolePosition\Cliente\cmake-build-debug-mingw-csfml\CMakeFiles\ClienteCliente.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ClienteCliente.dir/depend
