#pragma once

#ifndef SETTINGS_H
#define SETTINGS_H

namespace rva
{
	struct WindowProperties
	{
		unsigned int width;
		unsigned int height;
		const char* name;
	};

	struct CameraSettings
	{
		const float yaw;
		const float pitch;
		const float speed;
		const float sensitivity;
		const float zoom;
	};
}

#endif