#pragma once
#include "Build.h"

struct DLLEXPORT JoystickButtonEvent {
};

struct DLLEXPORT JoystickConnectEvent {
};

struct DLLEXPORT JoystickMoveEvent {
};

struct DLLEXPORT KeyEvent {
};

struct DLLEXPORT MouseButtonEvent {
};

struct DLLEXPORT MouseMoveEvent {
};

struct DLLEXPORT MouseWheelEvent {
};

struct DLLEXPORT SizeEvent {
	unsigned width, height;
};

struct DLLEXPORT TextEvent {
};


struct DLLEXPORT Event
{
	enum EventType
	{
		Closed,
		Resized,
		LostFocus,
		GainedFocus,
		TextEntered,
		KeyPressed,
		KeyReleased,
		MouseWheelMoved,
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseEntered,
		MouseLeft,
		JoystickButtonPressed,
		JoystickButtonReleased,
		JoystickMoved,
		JoystickConnected,
		JoystickDisconnected
	};

	EventType type;

	union {
		JoystickButtonEvent joystickButton;
		JoystickConnectEvent joystickConnect;
		JoystickMoveEvent joystickMove;
		KeyEvent key;
		MouseButtonEvent mouseButton;
		MouseMoveEvent mouseMove;
		MouseWheelEvent mouseWheel;
		SizeEvent size;
		TextEvent text;
	};
};

