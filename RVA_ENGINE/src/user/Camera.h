#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace rva
{
	class Camera
	{
	private:
		static Camera* s_cameraInstancePtr;

		glm::vec3 m_position;
		glm::vec3 m_front;
		glm::vec3 m_up;
		glm::vec3 m_right;
		glm::vec3 m_worldUp;

		float m_yaw;
		float m_pitch;

		float m_movementSpeed;
		float m_mouseSensitivity;
		float m_zoom;

		void m_updateCameraVectors();

	public:
		enum CameraMovement
		{
			FORWARD, BACKWARD, LEFT, RIGHT
		};

		Camera(); 
		Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch);
		Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

		static Camera* getActiveCamera();

		glm::mat4 getViewMatrix();

		void processKeyboard(CameraMovement key, float dt);
		void processMouseMovement(float xoffset, float yoffset, bool constrainPath);
		void processMouseScroll(float yoffset);

	};
}