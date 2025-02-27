#ifndef FILEMENU_H
#define FILEMENU_H

#include <QMenu>
#include <QAction>

namespace messenger {
class filemenu : public QMenu {
private:
  QAction *m_refresh_action;
  QAction *m_restart_action;
  QAction *m_quit_action;

private slots:
  void refresh_trigger();
  void restart_trigger();
  void quit_trigger();

public:
  filemenu();
  ~filemenu();
};
} // namespace messenger

#endif