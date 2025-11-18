#include <QApplication>
#include <QCommandLineParser>
#include <QPushButton>

#include "version.h"

int main(int argc, char* argv[]) {
    // Initialize the application
    const QApplication application(argc, argv);
    QCoreApplication::setApplicationName("TSDB Explorer");
    QCoreApplication::setApplicationVersion(PROJECT_VERSION);

    // Setup command-line interface
    QCommandLineParser parser;
    parser.setApplicationDescription("A Qt-based data acquisition, visualization, and analysis tool for time series databases, inspired by oscilloscope UX.");
    parser.addHelpOption();      // Adds --help and -h options
    parser.addVersionOption();   // Adds --version and -v options
    parser.process(application); // Parse arguments and handle built-in options

    // TODO: Replace this placeholder with MainWindow when ready
    QPushButton button("Hello world!", nullptr);
    button.resize(400, 200);
    button.show();

    return QCoreApplication::exec(); // Execute the event loop
}