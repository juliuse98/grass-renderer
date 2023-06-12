cmake_minimum_required(VERSION 3.7)

if(${CMAKE_VERSION} VERSION_LESS 3.26)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.26)
endif()

project("grass-renderer" VERSION 1.0
	LANGUAGES CXX 	
	DESCRIPTION "A grass renderer using OpenGL"
	)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")

add_subdirectory(lib/glfw)


add_executable("${PROJECT_NAME}"
	src/app.cpp #<< Main >>
	
	include/Renderer.h
	include/IndexBuffer.h
	include/Shader.h
	include/VertexArray.h
	include/VertexBuffer.h
	include/VertexBufferLayout.h
	include/Vertex.h
	include/Engine.h
	include/Camera.h
	include/CameraController.h
	include/FrustumCull.h
	include/Transform.h

	
	src/Renderer.cpp
	src/IndexBuffer.cpp
	src/Shader.cpp
	src/VertexArray.cpp
	src/VertexBuffer.cpp
	src/Engine.cpp
	src/CameraController.cpp
	
	#<< Resources
	src/res/grass.shader
	src/res/ground.shader
	#>> Resources
	
	#<< ImGui
	src/vendor/imgui/imgui.cpp
	src/vendor/imgui/imgui_demo.cpp
	src/vendor/imgui/imgui_draw.cpp
	src/vendor/imgui/imgui_impl_glfw_gl3.cpp
	#>> ImGui
)

add_dependencies("${PROJECT_NAME}" CopyResources)
target_compile_definitions("${PROJECT_NAME}" PUBLIC GLEW_STATIC)

target_include_directories("${PROJECT_NAME}" PUBLIC
	include
	lib/glew/include
	lib/glfw/include
	lib/assimp/include
	lib/simplex_noise
	src/vendor
)
	
add_custom_target(CopyResources ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/src/res/
        ${CMAKE_CURRENT_BINARY_DIR}/res
	COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/src/res/
        ${CMAKE_CURRENT_BINARY_DIR}/bin/${CMAKE_CFG_INTDIR}/res
    COMMENT "Copying Resources to the build directory"
	
	src/res/grass.shader
)
	
target_link_directories("${PROJECT_NAME}" PUBLIC 
	"${CMAKE_CURRENT_BINARY_DIR}/lib/glfw/Debug"
	"${CMAKE_CURRENT_BINARY_DIR}/lib/glfw/Debug"
	"${CMAKE_CURRENT_BINARY_DIR}/lib/imgui/src/Debug"
	"${CMAKE_CURRENT_LIST_DIR}/lib/glew/lib/Release/x64"
	"${CMAKE_CURRENT_LIST_DIR}/lib/assimp"
	)

target_link_libraries("${PROJECT_NAME}" PUBLIC 
	glfw3
	glew32s.lib
	opengl32.lib
    User32.lib
    Gdi32.lib
    Shell32.lib
	
	assimp-vc143-mtd.lib
)

set_target_properties("${PROJECT_NAME}"
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath=${}")
	
file(COPY_FILE ${CMAKE_CURRENT_SOURCE_DIR}/lib/assimp/assimp-vc143-mtd.dll ${CMAKE_CURRENT_BINARY_DIR}/assimp-vc143-mtd.dll)
    #file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/renderer-opengl/res DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release)
    #file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/renderer-opengl/res DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)