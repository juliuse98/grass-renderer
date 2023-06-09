#pragma once
#include "Camera.h"
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
namespace timothy
{
	void CheckInputs(Camera& camera, float deltaTime, GLFWwindow* window, bool& centerCursor);
}