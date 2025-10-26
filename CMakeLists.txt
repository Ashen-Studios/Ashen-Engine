cmake_minimum_required (VERSION 3.20)

set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER  "")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(Doom3 CXX C)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CPU_ARCH "x86")
set(ENGINE_SOURCE "${CMAKE_SOURCE_DIR}/neo")
set(OUTPUT_FOLDER "${ENGINE_SOURCE}/../")

add_compile_definitions(__DOOM__)
add_compile_definitions(__DOOM_DLL__)

if( WIN32 )
	set(CMAKE_SHARED_LINKER_FLAGS /MANIFEST:NO)

	# Allow addressing more memory on a 64-bit host.
	add_link_options("/LARGEADDRESSAWARE")

	# Project is not compatible with data execution prevention.
	add_link_options("/NXCOMPAT:NO")

	# Project is not compatible with safe exception handlers. 
	add_link_options("/SAFESEH:NO")
	
	# Stack size options.
	add_link_options("/STACK:16777216,16777216") # 16MB stack size

	# Parallel build (use all cores, or as many as configured in VS)
	add_compile_options("/MP")

	# Because of the "#define private public" and "#define protected public" in TypeInfo.cpp
	add_compile_definitions(_ALLOW_KEYWORD_MACROS)

	# Some windows definitions.
	add_compile_definitions(_ALLOW_KEYWORD_MACROS)
	add_compile_definitions(_CRT_SECURE_NO_DEPRECATE)
	add_compile_definitions(_CRT_NONSTDC_NO_DEPRECATE)

	if( NOT CMAKE_CL_64 )
		add_compile_definitions(_USE_32BIT_TIME_T)
	endif()

	if( CMAKE_CL_64 )
		set(CPU_ARCH "x64")
	endif()

	# Sets the system libraries to link against.
	set(src_syslibs
		dbghelp
		dinput8
		dsound
		dxguid
		glu32
		iphlpapi
		odbc32
		odbccp32
		opengl32
		winmm
		wsock32)
endif()

include_directories("${ENGINE_SOURCE}/idlib")
include_directories("${ENGINE_SOURCE}/libs/glew/include")

add_subdirectory(neo/libs)
add_subdirectory(neo/idlib)
add_subdirectory(neo/TypeInfo)
add_subdirectory(neo/game)
add_subdirectory(neo/d3xp)

file( GLOB src_engine
	"${ENGINE_SOURCE}/cm/*.cpp"
	"${ENGINE_SOURCE}/cm/*.h"
	"${ENGINE_SOURCE}/framework/*.cpp"
	"${ENGINE_SOURCE}/framework/*.h"
	"${ENGINE_SOURCE}/framework/async/*.cpp"
	"${ENGINE_SOURCE}/framework/async/*.h"
	"${ENGINE_SOURCE}/renderer/*.cpp"
	"${ENGINE_SOURCE}/renderer/*.h"
	"${ENGINE_SOURCE}/sound/*.cpp"
	"${ENGINE_SOURCE}/sound/*.h"
	"${ENGINE_SOURCE}/tools/compilers/aas/*.cpp"
	"${ENGINE_SOURCE}/tools/compilers/aas/*.h"
	"${ENGINE_SOURCE}/tools/compilers/dmap/*.cpp"
	"${ENGINE_SOURCE}/tools/compilers/dmap/*.h"
	"${ENGINE_SOURCE}/tools/compilers/renderbump/*.cpp"
	"${ENGINE_SOURCE}/tools/compilers/roqvq/*.cpp"
	"${ENGINE_SOURCE}/tools/compilers/roqvq/*.h"
	"${ENGINE_SOURCE}/tools/compilers/*.h"
	"${ENGINE_SOURCE}/sys/*.cpp"
	"${ENGINE_SOURCE}/sys/*.h"
	"${ENGINE_SOURCE}/ui/*.cpp"
	"${ENGINE_SOURCE}/ui/*.h")

if(WIN32)
file( GLOB src_engine_win32
	"${ENGINE_SOURCE}/sys/win32/*.cpp"
	"${ENGINE_SOURCE}/sys/win32/*.h"
	"${ENGINE_SOURCE}/sys/win32/rc/doom.rc"
	"${ENGINE_SOURCE}/sys/win32/rc/doom_resource.h"
	"${ENGINE_SOURCE}/sys/win32/rc/res/doom.ico")
list( REMOVE_ITEM src_engine_win32 "${ENGINE_SOURCE}/sys/win32/gl_logfuncs.cpp" )
list( APPEND src_engine ${src_engine_win32} )
endif()

source_group( TREE ${ENGINE_SOURCE} PREFIX "" FILES ${src_engine} )

# Doom3 Project
add_executable(DoomEXE WIN32 ${src_engine})
target_link_libraries(DoomEXE idLib external ${src_syslibs})
target_precompile_headers(DoomEXE PRIVATE "${ENGINE_SOURCE}/idlib/precompiled.h")
set_target_properties(DoomEXE PROPERTIES OUTPUT_NAME "Doom3" LINK_FLAGS "/PDB:\"Doom3.pdb\"" RUNTIME_OUTPUT_DIRECTORY $<1:>${OUTPUT_FOLDER})
set_target_properties(DoomEXE PROPERTIES FOLDER "exes")