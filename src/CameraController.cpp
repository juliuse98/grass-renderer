#include "CameraController.h"


namespace timothy
{
	void CheckInputs(Camera& camera,const float deltaTime, GLFWwindow* window, bool& centerCursor)
	{
		if (ImGui::IsKeyDown(GLFW_KEY_W))
		{
			camera.Transform.Position += camera.Transform.Forward() * 50.0f * (float)deltaTime;
		}
		if (ImGui::IsKeyDown(GLFW_KEY_A))
		{
			camera.Transform.Position += camera.Transform.Right() * 50.0f * (float)deltaTime;
		}
		if (ImGui::IsKeyDown(GLFW_KEY_S))
		{
			camera.Transform.Position -= camera.Transform.Forward() * 50.0f * (float)deltaTime;
		}
		if (ImGui::IsKeyDown(GLFW_KEY_D))
		{
			camera.Transform.Position -= camera.Transform.Right() * 50.0f * (float)deltaTime;
		}
		if (ImGui::IsKeyDown(GLFW_KEY_LEFT_SHIFT))
		{
			camera.Transform.Position -= camera.Transform.Up() * 50.0f * (float)deltaTime;
		}
		if (ImGui::IsKeyDown(GLFW_KEY_LEFT_CONTROL))
		{
			camera.Transform.Position += camera.Transform.Up() * 50.0f * (float)deltaTime;
		}
		if (ImGui::IsKeyPressed(GLFW_KEY_SPACE))
		{
			centerCursor = !centerCursor;
		}
		if (ImGui::IsKeyPressed(GLFW_KEY_ESCAPE))
		{
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		}
	}
}