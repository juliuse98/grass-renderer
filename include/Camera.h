#pragma once
#include "Transform.h"
#include "glm/gtc/matrix_transform.hpp"

namespace timothy
{
	struct Camera
	{
		glm::mat4 ProjectionMatrix;
		Transform Transform;

		Camera(glm::mat4 projectionMatrix, glm::vec3 position, glm::vec3 rotation) 
			: ProjectionMatrix(projectionMatrix),Transform({position,rotation,glm::vec3(1.0f,1.0f,1.0f)}) {};

		inline glm::mat4 GetViewMatrix() const
		{
			glm::mat4 result = glm::mat4(1.0f);
			result = glm::rotate(result, glm::radians(Transform.Rotation.x * -1.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			result = glm::rotate(result, glm::radians(Transform.Rotation.y * -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			result = glm::rotate(result, glm::radians(Transform.Rotation.z * -1.0f), glm::vec3(0.0f, 0.0f, 1.0f));

			result = glm::translate(result, Transform.Position);

			return result;
		};
	};
}