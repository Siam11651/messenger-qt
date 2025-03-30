#include <messenger/ui/menubar.hpp>
#include <messenger/ui/menu/filemenu.hpp>
#include <messenger/ui/menu/helpmenu.hpp>

messenger::menubar::menubar(QWidget *_parent) : QMenuBar(_parent) {
  messenger::filemenu *m_filemenu = new messenger::filemenu(this);
  messenger::helpmenu *m_helpmenu = new messenger::helpmenu(this);

  addMenu(m_filemenu);
  addMenu(m_helpmenu);
}

messenger::menubar::~menubar() {}