project(Game CXX)
add_library(${PROJECT_NAME} SHARED)

file( GLOB_RECURSE src_game
	"${ENGINE_SOURCE}/d3base/*.def"
	"${ENGINE_SOURCE}/d3base/*.cpp"
	"${ENGINE_SOURCE}/d3base/*.h"
	"${ENGINE_SOURCE}/game/*.cpp"
	"${ENGINE_SOURCE}/game/*.h")
list( REMOVE_ITEM src_game	"${ENGINE_SOURCE}/game/gamesys/Callbacks.cpp" )
source_group( TREE ${ENGINE_SOURCE} PREFIX "" FILES ${src_game} )
target_sources(${PROJECT_NAME} PRIVATE ${src_game})

target_compile_definitions(${PROJECT_NAME} PRIVATE GAME_DLL)
target_link_libraries(${PROJECT_NAME} idLib)
add_dependencies(${PROJECT_NAME} TypeInfo)
add_custom_command(TARGET ${PROJECT_NAME}
	PRE_BUILD
	COMMAND TypeInfo
	WORKING_DIRECTORY ${OUTPUT_FOLDER}
	COMMENT "Generating neo/game/gamesys/GameTypeInfo.h")
target_precompile_headers(${PROJECT_NAME} PRIVATE "${ENGINE_SOURCE}/idlib/precompiled.h")
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "game${CPU_ARCH}" LINK_FLAGS "/PDB:\"game${CPU_ARCH}.pdb\"" RUNTIME_OUTPUT_DIRECTORY $<1:>${OUTPUT_FOLDER}/base)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "dlls")