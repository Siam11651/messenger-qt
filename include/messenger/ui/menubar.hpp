#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>
#include <messenger/ui/menu/filemenu.hpp>
#include <messenger/ui/menu/helpmenu.hpp>

namespace messenger {
class menubar : public QMenuBar {
private:
  messenger::filemenu *m_filemenu;
  messenger::helpmenu *m_helpmenu;

public:
  menubar();
  ~menubar();
};
}; // namespace messenger

#endif