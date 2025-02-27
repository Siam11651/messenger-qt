#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QWebEngineView>

namespace messenger {
class main_window : public QMainWindow {
private:
  QWebEngineProfile *m_webview_profile;
  QWebEngineView *m_webview;

public:
  main_window();
  ~main_window();
};
} // namespace messenger

#endif