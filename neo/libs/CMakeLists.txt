project(external CXX)
add_library(${PROJECT_NAME} STATIC)

file( GLOB src_external
	"${ENGINE_SOURCE}/libs/miniz/*.c"
	"${ENGINE_SOURCE}/libs/miniz/*.h"
	"${ENGINE_SOURCE}/libs/minizip/*.cpp"
	"${ENGINE_SOURCE}/libs/minizip/*.c"
	"${ENGINE_SOURCE}/libs/minizip/*.h"
	"${ENGINE_SOURCE}/libs/stb/*.c"
	"${ENGINE_SOURCE}/libs/stb/*.h"
	"${ENGINE_SOURCE}/libs/glew/src/*.c"
	"${ENGINE_SOURCE}/libs/glew/include/GL/*.h")
source_group( TREE ${ENGINE_SOURCE} PREFIX "" FILES ${src_external} )
target_sources(${PROJECT_NAME} PRIVATE ${src_external})

target_compile_definitions(${PROJECT_NAME} PRIVATE NAME=$<TARGET_FILE_NAME:external> GLEW_STATIC)
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/PDB:\"external.pdb\"")
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "libs")