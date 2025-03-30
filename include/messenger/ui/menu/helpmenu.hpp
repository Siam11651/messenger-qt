#ifndef HELPMENU_H
#define HELPMENU_H

#include <QMenu>
#include <QAction>

namespace messenger {
class helpmenu : public QMenu {
private slots:
  void homepage_trigger();
  void about_trigger();

public:
  helpmenu(QWidget *_parent = nullptr);
  ~helpmenu();
};
} // namespace messenger

#endif
