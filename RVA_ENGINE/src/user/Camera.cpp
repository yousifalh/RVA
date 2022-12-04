#include "../Macro.h"
#include "Settings.h"
#include "Camera.h"

//TODO: PAN,ROTATE & ZOOM CAMERA


namespace rva
{
	CameraSettings defaultCS{ -90.0f, 0.0f, 4.0f, 0.1f, 45.0f };

	Camera* Camera::s_cameraInstancePtr{nullptr};

	Camera* Camera::getActiveCamera()
	{
		return s_cameraInstancePtr;
	}


	void Camera::m_updateCameraVectors()
	{
		// calculate the new Front vector
		glm::vec3 front;
		front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
		front.y = sin(glm::radians(m_pitch));
		front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
		m_front = glm::normalize(front);
		// also re-calculate the Right and Up vector
		m_right = glm::normalize(glm::cross(m_front, m_worldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
		m_up = glm::normalize(glm::cross(m_right, m_front));

		/*RVA_LOG(m_front.x);
		RVA_LOG(m_front.y);
		RVA_LOG(m_front.z);*/

	}

	Camera::Camera()
		: m_front(glm::vec3(0.0f, 0.0f, -1.0f)), m_movementSpeed(defaultCS.speed),
		m_mouseSensitivity(defaultCS.sensitivity), m_zoom(defaultCS.zoom)
	{
		m_position = glm::vec3(0.0f, 0.0f, 5.0f);
		m_worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
		m_yaw = defaultCS.yaw;
		m_pitch = defaultCS.pitch;
		m_updateCameraVectors();

		s_cameraInstancePtr = this;
	}

	Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
	{
		m_position = position;
		m_worldUp = up;
		m_yaw = defaultCS.yaw;
		m_pitch = defaultCS.pitch;
		m_updateCameraVectors();


		s_cameraInstancePtr = this;
	}

	Camera::Camera(float posX, float posY, float posZ, 
		float upX, float upY, float upZ,
		float yaw, float pitch) 
		: m_front(glm::vec3(0.0f, 0.0f, -1.0f)), m_movementSpeed(defaultCS.speed),
		  m_mouseSensitivity(defaultCS.sensitivity), m_zoom(defaultCS.zoom)
	{
		m_position = glm::vec3(posX, posY, posZ);
		m_worldUp = glm::vec3(upX, upY, upZ);
		m_yaw = yaw;
		m_pitch = pitch;
		m_updateCameraVectors();

		s_cameraInstancePtr = this;
	}

	glm::mat4 Camera::getViewMatrix()
	{
		return glm::lookAt(m_position, m_position + m_front, m_up);
	}

	void Camera::processKeyboard(CameraMovement direction, float dt)
	{
		//Will change to ray-cast and pivot + panning
		//Could make toggleable movement settings

		float velocity = m_movementSpeed * dt;

		if (direction == CameraMovement::FORWARD)
			m_position += m_front * velocity;
		if (direction == CameraMovement::BACKWARD)
			m_position -= m_front * velocity;
		if (direction == CameraMovement::LEFT)
			m_position -= m_right * velocity;
		if (direction == CameraMovement::RIGHT)
			m_position += m_right * velocity;

		/*RVA_LOG(m_position.x);
		RVA_LOG(m_position.y);
		RVA_LOG(m_position.z);*/
	}

	void Camera::processMouseMovement(float xoffset, float yoffset, bool constrainPath)
	{
		xoffset *= m_mouseSensitivity;
		yoffset *= m_mouseSensitivity;

		m_yaw   += xoffset;
		m_pitch -= yoffset;

		if (constrainPath)
		{
			if (m_pitch > 89.0f)
				m_pitch = 89.0f;
			if (m_pitch < -89.0f)
				m_pitch = -89.0f;
		}

		m_updateCameraVectors();
	}

	void Camera::processMouseScroll(float yoffset)
	{
		m_zoom -= (float)yoffset;
		if (m_zoom < 1.0f)
			m_zoom = 1.0f;
		if (m_zoom > 100.0f)
			m_zoom = 100.0f;
	}
}