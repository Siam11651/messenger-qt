#ifndef DIALOG_WINDOW_H
#define DIALOG_WINDOW_H

#include <QMainWindow>
#include <QWebEnginePage>

namespace messenger {
class dialog_window : public QMainWindow {
private:
  void handle_close();

public:
  dialog_window(QWebEnginePage *const _page, QWidget *const _parent = nullptr);
  ~dialog_window();
};
}

#endif
