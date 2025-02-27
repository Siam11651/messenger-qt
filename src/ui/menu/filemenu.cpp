#include <messenger/ui/menu/filemenu.hpp>

void messenger::filemenu::refresh_trigger() {
  
}

void messenger::filemenu::restart_trigger() {
  
}

void messenger::filemenu::quit_trigger() {
  
}

messenger::filemenu::filemenu() : QMenu() {
  setTitle("File");

  m_refresh_action = new QAction("Refresh");
  m_restart_action = new QAction("Restart");
  m_quit_action = new QAction("Quit");

  addAction(m_refresh_action);
  addAction(m_restart_action);
  addSeparator();
  addAction(m_quit_action);
  connect(m_refresh_action, &QAction::triggered, this, &messenger::filemenu::refresh_trigger);
  connect(m_restart_action, &QAction::triggered, this, &messenger::filemenu::restart_trigger);
  connect(m_quit_action, &QAction::triggered, this, &messenger::filemenu::quit_trigger);
}

messenger::filemenu::~filemenu() {
  delete m_refresh_action;
  delete m_restart_action;
  delete m_quit_action;
}