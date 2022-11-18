#pragma once


namespace rva
{
	struct WindowData
	{
		int width;
		int height;
		const char* name;
	};

	WindowData windowData{ 1000, 700, "rvaengine" };

}