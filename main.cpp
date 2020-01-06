#include "game.h"
#include <QDesktopWidget>
#include <QApplication>

void center(QWidget &widget)
{
    int x, y;
    int screenWidth;
    int screenHeight;

    int WIDTH = 300; ///Width of the game
    int HEIGHT = 500;///Height of the game

    QDesktopWidget *desktop = QApplication::desktop(); ///Fixed

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - WIDTH) / 2;
    y = (screenHeight - HEIGHT) / 2;

    widget.setGeometry(x, y, WIDTH, HEIGHT);
    widget.setFixedSize(WIDTH, HEIGHT);
}

int main(int argc, char *argv[]) ///Making the main window.
{
    QApplication app(argc, argv);

    Game window;
    window.setWindowTitle("Snake");
    window.show();
    center(window);

    return app.exec(); ///
}
