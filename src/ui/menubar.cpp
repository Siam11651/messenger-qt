#include <messenger/ui/menubar.hpp>

messenger::menubar::menubar() : QMenuBar() {
  m_filemenu = new messenger::filemenu();
  m_helpmenu = new messenger::helpmenu();

  addMenu(m_filemenu);
  addMenu(m_helpmenu);
}

messenger::menubar::~menubar() {
  delete m_helpmenu;
  delete m_filemenu;
}