#include <QWebEngineView>
#include <messenger/ui/dialog_window.hpp>

void messenger::dialog_window::handle_close() { deleteLater(); }

messenger::dialog_window::dialog_window(QWebEnginePage *const _page,
                                      QWidget *const _parent)
    : QMainWindow(_parent) {
  _page->setParent(this);
  setMinimumWidth(800);
  setMinimumHeight(600);
  setWindowTitle("Messenger Qt - Popup");
  setWindowIcon(QIcon("./assets/messenger.ico"));

  QWebEngineView *const view = new QWebEngineView(_page, this);

  setCentralWidget(view);
  connect(this, &messenger::dialog_window::close, this,
          &messenger::dialog_window::handle_close);
}

messenger::dialog_window::~dialog_window() {}
