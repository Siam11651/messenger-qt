#ifndef FILEMENU_H
#define FILEMENU_H

#include <QMenu>
#include <QAction>

namespace messenger {
class filemenu : public QMenu {
private:
  QAction *m_refresh_action;
  QAction *m_restart_action;
  QAction *m_downloads_action;
  QAction *m_quit_action;

private slots:
  void handle_refresh_trigger();
  void handle_restart_trigger();
  void handle_downloads_trigger();
  void handle_quit_trigger();

public:
  filemenu();
  ~filemenu();
};
} // namespace messenger

#endif