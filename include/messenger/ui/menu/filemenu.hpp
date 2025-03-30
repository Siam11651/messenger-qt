#ifndef FILEMENU_H
#define FILEMENU_H

#include <QMenu>
#include <QAction>

namespace messenger {
class filemenu : public QMenu {
private slots:
  void handle_refresh_trigger();
  void handle_restart_trigger();
  void handle_quit_trigger();

public:
  filemenu(QWidget *_parent = nullptr);
  ~filemenu();
};
} // namespace messenger

#endif