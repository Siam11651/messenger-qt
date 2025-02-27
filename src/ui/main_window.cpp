#include <QString>
#include <QStandardPaths>
#include <messenger/ui/main_windows.hpp>
#include <messenger/ui/menubar.hpp>
#include <messenger/app-info.hpp>

messenger::webengine_view *messenger::main_window::webengine_view = nullptr;

messenger::main_window::main_window() : QMainWindow() {
  setMinimumWidth(800);
  setMinimumHeight(600);
  setWindowTitle("Messenger Qt");
  setMenuBar(new messenger::menubar());

  if(webengine_view != nullptr) {
    setCentralWidget(webengine_view);
    webengine_view->load(QUrl(messenger::https_domain.c_str()));
  }
}

messenger::main_window::~main_window() {
  delete menuBar();
}