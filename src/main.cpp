#include <cstdint>
#include <QApplication>
#include <messenger/ui/main_window.hpp>
#include <messenger/ui/webengine_view.hpp>

int32_t main(int32_t argc, char **argv) {
  QApplication app(argc, argv);
  messenger::main_window::webengine_view = new messenger::webengine_view("default");
  messenger::main_window main_window;

  main_window.show();

  const int32_t returned = app.exec();

  delete messenger::main_window::webengine_view;

  return returned;
}