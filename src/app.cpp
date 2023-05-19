#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"
#include "imgui/imconfig.h"

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
		const char* error;
		glfwGetError(&error);
		std::cout << "GLFW Initialization Error: " << error << std::endl;
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


	if (glewInit() != GLEW_OK)
	{
		std::cout << "[ERROR]: Glew Initialization has failed." << std::endl;
	}


	std::cout << glGetString(GL_VERSION) << std::endl;
	{
		ImGui::CreateContext();
		ImGui_ImplGlfwGL3_Init(window, true);
		ImGui::StyleColorsDark();

		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();
			ImGui_ImplGlfwGL3_NewFrame();

			if (ImGui::IsKeyPressed(GLFW_KEY_W)) {
				std::cout << "W Key Pressed" << std::endl;
			}
			if (ImGui::IsKeyPressed(GLFW_KEY_A)) {
				std::cout << "A Key Pressed" << std::endl;
			}
			if (ImGui::IsKeyPressed(GLFW_KEY_S)) {
				std::cout << "S Key Pressed" << std::endl;
			}
			if (ImGui::IsKeyPressed(GLFW_KEY_D)) {
				std::cout << "D Key Pressed" << std::endl;
			}
			if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Escape))) {
				glfwSetWindowShouldClose(window, GLFW_TRUE);
			}

			auto pos = ImGui::GetMousePos();
			pos.x = pos.x - WIDTH / 2;
			pos.y = pos.y - HEIGHT / 2;
			
			ImGui::Begin("Test");
			std::string posString = "X: " + std::to_string(pos.x) + " Y: " + std::to_string(pos.y);
			ImGui::Text(posString.c_str());
			if(pos.x != 0)
				std::cout << "Delta " << posString << std::endl;
			glfwSetCursorPos(window, WIDTH / 2, HEIGHT / 2);
			ImGui::End();

			ImGui::Render();
			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

			glfwSwapBuffers(window);
		}
	}
	
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
	return 0;
}