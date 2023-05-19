#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <string>
#include <iostream>

#define WIDTH 960
#define HEIGHT 540

int main()
{
	GLFWwindow* window;

	if (!glfwInit())
	{
		std::cout << "[ERROR]: Glew Initialization has failed." << std::endl;
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(WIDTH, HEIGHT, "Grass Renderer", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glfwSwapInterval(0);


	if (glewInit() != GLEW_OK) {
		std::cout << "[ERROR]: Glew Initialization has failed." << std::endl;
	}


	std::cout << glGetString(GL_VERSION) << std::endl;
	{
		std::cout << "Hello World!" << std::endl;
		ImGui::CreateContext();
		ImGui_ImplGlfwGL3_Init(window, true);
		ImGui::StyleColorsDark();
		while (!glfwWindowShouldClose(window))
		{
			ImGui_ImplGlfwGL3_NewFrame();
			ImGui::Begin("Test");
			float x = 1;
			ImGui::SliderFloat3("Translation A", &x, 0.0f, 960.0f);
			ImGui::End();

			ImGui::Render();
			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
	
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
	return 0;
}