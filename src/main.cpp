#include <QApplication>
#include <QPushButton>

int main(int argc, char* argv[]) {
    // Initialize the application
    QApplication application(argc, argv);
    QApplication::setApplicationName("TSDB Explorer");

    QPushButton button("Hello world!", nullptr);
    button.resize(400, 200);
    button.show();

    return QApplication::exec(); // Execute the event loop
}