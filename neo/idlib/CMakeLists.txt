project(idLib CXX)
add_library(${PROJECT_NAME} STATIC)

file( GLOB src_idlib
	"${ENGINE_SOURCE}/idlib/*.cpp"
	"${ENGINE_SOURCE}/idlib/*.h"
	"${ENGINE_SOURCE}/idlib/bv/*.cpp"
	"${ENGINE_SOURCE}/idlib/bv/*.h"
	"${ENGINE_SOURCE}/idlib/containers/*.cpp"
	"${ENGINE_SOURCE}/idlib/containers/*.h"
	"${ENGINE_SOURCE}/idlib/geometry/*.cpp"
	"${ENGINE_SOURCE}/idlib/geometry/*.h"
	"${ENGINE_SOURCE}/idlib/hashing/*.cpp"
	"${ENGINE_SOURCE}/idlib/hashing/*.h"
	"${ENGINE_SOURCE}/idlib/math/*.cpp"
	"${ENGINE_SOURCE}/idlib/math/*.h")
list( REMOVE_ITEM src_idlib	"${ENGINE_SOURCE}/idlib/math/Simd_AltiVec.cpp" "${ENGINE_SOURCE}/idlib/math/Simd_AltiVec.h" )
source_group( TREE ${ENGINE_SOURCE} PREFIX "" FILES ${src_idlib} )
target_sources(${PROJECT_NAME} PRIVATE ${src_idlib})

target_precompile_headers(${PROJECT_NAME} PRIVATE "${ENGINE_SOURCE}/idlib/precompiled.h")
target_compile_definitions(${PROJECT_NAME} PRIVATE NAME=$<TARGET_FILE_NAME:idLib>)
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/PDB:\"idlib.pdb\"")
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "libs")