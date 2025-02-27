#include <QStandardPaths>
#include <messenger/ui/main_windows.hpp>

messenger::webengine_view *messenger::main_window::webengine_view = nullptr;

messenger::main_window::main_window() : QMainWindow() {
  setMinimumWidth(800);
  setMinimumHeight(600);
  setWindowTitle("Messenger Qt");

  if(webengine_view == nullptr) {
    exit(-1);
  } else {
    setCentralWidget(webengine_view);
    webengine_view->load(QUrl("https://www.messenger.com"));
  }
}

messenger::main_window::~main_window() {
  
}