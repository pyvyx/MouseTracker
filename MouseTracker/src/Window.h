#pragma once
#include <string>
#include <utility>

#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW/glfw3.h"
#include "GLFW/glfw3native.h"

#define IMGUI_WINDOW_FLAGS ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar

class Window
{
private:
	GLFWwindow* m_Window = nullptr;
public:
	Window(int width = 1600, int height = 920, const char* title = "Mouse Tracker", GLFWmonitor* monitor = NULL, GLFWwindow* share = NULL);
	~Window();

	// loop
	inline bool IsOpen()     const	{ return !glfwWindowShouldClose(m_Window);	}
	inline void Swap()       const	{ glfwSwapBuffers(m_Window);				}
	inline void Clear()      const	{ glClear(GL_COLOR_BUFFER_BIT);				}
	inline void PollEvents() const	{ glfwPollEvents();							}
	inline void WaitEvents() const	{ glfwWaitEvents();							}

	ImVec2 GetSize() const;
	HWND GetNativeHandle() const    { return glfwGetWin32Window(m_Window);      }

	// ImGui
	void ImGuiInit(const char* iniFileName = nullptr) const;
	void ImGuiStartFrame() const;
	void ImGuiRender() const;
};
