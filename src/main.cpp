#include <cstdint>
#include <QApplication>
#include <messenger/ui/main_windows.hpp>

int32_t main(int32_t argc, char **argv) {
  QApplication app(argc, argv);
  messenger::main_window main_window;

  main_window.show();

  return app.exec();
}