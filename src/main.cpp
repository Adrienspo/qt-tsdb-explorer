#include <QApplication>
#include <QCommandLineParser>

#include "mainwindow.h"
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

    // Setup and show main window
    MainWindow main_window;
    main_window.show();

    return QCoreApplication::exec(); // Execute the event loop
}