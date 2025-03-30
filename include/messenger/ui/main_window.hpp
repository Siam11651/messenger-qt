#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <messenger/ui/webengine_view.hpp>

namespace messenger {
class main_window : public QMainWindow {
public:
  static messenger::webengine_view *webengine_view;

  main_window();
  ~main_window();
};
} // namespace messenger

#endif
