#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>

namespace messenger {
class menubar : public QMenuBar {
public:
  menubar(QWidget *_parent = nullptr);
  ~menubar();
};
}; // namespace messenger

#endif
