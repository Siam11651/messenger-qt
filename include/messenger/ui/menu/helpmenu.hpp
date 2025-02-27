#ifndef HELPMENU_H
#define HELPMENU_H

#include <QMenu>
#include <QAction>

namespace messenger {
class helpmenu : public QMenu {
private:
  QAction *m_homepage_action;
  QAction *m_about_action;

private slots:
  void homepage_trigger();
  void about_trigger();

public:
  helpmenu();
  ~helpmenu();
};
} // namespace messenger

#endif