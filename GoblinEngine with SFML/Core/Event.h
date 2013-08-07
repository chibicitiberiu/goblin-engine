#pragma once

struct JoystickButtonEvent {
};

struct JoystickConnectEvent {
};

struct JoystickMoveEvent {
};

struct KeyEvent {
};

struct MouseButtonEvent {
};

struct MouseMoveEvent {
};

struct MouseWheelEvent {
};

struct SizeEvent {
	unsigned width, height;
};

struct TextEvent {
};


struct Event
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

