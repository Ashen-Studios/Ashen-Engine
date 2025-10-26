project(TypeInfo CXX)
add_executable(${PROJECT_NAME})

set( src_tools_support
	"${ENGINE_SOURCE}/framework/CmdSystem.cpp"
	"${ENGINE_SOURCE}/framework/CVarSystem.cpp"
	"${ENGINE_SOURCE}/framework/File.cpp"
	"${ENGINE_SOURCE}/framework/FileSystem.cpp"
	"${ENGINE_SOURCE}/framework/precompiled.cpp")
source_group( TREE ${ENGINE_SOURCE} PREFIX "" FILES ${src_tools_support} )
target_sources(${PROJECT_NAME} PRIVATE ${src_tools_support})

file( GLOB src_typeinfo
	"${ENGINE_SOURCE}/TypeInfo/*.cpp"
	"${ENGINE_SOURCE}/TypeInfo/*.h")
source_group( TREE ${ENGINE_SOURCE} PREFIX "" FILES ${src_typeinfo} )
target_sources(${PROJECT_NAME} PRIVATE ${src_typeinfo})

target_compile_definitions(${PROJECT_NAME} PUBLIC ID_ENABLE_CURL=0 ID_TYPEINFO)
target_link_libraries(${PROJECT_NAME} idLib external)
target_precompile_headers(${PROJECT_NAME} PRIVATE "${ENGINE_SOURCE}/idlib/precompiled.h")
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "TypeInfo" LINK_FLAGS "/PDB:\"TypeInfo.pdb\"" RUNTIME_OUTPUT_DIRECTORY $<1:>${ENGINE_SOURCE})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "exes")