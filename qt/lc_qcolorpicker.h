#pragma once

#include <QObject>
class lcQColorList;

class lcQColorPickerPopup : public QFrame
{
	Q_OBJECT

public:
	lcQColorPickerPopup(QWidget *parent = nullptr, int colorIndex = 0);
	~lcQColorPickerPopup();

	void exec();

signals:
	void changed(int colorIndex);
	void selected(int colorIndex);
	void hid();

public slots:
	void colorChanged(int colorIndex);
	void colorSelected(int colorIndex);

protected:
	void showEvent(QShowEvent* ShowEvent) override;
	void hideEvent(QHideEvent* HideEvent) override;
	void mouseReleaseEvent(QMouseEvent* MouseEvent) override;

private:
	QEventLoop *eventLoop;
	lcQColorList *colorList;
};

class lcQColorPicker : public QPushButton
{
	Q_OBJECT

public:
	lcQColorPicker(QWidget *parent = 0);
	~lcQColorPicker();

	int currentColor() const;
	int currentColorCode() const;
	void setCurrentColor(int colorIndex);
	void setCurrentColorCode(int colorCode);

public slots:
	void changed(int colorIndex);
	void selected(int colorIndex);

signals:
	void colorChanged(int colorIndex);

protected:
	void updateIcon();

private slots:
	void buttonPressed(bool toggled);
	void popupClosed();

private:
	int currentColorIndex;
	int initialColorIndex;
};

