#pragma once

#include <SFML\Graphics.hpp>

namespace Goblin {

enum UiAlign {
	UiAlignNone = 0,
	UiAlignTop = 0x01,
	UiAlignMiddle = 0x02,
	UiAlignBottom = 0x04,
	UiAlignLeft = 0x08,
	UiAlignCenter = 0x10,
	UiAlignRight = 0x20,
	UiAlignStretchVert = 0x40,
	UiAlignStretchHor = 0x80,
	UiAlignFill = UiAlignStretchVert | UiAlignStretchHor
};

class UiElement {

private:
	// Layout
	sf::Vector2f position;
	sf::Vector2f size, max_size, min_size, actual_size;
	int align;
	int z_index;

	// Appearance
	sf::Color back, fore;

	// Other
	bool enabled;
	int dpi;
	//bool needsRedraw;

	// Parenting
	UiElement* parent;
	void* parent_data;

protected:

	// Some events
	virtual void onLayoutChanged();
	virtual void onAppearanceChanged();
	virtual void onEnabledChanged();

public:
	UiElement();
	virtual ~UiElement();

	virtual bool handleEvent(const sf::Event& e) = 0;
	virtual void render(sf::RenderTarget& target, sf::FloatRect bounds) = 0;

	// Setters: layout
	virtual void setPosition(const sf::Vector2f& value);
	virtual void setPosition(float x, float y);
	virtual void setX(float value);
	virtual void setY(float value);

	virtual void setSize(const sf::Vector2f& value);
	virtual void setSize(float w, float h);
	virtual void setWidth(float value);
	virtual void setHeight(float value);
	virtual void setMaxSize(const sf::Vector2f& value);
	virtual void setMaxSize(float w, float h);
	virtual void setMaxWidth(float value);
	virtual void setMaxHeight(float value);
	virtual void setMinSize(const sf::Vector2f& value);
	virtual void setMinSize(float w, float h);
	virtual void setMinWidth(float value);
	virtual void setMinHeight(float value);
	virtual void setActualSize(const sf::Vector2f& value);
	virtual void setActualSize(float w, float h);
	virtual void setActualWidth(float value);
	virtual void setActualHeight(float value);

	virtual void setZIndex(int value);
	virtual void setAlign(int value);

	// Setters: Appearance
	virtual void setBackground(const sf::Color& value);
	virtual void setForeground(const sf::Color& value);

	// Setters: Parenting
	virtual void setParent(UiElement* el);
	virtual void setParentData(void* value);

	// Setters: Other
	virtual void setEnabled(bool value);
	virtual void setDpi(int value);
	//virtual void setNeedsRedraw(bool value);

	// Getters: Layout
	virtual sf::Vector2f getPosition() const;
	virtual float getX() const;
	virtual float getY() const;

	virtual sf::Vector2f getSize() const;
	virtual float getWidth() const;
	virtual float getHeight() const;
	virtual sf::Vector2f getMaxSize() const;
	virtual float getMaxWidth() const;
	virtual float getMaxHeight() const;
	virtual sf::Vector2f getMinSize() const;
	virtual float getMinWidth() const;
	virtual float getMinHeight() const;
	virtual sf::Vector2f getActualSize() const;
	virtual float getActualWidth() const;
	virtual float getActualHeight() const;

	virtual int getAlign() const;
	virtual int getZIndex() const;

	// Getters: Appearance
	virtual sf::Color getBackground() const;
	virtual sf::Color getForeground() const;

	// Getters: Parenting
	virtual bool hasParent() const;
	virtual UiElement* getParent() const;
	virtual void* getParentData() const;

	// Getters: Other
	virtual bool getEnabled() const;
	virtual int getDpi() const;
	//virtual bool getNeedsRedraw() const;

};

}  // namespace Goblin
