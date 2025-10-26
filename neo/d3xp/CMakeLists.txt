project(Game-d3xp CXX)
add_library(${PROJECT_NAME} SHARED)

file( GLOB_RECURSE src_d3xp
	"${ENGINE_SOURCE}/d3xp/*.def"
	"${ENGINE_SOURCE}/d3xp/*.cpp"
	"${ENGINE_SOURCE}/d3xp/*.h")
list( REMOVE_ITEM src_d3xp	"${ENGINE_SOURCE}/d3xp/gamesys/Callbacks.cpp" )
source_group( TREE ${ENGINE_SOURCE} PREFIX "" FILES ${src_d3xp} )
target_sources(${PROJECT_NAME} PRIVATE ${src_d3xp})

target_compile_definitions(${PROJECT_NAME} PRIVATE GAME_DLL _D3XP CTF)
target_link_libraries(${PROJECT_NAME} idLib)
add_dependencies(${PROJECT_NAME} TypeInfo)
add_custom_command(TARGET ${PROJECT_NAME}
	PRE_BUILD
	COMMAND TypeInfo
	ARGS d3xp d3xp/gamesys/GameTypeInfo.h _D3XP CTF
	WORKING_DIRECTORY ${OUTPUT_FOLDER}
	COMMENT "Generating neo/d3xp/gamesys/GameTypeInfo.h")
target_precompile_headers(${PROJECT_NAME} PRIVATE "${ENGINE_SOURCE}/idlib/precompiled.h")
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "game${CPU_ARCH}" LINK_FLAGS "/PDB:\"game${CPU_ARCH}.pdb\"" RUNTIME_OUTPUT_DIRECTORY $<1:>${OUTPUT_FOLDER}/d3xp)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "dlls")