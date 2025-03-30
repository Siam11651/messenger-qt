#include <QWebEngineView>
#include <messenger/app-info.hpp>
#include <messenger/ui/main_window.hpp>
#include <messenger/ui/menu/filemenu.hpp>

void messenger::filemenu::handle_refresh_trigger() {
  QWebEngineView *const webengine_view = messenger::main_window::webengine_view;

  if (webengine_view != nullptr) {
    webengine_view->reload();
  }
}

void messenger::filemenu::handle_restart_trigger() {
  QWebEngineView *const webengine_view = messenger::main_window::webengine_view;

  if (webengine_view != nullptr) {
    webengine_view->load(QUrl(messenger::https_domain.c_str()));
  }
}

void messenger::filemenu::handle_quit_trigger() {}

messenger::filemenu::filemenu(QWidget *_parent) : QMenu(_parent) {
  setTitle("File");

  QAction *m_refresh_action = new QAction("Refresh", this);
  QAction *m_restart_action = new QAction("Restart", this);
  QAction *m_quit_action = new QAction("Quit", this);

  addAction(m_refresh_action);
  addAction(m_restart_action);
  addSeparator();
  addAction(m_quit_action);
  connect(m_refresh_action, &QAction::triggered, this,
          &messenger::filemenu::handle_refresh_trigger);
  connect(m_restart_action, &QAction::triggered, this,
          &messenger::filemenu::handle_restart_trigger);
  connect(m_quit_action, &QAction::triggered, this,
          &messenger::filemenu::handle_quit_trigger);
}

messenger::filemenu::~filemenu() {}
